#pragma once
#include "hw_classes.h"
#include "clockwork_standard_compute_units.h"


//store is: bias_glb.stencil(bias_glb_s0_w_w) = bias_host.stencil(bias_glb_s0_w_w)
hw_uint<16> hcompute_bias_glb_stencil(hw_uint<16>& bias_host_stencil) {
  bfloat16_t _bias_host_stencil_1 = bfloat16_t::make_from_bits(bias_host_stencil.extract<0, 15>());

  return _bias_host_stencil_1;
}

//store is: input_glb.stencil(0, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(0, input_glb_s0_x, input_glb_s0_y)
hw_uint<16> hcompute_input_glb_stencil(hw_uint<16>& input_host_stencil) {
  bfloat16_t _input_host_stencil_1 = bfloat16_t::make_from_bits(input_host_stencil.extract<0, 15>());

  return _input_host_stencil_1;
}

//store is: input_glb.stencil(1, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(1, input_glb_s0_x, input_glb_s0_y)
hw_uint<16> hcompute_input_glb_stencil_1(hw_uint<16>& input_host_stencil) {
  bfloat16_t _input_host_stencil_2 = bfloat16_t::make_from_bits(input_host_stencil.extract<0, 15>());

  return _input_host_stencil_2;
}

//store is: input_glb.stencil(2, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(2, input_glb_s0_x, input_glb_s0_y)
hw_uint<16> hcompute_input_glb_stencil_2(hw_uint<16>& input_host_stencil) {
  bfloat16_t _input_host_stencil_3 = bfloat16_t::make_from_bits(input_host_stencil.extract<0, 15>());

  return _input_host_stencil_3;
}

//store is: input_glb.stencil(3, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(3, input_glb_s0_x, input_glb_s0_y)
hw_uint<16> hcompute_input_glb_stencil_3(hw_uint<16>& input_host_stencil) {
  bfloat16_t _input_host_stencil_4 = bfloat16_t::make_from_bits(input_host_stencil.extract<0, 15>());

  return _input_host_stencil_4;
}

//store is: kernel_glb.stencil((kernel_glb_s0_w_w*4), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil((kernel_glb_s0_w_w*4), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
hw_uint<16> hcompute_kernel_glb_stencil(hw_uint<16>& kernel_host_stencil) {
  bfloat16_t _kernel_host_stencil_1 = bfloat16_t::make_from_bits(kernel_host_stencil.extract<0, 15>());

  return _kernel_host_stencil_1;
}

//store is: kernel_glb.stencil(((kernel_glb_s0_w_w*4) + 1), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil(((kernel_glb_s0_w_w*4) + 1), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
hw_uint<16> hcompute_kernel_glb_stencil_1(hw_uint<16>& kernel_host_stencil) {
  bfloat16_t _kernel_host_stencil_2 = bfloat16_t::make_from_bits(kernel_host_stencil.extract<0, 15>());

  return _kernel_host_stencil_2;
}

//store is: kernel_glb.stencil(((kernel_glb_s0_w_w*4) + 2), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil(((kernel_glb_s0_w_w*4) + 2), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
hw_uint<16> hcompute_kernel_glb_stencil_2(hw_uint<16>& kernel_host_stencil) {
  bfloat16_t _kernel_host_stencil_3 = bfloat16_t::make_from_bits(kernel_host_stencil.extract<0, 15>());

  return _kernel_host_stencil_3;
}

//store is: kernel_glb.stencil(((kernel_glb_s0_w_w*4) + 3), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil(((kernel_glb_s0_w_w*4) + 3), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
hw_uint<16> hcompute_kernel_glb_stencil_3(hw_uint<16>& kernel_host_stencil) {
  bfloat16_t _kernel_host_stencil_4 = bfloat16_t::make_from_bits(kernel_host_stencil.extract<0, 15>());

  return _kernel_host_stencil_4;
}

//store is: bias_cgra.stencil(bias_cgra_s0_w_w_cgra_w_cgra, bias_cgra_s0_x, 0) = bias_glb.stencil(bias_cgra_s0_w_w_cgra_w_cgra)
hw_uint<16> hcompute_bias_cgra_stencil(hw_uint<16>& bias_glb_stencil) {
  bfloat16_t _bias_glb_stencil_1 = bfloat16_t::make_from_bits(bias_glb_stencil.extract<0, 15>());

  return _bias_glb_stencil_1;
}

