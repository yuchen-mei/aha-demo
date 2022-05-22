def generate_gdb():
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
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image2.bin 0x204A0000 0x204A0B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image3.bin 0x204E0000 0x204E0B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image4.bin 0x20520000 0x20520B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image5.bin 0x20560000 0x20560B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image6.bin 0x205A0000 0x205A0B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image7.bin 0x205E0000 0x205E0B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image8.bin 0x20620000 0x20620B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image9.bin 0x20660000 0x20660B58\n")
            f.write("dump binary memory /Users/kkoul/AHA_demo/jtag_app_run/app/output_bin/" + tile + "/out_image10.bin 0x206A0000 0x206A0B58\n")

            x = x + x_step

        x = 0
        y = y + y_step


    f.write("quit\n")

    f.close()

if __name__ == '__main__':
    generate_gdb()