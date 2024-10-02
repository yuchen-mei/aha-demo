#include "app.h"
#include "ubuffer.h"
#include "codegen.h"
#include "prog.h"

prog conv2D_fp() {
  prog prg;
  prg.compute_unit_file = "conv2D_fp_compute.h";
  prg.name = "conv2D_fp";

// Stencil<uint16_t, 16> &bias_host_stencil = arg_0;
  prg.add_input("bias_host_stencil");
  prg.buffer_port_widths["bias_host_stencil"] = 16;
// Stencil<bfloat16_t, 4, 101, 101> &input_host_stencil = arg_1;
  prg.add_input("input_host_stencil");
  prg.buffer_port_widths["input_host_stencil"] = 16;
// Stencil<bfloat16_t, 16, 4, 3, 3> &kernel_host_stencil = arg_2;
  prg.add_input("kernel_host_stencil");
  prg.buffer_port_widths["kernel_host_stencil"] = 16;
// Stencil<bfloat16_t, 16, 50, 50> &hw_output_stencil = arg_3;
  prg.add_output("hw_output_stencil");
  prg.buffer_port_widths["hw_output_stencil"] = 16;

////producing bias_glb.stencil
  auto bias_glb_s0_w_w = prg.add_loop("bias_glb_s0_w_w", 0, 16);

//store is: bias_glb.stencil(bias_glb_s0_w_w) = bias_host.stencil(bias_glb_s0_w_w)
  auto hcompute_bias_glb_stencil = bias_glb_s0_w_w->add_op("op_hcompute_bias_glb_stencil");
  hcompute_bias_glb_stencil->add_function("hcompute_bias_glb_stencil");
  hcompute_bias_glb_stencil->add_load("bias_host_stencil", "bias_glb_s0_w_w");
  prg.buffer_port_widths["bias_glb_stencil"] = 16;
  hcompute_bias_glb_stencil->add_store("bias_glb_stencil", "bias_glb_s0_w_w");

//consuming bias_glb.stencil
////producing input_glb.stencil
  auto input_glb_s0_y = prg.add_loop("input_glb_s0_y", 0, 101);
  auto input_glb_s0_x = input_glb_s0_y->add_loop("input_glb_s0_x", 0, 101);

//store is: input_glb.stencil(0, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(0, input_glb_s0_x, input_glb_s0_y)
  auto hcompute_input_glb_stencil = input_glb_s0_x->add_op("op_hcompute_input_glb_stencil");
  hcompute_input_glb_stencil->add_function("hcompute_input_glb_stencil");
  hcompute_input_glb_stencil->add_load("input_host_stencil", "input_glb_s0_y", "input_glb_s0_x", "0");
  prg.buffer_port_widths["input_glb_stencil"] = 16;
  hcompute_input_glb_stencil->add_store("input_glb_stencil", "input_glb_s0_y", "input_glb_s0_x", "0");

//store is: input_glb.stencil(1, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(1, input_glb_s0_x, input_glb_s0_y)
  auto hcompute_input_glb_stencil_1 = input_glb_s0_x->add_op("op_hcompute_input_glb_stencil_1");
  hcompute_input_glb_stencil_1->add_function("hcompute_input_glb_stencil_1");
  hcompute_input_glb_stencil_1->add_load("input_host_stencil", "input_glb_s0_y", "input_glb_s0_x", "1");
  hcompute_input_glb_stencil_1->add_store("input_glb_stencil", "input_glb_s0_y", "input_glb_s0_x", "1");

//store is: input_glb.stencil(2, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(2, input_glb_s0_x, input_glb_s0_y)
  auto hcompute_input_glb_stencil_2 = input_glb_s0_x->add_op("op_hcompute_input_glb_stencil_2");
  hcompute_input_glb_stencil_2->add_function("hcompute_input_glb_stencil_2");
  hcompute_input_glb_stencil_2->add_load("input_host_stencil", "input_glb_s0_y", "input_glb_s0_x", "2");
  hcompute_input_glb_stencil_2->add_store("input_glb_stencil", "input_glb_s0_y", "input_glb_s0_x", "2");

//store is: input_glb.stencil(3, input_glb_s0_x, input_glb_s0_y) = input_host.stencil(3, input_glb_s0_x, input_glb_s0_y)
  auto hcompute_input_glb_stencil_3 = input_glb_s0_x->add_op("op_hcompute_input_glb_stencil_3");
  hcompute_input_glb_stencil_3->add_function("hcompute_input_glb_stencil_3");
  hcompute_input_glb_stencil_3->add_load("input_host_stencil", "input_glb_s0_y", "input_glb_s0_x", "3");
  hcompute_input_glb_stencil_3->add_store("input_glb_stencil", "input_glb_s0_y", "input_glb_s0_x", "3");

//consuming input_glb.stencil
////producing kernel_glb.stencil
  auto kernel_glb_s0_y = prg.add_loop("kernel_glb_s0_y", 0, 3);
  auto kernel_glb_s0_x = kernel_glb_s0_y->add_loop("kernel_glb_s0_x", 0, 3);
  auto kernel_glb_s0_z = kernel_glb_s0_x->add_loop("kernel_glb_s0_z", 0, 4);
  auto kernel_glb_s0_w_w = kernel_glb_s0_z->add_loop("kernel_glb_s0_w_w", 0, 4);

//store is: kernel_glb.stencil((kernel_glb_s0_w_w*4), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil((kernel_glb_s0_w_w*4), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
  auto hcompute_kernel_glb_stencil = kernel_glb_s0_w_w->add_op("op_hcompute_kernel_glb_stencil");
  hcompute_kernel_glb_stencil->add_function("hcompute_kernel_glb_stencil");
  hcompute_kernel_glb_stencil->add_load("kernel_host_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "(kernel_glb_s0_w_w*4)");
  prg.buffer_port_widths["kernel_glb_stencil"] = 16;
  hcompute_kernel_glb_stencil->add_store("kernel_glb_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "(kernel_glb_s0_w_w*4)");

//store is: kernel_glb.stencil(((kernel_glb_s0_w_w*4) + 1), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil(((kernel_glb_s0_w_w*4) + 1), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
  auto hcompute_kernel_glb_stencil_1 = kernel_glb_s0_w_w->add_op("op_hcompute_kernel_glb_stencil_1");
  hcompute_kernel_glb_stencil_1->add_function("hcompute_kernel_glb_stencil_1");
  hcompute_kernel_glb_stencil_1->add_load("kernel_host_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "((kernel_glb_s0_w_w*4) + 1)");
  hcompute_kernel_glb_stencil_1->add_store("kernel_glb_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "((kernel_glb_s0_w_w*4) + 1)");

//store is: kernel_glb.stencil(((kernel_glb_s0_w_w*4) + 2), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil(((kernel_glb_s0_w_w*4) + 2), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
  auto hcompute_kernel_glb_stencil_2 = kernel_glb_s0_w_w->add_op("op_hcompute_kernel_glb_stencil_2");
  hcompute_kernel_glb_stencil_2->add_function("hcompute_kernel_glb_stencil_2");
  hcompute_kernel_glb_stencil_2->add_load("kernel_host_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "((kernel_glb_s0_w_w*4) + 2)");
  hcompute_kernel_glb_stencil_2->add_store("kernel_glb_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "((kernel_glb_s0_w_w*4) + 2)");

//store is: kernel_glb.stencil(((kernel_glb_s0_w_w*4) + 3), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y) = kernel_host.stencil(((kernel_glb_s0_w_w*4) + 3), kernel_glb_s0_z, kernel_glb_s0_x, kernel_glb_s0_y)
  auto hcompute_kernel_glb_stencil_3 = kernel_glb_s0_w_w->add_op("op_hcompute_kernel_glb_stencil_3");
  hcompute_kernel_glb_stencil_3->add_function("hcompute_kernel_glb_stencil_3");
  hcompute_kernel_glb_stencil_3->add_load("kernel_host_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "((kernel_glb_s0_w_w*4) + 3)");
  hcompute_kernel_glb_stencil_3->add_store("kernel_glb_stencil", "kernel_glb_s0_y", "kernel_glb_s0_x", "kernel_glb_s0_z", "((kernel_glb_s0_w_w*4) + 3)");

//consuming kernel_glb.stencil
////producing output_glb.stencil
  auto output_glb_s0_y_y_glb = prg.add_loop("output_glb_s0_y_y_glb", 0, 2);
  auto output_glb_s0_y_y_cgra = output_glb_s0_y_y_glb->add_loop("output_glb_s0_y_y_cgra", 0, 25);
////producing bias_cgra.stencil
  auto bias_cgra_s0_x = output_glb_s0_y_y_cgra->add_loop("bias_cgra_s0_x", 0, 50);
  auto bias_cgra_s0_w_w_cgra_w_cgra = bias_cgra_s0_x->add_loop("bias_cgra_s0_w_w_cgra_w_cgra", 0, 16);

//store is: bias_cgra.stencil(bias_cgra_s0_w_w_cgra_w_cgra, bias_cgra_s0_x, 0) = bias_glb.stencil(bias_cgra_s0_w_w_cgra_w_cgra)
  auto hcompute_bias_cgra_stencil = bias_cgra_s0_w_w_cgra_w_cgra->add_op("op_hcompute_bias_cgra_stencil");
  hcompute_bias_cgra_stencil->add_function("hcompute_bias_cgra_stencil");
  hcompute_bias_cgra_stencil->add_load("bias_glb_stencil", "bias_cgra_s0_w_w_cgra_w_cgra");
  prg.buffer_port_widths["bias_cgra_stencil"] = 16;
  hcompute_bias_cgra_stencil->add_store("bias_cgra_stencil", "0", "bias_cgra_s0_x", "bias_cgra_s0_w_w_cgra_w_cgra");

//consuming bias_cgra.stencil
////producing output_cgra.stencil
  auto output_cgra_s0_x = output_glb_s0_y_y_cgra->add_loop("output_cgra_s0_x", 0, 50);

//store is: output_cgra.stencil(0, output_cgra_s0_x, 0) = bias_cgra.stencil(0, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil");
  hcompute_output_cgra_stencil->add_function("hcompute_output_cgra_stencil");
  hcompute_output_cgra_stencil->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "0");
  prg.buffer_port_widths["output_cgra_stencil"] = 16;
  hcompute_output_cgra_stencil->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "0");

//store is: output_cgra.stencil(1, output_cgra_s0_x, 0) = bias_cgra.stencil(1, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_1 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_1");
  hcompute_output_cgra_stencil_1->add_function("hcompute_output_cgra_stencil_1");
  hcompute_output_cgra_stencil_1->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "1");
  hcompute_output_cgra_stencil_1->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "1");

//store is: output_cgra.stencil(2, output_cgra_s0_x, 0) = bias_cgra.stencil(2, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_2 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_2");
  hcompute_output_cgra_stencil_2->add_function("hcompute_output_cgra_stencil_2");
  hcompute_output_cgra_stencil_2->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "2");
  hcompute_output_cgra_stencil_2->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "2");

//store is: output_cgra.stencil(3, output_cgra_s0_x, 0) = bias_cgra.stencil(3, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_3 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_3");
  hcompute_output_cgra_stencil_3->add_function("hcompute_output_cgra_stencil_3");
  hcompute_output_cgra_stencil_3->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "3");
  hcompute_output_cgra_stencil_3->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "3");