//store is: output_cgra.stencil(0, output_cgra_s0_x, 0) = bias_cgra.stencil(0, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_1 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_1;
}

//store is: output_cgra.stencil(1, output_cgra_s0_x, 0) = bias_cgra.stencil(1, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_1(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_2 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_2;
}

//store is: output_cgra.stencil(2, output_cgra_s0_x, 0) = bias_cgra.stencil(2, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_2(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_3 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_3;
}

//store is: output_cgra.stencil(3, output_cgra_s0_x, 0) = bias_cgra.stencil(3, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_3(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_4 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_4;
}

//store is: output_cgra.stencil(4, output_cgra_s0_x, 0) = bias_cgra.stencil(4, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_4(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_5 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_5;
}

//store is: output_cgra.stencil(5, output_cgra_s0_x, 0) = bias_cgra.stencil(5, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_5(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_6 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_6;
}

//store is: output_cgra.stencil(6, output_cgra_s0_x, 0) = bias_cgra.stencil(6, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_6(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_7 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_7;
}

//store is: output_cgra.stencil(7, output_cgra_s0_x, 0) = bias_cgra.stencil(7, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_7(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_8 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_8;
}

//store is: output_cgra.stencil(8, output_cgra_s0_x, 0) = bias_cgra.stencil(8, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_8(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_9 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_9;
}

//store is: output_cgra.stencil(9, output_cgra_s0_x, 0) = bias_cgra.stencil(9, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_9(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_10 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_10;
}

//store is: output_cgra.stencil(10, output_cgra_s0_x, 0) = bias_cgra.stencil(10, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_10(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_11 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_11;
}

//store is: output_cgra.stencil(11, output_cgra_s0_x, 0) = bias_cgra.stencil(11, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_11(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_12 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_12;
}

//store is: output_cgra.stencil(12, output_cgra_s0_x, 0) = bias_cgra.stencil(12, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_12(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_13 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_13;
}

//store is: output_cgra.stencil(13, output_cgra_s0_x, 0) = bias_cgra.stencil(13, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_13(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_14 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_14;
}

//store is: output_cgra.stencil(14, output_cgra_s0_x, 0) = bias_cgra.stencil(14, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_14(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_15 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_15;
}

//store is: output_cgra.stencil(15, output_cgra_s0_x, 0) = bias_cgra.stencil(15, output_cgra_s0_x, 0)
hw_uint<16> hcompute_output_cgra_stencil_15(hw_uint<16>& bias_cgra_stencil) {
  bfloat16_t _bias_cgra_stencil_16 = bfloat16_t::make_from_bits(bias_cgra_stencil.extract<0, 15>());

  return _bias_cgra_stencil_16;
}

//store is: input_cgra.stencil(0, input_cgra_s0_x, (((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y) - (((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2))) = input_glb.stencil(0, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
hw_uint<16> hcompute_input_cgra_stencil(hw_uint<16>& input_glb_stencil) {
  bfloat16_t _input_glb_stencil_1 = bfloat16_t::make_from_bits(input_glb_stencil.extract<0, 15>());

  return _input_glb_stencil_1;
}

//store is: input_cgra.stencil(1, input_cgra_s0_x, (((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y) - (((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2))) = input_glb.stencil(1, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
hw_uint<16> hcompute_input_cgra_stencil_1(hw_uint<16>& input_glb_stencil) {
  bfloat16_t _input_glb_stencil_2 = bfloat16_t::make_from_bits(input_glb_stencil.extract<0, 15>());

  return _input_glb_stencil_2;
}

//store is: input_cgra.stencil(2, input_cgra_s0_x, (((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y) - (((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2))) = input_glb.stencil(2, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
hw_uint<16> hcompute_input_cgra_stencil_2(hw_uint<16>& input_glb_stencil) {
  bfloat16_t _input_glb_stencil_3 = bfloat16_t::make_from_bits(input_glb_stencil.extract<0, 15>());

  return _input_glb_stencil_3;
}

//store is: input_cgra.stencil(3, input_cgra_s0_x, (((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y) - (((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2))) = input_glb.stencil(3, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
hw_uint<16> hcompute_input_cgra_stencil_3(hw_uint<16>& input_glb_stencil) {
  bfloat16_t _input_glb_stencil_4 = bfloat16_t::make_from_bits(input_glb_stencil.extract<0, 15>());

  return _input_glb_stencil_4;
}

