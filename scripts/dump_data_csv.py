#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function

from roadrunner_receiver import RoadrunnerReceiver
from msg_to_csv import MsgToCSV

if __name__ == "__main__":
    msg_csv = MsgToCSV()
    rr = RoadrunnerReceiver(callback_all=msg_csv.write)
    rr.spin()
