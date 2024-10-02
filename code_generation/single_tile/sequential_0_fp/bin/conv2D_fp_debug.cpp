)
{
#pragma HLS DATAFLOW
#pragma HLS INLINE region
#pragma HLS INTERFACE s_axilite port=return bundle=config
#pragma HLS INTERFACE s_axilite port=arg_0 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_0.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_1 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_1.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_2 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_2.value complete dim=0
#pragma HLS INTERFACE s_axilite port=arg_3 bundle=config
#pragma HLS ARRAY_PARTITION variable=arg_3.value complete dim=0

 // alias the arguments
 Stencil<uint16_t, 16> &bias_host_stencil = arg_0;
 Stencil<bfloat16_t, 4, 101, 101> &input_host_stencil = arg_1;
 Stencil<bfloat16_t, 16, 4, 3, 3> &kernel_host_stencil = arg_2;
 Stencil<bfloat16_t, 16, 50, 50> &hw_output_stencil = arg_3;
[, ] // produce bias_glb.stencil
 for (int bias_glb_s0_w_w = 0; bias_glb_s0_w_w < 16; bias_glb_s0_w_w++)
 {
#pragma HLS PIPELINE II=1
  bfloat16_t _793 = _bias_host_stencil(_bias_glb_s0_w_w);
  _bias_glb_stencil(_bias_glb_s0_w_w) = _793;
 } // for bias_glb_s0_w_w
 // consume bias_glb.stencil
[, ], [, ], [, ] // produce input_glb.stencil
 for (int input_glb_s0_y = 0; input_glb_s0_y < 101; input_glb_s0_y++)
 {
  for (int input_glb_s0_x = 0; input_glb_s0_x < 101; input_glb_s0_x++)
  {
#pragma HLS PIPELINE II=1
   bfloat16_t _794 = _input_host_stencil(0, _input_glb_s0_x, _input_glb_s0_y);
   _input_glb_stencil(0, _input_glb_s0_x, _input_glb_s0_y) = _794;
   bfloat16_t _795 = _input_host_stencil(1, _input_glb_s0_x, _input_glb_s0_y);
   _input_glb_stencil(1, _input_glb_s0_x, _input_glb_s0_y) = _795;
   bfloat16_t _796 = _input_host_stencil(2, _input_glb_s0_x, _input_glb_s0_y);
   _input_glb_stencil(2, _input_glb_s0_x, _input_glb_s0_y) = _796;
   bfloat16_t _797 = _input_host_stencil(3, _input_glb_s0_x, _input_glb_s0_y);
   _input_glb_stencil(3, _input_glb_s0_x, _input_glb_s0_y) = _797;
  } // for input_glb_s0_x
 } // for input_glb_s0_y
 // consume input_glb.stencil
[, ], [, ], [, ], [, ] // produce kernel_glb.stencil
 for (int kernel_glb_s0_y = 0; kernel_glb_s0_y < 3; kernel_glb_s0_y++)
 {
  for (int kernel_glb_s0_x = 0; kernel_glb_s0_x < 3; kernel_glb_s0_x++)
  {
   for (int kernel_glb_s0_z = 0; kernel_glb_s0_z < 4; kernel_glb_s0_z++)
   {
    for (int kernel_glb_s0_w_w = 0; kernel_glb_s0_w_w < 4; kernel_glb_s0_w_w++)
    {
#pragma HLS PIPELINE II=1
     int32_t _798 = _kernel_glb_s0_w_w * 4;
     bfloat16_t _799 = _kernel_host_stencil(_798, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y);
     _kernel_glb_stencil(_798, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y) = _799;
     int32_t _800 = _kernel_glb_s0_w_w * 4;
     int32_t _801 = _800 + 1;
     bfloat16_t _802 = _kernel_host_stencil(_801, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y);
     _kernel_glb_stencil(_801, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y) = _802;
     int32_t _803 = _kernel_glb_s0_w_w * 4;
     int32_t _804 = _803 + 2;
     bfloat16_t _805 = _kernel_host_stencil(_804, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y);
     _kernel_glb_stencil(_804, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y) = _805;
     int32_t _806 = _kernel_glb_s0_w_w * 4;
     int32_t _807 = _806 + 3;
     bfloat16_t _808 = _kernel_host_stencil(_807, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y);
     _kernel_glb_stencil(_807, _kernel_glb_s0_z, _kernel_glb_s0_x, _kernel_glb_s0_y) = _808;
    } // for kernel_glb_s0_w_w
   } // for kernel_glb_s0_z
  } // for kernel_glb_s0_x
 } // for kernel_glb_s0_y
 // consume kernel_glb.stencil
[, ], [, ], [, ] // produce output_glb.stencil
 for (int output_glb_s0_y_y_glb = 0; output_glb_s0_y_y_glb < 2; output_glb_s0_y_y_glb++)
 {
  for (int output_glb_s0_y_y_cgra = 0; output_glb_s0_y_y_cgra < 25; output_glb_s0_y_y_cgra++)
  {
[, ], [, ], [, ]   // produce bias_cgra.stencil
   for (int bias_cgra_s0_x = 0; bias_cgra_s0_x < 50; bias_cgra_s0_x++)
   {
    for (int bias_cgra_s0_w_w_cgra_w_cgra = 0; bias_cgra_s0_w_w_cgra_w_cgra < 16; bias_cgra_s0_w_w_cgra_w_cgra++)
    {
#pragma HLS PIPELINE II=1
     bfloat16_t _809 = _bias_glb_stencil(_bias_cgra_s0_w_w_cgra_w_cgra);
     _bias_cgra_stencil(_bias_cgra_s0_w_w_cgra_w_cgra, _bias_cgra_s0_x, 0) = _809;
    } // for bias_cgra_s0_w_w_cgra_w_cgra
   } // for bias_cgra_s0_x
   // consume bias_cgra.stencil
[, ], [, ], [, ]   // produce output_cgra.stencil
   for (int output_cgra_s0_x = 0; output_cgra_s0_x < 50; output_cgra_s0_x++)
   {
#pragma HLS PIPELINE II=1
    bfloat16_t _810 = _bias_cgra_stencil(0, _output_cgra_s0_x, 0);
    _output_cgra_stencil(0, _output_cgra_s0_x, 0) = _810;
    bfloat16_t _811 = _bias_cgra_stencil(1, _output_cgra_s0_x, 0);
    _output_cgra_stencil(1, _output_cgra_s0_x, 0) = _811;
    bfloat16_t _812 = _bias_cgra_stencil(2, _output_cgra_s0_x, 0);
    _output_cgra_stencil(2, _output_cgra_s0_x, 0) = _812;
    bfloat16_t _813 = _bias_cgra_stencil(3, _output_cgra_s0_x, 0);
    _output_cgra_stencil(3, _output_cgra_s0_x, 0) = _813;
    bfloat16_t _814 = _bias_cgra_stencil(4, _output_cgra_s0_x, 0);
    _output_cgra_stencil(4, _output_cgra_s0_x, 0) = _814;
    bfloat16_t _815 = _bias_cgra_stencil(5, _output_cgra_s0_x, 0);
    _output_cgra_stencil(5, _output_cgra_s0_x, 0) = _815;
    bfloat16_t _816 = _bias_cgra_stencil(6, _output_cgra_s0_x, 0);
    _output_cgra_stencil(6, _output_cgra_s0_x, 0) = _816;
    bfloat16_t _817 = _bias_cgra_stencil(7, _output_cgra_s0_x, 0);
    _output_cgra_stencil(7, _output_cgra_s0_x, 0) = _817;
    bfloat16_t _818 = _bias_cgra_stencil(8, _output_cgra_s0_x, 0);
    _output_cgra_stencil(8, _output_cgra_s0_x, 0) = _818;
    bfloat16_t _819 = _bias_cgra_stencil(9, _output_cgra_s0_x, 0);
    _output_cgra_stencil(9, _output_cgra_s0_x, 0) = _819;
    bfloat16_t _820 = _bias_cgra_stencil(10, _output_cgra_s0_x, 0);
    _output_cgra_stencil(10, _output_cgra_s0_x, 0) = _820;
    bfloat16_t _821 = _bias_cgra_stencil(11, _output_cgra_s0_x, 0);
    _output_cgra_stencil(11, _output_cgra_s0_x, 0) = _821;
    bfloat16_t _822 = _bias_cgra_stencil(12, _output_cgra_s0_x, 0);
    _output_cgra_stencil(12, _output_cgra_s0_x, 0) = _822;
    bfloat16_t _823 = _bias_cgra_stencil(13, _output_cgra_s0_x, 0);
    _output_cgra_stencil(13, _output_cgra_s0_x, 0) = _823;
    bfloat16_t _824 = _bias_cgra_stencil(14, _output_cgra_s0_x, 0);
    _output_cgra_stencil(14, _output_cgra_s0_x, 0) = _824;
    bfloat16_t _825 = _bias_cgra_stencil(15, _output_cgra_s0_x, 0);
    _output_cgra_stencil(15, _output_cgra_s0_x, 0) = _825;
   } // for output_cgra_s0_x
[, ], [, ], [, ]   // produce input_cgra.stencil
   int32_t _826 = _output_glb_s0_y_y_glb * 25;
   int32_t _827 = _output_glb_s0_y_y_cgra + _826;
   int32_t _828 = _827 * 2;
   for (int input_cgra_s0_y = 0; input_cgra_s0_y < 3; input_cgra_s0_y++)
   {
    for (int input_cgra_s0_x = 0; input_cgra_s0_x < 101; input_cgra_s0_x++)
    {
#pragma HLS PIPELINE II=1
     int32_t _829 = _output_glb_s0_y_y_glb * 25;
     int32_t _830 = _829 + _output_glb_s0_y_y_cgra;
     int32_t _831 = _830 * 2;
     int32_t _832 = _831 + _input_cgra_s0_y;
     int32_t _833 = _832 - _831;
     bfloat16_t _834 = _input_glb_stencil(0, _input_cgra_s0_x, _832);
     _input_cgra_stencil(0, _input_cgra_s0_x, _833) = _834;
     int32_t _835 = _output_glb_s0_y_y_glb * 25;
     int32_t _836 = _835 + _output_glb_s0_y_y_cgra;
     int32_t _837 = _836 * 2;
     int32_t _838 = _837 + _input_cgra_s0_y;
     int32_t _839 = _838 - _837;
     bfloat16_t _840 = _input_glb_stencil(1, _input_cgra_s0_x, _838);
     _input_cgra_stencil(1, _input_cgra_s0_x, _839) = _840;
     int32_t _841 = _output_glb_s0_y_y_glb * 25;
     int32_t _842 = _841 + _output_glb_s0_y_y_cgra;
     int32_t _843 = _842 * 2;
     int32_t _844 = _843 + _input_cgra_s0_y;
     int32_t _845 = _844 - _843;
     bfloat16_t _846 = _input_glb_stencil(2, _input_cgra_s0_x, _844);
     _input_cgra_stencil(2, _input_cgra_s0_x, _845) = _846;
     int32_t _847 = _output_glb_s0_y_y_glb * 25;
     int32_t _848 = _847 + _output_glb_s0_y_y_cgra;
     int32_t _849 = _848 * 2;
     int32_t _850 = _849 + _input_cgra_s0_y;
     int32_t _851 = _850 - _849;
     bfloat16_t _852 = _input_glb_stencil(3, _input_cgra_s0_x, _850);
     _input_cgra_stencil(3, _input_cgra_s0_x, _851) = _852;
    } // for input_cgra_s0_x
   } // for input_cgra_s0_y
   // consume input_cgra.stencil
[, ], [, ], [, ], [, ]   // produce kernel_cgra.stencil
   for (int kernel_cgra_s0_y = 0; kernel_cgra_s0_y < 3; kernel_cgra_s0_y++)
   {
    for (int kernel_cgra_s0_x = 0; kernel_cgra_s0_x < 3; kernel_cgra_s0_x++)
    {
     for (int kernel_cgra_s0_z_z_cgra = 0; kernel_cgra_s0_z_z_cgra < 4; kernel_cgra_s0_z_z_cgra++)
     {
      for (int kernel_cgra_s0_w_w_cgra_w_cgra = 0; kernel_cgra_s0_w_w_cgra_w_cgra < 4; kernel_cgra_s0_w_w_cgra_w_cgra++)
      {
#pragma HLS PIPELINE II=1
       int32_t _853 = _kernel_cgra_s0_w_w_cgra_w_cgra * 4;
       bfloat16_t _854 = _kernel_glb_stencil(_853, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y);
       _kernel_cgra_stencil(_853, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y) = _854;
       int32_t _855 = _kernel_cgra_s0_w_w_cgra_w_cgra * 4;
       int32_t _856 = _855 + 1;
       bfloat16_t _857 = _kernel_glb_stencil(_856, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y);
       _kernel_cgra_stencil(_856, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y) = _857;
       int32_t _858 = _kernel_cgra_s0_w_w_cgra_w_cgra * 4;
       int32_t _859 = _858 + 2;
       bfloat16_t _860 = _kernel_glb_stencil(_859, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y);
       _kernel_cgra_stencil(_859, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y) = _860;
       int32_t _861 = _kernel_cgra_s0_w_w_cgra_w_cgra * 4;
       int32_t _862 = _861 + 3;
       bfloat16_t _863 = _kernel_glb_stencil(_862, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y);
       _kernel_cgra_stencil(_862, _kernel_cgra_s0_z_z_cgra, _kernel_cgra_s0_x, _kernel_cgra_s0_y) = _863;
      } // for kernel_cgra_s0_w_w_cgra_w_cgra
     } // for kernel_cgra_s0_z_z_cgra
    } // for kernel_cgra_s0_x
   } // for kernel_cgra_s0_y
   // consume kernel_cgra.stencil
   for (int output_cgra_s1_r_y = 0; output_cgra_s1_r_y < 3; output_cgra_s1_r_y++)
   {
    for (int output_cgra_s1_r_x = 0; output_cgra_s1_r_x < 3; output_cgra_s1_r_x++)
    {
     for (int output_cgra_s1_x = 0; output_cgra_s1_x < 50; output_cgra_s1_x++)
     {
#pragma HLS PIPELINE II=1
      bfloat16_t _880 = _kernel_cgra_stencil(0, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _881 = _output_cgra_s1_x * 2;
      int32_t _882 = _881 + _output_cgra_s1_r_x;
      bfloat16_t _883 = _input_cgra_stencil(3, _882, _output_cgra_s1_r_y);
      bfloat16_t _884 = _880 * _883;
      bfloat16_t _885 = _kernel_cgra_stencil(0, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _886 = _input_cgra_stencil(2, _882, _output_cgra_s1_r_y);
      bfloat16_t _887 = _885 * _886;
      bfloat16_t _888 = _kernel_cgra_stencil(0, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _889 = _input_cgra_stencil(1, _882, _output_cgra_s1_r_y);
      bfloat16_t _890 = _888 * _889;
      bfloat16_t _891 = _output_cgra_stencil(0, _output_cgra_s1_x, 0);
      bfloat16_t _892 = _kernel_cgra_stencil(0, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _893 = _input_cgra_stencil(0, _882, _output_cgra_s1_r_y);
      bfloat16_t _894 = _892 * _893;
      bfloat16_t _895 = _891 + _894;
      bfloat16_t _896 = _890 + _895;
      bfloat16_t _897 = _887 + _896;
      bfloat16_t _898 = _884 + _897;
      _output_cgra_stencil(0, _output_cgra_s1_x, 0) = _898;
      bfloat16_t _915 = _kernel_cgra_stencil(1, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _916 = _output_cgra_s1_x * 2;
      int32_t _917 = _916 + _output_cgra_s1_r_x;
      bfloat16_t _918 = _input_cgra_stencil(3, _917, _output_cgra_s1_r_y);
      bfloat16_t _919 = _915 * _918;
      bfloat16_t _920 = _kernel_cgra_stencil(1, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _921 = _input_cgra_stencil(2, _917, _output_cgra_s1_r_y);
      bfloat16_t _922 = _920 * _921;
      bfloat16_t _923 = _kernel_cgra_stencil(1, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _924 = _input_cgra_stencil(1, _917, _output_cgra_s1_r_y);
      bfloat16_t _925 = _923 * _924;
      bfloat16_t _926 = _output_cgra_stencil(1, _output_cgra_s1_x, 0);
      bfloat16_t _927 = _kernel_cgra_stencil(1, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _928 = _input_cgra_stencil(0, _917, _output_cgra_s1_r_y);
      bfloat16_t _929 = _927 * _928;
      bfloat16_t _930 = _926 + _929;
      bfloat16_t _931 = _925 + _930;
      bfloat16_t _932 = _922 + _931;
      bfloat16_t _933 = _919 + _932;
      _output_cgra_stencil(1, _output_cgra_s1_x, 0) = _933;
      bfloat16_t _950 = _kernel_cgra_stencil(2, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _951 = _output_cgra_s1_x * 2;
      int32_t _952 = _951 + _output_cgra_s1_r_x;
      bfloat16_t _953 = _input_cgra_stencil(3, _952, _output_cgra_s1_r_y);
      bfloat16_t _954 = _950 * _953;
      bfloat16_t _955 = _kernel_cgra_stencil(2, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _956 = _input_cgra_stencil(2, _952, _output_cgra_s1_r_y);
      bfloat16_t _957 = _955 * _956;
      bfloat16_t _958 = _kernel_cgra_stencil(2, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _959 = _input_cgra_stencil(1, _952, _output_cgra_s1_r_y);
      bfloat16_t _960 = _958 * _959;
      bfloat16_t _961 = _output_cgra_stencil(2, _output_cgra_s1_x, 0);
      bfloat16_t _962 = _kernel_cgra_stencil(2, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _963 = _input_cgra_stencil(0, _952, _output_cgra_s1_r_y);
      bfloat16_t _964 = _962 * _963;
      bfloat16_t _965 = _961 + _964;
      bfloat16_t _966 = _960 + _965;
      bfloat16_t _967 = _957 + _966;
      bfloat16_t _968 = _954 + _967;
      _output_cgra_stencil(2, _output_cgra_s1_x, 0) = _968;
      bfloat16_t _985 = _kernel_cgra_stencil(3, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _986 = _output_cgra_s1_x * 2;
      int32_t _987 = _986 + _output_cgra_s1_r_x;
      bfloat16_t _988 = _input_cgra_stencil(3, _987, _output_cgra_s1_r_y);
      bfloat16_t _989 = _985 * _988;
      bfloat16_t _990 = _kernel_cgra_stencil(3, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _991 = _input_cgra_stencil(2, _987, _output_cgra_s1_r_y);
      bfloat16_t _992 = _990 * _991;
      bfloat16_t _993 = _kernel_cgra_stencil(3, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _994 = _input_cgra_stencil(1, _987, _output_cgra_s1_r_y);
      bfloat16_t _995 = _993 * _994;
      bfloat16_t _996 = _output_cgra_stencil(3, _output_cgra_s1_x, 0);
      bfloat16_t _997 = _kernel_cgra_stencil(3, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _998 = _input_cgra_stencil(0, _987, _output_cgra_s1_r_y);
      bfloat16_t _999 = _997 * _998;
      bfloat16_t _1000 = _996 + _999;
      bfloat16_t _1001 = _995 + _1000;
      bfloat16_t _1002 = _992 + _1001;
      bfloat16_t _1003 = _989 + _1002;
      _output_cgra_stencil(3, _output_cgra_s1_x, 0) = _1003;
      bfloat16_t _1020 = _kernel_cgra_stencil(4, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1021 = _output_cgra_s1_x * 2;
      int32_t _1022 = _1021 + _output_cgra_s1_r_x;
      bfloat16_t _1023 = _input_cgra_stencil(3, _1022, _output_cgra_s1_r_y);
      bfloat16_t _1024 = _1020 * _1023;
      bfloat16_t _1025 = _kernel_cgra_stencil(4, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1026 = _input_cgra_stencil(2, _1022, _output_cgra_s1_r_y);
      bfloat16_t _1027 = _1025 * _1026;
      bfloat16_t _1028 = _kernel_cgra_stencil(4, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1029 = _input_cgra_stencil(1, _1022, _output_cgra_s1_r_y);
      bfloat16_t _1030 = _1028 * _1029;
      bfloat16_t _1031 = _output_cgra_stencil(4, _output_cgra_s1_x, 0);
      bfloat16_t _1032 = _kernel_cgra_stencil(4, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1033 = _input_cgra_stencil(0, _1022, _output_cgra_s1_r_y);
      bfloat16_t _1034 = _1032 * _1033;
      bfloat16_t _1035 = _1031 + _1034;
      bfloat16_t _1036 = _1030 + _1035;
      bfloat16_t _1037 = _1027 + _1036;
      bfloat16_t _1038 = _1024 + _1037;
      _output_cgra_stencil(4, _output_cgra_s1_x, 0) = _1038;
      bfloat16_t _1055 = _kernel_cgra_stencil(5, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1056 = _output_cgra_s1_x * 2;
      int32_t _1057 = _1056 + _output_cgra_s1_r_x;
      bfloat16_t _1058 = _input_cgra_stencil(3, _1057, _output_cgra_s1_r_y);
      bfloat16_t _1059 = _1055 * _1058;
      bfloat16_t _1060 = _kernel_cgra_stencil(5, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1061 = _input_cgra_stencil(2, _1057, _output_cgra_s1_r_y);
      bfloat16_t _1062 = _1060 * _1061;
      bfloat16_t _1063 = _kernel_cgra_stencil(5, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1064 = _input_cgra_stencil(1, _1057, _output_cgra_s1_r_y);
      bfloat16_t _1065 = _1063 * _1064;
      bfloat16_t _1066 = _output_cgra_stencil(5, _output_cgra_s1_x, 0);
      bfloat16_t _1067 = _kernel_cgra_stencil(5, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1068 = _input_cgra_stencil(0, _1057, _output_cgra_s1_r_y);
      bfloat16_t _1069 = _1067 * _1068;
      bfloat16_t _1070 = _1066 + _1069;
      bfloat16_t _1071 = _1065 + _1070;
      bfloat16_t _1072 = _1062 + _1071;
      bfloat16_t _1073 = _1059 + _1072;
      _output_cgra_stencil(5, _output_cgra_s1_x, 0) = _1073;
      bfloat16_t _1090 = _kernel_cgra_stencil(6, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1091 = _output_cgra_s1_x * 2;
      int32_t _1092 = _1091 + _output_cgra_s1_r_x;
      bfloat16_t _1093 = _input_cgra_stencil(3, _1092, _output_cgra_s1_r_y);
      bfloat16_t _1094 = _1090 * _1093;
      bfloat16_t _1095 = _kernel_cgra_stencil(6, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1096 = _input_cgra_stencil(2, _1092, _output_cgra_s1_r_y);
      bfloat16_t _1097 = _1095 * _1096;
      bfloat16_t _1098 = _kernel_cgra_stencil(6, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1099 = _input_cgra_stencil(1, _1092, _output_cgra_s1_r_y);
      bfloat16_t _1100 = _1098 * _1099;
      bfloat16_t _1101 = _output_cgra_stencil(6, _output_cgra_s1_x, 0);
      bfloat16_t _1102 = _kernel_cgra_stencil(6, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1103 = _input_cgra_stencil(0, _1092, _output_cgra_s1_r_y);
      bfloat16_t _1104 = _1102 * _1103;
      bfloat16_t _1105 = _1101 + _1104;
      bfloat16_t _1106 = _1100 + _1105;
      bfloat16_t _1107 = _1097 + _1106;
      bfloat16_t _1108 = _1094 + _1107;
      _output_cgra_stencil(6, _output_cgra_s1_x, 0) = _1108;
      bfloat16_t _1125 = _kernel_cgra_stencil(7, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1126 = _output_cgra_s1_x * 2;
      int32_t _1127 = _1126 + _output_cgra_s1_r_x;
      bfloat16_t _1128 = _input_cgra_stencil(3, _1127, _output_cgra_s1_r_y);
      bfloat16_t _1129 = _1125 * _1128;
      bfloat16_t _1130 = _kernel_cgra_stencil(7, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1131 = _input_cgra_stencil(2, _1127, _output_cgra_s1_r_y);
      bfloat16_t _1132 = _1130 * _1131;
      bfloat16_t _1133 = _kernel_cgra_stencil(7, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1134 = _input_cgra_stencil(1, _1127, _output_cgra_s1_r_y);
      bfloat16_t _1135 = _1133 * _1134;
      bfloat16_t _1136 = _output_cgra_stencil(7, _output_cgra_s1_x, 0);
      bfloat16_t _1137 = _kernel_cgra_stencil(7, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1138 = _input_cgra_stencil(0, _1127, _output_cgra_s1_r_y);
      bfloat16_t _1139 = _1137 * _1138;
      bfloat16_t _1140 = _1136 + _1139;
      bfloat16_t _1141 = _1135 + _1140;
      bfloat16_t _1142 = _1132 + _1141;
      bfloat16_t _1143 = _1129 + _1142;
      _output_cgra_stencil(7, _output_cgra_s1_x, 0) = _1143;
      bfloat16_t _1160 = _kernel_cgra_stencil(8, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1161 = _output_cgra_s1_x * 2;
      int32_t _1162 = _1161 + _output_cgra_s1_r_x;
      bfloat16_t _1163 = _input_cgra_stencil(3, _1162, _output_cgra_s1_r_y);
      bfloat16_t _1164 = _1160 * _1163;
      bfloat16_t _1165 = _kernel_cgra_stencil(8, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1166 = _input_cgra_stencil(2, _1162, _output_cgra_s1_r_y);
      bfloat16_t _1167 = _1165 * _1166;
      bfloat16_t _1168 = _kernel_cgra_stencil(8, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1169 = _input_cgra_stencil(1, _1162, _output_cgra_s1_r_y);
      bfloat16_t _1170 = _1168 * _1169;
      bfloat16_t _1171 = _output_cgra_stencil(8, _output_cgra_s1_x, 0);
      bfloat16_t _1172 = _kernel_cgra_stencil(8, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1173 = _input_cgra_stencil(0, _1162, _output_cgra_s1_r_y);
      bfloat16_t _1174 = _1172 * _1173;
      bfloat16_t _1175 = _1171 + _1174;
      bfloat16_t _1176 = _1170 + _1175;
      bfloat16_t _1177 = _1167 + _1176;
      bfloat16_t _1178 = _1164 + _1177;
      _output_cgra_stencil(8, _output_cgra_s1_x, 0) = _1178;
      bfloat16_t _1195 = _kernel_cgra_stencil(9, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1196 = _output_cgra_s1_x * 2;
      int32_t _1197 = _1196 + _output_cgra_s1_r_x;
      bfloat16_t _1198 = _input_cgra_stencil(3, _1197, _output_cgra_s1_r_y);
      bfloat16_t _1199 = _1195 * _1198;
      bfloat16_t _1200 = _kernel_cgra_stencil(9, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1201 = _input_cgra_stencil(2, _1197, _output_cgra_s1_r_y);
      bfloat16_t _1202 = _1200 * _1201;
      bfloat16_t _1203 = _kernel_cgra_stencil(9, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1204 = _input_cgra_stencil(1, _1197, _output_cgra_s1_r_y);
      bfloat16_t _1205 = _1203 * _1204;
      bfloat16_t _1206 = _output_cgra_stencil(9, _output_cgra_s1_x, 0);
      bfloat16_t _1207 = _kernel_cgra_stencil(9, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1208 = _input_cgra_stencil(0, _1197, _output_cgra_s1_r_y);
      bfloat16_t _1209 = _1207 * _1208;
      bfloat16_t _1210 = _1206 + _1209;
      bfloat16_t _1211 = _1205 + _1210;
      bfloat16_t _1212 = _1202 + _1211;
      bfloat16_t _1213 = _1199 + _1212;
      _output_cgra_stencil(9, _output_cgra_s1_x, 0) = _1213;
      bfloat16_t _1230 = _kernel_cgra_stencil(10, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1231 = _output_cgra_s1_x * 2;
      int32_t _1232 = _1231 + _output_cgra_s1_r_x;
      bfloat16_t _1233 = _input_cgra_stencil(3, _1232, _output_cgra_s1_r_y);
      bfloat16_t _1234 = _1230 * _1233;
      bfloat16_t _1235 = _kernel_cgra_stencil(10, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1236 = _input_cgra_stencil(2, _1232, _output_cgra_s1_r_y);
      bfloat16_t _1237 = _1235 * _1236;
      bfloat16_t _1238 = _kernel_cgra_stencil(10, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1239 = _input_cgra_stencil(1, _1232, _output_cgra_s1_r_y);
      bfloat16_t _1240 = _1238 * _1239;
      bfloat16_t _1241 = _output_cgra_stencil(10, _output_cgra_s1_x, 0);
      bfloat16_t _1242 = _kernel_cgra_stencil(10, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1243 = _input_cgra_stencil(0, _1232, _output_cgra_s1_r_y);
      bfloat16_t _1244 = _1242 * _1243;
      bfloat16_t _1245 = _1241 + _1244;
      bfloat16_t _1246 = _1240 + _1245;
      bfloat16_t _1247 = _1237 + _1246;
      bfloat16_t _1248 = _1234 + _1247;
      _output_cgra_stencil(10, _output_cgra_s1_x, 0) = _1248;
      bfloat16_t _1265 = _kernel_cgra_stencil(11, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1266 = _output_cgra_s1_x * 2;
      int32_t _1267 = _1266 + _output_cgra_s1_r_x;
      bfloat16_t _1268 = _input_cgra_stencil(3, _1267, _output_cgra_s1_r_y);
      bfloat16_t _1269 = _1265 * _1268;
      bfloat16_t _1270 = _kernel_cgra_stencil(11, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1271 = _input_cgra_stencil(2, _1267, _output_cgra_s1_r_y);
      bfloat16_t _1272 = _1270 * _1271;
      bfloat16_t _1273 = _kernel_cgra_stencil(11, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1274 = _input_cgra_stencil(1, _1267, _output_cgra_s1_r_y);
      bfloat16_t _1275 = _1273 * _1274;
      bfloat16_t _1276 = _output_cgra_stencil(11, _output_cgra_s1_x, 0);
      bfloat16_t _1277 = _kernel_cgra_stencil(11, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1278 = _input_cgra_stencil(0, _1267, _output_cgra_s1_r_y);
      bfloat16_t _1279 = _1277 * _1278;
      bfloat16_t _1280 = _1276 + _1279;
      bfloat16_t _1281 = _1275 + _1280;
      bfloat16_t _1282 = _1272 + _1281;
      bfloat16_t _1283 = _1269 + _1282;
      _output_cgra_stencil(11, _output_cgra_s1_x, 0) = _1283;
      bfloat16_t _1300 = _kernel_cgra_stencil(12, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1301 = _output_cgra_s1_x * 2;
      int32_t _1302 = _1301 + _output_cgra_s1_r_x;
      bfloat16_t _1303 = _input_cgra_stencil(3, _1302, _output_cgra_s1_r_y);
      bfloat16_t _1304 = _1300 * _1303;
      bfloat16_t _1305 = _kernel_cgra_stencil(12, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1306 = _input_cgra_stencil(2, _1302, _output_cgra_s1_r_y);
      bfloat16_t _1307 = _1305 * _1306;
      bfloat16_t _1308 = _kernel_cgra_stencil(12, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1309 = _input_cgra_stencil(1, _1302, _output_cgra_s1_r_y);
      bfloat16_t _1310 = _1308 * _1309;
      bfloat16_t _1311 = _output_cgra_stencil(12, _output_cgra_s1_x, 0);
      bfloat16_t _1312 = _kernel_cgra_stencil(12, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1313 = _input_cgra_stencil(0, _1302, _output_cgra_s1_r_y);
      bfloat16_t _1314 = _1312 * _1313;
      bfloat16_t _1315 = _1311 + _1314;
      bfloat16_t _1316 = _1310 + _1315;
      bfloat16_t _1317 = _1307 + _1316;
      bfloat16_t _1318 = _1304 + _1317;
      _output_cgra_stencil(12, _output_cgra_s1_x, 0) = _1318;
      bfloat16_t _1335 = _kernel_cgra_stencil(13, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1336 = _output_cgra_s1_x * 2;
      int32_t _1337 = _1336 + _output_cgra_s1_r_x;
      bfloat16_t _1338 = _input_cgra_stencil(3, _1337, _output_cgra_s1_r_y);
      bfloat16_t _1339 = _1335 * _1338;
      bfloat16_t _1340 = _kernel_cgra_stencil(13, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1341 = _input_cgra_stencil(2, _1337, _output_cgra_s1_r_y);
      bfloat16_t _1342 = _1340 * _1341;
      bfloat16_t _1343 = _kernel_cgra_stencil(13, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1344 = _input_cgra_stencil(1, _1337, _output_cgra_s1_r_y);
      bfloat16_t _1345 = _1343 * _1344;
      bfloat16_t _1346 = _output_cgra_stencil(13, _output_cgra_s1_x, 0);
      bfloat16_t _1347 = _kernel_cgra_stencil(13, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1348 = _input_cgra_stencil(0, _1337, _output_cgra_s1_r_y);
      bfloat16_t _1349 = _1347 * _1348;
      bfloat16_t _1350 = _1346 + _1349;
      bfloat16_t _1351 = _1345 + _1350;
      bfloat16_t _1352 = _1342 + _1351;
      bfloat16_t _1353 = _1339 + _1352;
      _output_cgra_stencil(13, _output_cgra_s1_x, 0) = _1353;
      bfloat16_t _1370 = _kernel_cgra_stencil(14, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1371 = _output_cgra_s1_x * 2;
      int32_t _1372 = _1371 + _output_cgra_s1_r_x;
      bfloat16_t _1373 = _input_cgra_stencil(3, _1372, _output_cgra_s1_r_y);
      bfloat16_t _1374 = _1370 * _1373;
      bfloat16_t _1375 = _kernel_cgra_stencil(14, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1376 = _input_cgra_stencil(2, _1372, _output_cgra_s1_r_y);
      bfloat16_t _1377 = _1375 * _1376;
      bfloat16_t _1378 = _kernel_cgra_stencil(14, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1379 = _input_cgra_stencil(1, _1372, _output_cgra_s1_r_y);
      bfloat16_t _1380 = _1378 * _1379;
      bfloat16_t _1381 = _output_cgra_stencil(14, _output_cgra_s1_x, 0);
      bfloat16_t _1382 = _kernel_cgra_stencil(14, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1383 = _input_cgra_stencil(0, _1372, _output_cgra_s1_r_y);
      bfloat16_t _1384 = _1382 * _1383;
      bfloat16_t _1385 = _1381 + _1384;
      bfloat16_t _1386 = _1380 + _1385;
      bfloat16_t _1387 = _1377 + _1386;
      bfloat16_t _1388 = _1374 + _1387;
      _output_cgra_stencil(14, _output_cgra_s1_x, 0) = _1388;
      bfloat16_t _1405 = _kernel_cgra_stencil(15, 3, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      int32_t _1406 = _output_cgra_s1_x * 2;
      int32_t _1407 = _1406 + _output_cgra_s1_r_x;
      bfloat16_t _1408 = _input_cgra_stencil(3, _1407, _output_cgra_s1_r_y);
      bfloat16_t _1409 = _1405 * _1408;
      bfloat16_t _1410 = _kernel_cgra_stencil(15, 2, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1411 = _input_cgra_stencil(2, _1407, _output_cgra_s1_r_y);
      bfloat16_t _1412 = _1410 * _1411;
      bfloat16_t _1413 = _kernel_cgra_stencil(15, 1, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1414 = _input_cgra_stencil(1, _1407, _output_cgra_s1_r_y);
      bfloat16_t _1415 = _1413 * _1414;
      bfloat16_t _1416 = _output_cgra_stencil(15, _output_cgra_s1_x, 0);
      bfloat16_t _1417 = _kernel_cgra_stencil(15, 0, _output_cgra_s1_r_x, _output_cgra_s1_r_y);
      bfloat16_t _1418 = _input_cgra_stencil(0, _1407, _output_cgra_s1_r_y);
      bfloat16_t _1419 = _1417 * _1418;
      bfloat16_t _1420 = _1416 + _1419;
      bfloat16_t _1421 = _1415 + _1420;
      bfloat16_t _1422 = _1412 + _1421;
      bfloat16_t _1423 = _1409 + _1422;
      _output_cgra_stencil(15, _output_cgra_s1_x, 0) = _1423;
     } // for output_cgra_s1_x
    } // for output_cgra_s1_r_x
   } // for output_cgra_s1_r_y
   // consume output_cgra.stencil
   for (int output_glb_s0_x_x_glb = 0; output_glb_s0_x_x_glb < 2; output_glb_s0_x_x_glb++)
   {
    for (int output_glb_s0_x_x_cgra = 0; output_glb_s0_x_x_cgra < 25; output_glb_s0_x_x_cgra++)
    {
     for (int output_glb_s0_w_w_cgra_w_cgra = 0; output_glb_s0_w_w_cgra_w_cgra < 4; output_glb_s0_w_w_cgra_w_cgra++)
     {
#pragma HLS PIPELINE II=1
      int32_t _1432 = _output_glb_s0_w_w_cgra_w_cgra * 4;
      int32_t _1433 = _output_glb_s0_x_x_glb * 25;
      int32_t _1434 = _1433 + _output_glb_s0_x_x_cgra;
      int32_t _1435 = _output_glb_s0_y_y_glb * 25;
      int32_t _1436 = _1435 + _output_glb_s0_y_y_cgra;
      bfloat16_t _1437 = _output_cgra_stencil(_1432, _1434, 0);
      bfloat16_t _1438 = bfloat_from_bits(1086324736 /* 6 */);
      bfloat16_t _1439 = ::halide_cpp_min(_1437, _1438);
      bfloat16_t _1440 = bfloat_from_bits(0 /* 0 */);
      bfloat16_t _1441 = ::halide_cpp_max(_1439, _1440);
      _output_glb_stencil(_1432, _1434, _1436) = _1441;
      int32_t _1450 = _output_glb_s0_w_w_cgra_w_cgra * 4;
      int32_t _1451 = _1450 + 1;
      int32_t _1452 = _output_glb_s0_x_x_glb * 25;
      int32_t _1453 = _1452 + _output_glb_s0_x_x_cgra;
      int32_t _1454 = _output_glb_s0_y_y_glb * 25;
      int32_t _1455 = _1454 + _output_glb_s0_y_y_cgra;
      bfloat16_t _1456 = _output_cgra_stencil(_1451, _1453, 0);
      bfloat16_t _1457 = bfloat_from_bits(1086324736 /* 6 */);
      bfloat16_t _1458 = ::halide_cpp_min(_1456, _1457);
      bfloat16_t _1459 = bfloat_from_bits(0 /* 0 */);
      bfloat16_t _1460 = ::halide_cpp_max(_1458, _1459);
      _output_glb_stencil(_1451, _1453, _1455) = _1460;
      int32_t _1469 = _output_glb_s0_w_w_cgra_w_cgra * 4;
      int32_t _1470 = _1469 + 2;
      int32_t _1471 = _output_glb_s0_x_x_glb * 25;
      int32_t _1472 = _1471 + _output_glb_s0_x_x_cgra;
      int32_t _1473 = _output_glb_s0_y_y_glb * 25;
      int32_t _1474 = _1473 + _output_glb_s0_y_y_cgra;
      bfloat16_t _1475 = _output_cgra_stencil(_1470, _1472, 0);
      bfloat16_t _1476 = bfloat_from_bits(1086324736 /* 6 */);
      bfloat16_t _1477 = ::halide_cpp_min(_1475, _1476);
      bfloat16_t _1478 = bfloat_from_bits(0 /* 0 */);
      bfloat16_t _1479 = ::halide_cpp_max(_1477, _1478);
      _output_glb_stencil(_1470, _1472, _1474) = _1479;
      int32_t _1488 = _output_glb_s0_w_w_cgra_w_cgra * 4;
      int32_t _1489 = _1488 + 3;
      int32_t _1490 = _output_glb_s0_x_x_glb * 25;
      int32_t _1491 = _1490 + _output_glb_s0_x_x_cgra;
      int32_t _1492 = _output_glb_s0_y_y_glb * 25;
      int32_t _1493 = _1492 + _output_glb_s0_y_y_cgra;
      bfloat16_t _1494 = _output_cgra_stencil(_1489, _1491, 0);
      bfloat16_t _1495 = bfloat_from_bits(1086324736 /* 6 */);
      bfloat16_t _1496 = ::halide_cpp_min(_1494, _1495);
      bfloat16_t _1497 = bfloat_from_bits(0 /* 0 */);
      bfloat16_t _1498 = ::halide_cpp_max(_1496, _1497);
      _output_glb_stencil(_1489, _1491, _1493) = _1498;
     } // for output_glb_s0_w_w_cgra_w_cgra
    } // for output_glb_s0_x_x_cgra
   } // for output_glb_s0_x_x_glb
  } // for output_glb_s0_y_y_cgra
 } // for output_glb_s0_y_y_glb
 // consume output_glb.stencil
 for (int hw_output_s0_y_yi = 0; hw_output_s0_y_yi < 50; hw_output_s0_y_yi++)
 {
  for (int hw_output_s0_x_xi = 0; hw_output_s0_x_xi < 50; hw_output_s0_x_xi++)
  {
   for (int hw_output_s0_w_w = 0; hw_output_s0_w_w < 4; hw_output_s0_w_w++)
   {
#pragma HLS PIPELINE II=1
    int32_t _1499 = _hw_output_s0_w_w * 4;
    bfloat16_t _1500 = _output_glb_stencil(_1499, _hw_output_s0_x_xi, _hw_output_s0_y_yi);
    _hw_output_stencil(_1499, _hw_output_s0_x_xi, _hw_output_s0_y_yi) = _1500;
    int32_t _1501 = _hw_output_s0_w_w * 4;
    int32_t _1502 = _1501 + 1;
    bfloat16_t _1503 = _output_glb_stencil(_1502, _hw_output_s0_x_xi, _hw_output_s0_y_yi);
    _hw_output_stencil(_1502, _hw_output_s0_x_xi, _hw_output_s0_y_yi) = _1503;
    int32_t _1504 = _hw_output_s0_w_w * 4;
    int32_t _1505 = _1504 + 2;
    bfloat16_t _1506 = _output_glb_stencil(_1505, _hw_output_s0_x_xi, _hw_output_s0_y_yi);
    _hw_output_stencil(_1505, _hw_output_s0_x_xi, _hw_output_s0_y_yi) = _1506;
    int32_t _1507 = _hw_output_s0_w_w * 4;
    int32_t _1508 = _1507 + 3;
    bfloat16_t _1509 = _output_glb_stencil(_1508, _hw_output_s0_x_xi, _hw_output_s0_y_yi);
    _hw_output_stencil(_1508, _hw_output_s0_x_xi, _hw_output_s0_y_yi) = _1509;
   } // for hw_output_s0_w_w
  } // for hw_output_s0_x_xi
 } // for hw_output_s0_y_yi
} // kernel hls_targetconv2D_fp