//store is: kernel_cgra.stencil((kernel_cgra_s0_w_w_cgra_w_cgra*4), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil((kernel_cgra_s0_w_w_cgra_w_cgra*4), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
hw_uint<16> hcompute_kernel_cgra_stencil(hw_uint<16>& kernel_glb_stencil) {
  bfloat16_t _kernel_glb_stencil_1 = bfloat16_t::make_from_bits(kernel_glb_stencil.extract<0, 15>());

  return _kernel_glb_stencil_1;
}

//store is: kernel_cgra.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 1), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 1), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
hw_uint<16> hcompute_kernel_cgra_stencil_1(hw_uint<16>& kernel_glb_stencil) {
  bfloat16_t _kernel_glb_stencil_2 = bfloat16_t::make_from_bits(kernel_glb_stencil.extract<0, 15>());

  return _kernel_glb_stencil_2;
}

//store is: kernel_cgra.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 2), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 2), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
hw_uint<16> hcompute_kernel_cgra_stencil_2(hw_uint<16>& kernel_glb_stencil) {
  bfloat16_t _kernel_glb_stencil_3 = bfloat16_t::make_from_bits(kernel_glb_stencil.extract<0, 15>());

  return _kernel_glb_stencil_3;
}

//store is: kernel_cgra.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 3), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 3), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
hw_uint<16> hcompute_kernel_cgra_stencil_3(hw_uint<16>& kernel_glb_stencil) {
  bfloat16_t _kernel_glb_stencil_4 = bfloat16_t::make_from_bits(kernel_glb_stencil.extract<0, 15>());

  return _kernel_glb_stencil_4;
}

//store is: output_cgra.stencil(0, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(0, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(0, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(0, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(0, output_cgra_s1_x, 0) + (kernel_cgra.stencil(0, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_16(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_1 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_2 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_3 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_4 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_1 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_2 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_3 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_4 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_1 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _864 = _kernel_cgra_stencil_1 * _input_cgra_stencil_1;
  bfloat16_t _865 = _kernel_cgra_stencil_2 * _input_cgra_stencil_2;
  bfloat16_t _866 = _kernel_cgra_stencil_3 * _input_cgra_stencil_3;
  bfloat16_t _867 = _kernel_cgra_stencil_4 * _input_cgra_stencil_4;
  bfloat16_t _868 = _output_cgra_stencil_1 + _867;
  bfloat16_t _869 = _866 + _868;
  bfloat16_t _870 = _865 + _869;
  bfloat16_t _871 = _864 + _870;
  return _871;
}

//store is: output_cgra.stencil(1, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(1, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(1, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(1, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(1, output_cgra_s1_x, 0) + (kernel_cgra.stencil(1, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_17(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_5 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_6 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_7 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_8 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_5 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_6 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_7 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_8 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_2 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _899 = _kernel_cgra_stencil_5 * _input_cgra_stencil_5;
  bfloat16_t _900 = _kernel_cgra_stencil_6 * _input_cgra_stencil_6;
  bfloat16_t _901 = _kernel_cgra_stencil_7 * _input_cgra_stencil_7;
  bfloat16_t _902 = _kernel_cgra_stencil_8 * _input_cgra_stencil_8;
  bfloat16_t _903 = _output_cgra_stencil_2 + _902;
  bfloat16_t _904 = _901 + _903;
  bfloat16_t _905 = _900 + _904;
  bfloat16_t _906 = _899 + _905;
  return _906;
}

//store is: output_cgra.stencil(2, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(2, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(2, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(2, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(2, output_cgra_s1_x, 0) + (kernel_cgra.stencil(2, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_18(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_10 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_11 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_12 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_9 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_10 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_11 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_12 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_9 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_3 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _934 = _kernel_cgra_stencil_9 * _input_cgra_stencil_9;
  bfloat16_t _935 = _kernel_cgra_stencil_10 * _input_cgra_stencil_10;
  bfloat16_t _936 = _kernel_cgra_stencil_11 * _input_cgra_stencil_11;
  bfloat16_t _937 = _kernel_cgra_stencil_12 * _input_cgra_stencil_12;
  bfloat16_t _938 = _output_cgra_stencil_3 + _937;
  bfloat16_t _939 = _936 + _938;
  bfloat16_t _940 = _935 + _939;
  bfloat16_t _941 = _934 + _940;
  return _941;
}