//store is: output_cgra.stencil(4, output_cgra_s0_x, 0) = bias_cgra.stencil(4, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_4 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_4");
  hcompute_output_cgra_stencil_4->add_function("hcompute_output_cgra_stencil_4");
  hcompute_output_cgra_stencil_4->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "4");
  hcompute_output_cgra_stencil_4->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "4");

//store is: output_cgra.stencil(5, output_cgra_s0_x, 0) = bias_cgra.stencil(5, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_5 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_5");
  hcompute_output_cgra_stencil_5->add_function("hcompute_output_cgra_stencil_5");
  hcompute_output_cgra_stencil_5->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "5");
  hcompute_output_cgra_stencil_5->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "5");

//store is: output_cgra.stencil(6, output_cgra_s0_x, 0) = bias_cgra.stencil(6, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_6 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_6");
  hcompute_output_cgra_stencil_6->add_function("hcompute_output_cgra_stencil_6");
  hcompute_output_cgra_stencil_6->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "6");
  hcompute_output_cgra_stencil_6->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "6");

//store is: output_cgra.stencil(7, output_cgra_s0_x, 0) = bias_cgra.stencil(7, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_7 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_7");
  hcompute_output_cgra_stencil_7->add_function("hcompute_output_cgra_stencil_7");
  hcompute_output_cgra_stencil_7->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "7");
  hcompute_output_cgra_stencil_7->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "7");

