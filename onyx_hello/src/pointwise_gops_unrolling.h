#define AHASOC_CGRA_DATA_BASE    (0x20400000UL)  /*!< (CGRA DATA ) Base Address */
int input_stencil_unroll = 1;
int input_stencil_unroll_array[1] = {
0
};
static void move_input_data()
{
for (int i = 0; i < input_stencil_unroll; i++) {
  write_glb_memory(0x40000 * (input_stencil_unroll_array[i]), (uint16_t * ) app_input_stencil_data, app_input_stencil_data_size / input_stencil_unroll, i, input_stencil_unroll);
}
}

int stream_pulse_g2f = 0x1;
int stream_pulse_f2g = 0x1;


int output_banks = 1;
int output_bank_array[1] = {
0
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

