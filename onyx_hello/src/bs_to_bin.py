import sys
import os



with open("camera_pipeline_2x2.bs", "r") as f:
    bs_lines = f.readlines()


print(bs_lines)

bin_data = []
for config in bs_lines:
    input_data0 = config[0:2]
    input_data1 = config[2:4]
    input_data2 = config[4:6]
    input_data3 = config[6:8]
    input_data4 = config[8:10]
    input_data5 = config[10:12]
    input_data6 = config[12:14]
    input_data7 = config[14:16]

    bin_data.append(int(input_data7, 16))
    bin_data.append(int(input_data6, 16))
    bin_data.append(int(input_data5, 16))
    bin_data.append(int(input_data4, 16))
    bin_data.append(int(input_data3, 16))
    bin_data.append(int(input_data2, 16)) 
    bin_data.append(int(input_data1, 16))
    bin_data.append(int(input_data0, 16))





bin_file = open("bitstream.bin", "wb")
bin_file.write(bytes(bin_data))
