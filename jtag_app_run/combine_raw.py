import glob
import subprocess
import sys
import numpy as np
from PIL import Image
import pdb



def combine_raw(): 

    x_step = 1
    x_tiles = 21
    x_dim = 66

    y_step = 66
    y_tiles = 35
    y_dim = 66
    column = []

    x = 0
    y = 0

    for height in range(y_tiles):
        row = []
        for width in range(x_tiles):
            tile_f = "chip/hw_output_"+str(y)+"_"+str(x)+".raw"
            with open(tile_f, "rb") as t:
                raw = t.read()
            # remove 0s
            raw_c = [c for c in raw]
            tile_raw_c = raw_c[1::2]
            tile = np.asarray(tile_raw_c, dtype='uint8')
            tile = np.reshape(tile, (y_dim, x_dim, 3))
            if row == []:
                row = tile
            else: 
                row = np.concatenate((row, tile), axis=1)
            x = x + x_step
        x = 0
        if column == []:
            column = row
        else: 
            column = np.concatenate((column, row), axis=0)  
        y = y + y_step
    full_image = column

    fi = open("full_image.raw", "wb")
    full_image = full_image.tobytes('C')
    fi.write(full_image)
    fi.close()

    rawData = open("full_image.raw", 'rb').read()
    imgSize = (x_dim*x_tiles, y_dim*y_tiles)
    img = Image.frombytes('RGB', imgSize, rawData)
    img.save("full_image.png")


if __name__ == '__main__':
    combine_raw()