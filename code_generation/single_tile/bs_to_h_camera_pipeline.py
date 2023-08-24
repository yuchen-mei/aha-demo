# script to convert bitstream to h file

import sys

bs_file_name = "camera_pipeline_2x2.bs"

bs_lines = []
bs_file_str = "camera_pipeline_2x2"

with open(bs_file_name) as bs_file:
    for bs_line in bs_file:
        bs_lines.append(bs_line)

f = open(bs_file_str+"_script.h", "w")
# defines
f.write("#ifndef BITSTREAM_H\n")
f.write("#define BITSTREAM_H\n\n")
f.write("int app_size = " + str(len(bs_lines)) + ";\n\n")

# addr array
f.write("const uint64_t app_addrs_script[] = {\n")
for line in bs_lines:
    strings = line.split()
    f.write("  0x" + strings[0] + strings[1] + ",\n")
f.write("};\n\n")


# defines
f.write("#endif  // BITSTREAM_H\n")


