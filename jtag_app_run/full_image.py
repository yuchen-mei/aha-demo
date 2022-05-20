import sys
import subprocess
import os
import time

import bin_to_raw_glb
import raw_to_bin_glb
import combine_raw

def full_image():

    print("full image script", flush=True)

    x_step = 1
    x_tiles = 21
    x_dim = 66

    y_step = 66
    y_tiles = 35
    y_dim = 66
    column = []

    x = 0
    y = 0

    tile_mismatch = 0
    for height in range(y_tiles):
        for width in range(x_tiles):
            start = time.time()
            tile_in = "gold/hw_input_stencil_"+str(y)+"_"+str(x)+".raw"
            tile_out = "hw_output_"+str(y)+"_"+str(x)+".raw"

            # Convert raw to binaries for glb
            raw_to_bin_glb.raw_to_bin(tile_in)
            # Run jtag which will place binaries in glb, run app, read binaries out of glb
            subprocess.run(["./Run.sh"], shell=True, check=True)
            # Convert output binaries into output raw file
            bin_to_raw_glb.bin_to_raw(tile_out)

            # diff chip output raw with gold raw
            cmd = "diff chip/" + tile_out + " " + "gold/" + tile_out
            try:   
                diff = subprocess.run([cmd], shell=True, check=True)   
            except CalledProcessError:
                print("output image mismatch")

            x = x + x_step

            print("tile time", flush=True)
            print(time.time() - start, flush=True)

        x = 0
        y = y + y_step

    print("tile_mismatch")
    print(tile_mismatch)
    
    combine_raw.combine_raw()



if __name__ == '__main__':
    full_image()