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
    f.write("symbol-file /Users/kkoul/AHA_demo/jtag_app_run/app/test_app.elf\n")
    f.write("load /Users/kkoul/AHA_demo/jtag_app_run/app/test_app.elf\n")


    # TODO generalize past unsharp
    output_tile_size = hex(int(app["x_dim"]*app["y_dim"]/3*2))[2:]

    while(len(output_tile_size) < 4):
        output_tile_size = '0' + output_tile_size

    print(output_tile_size)

    x = 0
    y = 0


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
            # f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/bitstream.bin binary 0x204A0000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_2.bin binary 0x20480000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_3.bin binary 0x204C0000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_4.bin binary 0x20500000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_5.bin binary 0x20540000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_6.bin binary 0x20580000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_7.bin binary 0x205C0000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_8.bin binary 0x20600000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_9.bin binary 0x20640000\n")
            f.write("restore /Users/kkoul/AHA_demo/jtag_app_run/app/input_bin/" + tile + "/image_10.bin binary 0x20680000\n")
            f.write("monitor clrbp\n")
            f.write("monitor reset\n")
            f.write("monitor halt\n")
            f.write("b main\n")
            f.write("continue\n")
            f.write("b _exit\n")
            f.write("continue\n")
            f.write("step\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image2.bin 0x204A0000 0x204A" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image3.bin 0x204E0000 0x204E" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image4.bin 0x20520000 0x2052" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image5.bin 0x20560000 0x2056" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image6.bin 0x205A0000 0x205A" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image7.bin 0x205E0000 0x205E" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image8.bin 0x20620000 0x2062" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image9.bin 0x20660000 0x2066" + output_tile_size+ "\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image10.bin 0x206A0000 0x206A" + output_tile_size+ "\n")

            x = x + app["x_step"]

        x = 0
        y = y + app["y_step"]


    f.write("quit\n")

    f.close()

if __name__ == '__main__':
    generate_gdb(app)