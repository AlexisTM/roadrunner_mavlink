#!/usr/bin/env python

from __future__ import print_function

import time
from collections import defaultdict
import mavlink
import serial

class FakeFile(object):
    def write(*args, **kwargs):
        pass

class RoadrunnerReceiver(object):
    def __init__(self, device="/dev/ttyUSB0", baudrate=921600, *args, **kwargs):
        self.data_amounts = defaultdict(int)
        self.data_timings = defaultdict(float)
        self.serial = serial.Serial(device, baudrate, timeout=0.1)
        self.mavlink_link = mavlink.MAVLink(FakeFile())
        self.mavlink_link.set_callback(self.print_all)

    def print_all(self, msg):
        index = msg.name

        # if len(msg.reason) > 30:
        #     index = msg.reason[29]
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
                print('w', waiting)
                if(waiting != 0):
                    char = self.serial.read(waiting) # Read all data left
                else:
                    char = self.serial.read(10) # 10 bytes
                self.mavlink_link.parse_buffer(char)
            except Exception as e:
                pass
                print("error", e)

if __name__ == "__main__":
    rr = RoadrunnerReceiver()
    rr.spin()
