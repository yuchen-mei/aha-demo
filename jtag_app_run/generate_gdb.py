import bin_to_raw_glb
import raw_to_bin_glb

def generate_gdb(app):
    f = open("app/new_script.gdb", "w")

    f.write("target remote localhost:2331\n")
    f.write("set mem inaccessible-by-default off\n")
    f.write("monitor speed 15000\n")
    f.write("monitor clrbp\n")
    f.write("monitor reset\n")
    f.write("monitor halt\n")
    f.write("monitor flash breakpoints 1\n")
    f.write("monitor semihosting enable\n")
    f.write("symbol-file /Users/kalhankoul/aha_demo/jtag_app_run/app/" + app["elf"] + "\n")
    f.write("load /Users/kalhankoul/aha_demo/jtag_app_run/app/" + app["elf"] + "\n")




    x = 0
    y = 0

    shift = 0

    input_place = raw_to_bin_glb.place_to_input(app)
    output_place = bin_to_raw_glb.place_to_output(app)

    # TODO HACKY
    if(len(output_place) == 9):
        unroll = 3
    elif (len(output_place) == 12):
        unroll = 4
    else:
        unroll = 1    
    output_tile_size = app["x_dim"]*app["y_dim"]//unroll*2


    tile_mismatch = 0
    for height in range(app["y_tiles"]):
        for width in range(app["x_tiles"]):
            tile = str(y)+"_"+str(x)
            
            f.write("monitor clrbp\n")
            f.write("monitor reset\n")
            f.write("monitor halt\n")
            # f.write("set $CGRA_CLK_SEL_ADDR = 0x40007028\n")
            # f.write("set $CLK_GATE_EN_ADDR = 0x40007044\n")
            # f.write("set $RESET_REQ_ADDR = 0x4000704C\n")
            # f.write("set {unsigned int}$CGRA_CLK_SEL_ADDR = 0x00000000\n")
            # f.write("set {unsigned int}$CLK_GATE_EN_ADDR = *(unsigned int)$CLK_GATE_EN_ADDR & ~(1 << 8)\n")
            # f.write("set {unsigned int}$RESET_REQ_ADDR = *(unsigned int)$RESET_REQ_ADDR & ~(1 << 8)\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/bitstream.bin binary 0x204A0000\n")

            for i in input_place:
                addr = hex(int(0x20400000) + i*int(0x40000))
                shift_i = shift + i
                f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_" + str(shift_i) + ".bin binary " + addr + "\n")

            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_2.bin binary 0x20480000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_3.bin binary 0x204C0000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_4.bin binary 0x20500000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_5.bin binary 0x20540000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_6.bin binary 0x20580000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_7.bin binary 0x205C0000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_8.bin binary 0x20600000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_9.bin binary 0x20640000\n")
            # f.write("restore /Users/kalhankoul/aha_demo/jtag_app_run/app/input_bin/" + tile + "/image_10.bin binary 0x20680000\n")
            f.write("monitor clrbp\n")
            f.write("monitor reset\n")
            f.write("monitor halt\n")
            f.write("b main\n")
            f.write("continue\n")
            f.write("b _exit\n")
            f.write("continue\n")
            f.write("step\n")

            for o in output_place:
                addr_start = hex(int(0x20400000) + o*int(0x40000) + int(0x20000))
                addr_end = hex(int(0x20400000) + (o)*int(0x40000) + int(0x20000) + output_tile_size) 
                shift_o = shift + o
                f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image" + str(shift_o) + ".bin " + addr_start + " " + addr_end + "\n")

            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image2.bin 0x204A0000 0x204A" + output_tile_size+ "\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image3.bin 0x204E0000 0x204E" + output_tile_size+ "\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image4.bin 0x20520000 0x20538000\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image5.bin 0x20560000 0x20578000\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image6.bin 0x205A0000 0x205B8000\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image7.bin 0x205E0000 0x205E" + output_tile_size+ "\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image8.bin 0x20620000 0x2062" + output_tile_size+ "\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image9.bin 0x20660000 0x2066" + output_tile_size+ "\n")
            # f.write("dump binary memory /Users/kalhankoul/aha_demo/jtag_app_run/app/output_bin/" + tile + "/out_image10.bin 0x206A0000 0x206A" + output_tile_size+ "\n")

            x = x + app["x_step"]

        x = 0
        y = y + app["y_step"]


    f.write("quit\n")

    f.close()

if __name__ == '__main__':
    generate_gdb(app)