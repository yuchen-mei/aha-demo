import glob
import subprocess
import sys
import numpy as np
from PIL import Image
import pdb



def combine_raw(app): 

    column = []

    x = 0
    y = 0

    for height in range(app["y_tiles"]):
        row = []
        for width in range(app["x_tiles"]):
            tile_f = "chip/hw_output_"+str(y)+"_"+str(x)+".raw"
            with open(tile_f, "rb") as t:
                raw = t.read()
            # remove 0s
            raw_c = [c for c in raw]
            tile_raw_c = raw_c[1::2]
            tile = np.asarray(tile_raw_c, dtype='uint8')
            tile = np.reshape(tile, (app["y_dim"], app["x_dim"], 3))
            if row == []:
                row = tile
            else: 
                row = np.concatenate((row, tile), axis=1)
            x = x + app["x_step"]
        x = 0
        if column == []:
            column = row
        else: 
            column = np.concatenate((column, row), axis=0)  
        y = y + app["y_step"]
    full_image = column

    fi = open("full_image.raw", "wb")
    full_image = full_image.tobytes('C')
    fi.write(full_image)
    fi.close()

    rawData = open("full_image.raw", 'rb').read()
    imgSize = (app["x_dim"]*app["x_tiles"], app["y_dim"]*app["y_tiles"])
    img = Image.frombytes('RGB', imgSize, rawData)
    img.save("full_image.png")


    if(app["gold"] == "gold_cp_small_dog"):
        pixels = list(img.getdata())
        pixels_first_half = pixels[::2]
        pixels_second_half = pixels[1::2]

        shuffle = []
        for i in range(336//2):
            shuffle = shuffle + (pixels_first_half[i*248:i*248+248])
            shuffle = shuffle + (pixels_second_half[i*248:i*248+248])
            
        new_img = Image.new("RGB", (app["x_dim"], app["y_dim"]))
        new_img.putdata(shuffle)
        new_img.save('full_image.png')
        new_img.show()
    else: 
        img.show()


if __name__ == '__main__':
    combine_raw(app)