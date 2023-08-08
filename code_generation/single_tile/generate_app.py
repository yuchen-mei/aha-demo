import sys
import shutil

import io_placement
import raw_to_h_16
import bs_to_h
import meta
import os



inputs, outputs, input_order, output_order, bitstream_name = meta.meta_scrape("design_meta.json")


raw_to_h_16.convert_image(inputs, outputs, sys.argv[1])
bs_to_h.convert_bs(bitstream_name, sys.argv[1])
io_placement.unrolling(inputs, outputs, input_order, output_order, sys.argv[1])
with open('reg_write.h', 'r') as file:
    data = file.read()
    data = data.replace('glb_reg_write', 'HAL_Cgra_Glb_WriteReg')
with open('reg_write.h', 'w') as file:
    file.write(data)
shutil.copyfile("reg_write.h", sys.argv[1] + "_reg_write.h")

