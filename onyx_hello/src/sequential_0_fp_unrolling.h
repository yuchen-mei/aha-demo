#define AHASOC_CGRA_DATA_BASE    (0x20400000UL)  /*!< (CGRA DATA ) Base Address */
int bias_host_stencil_unroll = 1;
int bias_host_stencil_unroll_array[1] = {
8
};
int input_host_stencil_unroll = 4;
int input_host_stencil_unroll_array[4] = {
0, 1, 2, 3
};
int kernel_host_stencil_unroll = 4;
int kernel_host_stencil_unroll_array[4] = {
4, 5, 6, 7
};
//static void move_input_data()
//{
//for (int i = 0; i < bias_host_stencil_unroll; i++) {
//  write_glb_memory(0x40000 * (bias_host_stencil_unroll_array[i]), (uint16_t * ) app_bias_host_stencil_data, app_bias_host_stencil_data_size / bias_host_stencil_unroll, i, bias_host_stencil_unroll);
//}
//for (int i = 0; i < input_host_stencil_unroll; i++) {
//  write_glb_memory(0x40000 * (input_host_stencil_unroll_array[i]), (uint16_t * ) app_input_host_stencil_data, app_input_host_stencil_data_size / input_host_stencil_unroll, i, input_host_stencil_unroll);
//}
//for (int i = 0; i < kernel_host_stencil_unroll; i++) {
//  write_glb_memory(0x40000 * (kernel_host_stencil_unroll_array[i]), (uint16_t * ) app_kernel_host_stencil_data, app_kernel_host_stencil_data_size / kernel_host_stencil_unroll, i, kernel_host_stencil_unroll);
//}
//}


int output_banks = 4;
int output_bank_array[4] = {
0, 1, 2, 3
};
static int check_gold_data()
{
int err = 0;
for (int b = 0; b < output_banks; b++){
    int bank = output_bank_array[b];
    uint16_t * read_base = AHASOC_CGRA_DATA_BASE + 0x20000 + bank*0x40000;
    for (int i = 0; i < app_output_data_size/output_banks; i++) {
        if ((uint16_t)(read_base[i]) != (uint16_t) app_output_data[i*output_banks+b]) {
        err++;
        trace_printf("index %d\n", i);
        trace_printf("output_data %lx\n", read_base[i]);
        trace_printf("gold_data %lx\n", app_output_data[i*output_banks+b]);
        }
        read_base[i] = 0xfefe;
    }
}
return err;
}

