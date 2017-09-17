import os
import shutil
import time
from subprocess import Popen, PIPE

file_name = ["total_list_0", "total_list_1", "total_list_2"
    , "total_list_3", "total_list_4", "total_list_5"
    , "total_list_6", "total_list_7", "total_list_8"
    , "total_list_9", "total_list_10", "total_list_11"]

file_count = [2000000, 2000000, 2000000, 2000000, 2000000
    , 2000000, 2000000, 2000000, 2000000, 2000000, 2000000, 355764]
file_name_prefix = "/home/slh/data/new_data_float/"
file_list_name = "/home/slh/Vechile_Search/libfaster_rcnn_cpp/examples/_temp/file_list"
num = 0
beg = time.time()
for index in file_name:
    if not os.path.exists(file_name_prefix + index):
        print file_name_prefix + index, " not exist"
        exit()
    lines = file_count[num]

    exec_script = "./bin/DoIndex -i " + file_name_prefix + index + " " + str(lines) + \
                  " 280 ~/data_float_2000000_" + str(num) + " GPU 0 "

    print exec_script
    resp = Popen(exec_script, shell=True, stdout=PIPE, stderr=PIPE).stdout.readlines()
    end = time.time()
    num = num + 1
    print "read: %f s" % (end - beg)
    print resp[-1]
