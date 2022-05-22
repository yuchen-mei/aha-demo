import sys
import subprocess
import os
import time

import bin_to_raw_glb
import raw_to_bin_glb
import combine_raw
import generate_gdb

def full_image():

    print("full image script", flush=True)

    generate_gdb.generate_gdb()

    x_step = 1
    x_tiles = 21
    x_dim = 66

    y_step = 66
    y_tiles = 35
    y_dim = 66
    column = []

    x = 0
    y = 0

    start = time.time()

    for height in range(y_tiles):
        for width in range(x_tiles):
            start = time.time()
            tile_in = "gold/hw_input_stencil_"+str(y)+"_"+str(x)+".raw"
            tile_out = "hw_output_"+str(y)+"_"+str(x)+".raw"

            # Convert raw to binaries for glb
            raw_to_bin_glb.raw_to_bin(tile_in)
            
            x = x + x_step

        x = 0
        y = y + y_step

    print("time to generate bins")
    print(time.time() - start)
    start = time.time()

    subprocess.run(["./Run.sh"], shell=True, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    #subprocess.run(["./Run.sh"], shell=True, check=True)

    print("time to run image")
    print(time.time() - start)
    start = time.time()

    x = 0
    y = 0

    for height in range(y_tiles):
        for width in range(x_tiles):
            start = time.time()
            tile_in = "gold/hw_input_stencil_"+str(y)+"_"+str(x)+".raw"
            tile_out = "hw_output_"+str(y)+"_"+str(x)+".raw"
            
            # Convert output binaries into output raw file
            bin_to_raw_glb.bin_to_raw(tile_out)

            # diff chip output raw with gold raw
            # cmd = "diff chip/" + tile_out + " " + "gold/" + tile_out
            # try:   
            #     diff = subprocess.run([cmd], shell=True, check=True)   
            # except CalledProcessError:
            #     print("output image mismatch")

            x = x + x_step

        x = 0
        y = y + y_step

 
    
    combine_raw.combine_raw()

    print("time to convert to raw and generate png")
    print(time.time() - start)

if __name__ == '__main__':
    full_image()