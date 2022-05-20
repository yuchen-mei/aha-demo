#include <stdio.h>
#include <stdlib.h>
#include "diag/trace.h"
#include "app/regmap.h"
#include "app/unsharp_input_script_new.h"
#include "app/unsharp_script.h"
#include "amberm3vx_hal.h"


HAL_PtfmCtrl_t PtfmCtl;

u32 test_app(void);
void write_cgra_configuration_streaming(u64 * , int);
void write_glb_memory(u32, u16 * , int, int, int);
void wait_for_interrupt();
void write_glb_setup(u32, int, int, int, int,
					int, int, int, int, int, int, int, int,
					int);
void write_glb_memory_bitstream(u32, u64 * , int);

// Global interrupt flag and expected interrupt code.
volatile u32 cgra_int_occured;
volatile u32 cgra_int_code;

int
main(int argc, char * argv[]) {
  HAL_UNUSED(argc);
  HAL_UNUSED(argv);

  int status;

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

  status = HAL_PtfmCtrl_Initialize( & PtfmCtl);

  //u32 dma_mask =
  //(1 << AHASOC_PCTRL_DMA0_Pos) | (1 << AHASOC_PCTRL_DMA1_Pos);
  u32 cgra_mask = (1 << AHASOC_PCTRL_CGRA_Pos);
  u32 sys_mask = (1 << AHASOC_PCTRL_SYS_Pos);
  //u32 all_mask = (1 << AHASOC_PCTRL_DMA0_Pos) |
  //            (1 << AHASOC_PCTRL_DMA1_Pos) |
  //            (1 << AHASOC_PCTRL_CGRA_Pos);
  //status = HAL_PtfmCtrl_SelectClock(&PtfmCtl, dma_mask, 0x0);
  //status = HAL_PtfmCtrl_SelectClock(&PtfmCtl, cgra_mask, 0x2); // 2 ^ power divide
  status = HAL_PtfmCtrl_SelectClock( & PtfmCtl, cgra_mask, 3); // 2^1 = 2 60/2 = 30
  status = HAL_PtfmCtrl_SelectClock( & PtfmCtl, sys_mask, 4); // 2^2 = 4 60/4 = 15
  status = HAL_PtfmCtrl_DisableCG( & PtfmCtl, cgra_mask);
  status = HAL_PtfmCtrl_ClearReset( & PtfmCtl, cgra_mask);

  // Send a greeting to the trace device
  trace_printf("Hello, I am Amber!\r\n");

  // App Test
  cgra_int_occured = 0;
  u32 checks = test_app();

  return 0;
}

