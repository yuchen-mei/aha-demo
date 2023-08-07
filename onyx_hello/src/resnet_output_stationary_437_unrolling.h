#define AHASOC_CGRA_DATA_BASE    (0x20400000UL)  /*!< (CGRA DATA ) Base Address */
int input_host_stencil_unroll = 8;
int input_host_stencil_unroll_array[8] = {
1, 15, 3, 5, 7, 9, 11, 13
};
int kernel_host_stencil_unroll = 8;
int kernel_host_stencil_unroll_array[8] = {
0, 6, 8, 10, 12, 14, 2, 4
};
static void move_input_data()
{
trace_printf("moving inputs\n");
for (int i = 0; i < input_host_stencil_unroll; i++) {
  trace_printf("on i %d of input_hoststencil %d \n", i, input_host_stencil_unroll);
  write_glb_memory(0x40000 * (input_host_stencil_unroll_array[i]), (uint16_t * ) app_input_host_stencil_data, app_input_host_stencil_data_size / input_host_stencil_unroll, i, input_host_stencil_unroll);
}
trace_printf("moving weights\n");
for (int i = 0; i < kernel_host_stencil_unroll; i++) {
  write_glb_memory(0x40000 * (kernel_host_stencil_unroll_array[i]), (uint16_t * ) app_kernel_host_stencil_data, app_kernel_host_stencil_data_size / kernel_host_stencil_unroll, i, kernel_host_stencil_unroll);
}
}

static int stream_pulse()
{
int stream_pulse_val = 0;
for (int i = 0; i < 16; i++) {
  stream_pulse_val = (stream_pulse_val << 1) | 1;
}
stream_pulse_val = stream_pulse_val | (stream_pulse_val << 16);
return stream_pulse_val;
}

int output_banks = 8;
int output_bank_array[8] = {
1, 3, 5, 7, 9, 11, 13, 15
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