//store is: output_cgra.stencil(8, output_cgra_s0_x, 0) = bias_cgra.stencil(8, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_8 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_8");
  hcompute_output_cgra_stencil_8->add_function("hcompute_output_cgra_stencil_8");
  hcompute_output_cgra_stencil_8->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "8");
  hcompute_output_cgra_stencil_8->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "8");

//store is: output_cgra.stencil(9, output_cgra_s0_x, 0) = bias_cgra.stencil(9, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_9 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_9");
  hcompute_output_cgra_stencil_9->add_function("hcompute_output_cgra_stencil_9");
  hcompute_output_cgra_stencil_9->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "9");
  hcompute_output_cgra_stencil_9->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "9");

//store is: output_cgra.stencil(10, output_cgra_s0_x, 0) = bias_cgra.stencil(10, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_10 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_10");
  hcompute_output_cgra_stencil_10->add_function("hcompute_output_cgra_stencil_10");
  hcompute_output_cgra_stencil_10->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "10");
  hcompute_output_cgra_stencil_10->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "10");

//store is: output_cgra.stencil(11, output_cgra_s0_x, 0) = bias_cgra.stencil(11, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_11 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_11");
  hcompute_output_cgra_stencil_11->add_function("hcompute_output_cgra_stencil_11");
  hcompute_output_cgra_stencil_11->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "11");
  hcompute_output_cgra_stencil_11->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "11");

//store is: output_cgra.stencil(12, output_cgra_s0_x, 0) = bias_cgra.stencil(12, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_12 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_12");
  hcompute_output_cgra_stencil_12->add_function("hcompute_output_cgra_stencil_12");
  hcompute_output_cgra_stencil_12->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "12");
  hcompute_output_cgra_stencil_12->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "12");

//store is: output_cgra.stencil(13, output_cgra_s0_x, 0) = bias_cgra.stencil(13, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_13 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_13");
  hcompute_output_cgra_stencil_13->add_function("hcompute_output_cgra_stencil_13");
  hcompute_output_cgra_stencil_13->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "13");
  hcompute_output_cgra_stencil_13->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "13");

//store is: output_cgra.stencil(14, output_cgra_s0_x, 0) = bias_cgra.stencil(14, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_14 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_14");
  hcompute_output_cgra_stencil_14->add_function("hcompute_output_cgra_stencil_14");
  hcompute_output_cgra_stencil_14->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "14");
  hcompute_output_cgra_stencil_14->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "14");

