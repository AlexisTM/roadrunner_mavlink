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
    def __init__(self, device="/dev/ttyUSB0", baudrate=1000000, *args, **kwargs):
        self.data_amounts = defaultdict(int)
        self.data_timings = defaultdict(float)
        self.serial = serial.Serial(device, baudrate, timeout=0.1)
        self.mavlink_link = mavlink.MAVLink(FakeFile())
        self.mavlink_link.set_callback(self.print_all)
        self.start = time.time()

    def print_all(self, msg):
        index = msg.name
        self.data_amounts[index] += 1
        if(self.data_amounts[index] % 100 == 0):
            tmp_time = time.time()
            hz = 1/((tmp_time - self.data_timings[index])/100)
            print(str(self.data_amounts[index]) + " of " + index + " " + str(hz) + "Hz")
            self.data_timings[index] = tmp_time

    def spin(self):
        while(True):
            try:
                start = time.time()
                t = 0
                while t < 1000: 
                    waiting = self.serial.in_waiting
                    char = self.serial.read() # 10 bytes
                    if(len(char) != 1): continue
                    self.mavlink_link.parse_char(char)
                    t += 1
                stop = time.time()
                # print("TIME: ", str(1/(stop-start)) + "Hz")
            except Exception as e:
                pass
                print("error", e)

if __name__ == "__main__":
    rr = RoadrunnerReceiver()
    rr.spin()
