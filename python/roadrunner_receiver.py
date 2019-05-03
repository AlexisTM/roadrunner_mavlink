#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function

import time
from collections import defaultdict
import mavlink as mavlink
import serial
from multilateration import Engine, Point  # https://github.com/AlexisTM/Multilateration

def TDoAHandler(object):
    # Should look into: https://pdfs.semanticscholar.org/4090/577dc06b844a73c3855df9cc751107acd9c7.pdf
    # Should look into: https://srbuenaf.webs.ull.es/potencia/hyperbolic%20location/HyperbolicLocation.pdf
    def __init__(self):
        self.engine = Engine(goal=[None, None, None])
        self.n_updates = 0

    def callback_long(self, msg):
        """Long message, the message contains both anchors positions"""
        self.n_updates += 1
        anchor_a = Point(msg.anchor_ax, msg.anchor_ay, msg.anchor_az)
        anchor_b = Point(msg.anchor_bx, msg.anchor_by, msg.anchor_bz)
        
        distance_anchors = anchor_a.dist(anchor_b)
        tdoa_measurement = msg.dist_diff

        print(tdoa_measurement, distance_anchors)


        # self.engine.add_measure(positionA, )


        if self.n_updates > 5:
            print(self.engine.solve())
        pass

    def callback_short(self, msg):
        """Short message, the message contains only the ID of the anchors, the position is given in a different message."""
        pass

    def callback_add_anchor(self, msg):
        """Add an anchor for short message usage"""
        pass


class FakeFile(object):
    """Mavlink class requires a File class but it is unused in our case."""
    def write(*args, **kwargs):
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
    rr = RoadrunnerReceiver()
    rr.spin()
