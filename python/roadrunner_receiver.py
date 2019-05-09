#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division

import time
import rospy
from collections import defaultdict
import mavlink as mavlink
import serial
from multilateration_tdoa import TDoAEngine, TDoAMeasurement, Anchor, Point  # https://github.com/AlexisTM/MultilaterationTDOA
from sensor_msgs.msg import Imu
from geometry_msgs.msg import PoseWithCovarianceStamped


class RoadrunnerHandler(object):
    # Should look into: [1] https://pdfs.semanticscholar.org/4090/577dc06b844a73c3855df9cc751107acd9c7.pdf
    # Should look into: [2] https://srbuenaf.webs.ull.es/potencia/hyperbolic%20location/HyperbolicLocation.pdf
    # Should look into: [3] https://github.com/chinmaysahu/TimeDifferenceOfArrival-Algorithm/blob/master/TDOA_algorithm.pdf
    def __init__(self):
        self.engine = TDoAEngine()
        self.height = float(rospy.get_param('height', 0.31))
        self.imu_publisher = rospy.Publisher('imu', Imu, queue_size=0)
        self.pose_publisher = rospy.Publisher('pose_cov', PoseWithCovarianceStamped, queue_size=0)
        self.has_orientation = False

        covariance_roll = float(rospy.get_param('~covariance_roll', 0.1))
        covariance_pitch = float(rospy.get_param('~covariance_pitch', 0.1))
        covariance_yaw = float(rospy.get_param('~covariance_yaw', 0.05)) # 3.4 deg

        # Message preparation
        self.pose_msg = PoseWithCovarianceStamped()
        self.pose_msg.header.frame_id = str(rospy.get_param('~frame_id_tdoa', 'map'))
        self.pose_msg.pose.covariance[21] = covariance_roll
        self.pose_msg.pose.covariance[28] = covariance_pitch
        self.pose_msg.pose.covariance[35] = covariance_yaw

        self.imu_msg = Imu()
        self.imu_msg.header.frame_id = str(rospy.get_param('~frame_id_imu', 'base_link'))
        self.imu_msg.orientation_covariance[0] = covariance_roll
        self.imu_msg.orientation_covariance[4] = covariance_pitch
        self.imu_msg.orientation_covariance[8] = covariance_yaw
        self.imu_msg.linear_acceleration_covariance[0] = float(rospy.get_param('~covariance_ax', 0.05))
        self.imu_msg.linear_acceleration_covariance[4] = float(rospy.get_param('~covariance_ay', 0.05))
        self.imu_msg.linear_acceleration_covariance[8] = float(rospy.get_param('~covariance_az', 0.05))
        self.imu_msg.angular_velocity_covariance[0] = float(rospy.get_param('~covariance_vx', 0.05))
        self.imu_msg.angular_velocity_covariance[4] = float(rospy.get_param('~covariance_vy', 0.05))
        self.imu_msg.angular_velocity_covariance[8] = float(rospy.get_param('~covariance_vz', 0.05))

    def quaternion_cb(self, msg):
        self.pose_msg.pose.pose.orientation.x = msg.x
        self.pose_msg.pose.pose.orientation.y = msg.y
        self.pose_msg.pose.pose.orientation.z = msg.z
        self.pose_msg.pose.pose.orientation.w = msg.w

        self.imu_msg.orientation.x = msg.x
        self.imu_msg.orientation.y = msg.y
        self.imu_msg.orientation.z = msg.z
        self.imu_msg.orientation.w = msg.w
        self.has_orientation = True
    
    def imu_cb(self, msg):
        self.imu_msg.linear_acceleration.x = msg.ax
        self.imu_msg.linear_acceleration.y = msg.ay
        self.imu_msg.linear_acceleration.z = msg.az
        self.imu_msg.angular_velocity.x = msg.vx
        self.imu_msg.angular_velocity.y = msg.vy
        self.imu_msg.angular_velocity.z = msg.vz

    def tdoa_long_cb(self, msg):
        now = rospy.Time.now()
        measure = TDoAMeasurement(Anchor((msg.anchor_ax, msg.anchor_ay, msg.anchor_az)),
                                  Anchor((msg.anchor_bx, msg.anchor_by, msg.anchor_bz)), 
                                  msg.dist_diff)
        result, hess_inv = self.engine.add_solve_2D(measure, 0.31)
        if result is None:
            return

        self.pose_msg.pose.pose.position.x = result.x
        self.pose_msg.pose.pose.position.y = result.y
        self.pose_msg.pose.pose.position.z = result.z
        self.pose_msg.pose.covariance[0] = hess_inv[0][0]  # xx
        self.pose_msg.pose.covariance[1] = hess_inv[0][1]  # xy
        self.pose_msg.pose.covariance[6] = hess_inv[1][0]  # yx
        self.pose_msg.pose.covariance[7] = hess_inv[1][1]  # yy
        self.pose_msg.pose.covariance[14] = 0.0001         # zz
        self.pose_msg.header.stamp = now
        if self.has_orientation:
            self.pose_publisher.publish(self.pose_msg)


class FakeFile(object):
    """Mavlink class requires a File class but it is unused in our case."""
    def write(self, *args, **kwargs):
        pass


class RoadrunnerReceiver(object):
    def __init__(self, device="/dev/ttyUSB0", baudrate=1000000, callback_all=lambda msg: None , *args, **kwargs):
        self.data_amounts = defaultdict(int)
        self.data_timings = defaultdict(float)
        self.serial = serial.Serial(device, baudrate, timeout=0.1)
        self.mavlink_link = mavlink.MAVLink(FakeFile())
        self.mavlink_link.set_callback(self.internal_callback_all)
        self.external_callback_all = callback_all
        self.start = time.time()
        self.callbacks = defaultdict(lambda: lambda msg: None)

    def add_callback(self, ID, callback):
        self.callbacks[ID] = callback

    def internal_callback_all(self, msg):
        self.external_callback_all(msg)
        index = msg.name
        self.callbacks[msg.id](msg)
        self.data_amounts[index] += 1
        if(self.data_amounts[index] % 100 == 0):
            tmp_time = time.time()
            hz = 1/((tmp_time - self.data_timings[index])/100)
            print(str(self.data_amounts[index]) + " of " + index + " " + str(hz) + "Hz")
            self.data_timings[index] = tmp_time


    def spin(self):
        while(True):
            try:
                waiting = self.serial.in_waiting
                char = self.serial.read() # 10 bytes
                if(len(char) != 1): continue
                self.mavlink_link.parse_char(char)
            except Exception as e:
                pass
                print("error", e)

if __name__ == "__main__":
    rospy.init_node('roadrunner_receiver')
    rr = RoadrunnerReceiver()
    tdoa_handler = RoadrunnerHandler()
    rr.add_callback(mavlink.MAVLINK_MSG_ID_TDOA_MEASUREMENT, tdoa_handler.tdoa_long_cb)
    rr.add_callback(mavlink.MAVLINK_MSG_ID_QUATERNION, tdoa_handler.quaternion_cb)
    rr.add_callback(mavlink.MAVLINK_MSG_ID_GYRO_ACC, tdoa_handler.imu_cb)
    rr.spin()