//store is: output_cgra.stencil(15, output_cgra_s0_x, 0) = bias_cgra.stencil(15, output_cgra_s0_x, 0)
  auto hcompute_output_cgra_stencil_15 = output_cgra_s0_x->add_op("op_hcompute_output_cgra_stencil_15");
  hcompute_output_cgra_stencil_15->add_function("hcompute_output_cgra_stencil_15");
  hcompute_output_cgra_stencil_15->add_load("bias_cgra_stencil", "0", "output_cgra_s0_x", "15");
  hcompute_output_cgra_stencil_15->add_store("output_cgra_stencil", "0", "output_cgra_s0_x", "15");
////producing input_cgra.stencil
  auto input_cgra_s0_y = output_glb_s0_y_y_cgra->add_loop("input_cgra_s0_y", 0, 3);
  auto input_cgra_s0_x = input_cgra_s0_y->add_loop("input_cgra_s0_x", 0, 101);

//store is: input_cgra.stencil(0, input_cgra_s0_x, input_cgra_s0_y) = input_glb.stencil(0, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
  auto hcompute_input_cgra_stencil = input_cgra_s0_x->add_op("op_hcompute_input_cgra_stencil");
  hcompute_input_cgra_stencil->add_function("hcompute_input_cgra_stencil");
  hcompute_input_cgra_stencil->add_load("input_glb_stencil", "((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y)", "input_cgra_s0_x", "0");
  prg.buffer_port_widths["input_cgra_stencil"] = 16;
  hcompute_input_cgra_stencil->add_store("input_cgra_stencil", "input_cgra_s0_y", "input_cgra_s0_x", "0");

//store is: input_cgra.stencil(1, input_cgra_s0_x, input_cgra_s0_y) = input_glb.stencil(1, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
  auto hcompute_input_cgra_stencil_1 = input_cgra_s0_x->add_op("op_hcompute_input_cgra_stencil_1");
  hcompute_input_cgra_stencil_1->add_function("hcompute_input_cgra_stencil_1");
  hcompute_input_cgra_stencil_1->add_load("input_glb_stencil", "((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y)", "input_cgra_s0_x", "1");
  hcompute_input_cgra_stencil_1->add_store("input_cgra_stencil", "input_cgra_s0_y", "input_cgra_s0_x", "1");

//store is: input_cgra.stencil(2, input_cgra_s0_x, input_cgra_s0_y) = input_glb.stencil(2, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
  auto hcompute_input_cgra_stencil_2 = input_cgra_s0_x->add_op("op_hcompute_input_cgra_stencil_2");
  hcompute_input_cgra_stencil_2->add_function("hcompute_input_cgra_stencil_2");
  hcompute_input_cgra_stencil_2->add_load("input_glb_stencil", "((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y)", "input_cgra_s0_x", "2");
  hcompute_input_cgra_stencil_2->add_store("input_cgra_stencil", "input_cgra_s0_y", "input_cgra_s0_x", "2");

//store is: input_cgra.stencil(3, input_cgra_s0_x, input_cgra_s0_y) = input_glb.stencil(3, input_cgra_s0_x, ((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y))
  auto hcompute_input_cgra_stencil_3 = input_cgra_s0_x->add_op("op_hcompute_input_cgra_stencil_3");
  hcompute_input_cgra_stencil_3->add_function("hcompute_input_cgra_stencil_3");
  hcompute_input_cgra_stencil_3->add_load("input_glb_stencil", "((((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)*2) + input_cgra_s0_y)", "input_cgra_s0_x", "3");
  hcompute_input_cgra_stencil_3->add_store("input_cgra_stencil", "input_cgra_s0_y", "input_cgra_s0_x", "3");

//consuming input_cgra.stencil
////producing kernel_cgra.stencil
  auto kernel_cgra_s0_y = output_glb_s0_y_y_cgra->add_loop("kernel_cgra_s0_y", 0, 3);
  auto kernel_cgra_s0_x = kernel_cgra_s0_y->add_loop("kernel_cgra_s0_x", 0, 3);
  auto kernel_cgra_s0_z_z_cgra = kernel_cgra_s0_x->add_loop("kernel_cgra_s0_z_z_cgra", 0, 4);
  auto kernel_cgra_s0_w_w_cgra_w_cgra = kernel_cgra_s0_z_z_cgra->add_loop("kernel_cgra_s0_w_w_cgra_w_cgra", 0, 4);

