import sys
import os

def place_to_input(app):
    design_place = app["design_place"]
    # read in design.place
    input_io = []
    with open(design_place, "r") as f:
        lines = f.readlines()
        for line in lines:
            if ("io16in" in line) and ("#I" in line):
                input_io.append(line)

    # alphabetically sort so io are in order
    input_io.sort()

    # extract placment
    input_place = []
    for input in input_io:
        input_place.append(int(input.split('\t')[2]) // 2)
    
    return input_place

def raw_to_bin(app, input_file):
    input_image = input_file

    input_place = place_to_input(app)

    input_unroll = len(input_place)


    # read in input image
    with open(input_image, "rb") as f:
        raw = f.read()
    raw = [hex(c) for c in raw]


    # sort input image
    for i in range(input_unroll):
        input_data0 = raw[2*i::2*input_unroll]
        input_data1 = raw[2*i+1::2*input_unroll]
        input_data_int = []
        for j in range(len(input_data0)):
            input_data_int.append(int(input_data1[j], 16))
            input_data_int.append(int(input_data0[j], 16))
        # make file
        current_dir = os.getcwd()
        new_dir = input_image.replace(app["gold"] + "/hw_input_stencil_","")
        new_dir = new_dir.replace(".raw","")
        new_dir_input = "app/input_bin/" + new_dir 
        new_dir_output = "app/output_bin/" + new_dir 
        input_path = os.path.join(current_dir, new_dir_input)
        output_path = os.path.join(current_dir, new_dir_output)
        if not os.path.isdir(input_path):
            os.mkdir(input_path)
        if not os.path.isdir(output_path):
            os.mkdir(output_path)
        shift = 0
        bin_file_name = input_path + "/image_" + str(input_place[i] + shift) + ".bin"
        bin_file = open(bin_file_name, "wb")
        # write to file
        bin_file.write(bytes(input_data_int))


if __name__ == '__main__':
    raw_to_bin(input_file)