//store is: output_cgra.stencil(3, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(3, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(3, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(3, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(3, output_cgra_s1_x, 0) + (kernel_cgra.stencil(3, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_19(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_13 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_14 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_15 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_16 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_13 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_14 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_15 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_16 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_4 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _969 = _kernel_cgra_stencil_13 * _input_cgra_stencil_13;
  bfloat16_t _970 = _kernel_cgra_stencil_14 * _input_cgra_stencil_14;
  bfloat16_t _971 = _kernel_cgra_stencil_15 * _input_cgra_stencil_15;
  bfloat16_t _972 = _kernel_cgra_stencil_16 * _input_cgra_stencil_16;
  bfloat16_t _973 = _output_cgra_stencil_4 + _972;
  bfloat16_t _974 = _971 + _973;
  bfloat16_t _975 = _970 + _974;
  bfloat16_t _976 = _969 + _975;
  return _976;
}

//store is: output_cgra.stencil(4, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(4, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(4, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(4, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(4, output_cgra_s1_x, 0) + (kernel_cgra.stencil(4, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_20(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_17 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_18 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_19 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_20 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_17 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_18 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_19 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_20 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_5 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1004 = _kernel_cgra_stencil_17 * _input_cgra_stencil_17;
  bfloat16_t _1005 = _kernel_cgra_stencil_18 * _input_cgra_stencil_18;
  bfloat16_t _1006 = _kernel_cgra_stencil_19 * _input_cgra_stencil_19;
  bfloat16_t _1007 = _kernel_cgra_stencil_20 * _input_cgra_stencil_20;
  bfloat16_t _1008 = _output_cgra_stencil_5 + _1007;
  bfloat16_t _1009 = _1006 + _1008;
  bfloat16_t _1010 = _1005 + _1009;
  bfloat16_t _1011 = _1004 + _1010;
  return _1011;
}

//store is: output_cgra.stencil(5, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(5, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(5, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(5, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(5, output_cgra_s1_x, 0) + (kernel_cgra.stencil(5, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_21(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_21 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_22 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_23 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_24 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_21 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_22 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_23 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_24 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_6 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1039 = _kernel_cgra_stencil_21 * _input_cgra_stencil_21;
  bfloat16_t _1040 = _kernel_cgra_stencil_22 * _input_cgra_stencil_22;
  bfloat16_t _1041 = _kernel_cgra_stencil_23 * _input_cgra_stencil_23;
  bfloat16_t _1042 = _kernel_cgra_stencil_24 * _input_cgra_stencil_24;
  bfloat16_t _1043 = _output_cgra_stencil_6 + _1042;
  bfloat16_t _1044 = _1041 + _1043;
  bfloat16_t _1045 = _1040 + _1044;
  bfloat16_t _1046 = _1039 + _1045;
  return _1046;
}

//store is: output_cgra.stencil(6, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(6, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(6, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(6, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(6, output_cgra_s1_x, 0) + (kernel_cgra.stencil(6, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_22(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_25 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_26 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_27 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_28 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_25 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_26 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_27 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_28 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_7 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1074 = _kernel_cgra_stencil_25 * _input_cgra_stencil_25;
  bfloat16_t _1075 = _kernel_cgra_stencil_26 * _input_cgra_stencil_26;
  bfloat16_t _1076 = _kernel_cgra_stencil_27 * _input_cgra_stencil_27;
  bfloat16_t _1077 = _kernel_cgra_stencil_28 * _input_cgra_stencil_28;
  bfloat16_t _1078 = _output_cgra_stencil_7 + _1077;
  bfloat16_t _1079 = _1076 + _1078;
  bfloat16_t _1080 = _1075 + _1079;
  bfloat16_t _1081 = _1074 + _1080;
  return _1081;
}

//store is: output_cgra.stencil(7, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(7, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(7, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(7, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(7, output_cgra_s1_x, 0) + (kernel_cgra.stencil(7, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_23(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_29 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_30 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_31 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_32 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_29 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_30 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_31 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_32 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_8 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1109 = _kernel_cgra_stencil_29 * _input_cgra_stencil_29;
  bfloat16_t _1110 = _kernel_cgra_stencil_30 * _input_cgra_stencil_30;
  bfloat16_t _1111 = _kernel_cgra_stencil_31 * _input_cgra_stencil_31;
  bfloat16_t _1112 = _kernel_cgra_stencil_32 * _input_cgra_stencil_32;
  bfloat16_t _1113 = _output_cgra_stencil_8 + _1112;
  bfloat16_t _1114 = _1111 + _1113;
  bfloat16_t _1115 = _1110 + _1114;
  bfloat16_t _1116 = _1109 + _1115;
  return _1116;
}