//store is: kernel_cgra.stencil((kernel_cgra_s0_w_w_cgra_w_cgra*4), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil((kernel_cgra_s0_w_w_cgra_w_cgra*4), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
  auto hcompute_kernel_cgra_stencil = kernel_cgra_s0_w_w_cgra_w_cgra->add_op("op_hcompute_kernel_cgra_stencil");
  hcompute_kernel_cgra_stencil->add_function("hcompute_kernel_cgra_stencil");
  hcompute_kernel_cgra_stencil->add_load("kernel_glb_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "(kernel_cgra_s0_w_w_cgra_w_cgra*4)");
  prg.buffer_port_widths["kernel_cgra_stencil"] = 16;
  hcompute_kernel_cgra_stencil->add_store("kernel_cgra_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "(kernel_cgra_s0_w_w_cgra_w_cgra*4)");

//store is: kernel_cgra.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 1), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 1), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
  auto hcompute_kernel_cgra_stencil_1 = kernel_cgra_s0_w_w_cgra_w_cgra->add_op("op_hcompute_kernel_cgra_stencil_1");
  hcompute_kernel_cgra_stencil_1->add_function("hcompute_kernel_cgra_stencil_1");
  hcompute_kernel_cgra_stencil_1->add_load("kernel_glb_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 1)");
  hcompute_kernel_cgra_stencil_1->add_store("kernel_cgra_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 1)");

//store is: kernel_cgra.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 2), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 2), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
  auto hcompute_kernel_cgra_stencil_2 = kernel_cgra_s0_w_w_cgra_w_cgra->add_op("op_hcompute_kernel_cgra_stencil_2");
  hcompute_kernel_cgra_stencil_2->add_function("hcompute_kernel_cgra_stencil_2");
  hcompute_kernel_cgra_stencil_2->add_load("kernel_glb_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 2)");
  hcompute_kernel_cgra_stencil_2->add_store("kernel_cgra_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 2)");

//store is: kernel_cgra.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 3), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y) = kernel_glb.stencil(((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 3), kernel_cgra_s0_z_z_cgra, kernel_cgra_s0_x, kernel_cgra_s0_y)
  auto hcompute_kernel_cgra_stencil_3 = kernel_cgra_s0_w_w_cgra_w_cgra->add_op("op_hcompute_kernel_cgra_stencil_3");
  hcompute_kernel_cgra_stencil_3->add_function("hcompute_kernel_cgra_stencil_3");
  hcompute_kernel_cgra_stencil_3->add_load("kernel_glb_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 3)");
  hcompute_kernel_cgra_stencil_3->add_store("kernel_cgra_stencil", "kernel_cgra_s0_y", "kernel_cgra_s0_x", "kernel_cgra_s0_z_z_cgra", "((kernel_cgra_s0_w_w_cgra_w_cgra*4) + 3)");

//consuming kernel_cgra.stencil
  auto output_cgra_s1_r_y = output_glb_s0_y_y_cgra->add_loop("output_cgra_s1_r_y", 0, 3);
  auto output_cgra_s1_r_x = output_cgra_s1_r_y->add_loop("output_cgra_s1_r_x", 0, 3);
  auto output_cgra_s1_x = output_cgra_s1_r_x->add_loop("output_cgra_s1_x", 0, 50);

//store is: output_cgra.stencil(0, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(0, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(0, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(0, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(0, output_cgra_s1_x, 0) + (kernel_cgra.stencil(0, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_16 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_16");
  hcompute_output_cgra_stencil_16->add_function("hcompute_output_cgra_stencil_16");
  hcompute_output_cgra_stencil_16->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_16->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_16->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_16->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_16->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "0");
  hcompute_output_cgra_stencil_16->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "0");
  hcompute_output_cgra_stencil_16->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "0");
  hcompute_output_cgra_stencil_16->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "0");
  hcompute_output_cgra_stencil_16->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "0");
  hcompute_output_cgra_stencil_16->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "0");

//store is: output_cgra.stencil(1, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(1, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(1, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(1, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(1, output_cgra_s1_x, 0) + (kernel_cgra.stencil(1, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_17 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_17");
  hcompute_output_cgra_stencil_17->add_function("hcompute_output_cgra_stencil_17");
  hcompute_output_cgra_stencil_17->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_17->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_17->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_17->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_17->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "1");
  hcompute_output_cgra_stencil_17->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "1");
  hcompute_output_cgra_stencil_17->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "1");
  hcompute_output_cgra_stencil_17->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "1");
  hcompute_output_cgra_stencil_17->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "1");
  hcompute_output_cgra_stencil_17->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "1");

//store is: output_cgra.stencil(2, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(2, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(2, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(2, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(2, output_cgra_s1_x, 0) + (kernel_cgra.stencil(2, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_18 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_18");
  hcompute_output_cgra_stencil_18->add_function("hcompute_output_cgra_stencil_18");
  hcompute_output_cgra_stencil_18->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_18->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_18->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_18->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_18->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "2");
  hcompute_output_cgra_stencil_18->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "2");
  hcompute_output_cgra_stencil_18->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "2");
  hcompute_output_cgra_stencil_18->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "2");
  hcompute_output_cgra_stencil_18->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "2");
  hcompute_output_cgra_stencil_18->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "2");

//store is: output_cgra.stencil(3, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(3, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(3, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(3, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(3, output_cgra_s1_x, 0) + (kernel_cgra.stencil(3, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_19 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_19");
  hcompute_output_cgra_stencil_19->add_function("hcompute_output_cgra_stencil_19");
  hcompute_output_cgra_stencil_19->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_19->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_19->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_19->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_19->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "3");
  hcompute_output_cgra_stencil_19->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "3");
  hcompute_output_cgra_stencil_19->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "3");
  hcompute_output_cgra_stencil_19->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "3");
  hcompute_output_cgra_stencil_19->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "3");
  hcompute_output_cgra_stencil_19->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "3");

//store is: output_cgra.stencil(4, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(4, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(4, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(4, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(4, output_cgra_s1_x, 0) + (kernel_cgra.stencil(4, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_20 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_20");
  hcompute_output_cgra_stencil_20->add_function("hcompute_output_cgra_stencil_20");
  hcompute_output_cgra_stencil_20->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_20->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_20->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_20->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_20->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "4");
  hcompute_output_cgra_stencil_20->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "4");
  hcompute_output_cgra_stencil_20->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "4");
  hcompute_output_cgra_stencil_20->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "4");
  hcompute_output_cgra_stencil_20->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "4");
  hcompute_output_cgra_stencil_20->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "4");

