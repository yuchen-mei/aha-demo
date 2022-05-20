import sys

def raw_to_bin(input_file):
    design_place = 'design.place'
    input_image = input_file


    shift = 2

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
        bin_file_name = "app/image_" + str(input_place[i] + shift) + ".bin"
        bin_file = open(bin_file_name, "wb")
        # write to file
        bin_file.write(bytes(input_data_int))


if __name__ == '__main__':
    raw_to_bin(input_file)









