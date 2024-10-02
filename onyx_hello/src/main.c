#include <stdio.h>
#include <stdlib.h>
#include "diag/trace.h"

#include "amberm3vx_hal.h"
#include "sequential_0_fp_input_script.h"
#include "sequential_0_fp_script.h"
#include "sequential_0_fp_reg_write.h"
#include "sequential_0_fp_unrolling.h"
#include "glb.h"
#include "glc.h"
#include "memory.h"


#define AHASOC_PCTRL_SYS_Pos                  0
#define AHASOC_PCTRL_CPU_Pos                  1
#define AHASOC_PCTRL_DAP_Pos                  2
#define AHASOC_PCTRL_DMA0_Pos                 3
#define AHASOC_PCTRL_DMA1_Pos                 4
#define AHASOC_PCTRL_SRAM_Pos                 5
#define AHASOC_PCTRL_TLX_FWD_Pos              6
#define AHASOC_PCTRL_TLX_REV_Pos              7
#define AHASOC_PCTRL_CGRA_Pos                 8
#define AHASOC_PCTRL_NIC_Pos                  9
#define AHASOC_PCTRL_TIMER0_Pos               10
#define AHASOC_PCTRL_TIMER1_Pos               11
#define AHASOC_PCTRL_UART0_Pos                12
#define AHASOC_PCTRL_UART1_Pos                13
#define AHASOC_PCTRL_WDOG_Pos                 14
#define AHASOC_ROM_BASE          (0x00000000UL)  /*!< (ROM     ) Base Address */
#define AHASOC_SRAM_BASE         (0x20000000UL)  /*!< (SRAM      ) Base Address */
#define AHASOC_SRAM_BANK0_BASE   (0x20000000UL)  /*!< (SRAM      ) Base Address */
#define AHASOC_SRAM_BANK1_BASE   (0x20008000UL)  /*!< (SRAM      ) Base Address */
#define AHASOC_SRAM_BANK2_BASE   (0x20010000UL)  /*!< (SRAM      ) Base Address */
#define AHASOC_SRAM_BANK3_BASE   (0x20018000UL)  /*!< (SRAM      ) Base Address */
#define AHASOC_SRAM_END_ADDR     (0x2001FFFFUL)  /*!< (SRAM      ) Base Address */
#define AHASOC_PERIPH_BASE       (0x40000000UL)  /*!< (Peripheral) Base Address */
#define AHASOC_TLX_BASE          (0x60000000UL)  /*!< (TLX       ) Base Address */
#define AHASOC_CGRA_DATA_BASE    (0x20400000UL)  /*!< (CGRA DATA ) Base Address */
#define AHASOC_CGRA_REG_BASE     (0x40010000UL)  /*!< (CGRA REG  ) Base Address */
#define AHASOC_TLXCTRL_BASE      (0x40014000UL)  /*!< (TLX REG  ) Base Address */

HAL_PtfmCtrl_t PtfmCtl;


void write_glb_memory_bitstream(uint32_t start_addr, uint64_t* data, int size) {

  uint64_t* base_ptr = (uint64_t*) (AHASOC_CGRA_DATA_BASE + start_addr);

  for(int i = 0; i < size; i++) {
    base_ptr[i] = data[i];
  }


}

uint64_t make_config(uint32_t addr, uint32_t data) {
  uint64_t long_addr = (uint64_t) addr;
  return ((long_addr << 32) | data);
}

void write_cgra_configuration_streaming(uint64_t* addrs,
          //uint32_t* datas,
          int size) {
  // Load config into GLB memory.
  //uint64_t config[size];
  int i;
//  for (i = 0; i < size; i++) {
//    config[i] = make_config(addrs[i], datas[i]);
//  }
  trace_printf("\n** Stream Calculation Finished **\n");

  write_glb_memory_bitstream(0x00000, addrs, size);

  trace_printf("\n** Configure Tile 0 for write stream **\n");
  // Configure GLB Tile 0 for write stream.

  bitstream_glb_config();


  trace_printf("\n** Start PC **\n");
  HAL_Cgra_Glc_WriteReg(GLC_GLB_FLUSH_CROSSBAR_R, 0);
  HAL_Cgra_Glc_WriteReg(GLC_CGRA_STALL_R, 0xFFFF);
  HAL_Cgra_Glc_WriteReg(GLC_PC_START_PULSE_R, 1);

}



int

main(int argc, char* argv[])
{
  HAL_UNUSED(argc);
  HAL_UNUSED(argv);

  int status = HAL_PtfmCtrl_Initialize( & PtfmCtl);
  trace_printf("status1 %d\n", status);
  u32 cgra_mask = (1 << AHASOC_PCTRL_CGRA_Pos);
  u32 sys_mask = (1 << AHASOC_PCTRL_SYS_Pos);
  status = HAL_PtfmCtrl_SelectClock( & PtfmCtl, cgra_mask, 0); // 2^1 = 2 60/2 = 30
  status = HAL_PtfmCtrl_SelectClock( & PtfmCtl, sys_mask, 0); // 2^2 = 4 60/4 = 15
  status = HAL_PtfmCtrl_DisableCG( & PtfmCtl, cgra_mask);
  status = HAL_PtfmCtrl_ClearReset( & PtfmCtl, cgra_mask);



  trace_printf("\nCONFIG \n");

  for (int config = 0; config < app_size; config++){
	  HAL_Cgra_Tile_WriteReg(app_addrs_script[config], app_datas_script[config]);
  }

  for (int config = 0; config < app_size; config++){
	  uint32_t read_data = HAL_Cgra_Tile_ReadReg(app_addrs_script[config]);

	  uint32_t gold = app_datas_script[config];

	  if ( read_data != gold){
		  trace_printf("config error: %d \n", config);
		  trace_printf("read_data %lx \n", read_data);
		  trace_printf("gold data %lx\n", gold);
	  }
  }

//  move_input_data();

  trace_printf("\nCONFIG GLB\n");

  app_glb_config();

  for(int glb=0; glb < 4; glb++){
	  uint64_t * read_base = AHASOC_CGRA_DATA_BASE + 0x20000 + glb*0x40000;
	  for (int i=0; i < 16384; i++){
		  read_base[i] = 0;
	  }
  }

  int stream_pulse_g2f = 0x1ff;
  int stream_pulse_f2g = 0xf;


  trace_printf("\nAPP Prep\n");

  HAL_Cgra_Glc_WriteReg(GLC_GLB_FLUSH_CROSSBAR_R, 0);
  HAL_Cgra_Glc_WriteReg(GLC_CGRA_STALL_R, 0x0);

  for (int i=0; i < 1; i++){
  HAL_Cgra_Glc_WriteReg(GLC_STREAM_START_PULSE_R, (stream_pulse_f2g << 16) | stream_pulse_g2f);

	  // Wait for inputs to finish sending
	  while(HAL_Cgra_Glc_ReadReg(GLC_STRM_G2F_ISR_R) != stream_pulse_g2f){
		  //cnt++;
	  }

	  HAL_Cgra_Glc_WriteReg(GLC_STRM_G2F_ISR_R, stream_pulse_g2f);
	  // Wait for outputs to all fill in
	  while(HAL_Cgra_Glc_ReadReg(GLC_STRM_F2G_ISR_R) != stream_pulse_f2g){
		  //cnt++;
	  }
	  HAL_Cgra_Glc_WriteReg(GLC_STRM_F2G_ISR_R, stream_pulse_f2g);

  }



  int error = 0;


  check_gold_data();

  return 0;
}
