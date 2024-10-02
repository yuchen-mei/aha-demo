import itertools

def convert_image_unroll(input_data, output_data, input_order, data_file_str):

    def process_file(file, unroll_factor):
        with open(file, "rb") as f:
            raw = f.read()
        raw = [hex(c) for c in raw]

        # Split data for interleaving
        raw1 = raw[0::2]
        raw2 = raw[1::2]
        raw_image0 = []

        for (raw_i, raw_j) in itertools.zip_longest(raw1, raw2):
            raw_j = raw_j[2:]
            if(len(raw_j) == 1):
                raw_j = '0'+ raw_j
            raw_final = raw_i + raw_j
            raw_image0.append(raw_final)

        # Interleave data according to unroll factor
        interleaved_data = [[] for _ in range(unroll_factor)]
        for idx, value in enumerate(raw_image0):
            interleaved_data[idx % unroll_factor].append(value)
        
        interleaved_sizes = [len(data) for data in interleaved_data]
        interleaved_data = [', '.join(data) for data in interleaved_data]

        return interleaved_data, interleaved_sizes

    # Process input files
    input_data_processed = [process_file(file, len(order)) for file, order in zip(input_data, input_order)]

    # Process output files
    output_data_processed = [process_file(file, 1) for file in output_data]

    with open(data_file_str+"_input_script.h", "w") as f:
        # defines
        f.write("#ifndef DATA_H\n")
        f.write("#define DATA_H\n\n")

        for file, order, (data_list, size_list) in zip(input_data, input_order, input_data_processed):
            file_str = file.replace("hw_", "").replace(".raw", "")
            for i in range(len(order)):
                section_name = f".app_{file_str}_data_{i}"
                f.write(f"const uint16_t app_{file_str}_data_{i}[] __attribute__((section(\"{section_name}\"))) = {{ \n")
                f.write(data_list[i])
                f.write("\n};\n")
                f.write(f"const unsigned int app_{file_str}_data_{i}_size =  {size_list[i]};\n")

        for file, (data_list, size_list) in zip(output_data, output_data_processed):
            file_str = file.replace("hw_", "").replace(".raw", "")
            section_name = f".app_{file_str}_data"
            f.write(f"const uint16_t app_{file_str}_data[] __attribute__((section(\"{section_name}\"))) = {{ \n")
            f.write(data_list[0])
            f.write("\n};\n")
            f.write(f"const unsigned int app_{file_str}_data_size =  {size_list[0]};\n")

        # defines
        f.write("#endif // DATA_H\n\n")

if __name__ == '__main__':
    convert_image_unroll(['bias_host_stencil.raw', 'input_host_stencil.raw', 'kernel_host_stencil.raw'], 
                         ['hw_output.raw'], 
                         [[8], [0, 1, 2, 3], [4, 5, 6, 7]], 
                         "sequential_0_fp")