//store is: output_cgra.stencil(5, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(5, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(5, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(5, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(5, output_cgra_s1_x, 0) + (kernel_cgra.stencil(5, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_21 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_21");
  hcompute_output_cgra_stencil_21->add_function("hcompute_output_cgra_stencil_21");
  hcompute_output_cgra_stencil_21->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_21->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_21->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_21->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_21->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "5");
  hcompute_output_cgra_stencil_21->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "5");
  hcompute_output_cgra_stencil_21->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "5");
  hcompute_output_cgra_stencil_21->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "5");
  hcompute_output_cgra_stencil_21->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "5");
  hcompute_output_cgra_stencil_21->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "5");

//store is: output_cgra.stencil(6, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(6, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(6, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(6, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(6, output_cgra_s1_x, 0) + (kernel_cgra.stencil(6, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_22 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_22");
  hcompute_output_cgra_stencil_22->add_function("hcompute_output_cgra_stencil_22");
  hcompute_output_cgra_stencil_22->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_22->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_22->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_22->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_22->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "6");
  hcompute_output_cgra_stencil_22->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "6");
  hcompute_output_cgra_stencil_22->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "6");
  hcompute_output_cgra_stencil_22->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "6");
  hcompute_output_cgra_stencil_22->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "6");
  hcompute_output_cgra_stencil_22->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "6");

//store is: output_cgra.stencil(7, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(7, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(7, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(7, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(7, output_cgra_s1_x, 0) + (kernel_cgra.stencil(7, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_23 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_23");
  hcompute_output_cgra_stencil_23->add_function("hcompute_output_cgra_stencil_23");
  hcompute_output_cgra_stencil_23->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_23->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_23->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_23->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_23->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "7");
  hcompute_output_cgra_stencil_23->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "7");
  hcompute_output_cgra_stencil_23->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "7");
  hcompute_output_cgra_stencil_23->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "7");
  hcompute_output_cgra_stencil_23->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "7");
  hcompute_output_cgra_stencil_23->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "7");

//store is: output_cgra.stencil(8, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(8, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(8, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(8, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(8, output_cgra_s1_x, 0) + (kernel_cgra.stencil(8, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_24 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_24");
  hcompute_output_cgra_stencil_24->add_function("hcompute_output_cgra_stencil_24");
  hcompute_output_cgra_stencil_24->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_24->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_24->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_24->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_24->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "8");
  hcompute_output_cgra_stencil_24->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "8");
  hcompute_output_cgra_stencil_24->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "8");
  hcompute_output_cgra_stencil_24->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "8");
  hcompute_output_cgra_stencil_24->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "8");
  hcompute_output_cgra_stencil_24->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "8");

//store is: output_cgra.stencil(9, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(9, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(9, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(9, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(9, output_cgra_s1_x, 0) + (kernel_cgra.stencil(9, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_25 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_25");
  hcompute_output_cgra_stencil_25->add_function("hcompute_output_cgra_stencil_25");
  hcompute_output_cgra_stencil_25->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_25->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_25->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_25->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_25->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "9");
  hcompute_output_cgra_stencil_25->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "9");
  hcompute_output_cgra_stencil_25->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "9");
  hcompute_output_cgra_stencil_25->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "9");
  hcompute_output_cgra_stencil_25->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "9");
  hcompute_output_cgra_stencil_25->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "9");

//store is: output_cgra.stencil(10, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(10, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(10, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(10, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(10, output_cgra_s1_x, 0) + (kernel_cgra.stencil(10, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_26 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_26");
  hcompute_output_cgra_stencil_26->add_function("hcompute_output_cgra_stencil_26");
  hcompute_output_cgra_stencil_26->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_26->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_26->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_26->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_26->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "10");
  hcompute_output_cgra_stencil_26->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "10");
  hcompute_output_cgra_stencil_26->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "10");
  hcompute_output_cgra_stencil_26->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "10");
  hcompute_output_cgra_stencil_26->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "10");
  hcompute_output_cgra_stencil_26->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "10");

//store is: output_cgra.stencil(11, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(11, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(11, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(11, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(11, output_cgra_s1_x, 0) + (kernel_cgra.stencil(11, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_27 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_27");
  hcompute_output_cgra_stencil_27->add_function("hcompute_output_cgra_stencil_27");
  hcompute_output_cgra_stencil_27->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_27->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_27->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_27->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_27->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "11");
  hcompute_output_cgra_stencil_27->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "11");
  hcompute_output_cgra_stencil_27->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "11");
  hcompute_output_cgra_stencil_27->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "11");
  hcompute_output_cgra_stencil_27->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "11");
  hcompute_output_cgra_stencil_27->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "11");