//store is: output_cgra.stencil(8, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(8, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(8, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(8, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(8, output_cgra_s1_x, 0) + (kernel_cgra.stencil(8, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_24(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_33 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_34 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_35 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_36 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_33 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_34 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_35 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_36 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_9 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1144 = _kernel_cgra_stencil_33 * _input_cgra_stencil_33;
  bfloat16_t _1145 = _kernel_cgra_stencil_34 * _input_cgra_stencil_34;
  bfloat16_t _1146 = _kernel_cgra_stencil_35 * _input_cgra_stencil_35;
  bfloat16_t _1147 = _kernel_cgra_stencil_36 * _input_cgra_stencil_36;
  bfloat16_t _1148 = _output_cgra_stencil_9 + _1147;
  bfloat16_t _1149 = _1146 + _1148;
  bfloat16_t _1150 = _1145 + _1149;
  bfloat16_t _1151 = _1144 + _1150;
  return _1151;
}

//store is: output_cgra.stencil(9, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(9, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(9, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(9, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(9, output_cgra_s1_x, 0) + (kernel_cgra.stencil(9, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_25(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_37 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_38 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_39 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_40 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_37 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_38 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_39 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_40 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_10 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1179 = _kernel_cgra_stencil_37 * _input_cgra_stencil_37;
  bfloat16_t _1180 = _kernel_cgra_stencil_38 * _input_cgra_stencil_38;
  bfloat16_t _1181 = _kernel_cgra_stencil_39 * _input_cgra_stencil_39;
  bfloat16_t _1182 = _kernel_cgra_stencil_40 * _input_cgra_stencil_40;
  bfloat16_t _1183 = _output_cgra_stencil_10 + _1182;
  bfloat16_t _1184 = _1181 + _1183;
  bfloat16_t _1185 = _1180 + _1184;
  bfloat16_t _1186 = _1179 + _1185;
  return _1186;
}

//store is: output_cgra.stencil(10, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(10, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(10, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(10, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(10, output_cgra_s1_x, 0) + (kernel_cgra.stencil(10, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_26(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_41 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_42 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_43 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_44 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_41 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_42 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_43 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_44 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_11 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1214 = _kernel_cgra_stencil_41 * _input_cgra_stencil_41;
  bfloat16_t _1215 = _kernel_cgra_stencil_42 * _input_cgra_stencil_42;
  bfloat16_t _1216 = _kernel_cgra_stencil_43 * _input_cgra_stencil_43;
  bfloat16_t _1217 = _kernel_cgra_stencil_44 * _input_cgra_stencil_44;
  bfloat16_t _1218 = _output_cgra_stencil_11 + _1217;
  bfloat16_t _1219 = _1216 + _1218;
  bfloat16_t _1220 = _1215 + _1219;
  bfloat16_t _1221 = _1214 + _1220;
  return _1221;
}

//store is: output_cgra.stencil(11, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(11, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(11, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(11, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(11, output_cgra_s1_x, 0) + (kernel_cgra.stencil(11, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_27(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_45 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_46 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_47 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_48 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_45 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_46 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_47 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_48 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_12 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1249 = _kernel_cgra_stencil_45 * _input_cgra_stencil_45;
  bfloat16_t _1250 = _kernel_cgra_stencil_46 * _input_cgra_stencil_46;
  bfloat16_t _1251 = _kernel_cgra_stencil_47 * _input_cgra_stencil_47;
  bfloat16_t _1252 = _kernel_cgra_stencil_48 * _input_cgra_stencil_48;
  bfloat16_t _1253 = _output_cgra_stencil_12 + _1252;
  bfloat16_t _1254 = _1251 + _1253;
  bfloat16_t _1255 = _1250 + _1254;
  bfloat16_t _1256 = _1249 + _1255;
  return _1256;
}

