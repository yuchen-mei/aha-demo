import sys
import os



with open("unsharp_padded.bs", "r") as f:
    bs_lines = f.readlines()

size = len(bs_lines)
block_iter = int((size + 63) / 64)
total_size = 2 * (block_iter-1) * 64 + (size % 64)

bs_double = []

for i in range(block_iter):
    bs_block_lines = bs_lines[i*64:(i+1)*64]
    if i == (block_iter-1):
        for line in bs_block_lines:
            bs_double.append(line)
    else:
        for _ in range(2):
            for line in bs_block_lines:
                bs_double.append(line)

bs_shifted = []

for line in bs_double:
    strings = line.split()
    addr = strings[0]
    shift = hex(int(addr[4:6], 16) + 4)[2:4]
    if(len(shift) == 1):
        shift = '0' + shift
    shifted_addr = addr[0:4] + shift + addr[6:8]
    total_packet = shifted_addr + strings[1]
    bs_shifted.append(total_packet)

print(bs_shifted)

bin_data = []
for config in bs_shifted:
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





bin_file = open("app/bitstream.bin", "wb")
bin_file.write(bytes(bin_data))