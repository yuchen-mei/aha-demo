import sys
import shutil
import json

import io_placement
import raw_to_h_16
import bs_to_h
import meta



name_list = sys.argv[2:]
name_list = []
name_list.append(f"tile0")
for i in range(1, 44):
    name_list.append(f"tile{i}")
print(name_list)
path = name_list[0] + "/"

# for dense use the single app, for sparse we use the concatenation of inputs
if sys.argv[1] == "dense":
    dense = 1
    data_file_str = name_list[0] + "/"
else:
    dense = 0
    data_file_str = "./"

# Get input/output file name information, io order and bitstream from first tile
inputs, outputs, input_order, output_order, bitstream_name = meta.meta_scrape(name_list[0] + "/design_meta.json")

# bitstream is same for every tile
bs_to_h.convert_bs(path + bitstream_name, path)

# copy reg_write and script into base folder
shutil.copy(f"{path}reg_write.h", "./")
shutil.copy(f"{path}script.h", "./")


# need to generate image input/output per tile
# combine inputs into one raw file
if not dense: 
    input_paths = []
    for input_file in inputs:
        for name in name_list:
            input_paths.append(f"{name}/{input_file}")
        with open(input_file, "wb") as output:
            for file in input_paths:
                with open(file, "rb") as partial:
                    shutil.copyfileobj(partial, output)
        input_paths = []


# get extents of all inputs
# initialize dict
extent_dict = {}
for input in inputs:
    extent_dict[input] = []


for name in name_list:
    meta_file_name = name + "/design_meta.json"
    f = open(meta_file_name)
    meta = json.load(f)

    # add extents
    for input in meta["IOs"]["inputs"]:
        extent_dict[input["datafile"]].append(input["shape"][0])


# convert to input
raw_to_h_16.convert_image(inputs, outputs, data_file_str, len(name_list), dense)

# io placement and extents
io_placement.unrolling(inputs, outputs, input_order, output_order, extent_dict, name_list, dense)