//store is: output_cgra.stencil(12, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(12, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(12, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(12, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(12, output_cgra_s1_x, 0) + (kernel_cgra.stencil(12, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_28(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_49 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_50 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_51 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_52 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_49 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_50 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_51 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_52 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_13 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1284 = _kernel_cgra_stencil_49 * _input_cgra_stencil_49;
  bfloat16_t _1285 = _kernel_cgra_stencil_50 * _input_cgra_stencil_50;
  bfloat16_t _1286 = _kernel_cgra_stencil_51 * _input_cgra_stencil_51;
  bfloat16_t _1287 = _kernel_cgra_stencil_52 * _input_cgra_stencil_52;
  bfloat16_t _1288 = _output_cgra_stencil_13 + _1287;
  bfloat16_t _1289 = _1286 + _1288;
  bfloat16_t _1290 = _1285 + _1289;
  bfloat16_t _1291 = _1284 + _1290;
  return _1291;
}

//store is: output_cgra.stencil(13, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(13, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(13, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(13, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(13, output_cgra_s1_x, 0) + (kernel_cgra.stencil(13, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_29(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_53 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_54 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_55 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_56 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_53 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_54 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_55 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_56 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_14 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1319 = _kernel_cgra_stencil_53 * _input_cgra_stencil_53;
  bfloat16_t _1320 = _kernel_cgra_stencil_54 * _input_cgra_stencil_54;
  bfloat16_t _1321 = _kernel_cgra_stencil_55 * _input_cgra_stencil_55;
  bfloat16_t _1322 = _kernel_cgra_stencil_56 * _input_cgra_stencil_56;
  bfloat16_t _1323 = _output_cgra_stencil_14 + _1322;
  bfloat16_t _1324 = _1321 + _1323;
  bfloat16_t _1325 = _1320 + _1324;
  bfloat16_t _1326 = _1319 + _1325;
  return _1326;
}

//store is: output_cgra.stencil(14, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(14, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(14, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(14, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(14, output_cgra_s1_x, 0) + (kernel_cgra.stencil(14, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_30(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_57 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_58 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_59 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_60 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_57 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_58 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_59 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_60 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_15 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1354 = _kernel_cgra_stencil_57 * _input_cgra_stencil_57;
  bfloat16_t _1355 = _kernel_cgra_stencil_58 * _input_cgra_stencil_58;
  bfloat16_t _1356 = _kernel_cgra_stencil_59 * _input_cgra_stencil_59;
  bfloat16_t _1357 = _kernel_cgra_stencil_60 * _input_cgra_stencil_60;
  bfloat16_t _1358 = _output_cgra_stencil_15 + _1357;
  bfloat16_t _1359 = _1356 + _1358;
  bfloat16_t _1360 = _1355 + _1359;
  bfloat16_t _1361 = _1354 + _1360;
  return _1361;
}

//store is: output_cgra.stencil(15, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(15, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(15, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(15, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(15, output_cgra_s1_x, 0) + (kernel_cgra.stencil(15, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
hw_uint<16> hcompute_output_cgra_stencil_31(hw_uint<64>& input_cgra_stencil, hw_uint<64>& kernel_cgra_stencil, hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _input_cgra_stencil_61 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<0, 15>());
  bfloat16_t _input_cgra_stencil_62 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<16, 31>());
  bfloat16_t _input_cgra_stencil_63 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<32, 47>());
  bfloat16_t _input_cgra_stencil_64 = bfloat16_t::make_from_bits(input_cgra_stencil.extract<48, 63>());

  bfloat16_t _kernel_cgra_stencil_61 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<0, 15>());
  bfloat16_t _kernel_cgra_stencil_62 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<16, 31>());
  bfloat16_t _kernel_cgra_stencil_63 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<32, 47>());
  bfloat16_t _kernel_cgra_stencil_64 = bfloat16_t::make_from_bits(kernel_cgra_stencil.extract<48, 63>());

  bfloat16_t _output_cgra_stencil_16 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1389 = _kernel_cgra_stencil_61 * _input_cgra_stencil_61;
  bfloat16_t _1390 = _kernel_cgra_stencil_62 * _input_cgra_stencil_62;
  bfloat16_t _1391 = _kernel_cgra_stencil_63 * _input_cgra_stencil_63;
  bfloat16_t _1392 = _kernel_cgra_stencil_64 * _input_cgra_stencil_64;
  bfloat16_t _1393 = _output_cgra_stencil_16 + _1392;
  bfloat16_t _1394 = _1391 + _1393;
  bfloat16_t _1395 = _1390 + _1394;
  bfloat16_t _1396 = _1389 + _1395;
  return _1396;
}