// Main test function.
u32 test_app(void) {

	uint16_t app_input_data[4] = {0,0,0,0};
	//uint16_t app_gold_data[4] = {0,0,0,0};
	int app_input_data_size = 15552;
	//int app_gold_data_size = 4;


  int i;

  //const int NUM_APP_DATA = app_input_data_size;
  const int NUM_READ_DATA = app_gold_data_size;

  //uint16_t app_data[NUM_APP_DATA];
  uint16_t gold_data[NUM_READ_DATA];
  //for (i = 0; i < NUM_APP_DATA; i++) app_data[i] = (uint16_t) app_input_data[i];
  for (i = 0; i < NUM_READ_DATA; i++) gold_data[i] = (uint16_t) app_gold_data[i];

  int deploy_tile = 2;

  const u32 start_addr = 0x00000 + 0x40000 * deploy_tile;
  const u32 read_start_addr = 0x20000 + 0x40000 * deploy_tile;


  trace_printf("addr0: %lx\n", (u32) (bitstream[0] >> 32));
  trace_printf("data0: %lx\n", (u32) (bitstream[0] & 0xffffffff));

  trace_printf("addre: %lx\n", (u32) (bitstream[app_size-1] >> 32));
  trace_printf("datae: %lx\n", (u32) (bitstream[app_size-1] & 0xffffffff));

  HAL_Cgra_Glc_WriteReg(GLC_STALL, 0xFFFF);
  write_cgra_configuration_streaming(bitstream,
    app_size);

  trace_printf("bitstream size: %d \r\n", app_size);
  //    for (int i = 0; i < app_size; i++) {
  //       u32 addr = app_addrs_script[i];
  //       u32 addr_shifted = (addr & 0xFFFF00FF) | ((((addr >> 8) & 0xFF) + 2*deploy_tile) << 8);
  //       HAL_Cgra_Tile_WriteReg(addr_shifted,
  //                       app_datas_script[i]);
  //    }

  int error = 0;
  trace_printf("do compare\r\n");
  for (int i = 0; i < app_size; i++) {
    u64 addr = bitstream[i];
    u32 addr_shifted = addr >> 32;
    if (HAL_Cgra_Tile_ReadReg(addr_shifted) != (bitstream[i] & 0xffffffff)) {
//      trace_printf("index: %d \r\n", i);
//      trace_printf("addr: %lx \r\n", addr_shifted);
//      trace_printf("recieved value: %lx \r\n", (u32) HAL_Cgra_Tile_ReadReg(addr_shifted));
//      trace_printf("correct value: %lx \r\n", (u32)(bitstream[i] & 0xffffffff));
      error++;
    }
  }

  if (error != 0) {
    trace_printf("Failed streaming config, errors: %d\r\n", error);
    //return 0;
  }
  cgra_int_occured = 0;

  ////trace_printf("\n** Write extent to GLB memory tile 0 **\n");


  u16 * pixel_check0 = AHASOC_CGRA_DATA_BASE + start_addr;
  u16 * pixel_check1 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*1;
  u16 * pixel_check2 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*2;
  u16 * pixel_check3 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*3;
  u16 * pixel_check4 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*4;
  u16 * pixel_check5 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*5;
  u16 * pixel_check6 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*6;
  u16 * pixel_check7 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*7;
  u16 * pixel_check8 = AHASOC_CGRA_DATA_BASE + start_addr + 0x40000*8;






  int unroll = 9;
  int banks = 9;

  int unroll_array[9] = {
    8,
    3,
    2,
    6,
    5,
    4,
    7,
    1,
    0
  };
  int bank_array[9] = {
    6,
    7,
    8,
    0,
    1,
    2,
    3,
    4,
    5
  };

  // Write extent to GLB memory tile 0.
//  for (int i = 0; i < unroll; i++) {
//    write_glb_memory(start_addr + 0x40000 * unroll_array[i], (u16 * ) app_data, NUM_APP_DATA / unroll, i, unroll);
//  }

  // Stream extent to CGRA.

  /*void write_glb_setup(u32 tile, int input, int output,
		  	  	  	int num_active_words, int num_inactive_words,
  					int extent0, int stride0,
					int extent1, int stride1,
					int extent2, int stride2,
					int extent3, int stride3,
  					int num_read_data)*/

  for(int i=2; i < 11; i++){
  write_glb_setup(i, 1, 1,
		  1, 0,
		  1728, 1,
		  0, 0,
		  0, 0,
		  0, 0,
		  NUM_READ_DATA / banks);
  }

  NVIC_ClearPendingIRQ(CGRA_IRQn);
  NVIC_EnableIRQ(CGRA_IRQn);
  cgra_int_code = GLC_STRM_F2G_ISR;

  HAL_Cgra_Glc_WriteReg(GLC_GLOBAL_IER, 0x7);
  HAL_Cgra_Glc_WriteReg(GLC_STRM_F2G_IER, 0xffff);
  HAL_Cgra_Glc_WriteReg(GLC_STALL, 0b00);

  // bit map for starting tiles
  int stream_pulse_val = 0;
  for (int i = 0; i < unroll; i++){
	  stream_pulse_val = (stream_pulse_val << 1) | 1;
  }

  // shift by deploy
  stream_pulse_val = stream_pulse_val << deploy_tile;

  HAL_Cgra_Glc_WriteReg(GLC_STREAM_START_PULSE, stream_pulse_val); // pulsed reg.

  ////trace_printf("\n** Wait for interrupt  **\n");
  // Wait for GLB interrupt signaling writes are done.
  //trace_printf("Errors in setup: %d\r\n", error);
  wait_for_interrupt();

  //trace_printf("Finished interrupt\r\n", error);
  trace_printf("\n** Check with Gold  **\n");
  // Check app output data.
  int err = 0;



  /*u16 * read_base = AHASOC_CGRA_DATA_BASE + read_start_addr;
  for (int b = 0; b < banks; b++){
	  int bank = bank_array[b];
	  read_base = AHASOC_CGRA_DATA_BASE + read_start_addr + bank*0x40000;
	  for (i = 0; i < NUM_READ_DATA/banks; i++) {
		if ((u16)(read_base[i] & 0xff) != (u16) gold_data[i*banks+b]) {
		  err++;
		  trace_printf("index %d\n", i);
		  trace_printf("output_data %lx\n", read_base[i] & 0xff);
		  trace_printf("gold_data %lx\n", gold_data[i*banks+b]);
		}
		//read_base[i] = 0;
	  }
  }*/

  trace_printf("Application finished errors: %d\n", err);
  return err;
}

void write_glb_memory(u32 start_addr, u16 * data, int size, int num, int stride) {
  int i;
  u16 * base_ptr = (u16*) (AHASOC_CGRA_DATA_BASE + start_addr);

  for (i = 0; i < size; i++) {
    base_ptr[i] = data[i * stride + num];
  }
}

