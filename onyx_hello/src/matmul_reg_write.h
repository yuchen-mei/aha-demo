

static void bitstream_glb_config()
{
HAL_Cgra_Glb_WriteReg(0xe8, 0x1);
HAL_Cgra_Glb_WriteReg(0xec, 0x0);
HAL_Cgra_Glb_WriteReg(0xf0, 0xfc);
HAL_Cgra_Glb_WriteReg(0xf4, 0x14);
HAL_Cgra_Glb_WriteReg(0x1f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x2f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x3f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x4f4, 0x28);
HAL_Cgra_Glb_WriteReg(0x5f4, 0x28);
}


static void app_glb_config()
{
HAL_Cgra_Glb_WriteReg(0x78, 0x29);
HAL_Cgra_Glb_WriteReg(0x7c, 0x1);
HAL_Cgra_Glb_WriteReg(0x80, 0x0);
HAL_Cgra_Glb_WriteReg(0x84, 0x0);
HAL_Cgra_Glb_WriteReg(0x88, 0xc);
HAL_Cgra_Glb_WriteReg(0x90, 0x1);
HAL_Cgra_Glb_WriteReg(0x8c, 0x2);
HAL_Cgra_Glb_WriteReg(0x178, 0x29);
HAL_Cgra_Glb_WriteReg(0x17c, 0x1);
HAL_Cgra_Glb_WriteReg(0x180, 0x40000);
HAL_Cgra_Glb_WriteReg(0x184, 0x0);
HAL_Cgra_Glb_WriteReg(0x188, 0xc);
HAL_Cgra_Glb_WriteReg(0x190, 0x1);
HAL_Cgra_Glb_WriteReg(0x18c, 0x2);
HAL_Cgra_Glb_WriteReg(0x278, 0x29);
HAL_Cgra_Glb_WriteReg(0x27c, 0x1);
HAL_Cgra_Glb_WriteReg(0x280, 0x80000);
HAL_Cgra_Glb_WriteReg(0x284, 0x0);
HAL_Cgra_Glb_WriteReg(0x288, 0x3f);
HAL_Cgra_Glb_WriteReg(0x290, 0x1);
HAL_Cgra_Glb_WriteReg(0x28c, 0x2);
HAL_Cgra_Glb_WriteReg(0x378, 0x29);
HAL_Cgra_Glb_WriteReg(0x37c, 0x1);
HAL_Cgra_Glb_WriteReg(0x380, 0xc0000);
HAL_Cgra_Glb_WriteReg(0x384, 0x0);
HAL_Cgra_Glb_WriteReg(0x388, 0x30);
HAL_Cgra_Glb_WriteReg(0x390, 0x1);
HAL_Cgra_Glb_WriteReg(0x38c, 0x2);
HAL_Cgra_Glb_WriteReg(0x478, 0x29);
HAL_Cgra_Glb_WriteReg(0x47c, 0x1);
HAL_Cgra_Glb_WriteReg(0x480, 0x100000);
HAL_Cgra_Glb_WriteReg(0x484, 0x0);
HAL_Cgra_Glb_WriteReg(0x488, 0x33);
HAL_Cgra_Glb_WriteReg(0x490, 0x1);
HAL_Cgra_Glb_WriteReg(0x48c, 0x2);
HAL_Cgra_Glb_WriteReg(0x578, 0x29);
HAL_Cgra_Glb_WriteReg(0x57c, 0x1);
HAL_Cgra_Glb_WriteReg(0x580, 0x140000);
HAL_Cgra_Glb_WriteReg(0x584, 0x0);
HAL_Cgra_Glb_WriteReg(0x588, 0x24);
HAL_Cgra_Glb_WriteReg(0x590, 0x1);
HAL_Cgra_Glb_WriteReg(0x58c, 0x2);
HAL_Cgra_Glb_WriteReg(0x10, 0x25);
HAL_Cgra_Glb_WriteReg(0x14, 0x2);
HAL_Cgra_Glb_WriteReg(0x18, 0x1);
HAL_Cgra_Glb_WriteReg(0x1c, 0x20000);
HAL_Cgra_Glb_WriteReg(0x20, 0x0);
HAL_Cgra_Glb_WriteReg(0x24, 0x3fe);
HAL_Cgra_Glb_WriteReg(0x2c, 0x1);
HAL_Cgra_Glb_WriteReg(0x28, 0x2);
HAL_Cgra_Glb_WriteReg(0x110, 0x25);
HAL_Cgra_Glb_WriteReg(0x114, 0x2);
HAL_Cgra_Glb_WriteReg(0x118, 0x1);
HAL_Cgra_Glb_WriteReg(0x11c, 0x60000);
HAL_Cgra_Glb_WriteReg(0x120, 0x0);
HAL_Cgra_Glb_WriteReg(0x124, 0x3fe);
HAL_Cgra_Glb_WriteReg(0x12c, 0x1);
HAL_Cgra_Glb_WriteReg(0x128, 0x2);
HAL_Cgra_Glb_WriteReg(0x210, 0x25);
HAL_Cgra_Glb_WriteReg(0x214, 0x1);
HAL_Cgra_Glb_WriteReg(0x218, 0x1);
HAL_Cgra_Glb_WriteReg(0x21c, 0xa0000);
HAL_Cgra_Glb_WriteReg(0x220, 0x0);
HAL_Cgra_Glb_WriteReg(0x224, 0x3fe);
HAL_Cgra_Glb_WriteReg(0x22c, 0x1);
HAL_Cgra_Glb_WriteReg(0x228, 0x2);

//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x78));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x7c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x80));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x84));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x88));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x90));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x8c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x178));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x17c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x180));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x184));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x188));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x190));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x18c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x278));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x27c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x280));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x284));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x288));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x290));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x28c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x378));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x37c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x380));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x384));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x388));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x390));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x38c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x478));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x47c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x480));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x484));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x488));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x490));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x48c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x578));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x57c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x580));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x584));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x588));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x590));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x58c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x10));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x14));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x18));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x1c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x20));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x24));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x2c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x28));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x110));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x114));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x118));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x11c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x120));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x124));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x12c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x128));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x210));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x214));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x218));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x21c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x220));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x224));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x22c));
//trace_printf("reg %lx\n", HAL_Cgra_Glb_ReadReg(0x228));


}
