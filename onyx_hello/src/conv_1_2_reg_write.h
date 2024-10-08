

static void bitstream_glb_config()
{
HAL_Cgra_Glb_WriteReg(0xe8, 0x1);
HAL_Cgra_Glb_WriteReg(0xec, 0x0);
HAL_Cgra_Glb_WriteReg(0xf0, 0x39);
HAL_Cgra_Glb_WriteReg(0xf4, 0x14);
HAL_Cgra_Glb_WriteReg(0x8f4, 0x28);
}


static void app_glb_config()
{
HAL_Cgra_Glb_WriteReg(0x78, 0x21);
HAL_Cgra_Glb_WriteReg(0x7c, 0x1);
HAL_Cgra_Glb_WriteReg(0x80, 0x0);
HAL_Cgra_Glb_WriteReg(0x84, 0x0);
HAL_Cgra_Glb_WriteReg(0x88, 0xffe);
HAL_Cgra_Glb_WriteReg(0x90, 0x1);
HAL_Cgra_Glb_WriteReg(0x8c, 0x2);
HAL_Cgra_Glb_WriteReg(0x10, 0x21);
HAL_Cgra_Glb_WriteReg(0x14, 0x1);
HAL_Cgra_Glb_WriteReg(0x18, 0x2);
HAL_Cgra_Glb_WriteReg(0x1c, 0x20000);
HAL_Cgra_Glb_WriteReg(0x20, 0x7);
HAL_Cgra_Glb_WriteReg(0x24, 0x3d);
HAL_Cgra_Glb_WriteReg(0x2c, 0x1);
HAL_Cgra_Glb_WriteReg(0x28, 0x2);
HAL_Cgra_Glb_WriteReg(0x30, 0x3e);
HAL_Cgra_Glb_WriteReg(0x38, 0x2);
HAL_Cgra_Glb_WriteReg(0x34, 0x2);
}
