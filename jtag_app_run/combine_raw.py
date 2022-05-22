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
    img.show()

if __name__ == '__main__':
    combine_raw(app)