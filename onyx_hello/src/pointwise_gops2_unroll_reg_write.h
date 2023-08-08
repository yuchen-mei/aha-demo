

static void bitstream_glb_config()
{
HAL_Cgra_Glb_WriteReg(0xe8, 0x1);
HAL_Cgra_Glb_WriteReg(0xec, 0x20000);
HAL_Cgra_Glb_WriteReg(0xf0, 3296);
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
HAL_Cgra_Glb_WriteReg(0xcf4, 0x28);
HAL_Cgra_Glb_WriteReg(0xdf4, 0x28);
HAL_Cgra_Glb_WriteReg(0xef4, 0x28);
HAL_Cgra_Glb_WriteReg(0xff4, 0x28);
}


static void app_glb_config(int glb_tile_offset)
{
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x78, 0x21);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x7c, 0x1);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x80, glb_tile_offset*0x40000 + 0x0);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x84, 0x0);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x88, 0xffe);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x90, 0x1);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x8c, 0x2);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x110, 0x21);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x114, 0x1);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x118, 0x1);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x11c, glb_tile_offset*0x40000 + 0x60000);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x120, 0x30);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x124, 0xffe);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x12c, 0x1);
HAL_Cgra_Glb_WriteReg(0x100*glb_tile_offset+0x128, 0x2);
}
