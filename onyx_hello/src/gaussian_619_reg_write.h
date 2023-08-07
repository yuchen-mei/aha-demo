

static void bitstream_glb_config()
{
HAL_Cgra_Glb_WriteReg(0xe8, 0x1);
HAL_Cgra_Glb_WriteReg(0xec, 0x0);
HAL_Cgra_Glb_WriteReg(0xf0, 0x1a2);
HAL_Cgra_Glb_WriteReg(0xf4, 0x14);
HAL_Cgra_Glb_WriteReg(0x1f4, 0x28);
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
HAL_Cgra_Glb_WriteReg(0x20, 0x4f);
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
HAL_Cgra_Glb_WriteReg(0x120, 0x4f);
HAL_Cgra_Glb_WriteReg(0x124, 0x1d);
HAL_Cgra_Glb_WriteReg(0x12c, 0x1);
HAL_Cgra_Glb_WriteReg(0x128, 0x2);
HAL_Cgra_Glb_WriteReg(0x130, 0xc2);
HAL_Cgra_Glb_WriteReg(0x138, 0x2);
HAL_Cgra_Glb_WriteReg(0x134, 0x2);
}
