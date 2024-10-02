#include <fstream>
#include "unoptimized_conv2D_fp.h"

int main() {
  srand(234);
  ofstream fout("regression_result_unoptimized_conv2D_fp.txt");
  HWStream<hw_uint<16 > > bias_host_stencil;
  HWStream<hw_uint<16 > > input_host_stencil_clkwrk_0;
  HWStream<hw_uint<16 > > input_host_stencil_clkwrk_1;
  HWStream<hw_uint<16 > > input_host_stencil_clkwrk_2;
  HWStream<hw_uint<16 > > input_host_stencil_clkwrk_3;
  HWStream<hw_uint<16 > > kernel_host_stencil_clkwrk_4;
  HWStream<hw_uint<16 > > kernel_host_stencil_clkwrk_5;
  HWStream<hw_uint<16 > > kernel_host_stencil_clkwrk_6;
  HWStream<hw_uint<16 > > kernel_host_stencil_clkwrk_7;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_10;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_11;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_8;
  HWStream<hw_uint<16 > > hw_output_stencil_clkwrk_9;


  // Loading input data
  srand(1);
  // cmap    : { op_hcompute_bias_glb_stencil[root = 0, bias_glb_s0_w_w] -> bias_host_stencil[bias_glb_s0_w_w] : 0 <= bias_glb_s0_w_w <= 15 }
  // read map: { bias_host_stencil[i0] -> op_hcompute_bias_glb_stencil[root = 0, bias_glb_s0_w_w = i0] : 0 <= i0 <= 15 }
  // rng     : { op_hcompute_bias_glb_stencil[root = 0, bias_glb_s0_w_w] : 0 <= bias_glb_s0_w_w <= 15 }
  // rng card: { 16 }
  for (int i = 0; i < 16; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    bias_host_stencil.write(value);
  }

  // cmap    : { op_hcompute_input_glb_stencil[root = 0, input_glb_s0_y, input_glb_s0_x] -> input_host_stencil_clkwrk_0[input_glb_s0_y, input_glb_s0_x, 0] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // read map: { input_host_stencil_clkwrk_0[i0, i1, 0] -> op_hcompute_input_glb_stencil[root = 0, input_glb_s0_y = i0, input_glb_s0_x = i1] : 0 <= i0 <= 100 and 0 <= i1 <= 100 }
  // rng     : { op_hcompute_input_glb_stencil[root = 0, input_glb_s0_y, input_glb_s0_x] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // rng card: { 10201 }
  for (int i = 0; i < 10201; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    input_host_stencil_clkwrk_0.write(value);
  }

  // cmap    : { op_hcompute_input_glb_stencil_1[root = 0, input_glb_s0_y, input_glb_s0_x] -> input_host_stencil_clkwrk_1[input_glb_s0_y, input_glb_s0_x, 1] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // read map: { input_host_stencil_clkwrk_1[i0, i1, 1] -> op_hcompute_input_glb_stencil_1[root = 0, input_glb_s0_y = i0, input_glb_s0_x = i1] : 0 <= i0 <= 100 and 0 <= i1 <= 100 }
  // rng     : { op_hcompute_input_glb_stencil_1[root = 0, input_glb_s0_y, input_glb_s0_x] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // rng card: { 10201 }
  for (int i = 0; i < 10201; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    input_host_stencil_clkwrk_1.write(value);
  }

  // cmap    : { op_hcompute_input_glb_stencil_2[root = 0, input_glb_s0_y, input_glb_s0_x] -> input_host_stencil_clkwrk_2[input_glb_s0_y, input_glb_s0_x, 2] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // read map: { input_host_stencil_clkwrk_2[i0, i1, 2] -> op_hcompute_input_glb_stencil_2[root = 0, input_glb_s0_y = i0, input_glb_s0_x = i1] : 0 <= i0 <= 100 and 0 <= i1 <= 100 }
  // rng     : { op_hcompute_input_glb_stencil_2[root = 0, input_glb_s0_y, input_glb_s0_x] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // rng card: { 10201 }
  for (int i = 0; i < 10201; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    input_host_stencil_clkwrk_2.write(value);
  }

  // cmap    : { op_hcompute_input_glb_stencil_3[root = 0, input_glb_s0_y, input_glb_s0_x] -> input_host_stencil_clkwrk_3[input_glb_s0_y, input_glb_s0_x, 3] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // read map: { input_host_stencil_clkwrk_3[i0, i1, 3] -> op_hcompute_input_glb_stencil_3[root = 0, input_glb_s0_y = i0, input_glb_s0_x = i1] : 0 <= i0 <= 100 and 0 <= i1 <= 100 }
  // rng     : { op_hcompute_input_glb_stencil_3[root = 0, input_glb_s0_y, input_glb_s0_x] : 0 <= input_glb_s0_y <= 100 and 0 <= input_glb_s0_x <= 100 }
  // rng card: { 10201 }
  for (int i = 0; i < 10201; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    input_host_stencil_clkwrk_3.write(value);
  }

  // cmap    : { op_hcompute_kernel_glb_stencil[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] -> kernel_host_stencil_clkwrk_4[kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, 4kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // read map: { kernel_host_stencil_clkwrk_4[i0, i1, i2, i3] -> op_hcompute_kernel_glb_stencil[root = 0, kernel_glb_s0_y = i0, kernel_glb_s0_x = i1, kernel_glb_s0_z = i2, kernel_glb_s0_w_w] : 4kernel_glb_s0_w_w = i3 and 0 <= i0 <= 2 and 0 <= i1 <= 2 and 0 <= i2 <= 3 and 0 <= i3 <= 12 }
  // rng     : { op_hcompute_kernel_glb_stencil[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // rng card: { 144 }
  for (int i = 0; i < 144; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    kernel_host_stencil_clkwrk_4.write(value);
  }

  // cmap    : { op_hcompute_kernel_glb_stencil_1[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] -> kernel_host_stencil_clkwrk_5[kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, 1 + 4kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // read map: { kernel_host_stencil_clkwrk_5[i0, i1, i2, i3] -> op_hcompute_kernel_glb_stencil_1[root = 0, kernel_glb_s0_y = i0, kernel_glb_s0_x = i1, kernel_glb_s0_z = i2, kernel_glb_s0_w_w] : 4kernel_glb_s0_w_w = -1 + i3 and 0 <= i0 <= 2 and 0 <= i1 <= 2 and 0 <= i2 <= 3 and 0 < i3 <= 13 }
  // rng     : { op_hcompute_kernel_glb_stencil_1[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // rng card: { 144 }
  for (int i = 0; i < 144; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    kernel_host_stencil_clkwrk_5.write(value);
  }

  // cmap    : { op_hcompute_kernel_glb_stencil_2[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] -> kernel_host_stencil_clkwrk_6[kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, 2 + 4kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // read map: { kernel_host_stencil_clkwrk_6[i0, i1, i2, i3] -> op_hcompute_kernel_glb_stencil_2[root = 0, kernel_glb_s0_y = i0, kernel_glb_s0_x = i1, kernel_glb_s0_z = i2, kernel_glb_s0_w_w] : 4kernel_glb_s0_w_w = -2 + i3 and 0 <= i0 <= 2 and 0 <= i1 <= 2 and 0 <= i2 <= 3 and 2 <= i3 <= 14 }
  // rng     : { op_hcompute_kernel_glb_stencil_2[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // rng card: { 144 }
  for (int i = 0; i < 144; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    kernel_host_stencil_clkwrk_6.write(value);
  }

  // cmap    : { op_hcompute_kernel_glb_stencil_3[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] -> kernel_host_stencil_clkwrk_7[kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, 3 + 4kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // read map: { kernel_host_stencil_clkwrk_7[i0, i1, i2, i3] -> op_hcompute_kernel_glb_stencil_3[root = 0, kernel_glb_s0_y = i0, kernel_glb_s0_x = i1, kernel_glb_s0_z = i2, kernel_glb_s0_w_w] : 4kernel_glb_s0_w_w = -3 + i3 and 0 <= i0 <= 2 and 0 <= i1 <= 2 and 0 <= i2 <= 3 and 3 <= i3 <= 15 }
  // rng     : { op_hcompute_kernel_glb_stencil_3[root = 0, kernel_glb_s0_y, kernel_glb_s0_x, kernel_glb_s0_z, kernel_glb_s0_w_w] : 0 <= kernel_glb_s0_y <= 2 and 0 <= kernel_glb_s0_x <= 2 and 0 <= kernel_glb_s0_z <= 3 and 0 <= kernel_glb_s0_w_w <= 3 }
  // rng card: { 144 }
  for (int i = 0; i < 144; i++) {
    hw_uint<16 > value;
    set_at<0, 16, 16>(value, rand() % 256);
    kernel_host_stencil_clkwrk_7.write(value);
  }

  unoptimized_conv2D_fp(bias_host_stencil, input_host_stencil_clkwrk_0, input_host_stencil_clkwrk_1, input_host_stencil_clkwrk_2, input_host_stencil_clkwrk_3, kernel_host_stencil_clkwrk_4, kernel_host_stencil_clkwrk_5, kernel_host_stencil_clkwrk_6, kernel_host_stencil_clkwrk_7, hw_output_stencil_clkwrk_10, hw_output_stencil_clkwrk_11, hw_output_stencil_clkwrk_8, hw_output_stencil_clkwrk_9);
  for (int i = 0; i < 10000; i++) {
    auto actual = hw_output_stencil_clkwrk_10.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 10000; i++) {
    auto actual = hw_output_stencil_clkwrk_11.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 10000; i++) {
    auto actual = hw_output_stencil_clkwrk_8.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  for (int i = 0; i < 10000; i++) {
    auto actual = hw_output_stencil_clkwrk_9.read();
    hw_uint<16> actual_lane_0 = actual.extract<0, 15>();
    fout << actual_lane_0 << endl;
  }

  assert(bias_host_stencil.is_empty());
  assert(input_host_stencil_clkwrk_0.is_empty());
  assert(input_host_stencil_clkwrk_1.is_empty());
  assert(input_host_stencil_clkwrk_2.is_empty());
  assert(input_host_stencil_clkwrk_3.is_empty());
  assert(kernel_host_stencil_clkwrk_4.is_empty());
  assert(kernel_host_stencil_clkwrk_5.is_empty());
  assert(kernel_host_stencil_clkwrk_6.is_empty());
  assert(kernel_host_stencil_clkwrk_7.is_empty());
  assert(hw_output_stencil_clkwrk_10.is_empty());
  assert(hw_output_stencil_clkwrk_11.is_empty());
  assert(hw_output_stencil_clkwrk_8.is_empty());
  assert(hw_output_stencil_clkwrk_9.is_empty());
  return 0;
}