void write_glb_memory_bitstream(u32 start_addr, u64 * data, int size) {
  int i;
  u64 *
    const base_ptr =
      (u64 *
        const)(AHASOC_CGRA_DATA_BASE + start_addr);

  int blocks = (size / 64) + 1;
  int j;
  i = 0;
  j = 0;
  while (j < blocks) {
    for (i = 0; i < 64; i++) {
      base_ptr[i + 2 * j * 64] = data[i + j * 64];
    }
    for (i = 0; i < 64; i++) {
      base_ptr[i + 64 + 2 * j * 64] = data[i + j * 64];
    }
    j++;
  }

}

// Streaming CGRA configuration write (SWRITE).
void write_cgra_configuration_streaming(u64 * addrs, //u32 *datas,
  int size) {
  // Load config into GLB memory.

  // printf ("\n** Stream Calculation Finished **\n");
  //write_glb_memory(0x00000 + 0x40000 * 2, config, size);
  write_glb_memory_bitstream(0x00000 + 0x40000 * 2 + 0x20000, addrs, size);

  // printf ("\n** Configure Tile 0 for write stream **\n");
  // Configure GLB Tile 0 for write stream.

  const u32 TILE_CTRL_VALUE = (1 << 10);
  HAL_Cgra_Glb_WriteReg(0x200 + 0x00, TILE_CTRL_VALUE);
  trace_printf("tile ctrl: %lx\r\n", HAL_Cgra_Glb_ReadReg(0x200 + 0x00));
  HAL_Cgra_Glb_WriteReg(0x200 + 0xa8, 0x00000 + 0x40000 * 2 + 0x20000);
  trace_printf("start addr: %lx\r\n", HAL_Cgra_Glb_ReadReg(0x200 + 0xa8));
  HAL_Cgra_Glb_WriteReg(0x200 + 0xac, size * 2);
  trace_printf("size : %d\r\n", HAL_Cgra_Glb_ReadReg(0x200 + 0xac));

  cgra_int_code = 0x30;

  // printf ("\n** Enable PC interrupt for GLB Tile 0 **\n");
  // Enable PC interrupt for GLB Tile 0.
  NVIC_ClearPendingIRQ(CGRA_IRQn);
  NVIC_EnableIRQ(CGRA_IRQn);

  HAL_Cgra_Glc_WriteReg(0x20, 1 << 2); // input tile
  HAL_Cgra_Glc_WriteReg(0x24, 1 << 2);

  // printf ("\n** Start PC **\n");
  // Start PC
  HAL_Cgra_Glc_WriteReg(0x14, 1 << 2); // input tile

  wait_for_interrupt();
}

