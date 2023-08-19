import sys
import os 
import re


def unrolling(inputs, outputs, input_order, output_order, app_name):
    input_place_list = input_order
    output_place_list = output_order 
    f = open(app_name + "_unrolling.h", "w")
    checkpoint = 0
    f.write("#define AHASOC_CGRA_DATA_BASE    (0x20400000UL)  /*!< (CGRA DATA ) Base Address */\n");
    for idx, input_name in enumerate(inputs):
        input_name_str = input_name.replace("hw_", "")
        input_name_str = input_name_str.replace(".raw", "")
        f.write(f"int {input_name_str}_unroll = {len(input_place_list[idx])};\n")
        f.write(f"int {input_name_str}_unroll_array[{len(input_place_list[idx])}] = {{\n")
        input_str = ", ".join([str(elem) for elem in input_place_list[idx]])
        f.write(input_str)
        f.write(f"\n}};\n")

    f.write("static void move_input_data()\n")
    f.write("{\n")
    for idx, input_name in enumerate(inputs):
        input_name_str = input_name.replace("hw_", "")
        input_name_str = input_name_str.replace(".raw", "")
        f.write(f"for (int i = 0; i < {input_name_str}_unroll; i++) {{\n")
        f.write(f"  write_glb_memory(0x40000 * ({input_name_str}_unroll_array[i]), (uint16_t * ) app_{input_name_str}_data, app_{input_name_str}_data_size / {input_name_str}_unroll, i, {input_name_str}_unroll);\n")
        f.write("}\n")

        checkpoint = checkpoint + len(input_place_list[idx])
    f.write("}\n\n")

    # stream val calculations
    stream_pulse_g2f = 0
    stream_pulse_f2g = 0

    for io_in in input_place_list:
        stream_pulse_g2f |= (1 << io_in[0])
    for io_out in output_place_list:
        stream_pulse_f2g |= (1 << io_out[0])

    f.write(f"int stream_pulse_g2f = {hex(stream_pulse_g2f)};\n")
    f.write(f"int stream_pulse_f2g = {hex(stream_pulse_f2g)};\n\n")

    for idx, output_name in enumerate(outputs):
        output_name_str = output_name.replace("hw_", "")
        output_name_str = output_name_str.replace(".raw", "")
        f.write(f"int {output_name_str}_banks = {len(output_place_list[idx])};\n")
        f.write(f"int {output_name_str}_bank_array[{len(output_place_list[idx])}] = {{\n")
        output_place = ", ".join([str(elem) for elem in output_place_list[idx]])
        f.write(output_place)
        f.write(f"\n}};\n")

    f.write("static int check_gold_data()\n")
    f.write("{\n")
    f.write("int err = 0;\n")
    for idx, output_name in enumerate(outputs):
        output_name_str = output_name.replace("hw_", "")
        output_name_str = output_name_str.replace(".raw", "")
        f.write(f"for (int b = 0; b < {output_name_str}_banks; b++){{\n")
        f.write(f"    int bank = {output_name_str}_bank_array[b];\n")
        f.write(f"    uint16_t * read_base = AHASOC_CGRA_DATA_BASE + 0x20000 + bank*0x40000;\n")
        f.write(f"    for (int i = 0; i < app_{output_name_str}_data_size/{output_name_str}_banks; i++) {{\n")
        f.write(f"        if ((uint16_t)(read_base[i]) != (uint16_t) app_{output_name_str}_data[i*{output_name_str}_banks+b]) {{\n")
        f.write(f"        err++;\n")
        f.write(f"        trace_printf(\"index %d\\n\", i);\n")
        f.write(f"        trace_printf(\"output_data %lx\\n\", read_base[i]);\n")
        f.write(f"        trace_printf(\"gold_data %lx\\n\", app_{output_name_str}_data[i*{output_name_str}_banks+b]);\n")
        f.write(f"        }}\n")
        f.write(f"        read_base[i] = 0xfefe;\n")
        f.write(f"    }}\n")
        f.write(f"}}\n")
    f.write("return err;\n")
    f.write("}\n\n")


if __name__ == '__main__':
    unrolling(inputs, outputs, input_order, output_order, app_name)

