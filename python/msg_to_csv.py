#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import defaultdict
import csv
from time import time
import warnings
import os

class MsgToCSV(object):
    def __init__(self, folder="dump"):
        self.handlers = defaultdict(dict)
        self.folder = folder
        self.start_time = time()
        if not os.path.exists(self.folder):
            os.makedirs(self.folder)

    def write(self, msg):
        if msg.name in self.handlers:
            self.handlers[msg.name]["writer"].writerow([str(time() - self.start_time)] + msg.to_dict().values()[:-1])
        else:
            filename = msg.name + ".csv"
            path = os.path.join(self.folder, filename)
            csvfile = open(path, 'w')
            self.handlers[msg.name]['file'] = csvfile
            handler = csv.writer(csvfile)
            handler.writerow(["timestamp"] + msg._fieldnames)
            self.handlers[msg.name]['writer'] = handler


    def __del__(self):
        try:
            for f in self.handlers.values():
                f['file'].close()
        except Exception as ex:
            warnings.warn(ex)
