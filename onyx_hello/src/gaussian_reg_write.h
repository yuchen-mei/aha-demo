

static void bitstream_glb_config()
{
HAL_Cgra_Glb_WriteReg(0xe8, 0x1);
HAL_Cgra_Glb_WriteReg(0xec, 0x0);
HAL_Cgra_Glb_WriteReg(0xf0, 0x258);
HAL_Cgra_Glb_WriteReg(0xf4, 0x14);
HAL_Cgra_Glb_WriteReg(0x1f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x2f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x3f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x4f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x5f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x6f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x7f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x8f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x9f4, 0x28);
HAL_Cgra_Glb_WriteReg(0xaf4, 0x28);
HAL_Cgra_Glb_WriteReg(0xbf4, 0x28);
}


static void app_glb_config()
{
HAL_Cgra_Glb_WriteReg(0x78, 0x21);
HAL_Cgra_Glb_WriteReg(0x7c, 0x1);
HAL_Cgra_Glb_WriteReg(0x80, 0x0);
HAL_Cgra_Glb_WriteReg(0x84, 0x0);
HAL_Cgra_Glb_WriteReg(0x88, 0x18be);
HAL_Cgra_Glb_WriteReg(0x90, 0x1);
HAL_Cgra_Glb_WriteReg(0x8c, 0x2);
HAL_Cgra_Glb_WriteReg(0x178, 0x21);
HAL_Cgra_Glb_WriteReg(0x17c, 0x1);
HAL_Cgra_Glb_WriteReg(0x180, 0x40000);
HAL_Cgra_Glb_WriteReg(0x184, 0x0);
HAL_Cgra_Glb_WriteReg(0x188, 0x18be);
HAL_Cgra_Glb_WriteReg(0x190, 0x1);
HAL_Cgra_Glb_WriteReg(0x18c, 0x2);
HAL_Cgra_Glb_WriteReg(0x10, 0x21);
HAL_Cgra_Glb_WriteReg(0x14, 0x1);
HAL_Cgra_Glb_WriteReg(0x18, 0x2);
HAL_Cgra_Glb_WriteReg(0x1c, 0x20000);
HAL_Cgra_Glb_WriteReg(0x20, 0x4a);
HAL_Cgra_Glb_WriteReg(0x24, 0x1d);
HAL_Cgra_Glb_WriteReg(0x2c, 0x1);
HAL_Cgra_Glb_WriteReg(0x28, 0x2);
HAL_Cgra_Glb_WriteReg(0x30, 0xc2);
HAL_Cgra_Glb_WriteReg(0x38, 0x2);
HAL_Cgra_Glb_WriteReg(0x34, 0x2);
HAL_Cgra_Glb_WriteReg(0x110, 0x21);
HAL_Cgra_Glb_WriteReg(0x114, 0x1);
HAL_Cgra_Glb_WriteReg(0x118, 0x2);
HAL_Cgra_Glb_WriteReg(0x11c, 0x60000);
HAL_Cgra_Glb_WriteReg(0x120, 0x4a);
HAL_Cgra_Glb_WriteReg(0x124, 0x1d);
HAL_Cgra_Glb_WriteReg(0x12c, 0x1);
HAL_Cgra_Glb_WriteReg(0x128, 0x2);
HAL_Cgra_Glb_WriteReg(0x130, 0xc2);
HAL_Cgra_Glb_WriteReg(0x138, 0x2);
HAL_Cgra_Glb_WriteReg(0x134, 0x2);

trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x78));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x7c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x80));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x84));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x88));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x90));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x8c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x178));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x17c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x180));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x184));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x188));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x190));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x18c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x10));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x14));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x18));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x1c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x20));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x24));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x2c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x28));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x30));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x38));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x34));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x110));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x114));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x118));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x11c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x120));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x124));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x12c));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x128));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x130));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x138));
trace_printf("glb reg read:%lx\n", HAL_Cgra_Glb_ReadReg(0x134));

}
