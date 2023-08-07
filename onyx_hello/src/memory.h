#define AHASOC_CGRA_DATA_BASE    (0x20400000UL)  /*!< (CGRA DATA ) Base Address */

void write_glb_memory(uint32_t start_addr, uint16_t* data, int size, int num, int stride) {
  int i;
  uint16_t * base_ptr = (uint16_t*) (AHASOC_CGRA_DATA_BASE + start_addr);

  for (i = 0; i < size; i++) {
    base_ptr[i] = data[i * stride + num];
  }
}


