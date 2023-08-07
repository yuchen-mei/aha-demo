#include "glb.h"
int output_mask = 0b111;
int tensor_B_mode_0_unroll = 1;
int tensor_B_mode_0_unroll_array[1] = {0};

int tensor_C_mode_0_unroll = 1;
int tensor_C_mode_0_unroll_array[1] = {1};

int tensor_B_mode_1_unroll = 1;
int tensor_B_mode_1_unroll_array[1] = {2};

int tensor_C_mode_1_unroll = 1;
int tensor_C_mode_1_unroll_array[1] = {3};

int tensor_B_mode_vals_unroll = 1;
int tensor_B_mode_vals_unroll_array[1] = {4};

int tensor_C_mode_vals_unroll = 1;
int tensor_C_mode_vals_unroll_array[1] = {5};


int tensor_B_mode_0_extents[44] = {36, 36, 36, 36, 36, 36, 36, 36, 36, 16, 16, 16, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 16, 16, 16, 16, 16, 16, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 6, 6};

int tensor_C_mode_0_extents[44] = {16, 36, 36, 36, 36, 36, 20, 16, 36, 20, 16, 36, 16, 36, 36, 36, 36, 36, 16, 36, 36, 36, 36, 36, 16, 36, 36, 36, 36, 36, 16, 36, 36, 36, 36, 36, 16, 36, 36, 36, 36, 36, 20, 16};

int tensor_B_mode_1_extents[44] = {153, 153, 153, 153, 153, 153, 81, 81, 81, 39, 39, 39, 151, 151, 151, 151, 151, 151, 157, 157, 157, 157, 157, 157, 39, 39, 39, 39, 39, 39, 111, 111, 111, 111, 111, 111, 163, 163, 163, 163, 163, 163, 7, 7};

int tensor_C_mode_1_extents[44] = {51, 163, 143, 107, 151, 153, 35, 27, 85, 35, 27, 85, 51, 163, 143, 107, 151, 153, 51, 163, 143, 107, 151, 153, 51, 163, 143, 107, 151, 153, 51, 163, 143, 107, 151, 153, 51, 163, 143, 107, 151, 153, 35, 27};

int tensor_B_mode_vals_extents[44] = {119, 119, 119, 119, 119, 119, 47, 47, 47, 25, 25, 25, 117, 117, 117, 117, 117, 117, 123, 123, 123, 123, 123, 123, 25, 25, 25, 25, 25, 25, 77, 77, 77, 77, 77, 77, 129, 129, 129, 129, 129, 129, 3, 3};

int tensor_C_mode_vals_extents[44] = {37, 129, 109, 73, 117, 119, 17, 13, 51, 17, 13, 51, 37, 129, 109, 73, 117, 119, 37, 129, 109, 73, 117, 119, 37, 129, 109, 73, 117, 119, 37, 129, 109, 73, 117, 119, 37, 129, 109, 73, 117, 119, 17, 13};

