import sys
import numpy as np

def place_to_output(app):

    design_place = app["design_place"]

    # read in design.place, TODO change to output
    input_io = []
    with open(design_place, "r") as f:
        lines = f.readlines()
        for line in lines:
            if ("io16_hw_output" in line) and ("#I" in line):
                input_io.append(line)
    strip_io = []
    for input in input_io:
        idx = input[input.find('hcompute'):]
        if(idx.find('stencil_write')):
            idx = idx.replace('stencil_write', 'stencil_0_write')
        strip_io.append(idx)

    strip_io.sort()
    # print(strip_io)


    # extract placment
    input_place = []
    for input in strip_io:
        input_place.append(int(input.split('\t')[2]) // 2)

    return input_place

def bin_to_raw(app, output_file):
    design_place = app["design_place"]
    new_dir = output_file.replace("hw_output_","")
    new_dir = new_dir.replace(".raw","")
    bin_folder = 'app/output_bin/'  + new_dir + "/"


    input_place = place_to_output(app)

    # print(input_place)

    input_data = []

    shift = 2
    # read all bin files
    sorted_inputs = sorted(input_place)
    for i in sorted_inputs:
        with open(bin_folder + "out_image" + str(shift + i) + ".bin", "rb") as f:
            input_data.append(f.read())

    raw = []


    for j in range(int(len(input_data[0])/2)):
        for i in range(len(input_place)):
            idx = input_place[i] - min(input_place)
            raw.append(input_data[idx][2*j+1])
            raw.append(input_data[idx][2*j])


    tile = np.asarray(raw, dtype='uint8')
    tile = tile.tobytes()
    fi = open("chip/" + output_file, "wb")
    fi.write(tile)
    fi.close() 

if __name__ == '__main__':
    bin_to_raw(app, output_file)











