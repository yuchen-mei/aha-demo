#include "clockwork_testscript.h"
#include "unoptimized_conv2D_fp.h"
#include "hw_classes.h"
#include <fstream>
#include <vector>

void run_clockwork_program(RDAI_MemObject **mem_object_list) {
	// input and output memory objects
	uint16_t *bias_host_stencil = (uint16_t*) mem_object_list[0]->host_ptr;
	bfloat16_t *input_host_stencil = (bfloat16_t*) mem_object_list[1]->host_ptr;
	bfloat16_t *kernel_host_stencil = (bfloat16_t*) mem_object_list[2]->host_ptr;
	bfloat16_t *hw_output_stencil = (bfloat16_t*) mem_object_list[3]->host_ptr;

	// input and output stream declarations
	HWStream< hw_uint<16> > bias_host_stencil_stream;
	HWStream< hw_uint<16> > input_host_stencil_stream;
	HWStream< hw_uint<16> > kernel_host_stencil_stream;
	HWStream< hw_uint<16> > hw_output_stencil_stream;
	int idx = 0;

	// provision input stream bias_host_stencil_stream
	std::vector<uint16_t> bias_host_stencil_stream_tile(16);   idx=0;
	for (int l0 = 0; l0 < 16; l0++) {
		hw_uint<16> in_val;
		set_at<0, 16, 16>(in_val, hw_uint<16>(bias_host_stencil[l0]));
		bias_host_stencil_stream.write(in_val);
		bias_host_stencil_stream_tile[idx] = bias_host_stencil[l0];  idx += 1;
	} 
	ofstream bias_host_stencil_file("bin/bias_host_stencil.leraw", ios::binary);
	bias_host_stencil_file.write(reinterpret_cast<const char *>(bias_host_stencil_stream_tile.data()),
		sizeof(bias_host_stencil_stream_tile[0]) * 16);
	bias_host_stencil_file.close();

	// provision input stream input_host_stencil_stream
	std::vector<bfloat16_t> input_host_stencil_stream_tile(4*101*101);   idx=0;
	for (int l2 = 0; l2 < 101; l2++) {
	for (int l1 = 0; l1 < 101; l1++) {
	for (int l0 = 0; l0 < 4; l0++) {
		hw_uint<16> in_val;
		set_at<0, 16, 16>(in_val, hw_uint<16>(input_host_stencil[((l2*404) + ((l1*4) + l0))]));
		input_host_stencil_stream.write(in_val);
		input_host_stencil_stream_tile[idx] = input_host_stencil[((l2*404) + ((l1*4) + l0))];  idx += 1;
	} } } 
	ofstream input_host_stencil_file("bin/input_host_stencil.leraw", ios::binary);
	input_host_stencil_file.write(reinterpret_cast<const char *>(input_host_stencil_stream_tile.data()),
		sizeof(input_host_stencil_stream_tile[0]) * 4 * 101 * 101);
	input_host_stencil_file.close();

	// provision input stream kernel_host_stencil_stream
	std::vector<bfloat16_t> kernel_host_stencil_stream_tile(16*4*3*3);   idx=0;
	for (int l3 = 0; l3 < 3; l3++) {
	for (int l2 = 0; l2 < 3; l2++) {
	for (int l1 = 0; l1 < 4; l1++) {
	for (int l0 = 0; l0 < 16; l0++) {
		hw_uint<16> in_val;
		set_at<0, 16, 16>(in_val, hw_uint<16>(kernel_host_stencil[((l3*192) + ((l2*64) + ((l1*16) + l0)))]));
		kernel_host_stencil_stream.write(in_val);
		kernel_host_stencil_stream_tile[idx] = kernel_host_stencil[((l3*192) + ((l2*64) + ((l1*16) + l0)))];  idx += 1;
	} } } } 
	ofstream kernel_host_stencil_file("bin/kernel_host_stencil.leraw", ios::binary);
	kernel_host_stencil_file.write(reinterpret_cast<const char *>(kernel_host_stencil_stream_tile.data()),
		sizeof(kernel_host_stencil_stream_tile[0]) * 16 * 4 * 3 * 3);
	kernel_host_stencil_file.close();


	// invoke clockwork program
	unoptimized_conv2D_fp(
		bias_host_stencil_stream,
		input_host_stencil_stream,
		kernel_host_stencil_stream,
		hw_output_stencil_stream
	);

	// provision output buffer
	std::vector<bfloat16_t> hw_output_stencil_stream_tile(16*50*50);   idx=0;
	for (int l2 = 0; l2 < 50; l2++) {
	for (int l1 = 0; l1 < 50; l1++) {
	for (int l0 = 0; l0 < 16; l0++) {
		hw_uint<16> actual = hw_output_stencil_stream.read();
		int actual_lane = actual.extract<0, 15>();
		hw_output_stencil[((l2*800) + ((l1*16) + l0))] = bfloat16_t::make_from_bits(actual_lane);
		hw_output_stencil_stream_tile[idx] = hw_output_stencil[((l2*800) + ((l1*16) + l0))];  idx += 1;
	} } } 
	ofstream hw_output_file("bin/hw_output.leraw", ios::binary);
	hw_output_file.write(reinterpret_cast<const char *>(hw_output_stencil_stream_tile.data()),
		sizeof(hw_output_stencil_stream_tile[0]) * 16 * 50 * 50);
	hw_output_file.close();
	ofstream hw_output_header_file("bin/hw_output_header.txt", ios::binary);
	hw_output_header_file << "P5" << std::endl;
	hw_output_header_file << "16 50 50" << std::endl;
	hw_output_header_file << "65535" << std::endl;
	hw_output_header_file.close();
}