static void move_input_data(){
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


static int stream_pulse(){
int stream_pulse_val = 0;
for (int i = 0; i < 6; i++) {
  stream_pulse_val = (stream_pulse_val << 1) | 1;
}
stream_pulse_val = stream_pulse_val | (stream_pulse_val << 16);
return stream_pulse_val;
}

static void update_glb_pointer_start_addr(int k){
for (int i = 0; i < tensor_B_mode_0_unroll; i++) {
  int sum = 0;
  if (k == 0) {
    sum = tensor_B_mode_0_extents[k]*2;
  } else {
    sum = tensor_B_mode_0_extents[k]*2 + tensor_B_mode_0_extents[k-1]*2;
    tensor_B_mode_0_extents[k] = sum/2;
  }
HAL_Cgra_Glb_WriteReg(0x100 * (tensor_B_mode_0_unroll_array[i]) + GLB_LD_DMA_HEADER_0_START_ADDR_R, 0x40000 * (tensor_B_mode_0_unroll_array[i]) + sum);
}

for (int i = 0; i < tensor_C_mode_1_unroll; i++) {
  int sum = 0;
  if (k == 0) {
    sum = tensor_C_mode_1_extents[k]*2;
  } else {
    sum = tensor_C_mode_1_extents[k]*2 + tensor_C_mode_1_extents[k-1]*2;
    tensor_C_mode_1_extents[k] = sum/2;
  }
HAL_Cgra_Glb_WriteReg(0x100 * (tensor_C_mode_1_unroll_array[i]) + GLB_LD_DMA_HEADER_0_START_ADDR_R, 0x40000 * (tensor_C_mode_1_unroll_array[i]) + sum);
}

for (int i = 0; i < tensor_B_mode_1_unroll; i++) {
  int sum = 0;
  if (k == 0) {
    sum = tensor_B_mode_1_extents[k]*2;
  } else {
    sum = tensor_B_mode_1_extents[k]*2 + tensor_B_mode_1_extents[k-1]*2;
    tensor_B_mode_1_extents[k] = sum/2;
  }
HAL_Cgra_Glb_WriteReg(0x100 * (tensor_B_mode_1_unroll_array[i]) + GLB_LD_DMA_HEADER_0_START_ADDR_R, 0x40000 * (tensor_B_mode_1_unroll_array[i]) + sum);
}

for (int i = 0; i < tensor_C_mode_0_unroll; i++) {
  int sum = 0;
  if (k == 0) {
    sum = tensor_C_mode_0_extents[k]*2;
  } else {
    sum = tensor_C_mode_0_extents[k]*2 + tensor_C_mode_0_extents[k-1]*2;
    tensor_C_mode_0_extents[k] = sum/2;
  }
HAL_Cgra_Glb_WriteReg(0x100 * (tensor_C_mode_0_unroll_array[i]) + GLB_LD_DMA_HEADER_0_START_ADDR_R, 0x40000 * (tensor_C_mode_0_unroll_array[i]) + sum);
}

for (int i = 0; i < tensor_B_mode_vals_unroll; i++) {
  int sum = 0;
  if (k == 0) {
    sum = tensor_B_mode_vals_extents[k]*2;
  } else {
    sum = tensor_B_mode_vals_extents[k]*2 + tensor_B_mode_vals_extents[k-1]*2;
    tensor_B_mode_vals_extents[k] = sum/2;
  }
HAL_Cgra_Glb_WriteReg(0x100 * (tensor_B_mode_vals_unroll_array[i]) + GLB_LD_DMA_HEADER_0_START_ADDR_R, 0x40000 * (tensor_B_mode_vals_unroll_array[i]) + sum);
}

for (int i = 0; i < tensor_C_mode_vals_unroll; i++) {
  int sum = 0;
  if (k == 0) {
    sum = tensor_C_mode_vals_extents[k]*2;
  } else {
    sum = tensor_C_mode_vals_extents[k]*2 + tensor_C_mode_vals_extents[k-1]*2;
    tensor_C_mode_vals_extents[k] = sum/2;
  }
HAL_Cgra_Glb_WriteReg(0x100 * (tensor_C_mode_vals_unroll_array[i]) + GLB_LD_DMA_HEADER_0_START_ADDR_R, 0x40000 * (tensor_C_mode_vals_unroll_array[i]) + sum);
}
}


static void update_glb_pointer_extent(int k){
for (int i = 0; i < tensor_B_mode_0_unroll; i++) {
  HAL_Cgra_Glb_WriteReg(0x100 * (tensor_B_mode_0_unroll_array[i]) + GLB_LD_DMA_HEADER_0_RANGE_0_R, tensor_B_mode_0_extents[k]-2);
}

for (int i = 0; i < tensor_C_mode_1_unroll; i++) {
  HAL_Cgra_Glb_WriteReg(0x100 * (tensor_C_mode_1_unroll_array[i]) + GLB_LD_DMA_HEADER_0_RANGE_0_R, tensor_C_mode_1_extents[k]-2);
}

for (int i = 0; i < tensor_B_mode_1_unroll; i++) {
  HAL_Cgra_Glb_WriteReg(0x100 * (tensor_B_mode_1_unroll_array[i]) + GLB_LD_DMA_HEADER_0_RANGE_0_R, tensor_B_mode_1_extents[k]-2);
}

for (int i = 0; i < tensor_C_mode_0_unroll; i++) {
  HAL_Cgra_Glb_WriteReg(0x100 * (tensor_C_mode_0_unroll_array[i]) + GLB_LD_DMA_HEADER_0_RANGE_0_R, tensor_C_mode_0_extents[k]-2);
}

for (int i = 0; i < tensor_B_mode_vals_unroll; i++) {
  HAL_Cgra_Glb_WriteReg(0x100 * (tensor_B_mode_vals_unroll_array[i]) + GLB_LD_DMA_HEADER_0_RANGE_0_R, tensor_B_mode_vals_extents[k]-2);
}

for (int i = 0; i < tensor_C_mode_vals_unroll; i++) {
  HAL_Cgra_Glb_WriteReg(0x100 * (tensor_C_mode_vals_unroll_array[i]) + GLB_LD_DMA_HEADER_0_RANGE_0_R, tensor_C_mode_vals_extents[k]-2);
}
}


