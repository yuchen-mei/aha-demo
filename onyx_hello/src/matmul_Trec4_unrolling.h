#define AHASOC_CGRA_DATA_BASE    (0x20400000UL)  /*!< (CGRA DATA ) Base Address */
int tensor_B_mode_0_unroll = 1;
int tensor_B_mode_0_unroll_array[1] = {
0
};
int tensor_C_mode_1_unroll = 1;
int tensor_C_mode_1_unroll_array[1] = {
1
};
int tensor_B_mode_1_unroll = 1;
int tensor_B_mode_1_unroll_array[1] = {
2
};
int tensor_C_mode_0_unroll = 1;
int tensor_C_mode_0_unroll_array[1] = {
3
};
int tensor_B_mode_vals_unroll = 1;
int tensor_B_mode_vals_unroll_array[1] = {
4
};
int tensor_C_mode_vals_unroll = 1;
int tensor_C_mode_vals_unroll_array[1] = {
5
};
static void move_input_data()
{
for (int i = 0; i < tensor_B_mode_0_unroll; i++) {
  write_glb_memory(0x40000 * (tensor_B_mode_0_unroll_array[i]), (uint16_t * ) app_tensor_B_mode_0_data, app_tensor_B_mode_0_data_size / tensor_B_mode_0_unroll, i, tensor_B_mode_0_unroll);
}
for (int i = 0; i < tensor_C_mode_1_unroll; i++) {
  write_glb_memory(0x40000 * (tensor_C_mode_1_unroll_array[i]), (uint16_t * ) app_tensor_C_mode_1_data, app_tensor_C_mode_1_data_size / tensor_C_mode_1_unroll, i, tensor_C_mode_1_unroll);
}
for (int i = 0; i < tensor_B_mode_1_unroll; i++) {
  write_glb_memory(0x40000 * (tensor_B_mode_1_unroll_array[i]), (uint16_t * ) app_tensor_B_mode_1_data, app_tensor_B_mode_1_data_size / tensor_B_mode_1_unroll, i, tensor_B_mode_1_unroll);
}
for (int i = 0; i < tensor_C_mode_0_unroll; i++) {
  write_glb_memory(0x40000 * (tensor_C_mode_0_unroll_array[i]), (uint16_t * ) app_tensor_C_mode_0_data, app_tensor_C_mode_0_data_size / tensor_C_mode_0_unroll, i, tensor_C_mode_0_unroll);
}
for (int i = 0; i < tensor_B_mode_vals_unroll; i++) {
  write_glb_memory(0x40000 * (tensor_B_mode_vals_unroll_array[i]), (uint16_t * ) app_tensor_B_mode_vals_data, app_tensor_B_mode_vals_data_size / tensor_B_mode_vals_unroll, i, tensor_B_mode_vals_unroll);
}
for (int i = 0; i < tensor_C_mode_vals_unroll; i++) {
  write_glb_memory(0x40000 * (tensor_C_mode_vals_unroll_array[i]), (uint16_t * ) app_tensor_C_mode_vals_data, app_tensor_C_mode_vals_data_size / tensor_C_mode_vals_unroll, i, tensor_C_mode_vals_unroll);
}
}

int stream_pulse_g2f = 0x3f;
int stream_pulse_f2g = 0x7;


int tensor_X_mode_0_banks = 1;
int tensor_X_mode_0_bank_array[1] = {
0
};
int tensor_X_mode_1_banks = 1;
int tensor_X_mode_1_bank_array[1] = {
1
};
int tensor_X_mode_vals_banks = 1;
int tensor_X_mode_vals_bank_array[1] = {
2
};
static int check_gold_data()
{
int err = 0;
for (int b = 0; b < tensor_X_mode_0_banks; b++){
    int bank = tensor_X_mode_0_bank_array[b];
    uint16_t * read_base = AHASOC_CGRA_DATA_BASE + 0x20000 + bank*0x40000;
    for (int i = 0; i < app_tensor_X_mode_0_data_size/tensor_X_mode_0_banks; i++) {
        if ((uint16_t)(read_base[i]) != (uint16_t) app_tensor_X_mode_0_data[i*tensor_X_mode_0_banks+b]) {
        err++;
        trace_printf("index %d\n", i);
        trace_printf("output_data %lx\n", read_base[i]);
        trace_printf("gold_data %lx\n", app_tensor_X_mode_0_data[i*tensor_X_mode_0_banks+b]);
        }
        read_base[i] = 0xfefe;
    }
}
for (int b = 0; b < tensor_X_mode_1_banks; b++){
    int bank = tensor_X_mode_1_bank_array[b];
    uint16_t * read_base = AHASOC_CGRA_DATA_BASE + 0x20000 + bank*0x40000;
    for (int i = 0; i < app_tensor_X_mode_1_data_size/tensor_X_mode_1_banks; i++) {
        if ((uint16_t)(read_base[i]) != (uint16_t) app_tensor_X_mode_1_data[i*tensor_X_mode_1_banks+b]) {
        err++;
        trace_printf("index %d\n", i);
        trace_printf("output_data %lx\n", read_base[i]);
        trace_printf("gold_data %lx\n", app_tensor_X_mode_1_data[i*tensor_X_mode_1_banks+b]);
        }
        read_base[i] = 0xfefe;
    }
}
for (int b = 0; b < tensor_X_mode_vals_banks; b++){
    int bank = tensor_X_mode_vals_bank_array[b];
    uint16_t * read_base = AHASOC_CGRA_DATA_BASE + 0x20000 + bank*0x40000;
    for (int i = 0; i < app_tensor_X_mode_vals_data_size/tensor_X_mode_vals_banks; i++) {
        if ((uint16_t)(read_base[i]) != (uint16_t) app_tensor_X_mode_vals_data[i*tensor_X_mode_vals_banks+b]) {
        err++;
        trace_printf("index %d\n", i);
        trace_printf("output_data %lx\n", read_base[i]);
        trace_printf("gold_data %lx\n", app_tensor_X_mode_vals_data[i*tensor_X_mode_vals_banks+b]);
        }
        read_base[i] = 0xfefe;
    }
}
return err;
}