//store is: output_cgra.stencil(12, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(12, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(12, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(12, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(12, output_cgra_s1_x, 0) + (kernel_cgra.stencil(12, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_28 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_28");
  hcompute_output_cgra_stencil_28->add_function("hcompute_output_cgra_stencil_28");
  hcompute_output_cgra_stencil_28->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_28->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_28->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_28->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_28->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "12");
  hcompute_output_cgra_stencil_28->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "12");
  hcompute_output_cgra_stencil_28->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "12");
  hcompute_output_cgra_stencil_28->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "12");
  hcompute_output_cgra_stencil_28->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "12");
  hcompute_output_cgra_stencil_28->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "12");

//store is: output_cgra.stencil(13, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(13, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(13, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(13, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(13, output_cgra_s1_x, 0) + (kernel_cgra.stencil(13, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_29 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_29");
  hcompute_output_cgra_stencil_29->add_function("hcompute_output_cgra_stencil_29");
  hcompute_output_cgra_stencil_29->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_29->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_29->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_29->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_29->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "13");
  hcompute_output_cgra_stencil_29->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "13");
  hcompute_output_cgra_stencil_29->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "13");
  hcompute_output_cgra_stencil_29->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "13");
  hcompute_output_cgra_stencil_29->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "13");
  hcompute_output_cgra_stencil_29->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "13");

//store is: output_cgra.stencil(14, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(14, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(14, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(14, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(14, output_cgra_s1_x, 0) + (kernel_cgra.stencil(14, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_30 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_30");
  hcompute_output_cgra_stencil_30->add_function("hcompute_output_cgra_stencil_30");
  hcompute_output_cgra_stencil_30->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_30->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_30->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_30->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_30->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "14");
  hcompute_output_cgra_stencil_30->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "14");
  hcompute_output_cgra_stencil_30->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "14");
  hcompute_output_cgra_stencil_30->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "14");
  hcompute_output_cgra_stencil_30->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "14");
  hcompute_output_cgra_stencil_30->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "14");

//store is: output_cgra.stencil(15, output_cgra_s1_x, 0) = ((kernel_cgra.stencil(15, 3, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(3, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(15, 2, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(2, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + ((kernel_cgra.stencil(15, 1, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(1, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y)) + (output_cgra.stencil(15, output_cgra_s1_x, 0) + (kernel_cgra.stencil(15, 0, output_cgra_s1_r_x, output_cgra_s1_r_y)*input_cgra.stencil(0, ((output_cgra_s1_x*2) + output_cgra_s1_r_x), output_cgra_s1_r_y))))))
  auto hcompute_output_cgra_stencil_31 = output_cgra_s1_x->add_op("op_hcompute_output_cgra_stencil_31");
  hcompute_output_cgra_stencil_31->add_function("hcompute_output_cgra_stencil_31");
  hcompute_output_cgra_stencil_31->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "3");
  hcompute_output_cgra_stencil_31->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "2");
  hcompute_output_cgra_stencil_31->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "1");
  hcompute_output_cgra_stencil_31->add_load("input_cgra_stencil", "output_cgra_s1_r_y", "((output_cgra_s1_x*2) + output_cgra_s1_r_x)", "0");
  hcompute_output_cgra_stencil_31->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "3", "15");
  hcompute_output_cgra_stencil_31->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "2", "15");
  hcompute_output_cgra_stencil_31->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "1", "15");
  hcompute_output_cgra_stencil_31->add_load("kernel_cgra_stencil", "output_cgra_s1_r_y", "output_cgra_s1_r_x", "0", "15");
  hcompute_output_cgra_stencil_31->add_load("output_cgra_stencil", "0", "output_cgra_s1_x", "15");
  hcompute_output_cgra_stencil_31->add_store("output_cgra_stencil", "0", "output_cgra_s1_x", "15");

//consuming output_cgra.stencil
  auto output_glb_s0_x_x_glb = output_glb_s0_y_y_cgra->add_loop("output_glb_s0_x_x_glb", 0, 2);
  auto output_glb_s0_x_x_cgra = output_glb_s0_x_x_glb->add_loop("output_glb_s0_x_x_cgra", 0, 25);
  auto output_glb_s0_w_w_cgra_w_cgra = output_glb_s0_x_x_cgra->add_loop("output_glb_s0_w_w_cgra_w_cgra", 0, 4);

