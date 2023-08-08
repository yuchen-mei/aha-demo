#include "amberm3vx_hal_cgra.h"

/************************* Constant Definitions *******************************/

/************************* Variable Definitions *******************************/

/************************* Function Definitions *******************************/

void HAL_Cgra_Glb_WriteReg(u32 RegOffset, u32 Value)
{
  HAL_Cgra_WriteReg(GLB_REG_BASE_ADDR, RegOffset, Value);
}

u32 HAL_Cgra_Glb_ReadReg(u32 RegOffset)
{
  return HAL_Cgra_ReadReg(GLB_REG_BASE_ADDR, RegOffset);
}

void HAL_Cgra_Glc_WriteReg(u32 RegOffset, u32 Value)
{
  HAL_Cgra_WriteReg(GLC_REG_BASE_ADDR, RegOffset, Value);
}

u32 HAL_Cgra_Glc_ReadReg(u32 RegOffset)
{
  return HAL_Cgra_ReadReg(GLC_REG_BASE_ADDR, RegOffset);
}

void HAL_Cgra_Tile_WriteReg(u32 RegOffset, u32 Value)
{
  HAL_Cgra_Glc_WriteReg(0x40, RegOffset);
  HAL_Cgra_Glc_WriteReg(0x44, Value);
  HAL_Cgra_Glc_WriteReg(0x48, 32);
}

u32 HAL_Cgra_Tile_ReadReg(u32 RegOffset)
{
  volatile u32 Wait = 0;

  HAL_Cgra_Glc_WriteReg(0x40, RegOffset);
  HAL_Cgra_Glc_WriteReg(0x4C, 32);
  while (Wait < 64) Wait++;

  return HAL_Cgra_Glc_ReadReg(0x50);
}