//store is: output_glb.stencil((output_glb_s0_w_w_cgra_w_cgra*4), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil((output_glb_s0_w_w_cgra_w_cgra*4), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
hw_uint<16> hcompute_output_glb_stencil(hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _output_cgra_stencil_17 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1424 = bfloat_from_bits(1086324736 /* 6 */);
  bfloat16_t _1425 = min(_output_cgra_stencil_17, _1424);
  bfloat16_t _1426 = bfloat_from_bits(0 /* 0 */);
  bfloat16_t _1427 = max(_1425, _1426);
  return _1427;
}

//store is: output_glb.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 1), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 1), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
hw_uint<16> hcompute_output_glb_stencil_1(hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _output_cgra_stencil_18 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1442 = bfloat_from_bits(1086324736 /* 6 */);
  bfloat16_t _1443 = min(_output_cgra_stencil_18, _1442);
  bfloat16_t _1444 = bfloat_from_bits(0 /* 0 */);
  bfloat16_t _1445 = max(_1443, _1444);
  return _1445;
}

//store is: output_glb.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 2), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 2), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
hw_uint<16> hcompute_output_glb_stencil_2(hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _output_cgra_stencil_19 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1461 = bfloat_from_bits(1086324736 /* 6 */);
  bfloat16_t _1462 = min(_output_cgra_stencil_19, _1461);
  bfloat16_t _1463 = bfloat_from_bits(0 /* 0 */);
  bfloat16_t _1464 = max(_1462, _1463);
  return _1464;
}

//store is: output_glb.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 3), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 3), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
hw_uint<16> hcompute_output_glb_stencil_3(hw_uint<16>& output_cgra_stencil) {
  bfloat16_t _output_cgra_stencil_20 = bfloat16_t::make_from_bits(output_cgra_stencil.extract<0, 15>());

  bfloat16_t _1480 = bfloat_from_bits(1086324736 /* 6 */);
  bfloat16_t _1481 = min(_output_cgra_stencil_20, _1480);
  bfloat16_t _1482 = bfloat_from_bits(0 /* 0 */);
  bfloat16_t _1483 = max(_1481, _1482);
  return _1483;
}

//store is: hw_output.stencil((hw_output_s0_w_w*4), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil((hw_output_s0_w_w*4), hw_output_s0_x_xi, hw_output_s0_y_yi)
hw_uint<16> hcompute_hw_output_stencil(hw_uint<16>& output_glb_stencil) {
  bfloat16_t _output_glb_stencil_1 = bfloat16_t::make_from_bits(output_glb_stencil.extract<0, 15>());

  return _output_glb_stencil_1;
}

//store is: hw_output.stencil(((hw_output_s0_w_w*4) + 1), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil(((hw_output_s0_w_w*4) + 1), hw_output_s0_x_xi, hw_output_s0_y_yi)
hw_uint<16> hcompute_hw_output_stencil_1(hw_uint<16>& output_glb_stencil) {
  bfloat16_t _output_glb_stencil_2 = bfloat16_t::make_from_bits(output_glb_stencil.extract<0, 15>());

  return _output_glb_stencil_2;
}

//store is: hw_output.stencil(((hw_output_s0_w_w*4) + 2), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil(((hw_output_s0_w_w*4) + 2), hw_output_s0_x_xi, hw_output_s0_y_yi)
hw_uint<16> hcompute_hw_output_stencil_2(hw_uint<16>& output_glb_stencil) {
  bfloat16_t _output_glb_stencil_3 = bfloat16_t::make_from_bits(output_glb_stencil.extract<0, 15>());

  return _output_glb_stencil_3;
}

//store is: hw_output.stencil(((hw_output_s0_w_w*4) + 3), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil(((hw_output_s0_w_w*4) + 3), hw_output_s0_x_xi, hw_output_s0_y_yi)
hw_uint<16> hcompute_hw_output_stencil_3(hw_uint<16>& output_glb_stencil) {
  bfloat16_t _output_glb_stencil_4 = bfloat16_t::make_from_bits(output_glb_stencil.extract<0, 15>());

  return _output_glb_stencil_4;
}