//store is: output_glb.stencil((output_glb_s0_w_w_cgra_w_cgra*4), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil((output_glb_s0_w_w_cgra_w_cgra*4), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
  auto hcompute_output_glb_stencil = output_glb_s0_w_w_cgra_w_cgra->add_op("op_hcompute_output_glb_stencil");
  hcompute_output_glb_stencil->add_function("hcompute_output_glb_stencil");
  hcompute_output_glb_stencil->add_load("output_cgra_stencil", "0", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "(output_glb_s0_w_w_cgra_w_cgra*4)");
  prg.buffer_port_widths["output_glb_stencil"] = 16;
  hcompute_output_glb_stencil->add_store("output_glb_stencil", "((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "(output_glb_s0_w_w_cgra_w_cgra*4)");

//store is: output_glb.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 1), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 1), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
  auto hcompute_output_glb_stencil_1 = output_glb_s0_w_w_cgra_w_cgra->add_op("op_hcompute_output_glb_stencil_1");
  hcompute_output_glb_stencil_1->add_function("hcompute_output_glb_stencil_1");
  hcompute_output_glb_stencil_1->add_load("output_cgra_stencil", "0", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "((output_glb_s0_w_w_cgra_w_cgra*4) + 1)");
  hcompute_output_glb_stencil_1->add_store("output_glb_stencil", "((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "((output_glb_s0_w_w_cgra_w_cgra*4) + 1)");

//store is: output_glb.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 2), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 2), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
  auto hcompute_output_glb_stencil_2 = output_glb_s0_w_w_cgra_w_cgra->add_op("op_hcompute_output_glb_stencil_2");
  hcompute_output_glb_stencil_2->add_function("hcompute_output_glb_stencil_2");
  hcompute_output_glb_stencil_2->add_load("output_cgra_stencil", "0", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "((output_glb_s0_w_w_cgra_w_cgra*4) + 2)");
  hcompute_output_glb_stencil_2->add_store("output_glb_stencil", "((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "((output_glb_s0_w_w_cgra_w_cgra*4) + 2)");

//store is: output_glb.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 3), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), ((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)) = max(min(output_cgra.stencil(((output_glb_s0_w_w_cgra_w_cgra*4) + 3), ((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra), 0), 6.000000h), 0.000000h)
  auto hcompute_output_glb_stencil_3 = output_glb_s0_w_w_cgra_w_cgra->add_op("op_hcompute_output_glb_stencil_3");
  hcompute_output_glb_stencil_3->add_function("hcompute_output_glb_stencil_3");
  hcompute_output_glb_stencil_3->add_load("output_cgra_stencil", "0", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "((output_glb_s0_w_w_cgra_w_cgra*4) + 3)");
  hcompute_output_glb_stencil_3->add_store("output_glb_stencil", "((output_glb_s0_y_y_glb*25) + output_glb_s0_y_y_cgra)", "((output_glb_s0_x_x_glb*25) + output_glb_s0_x_x_cgra)", "((output_glb_s0_w_w_cgra_w_cgra*4) + 3)");

//consuming output_glb.stencil
  auto hw_output_s0_y_yi = prg.add_loop("hw_output_s0_y_yi", 0, 50);
  auto hw_output_s0_x_xi = hw_output_s0_y_yi->add_loop("hw_output_s0_x_xi", 0, 50);
  auto hw_output_s0_w_w = hw_output_s0_x_xi->add_loop("hw_output_s0_w_w", 0, 4);

//store is: hw_output.stencil((hw_output_s0_w_w*4), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil((hw_output_s0_w_w*4), hw_output_s0_x_xi, hw_output_s0_y_yi)
  auto hcompute_hw_output_stencil = hw_output_s0_w_w->add_op("op_hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_function("hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_load("output_glb_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "(hw_output_s0_w_w*4)");
  hcompute_hw_output_stencil->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "(hw_output_s0_w_w*4)");

//store is: hw_output.stencil(((hw_output_s0_w_w*4) + 1), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil(((hw_output_s0_w_w*4) + 1), hw_output_s0_x_xi, hw_output_s0_y_yi)
  auto hcompute_hw_output_stencil_1 = hw_output_s0_w_w->add_op("op_hcompute_hw_output_stencil_1");
  hcompute_hw_output_stencil_1->add_function("hcompute_hw_output_stencil_1");
  hcompute_hw_output_stencil_1->add_load("output_glb_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "((hw_output_s0_w_w*4) + 1)");
  hcompute_hw_output_stencil_1->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "((hw_output_s0_w_w*4) + 1)");

//store is: hw_output.stencil(((hw_output_s0_w_w*4) + 2), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil(((hw_output_s0_w_w*4) + 2), hw_output_s0_x_xi, hw_output_s0_y_yi)
  auto hcompute_hw_output_stencil_2 = hw_output_s0_w_w->add_op("op_hcompute_hw_output_stencil_2");
  hcompute_hw_output_stencil_2->add_function("hcompute_hw_output_stencil_2");
  hcompute_hw_output_stencil_2->add_load("output_glb_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "((hw_output_s0_w_w*4) + 2)");
  hcompute_hw_output_stencil_2->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "((hw_output_s0_w_w*4) + 2)");

//store is: hw_output.stencil(((hw_output_s0_w_w*4) + 3), hw_output_s0_x_xi, hw_output_s0_y_yi) = output_glb.stencil(((hw_output_s0_w_w*4) + 3), hw_output_s0_x_xi, hw_output_s0_y_yi)
  auto hcompute_hw_output_stencil_3 = hw_output_s0_w_w->add_op("op_hcompute_hw_output_stencil_3");
  hcompute_hw_output_stencil_3->add_function("hcompute_hw_output_stencil_3");
  hcompute_hw_output_stencil_3->add_load("output_glb_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "((hw_output_s0_w_w*4) + 3)");
  hcompute_hw_output_stencil_3->add_store("hw_output_stencil", "hw_output_s0_y_yi", "hw_output_s0_x_xi", "((hw_output_s0_w_w*4) + 3)");

  return prg;
}


// in_img=101 pad_o_left=1 pad_o_right=1 ksize=3 stride=2 n_ic=4 n_oc=16 k_ic=4 k_oc=16 glb_i=4 glb_k=4 glb_o=4 relu6=1
