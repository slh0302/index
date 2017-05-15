import os
import shutil
import time
from subprocess import Popen, PIPE

file_name = ["total.list_0", "total.list_1", "total.list_2"
    , "total.list_3", "total.list_4", "total.list_5", "total.list_6"]

file_count = [2000000, 2000000, 2000000, 2000000, 2000000, 2000000, 251928]
file_name_prefix = "/home/slh/extract_file/"
target_prefix = "/home/slh/Vechile_Search/libfaster_rcnn_cpp"
file_list_name = "/home/slh/Vechile_Search/libfaster_rcnn_cpp/examples/_temp/file_list"
num = 0
beg = time.time()
for index in file_name:
    if os.path.isfile(file_list_name):
        os.remove(file_list_name)
        shutil.copyfile(file_name_prefix + index, file_list_name)
    else:
        shutil.copyfile(file_name_prefix + index, file_list_name)

    lines = file_count[num]
    print os.path.isfile(file_list_name)

    exec_script = "./bin/DoIndex -i " + file_name_prefix + index + " " + str(lines) + \
                  " 280 ~/data_model_120000_2000000_" + str(num) + " GPU 0 "

    print exec_script
    resp = Popen(exec_script, shell=True, stdout=PIPE, stderr=PIPE).stdout.readlines()
    end = time.time()
    num = num + 1
    print "read: %f s" % (end - beg)
    print resp[-1]
