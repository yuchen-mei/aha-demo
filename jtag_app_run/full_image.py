import sys
import subprocess
import os
import time
from PIL import Image
import json

import bin_to_raw_glb
import raw_to_bin_glb
import combine_raw
import generate_gdb

def full_image(app_json):

    #print("full image script", flush=True)

    with open(sys.argv[1]) as json_file:
        app = json.load(json_file)

    generate_gdb.generate_gdb(app)


    x = 0
    y = 0

    start = time.time()

    for height in range(app['y_tiles']):
        for width in range(app['x_tiles']):
            start = time.time()
            tile_in = app["gold"] + "/hw_input_stencil_"+str(y)+"_"+str(x)+".raw"

            # Convert raw to binaries for glb
            raw_to_bin_glb.raw_to_bin(app, tile_in)
            
            x = x + app['x_step']

        x = 0
        y = y + app['y_step']

    # print("time to generate bins")
    # print(time.time() - start)
    start = time.time()

    img = Image.open(app["input_image"])
    img.show()

    wait = input("Accelerate Application")

    subprocess.run(["./Run.sh"], shell=True, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    #subprocess.run(["./Run.sh"], shell=True, check=True)

    # print("time to run image")
    # print(time.time() - start)
    #start = time.time()

    x = 0
    y = 0

    for height in range(app['y_tiles']):
        for width in range(app['x_tiles']):
            # start = time.time()
            tile_out = "hw_output_"+str(y)+"_"+str(x)+".raw"
            
            # Convert output binaries into output raw file
            bin_to_raw_glb.bin_to_raw(app, tile_out)

            # diff chip output raw with gold_ltu raw
            # cmd = "diff chip/" + tile_out + " " + "gold_ltu/" + tile_out
            # try:   
            #     diff = subprocess.run([cmd], shell=True, check=True)   
            # except CalledProcessError:
            #     print("output image mismatch")

            x = x + app['x_step']

        x = 0
        y = y + app['y_step']

 
    
    combine_raw.combine_raw(app)

    # print("time to convert to raw and generate png")
    # print(time.time() - start)

if __name__ == '__main__':
    full_image(sys.argv[1])