target remote localhost:2331
set mem inaccessible-by-default off
monitor speed 1000
set $CGRA_CLK_SEL_ADDR = 0x40007028
set $CLK_GATE_EN_ADDR = 0x40007044
set $RESET_REQ_ADDR = 0x4000704C

set {unsigned int}$CGRA_CLK_SEL_ADDR = 0x00000000
set {unsigned int}$CLK_GATE_EN_ADDR = *(unsigned int)$CLK_GATE_EN_ADDR & ~(1 << 8)
set {unsigned int}$RESET_REQ_ADDR = *(unsigned int)$RESET_REQ_ADDR & ~(1 << 8)