void write_glb_setup(u32 tile, int input, int output, int num_active_words, int num_inactive_words,
					int extent0, int stride0, int extent1, int stride1, int extent2, int stride2, int extent3, int stride3,
					int num_read_data) {

  // Setup load side.
  u32 TILE_CTRL_VALUE = 0;
  if (input && output) {
    TILE_CTRL_VALUE = (1 << 8) | (1 << 5) | (1 << 6) | (1 << 2);
  } else if (input) {
    TILE_CTRL_VALUE = (1 << 6) | (1 << 2);
  } else if (output) {
    TILE_CTRL_VALUE = (1 << 8) | (1 << 5);
  }

  HAL_Cgra_Glb_WriteReg(GLB_TILE0_TILE_CTRL + tile * 0x100, TILE_CTRL_VALUE);
  trace_printf("tile ctrl: %lx\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_TILE_CTRL + tile * 0x100));

  if (input) {
    //trace_printf ("\n** Setup Load side (glb reg writes) Tile %d **\n", tile);
    HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_START_ADDR + tile * 0x100, tile << 18);
    trace_printf("input_address: %lx\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_START_ADDR + tile * 0x100));
    HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_ACTIVE_CTRL + tile * 0x100,
      //  num_active_words=1, num_inactive_words=0
      (num_active_words | (num_inactive_words << 16)));
    trace_printf("num active words: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ACTIVE_CTRL + tile * 0x100));

    HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_0 + tile * 0x100, (((u32) extent0) << 10) | stride0);
    if(HAL_Cgra_Glb_ReadReg((GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_0 + tile * 0x100) >> 10) < extent0){
    	HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_0 + tile * 0x100, (((u32) extent0) << 10) | stride0);
    }
    trace_printf("extent0: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_0 + tile * 0x100) >> 10);
    trace_printf("stride0: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_0 + tile * 0x100) & 0x3ff);


    HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_1 + tile * 0x100, (((u32) extent1) << 10) | stride1);
    trace_printf("extent1: %lx\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_1 + tile * 0x100) >> 10);
    trace_printf("stride1: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_1 + tile * 0x100) & 0x3ff);

    HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_2 + tile * 0x100, (((u32) extent2) << 10) | stride2);
    trace_printf("extent2: %lx\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_2 + tile * 0x100) >> 10);
    trace_printf("stride2: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_2 + tile * 0x100) & 0x3ff);

    HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_3 + tile * 0x100, (((u32) extent3) << 10) | stride3);
    trace_printf("extent3: %lx\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_3 + tile * 0x100) >> 10);
    trace_printf("stride3: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_ITER_CTRL_3 + tile * 0x100) & 0x3ff);

    HAL_Cgra_Glb_WriteReg(GLB_TILE0_LD_DMA_HEADER_0_VALIDATE + tile * 0x100, 1);
    trace_printf("validate: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_LD_DMA_HEADER_0_VALIDATE + tile * 0x100) & 0x3ff);
  }

  if (output) {
    //trace_printf ("\n** Setup Store 3 side (glb reg writes) **\n");
    // Setup store side.
    HAL_Cgra_Glb_WriteReg(GLB_TILE0_ST_DMA_HEADER_0_START_ADDR + tile * 0x100, (tile << 18) + 0x20000);
    trace_printf("output addr: %lx\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_ST_DMA_HEADER_0_START_ADDR + tile * 0x100));
    HAL_Cgra_Glb_WriteReg(GLB_TILE0_ST_DMA_HEADER_0_NUM_WORDS + tile * 0x100, (u32) num_read_data);
    trace_printf("num words: %d\r\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_ST_DMA_HEADER_0_NUM_WORDS + tile * 0x100));
    HAL_Cgra_Glb_WriteReg(GLB_TILE0_ST_DMA_HEADER_0_VALIDATE + tile * 0x100, 1);
    trace_printf("validate: %lx\r\n\n", HAL_Cgra_Glb_ReadReg(GLB_TILE0_ST_DMA_HEADER_0_VALIDATE + tile * 0x100));
  }

  return;

}

void wait_for_interrupt() {
  // Wait for interrupt (spin loop on cgra_int_occured).
  int counter = 0;

  while (!cgra_int_occured) {
    // //printf("wfi WAIT %d %d %d\n", HAL_Cgra_Glc_ReadReg(GLC_GLOBAL_ISR),
    // HAL_Cgra_Glc_ReadReg(GLC_STRM_F2G_ISR), HAL_Cgra_Glc_ReadReg(GLC_STRM_G2F_ISR));
    // counter++;
    trace_printf("In wfi\r\n");
  }
  // //printf("counter %d\n", counter);
  return;
}

/* -------------------------------------------------------------------- */
/*   BEGIN Driver Helpers                                               */
/*   !! DON'T TOUCH !!                                                  */
/*                                                                      */
/*   * Interrupt ISRs                                                   */
/*   * Interrupt Handlers                                               */
/* -------------------------------------------------------------------- */
// Capture all interrupts with unregistered handlers.
void HardFault_Handler_c(unsigned int * hardfault_args, unsigned lr_value) {
  // puts ("ERROR : Unexpected HardFault interrupt occurred.\n");
  // UartEndSimulation();
  while (1)
  ;
}

void HardFault_Handler(void) __attribute__((naked));
void HardFault_Handler(void) {
  __asm("  movs   r0,#4\n"
    "  mov    r1,lr\n"
    "  tst    r0,r1\n"
    "  beq    stacking_used_MSP\n"
    "  mrs    r0,psp\n" /*  first parameter - stacking was using PSP */
    "  ldr    r1,=HardFault_Handler_c  \n"
    "  bx     r1\n"
    "stacking_used_MSP:\n"
    "  mrs    r0,msp\n" /*  first parameter - stacking was using PSP */
    "  ldr    r1,=HardFault_Handler_c  \n"
    "  bx     r1\n"
    ".pool\n");
}

void CGRA_IRQHandler(void) {
  __NVIC_ClearPendingIRQ(CGRA_IRQn);
  NVIC_DisableIRQ(CGRA_IRQn);
  cgra_int_occured = 1;
  //trace_printf("cgra handled\r\n");

  //         //printf("Handler: %d\n", HAL_Cgra_Glc_ReadReg(cgra_int_code));
  // //printf("123456789101112\n");
  // //printf("CGRA Handler WAIT %d %d %d %d\n", HAL_Cgra_Glc_ReadReg(GLC_GLOBAL_ISR),
  // HAL_Cgra_Glc_ReadReg(GLC_STRM_F2G_ISR), HAL_Cgra_Glc_ReadReg(GLC_STRM_G2F_ISR),
  // HAL_Cgra_Glc_ReadReg(GLC_PAR_CFG_G2F_ISR));

  HAL_Cgra_Glc_WriteReg(cgra_int_code, 1);
}

/* -------------------------------------------------------------------- */
/*   END Driver Helpers                                                 */
/* -------------------------------------------------------------------- */
