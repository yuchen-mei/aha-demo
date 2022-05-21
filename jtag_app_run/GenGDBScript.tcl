# ==============================================================================
# Generate GDB Command File
# ------------------------------------------------------------------------------

#
# Helper Procedures
#

#
# Source User App Configuration
#

set USER_FILE       [file normalize ./app/app.tcl]
source $USER_FILE

# GDB Script FullPath
set GDB_CMD_FILE    [file normalize ./app/script.gdb]

#
# Populate GDB Command File
#
set fp              [open $GDB_CMD_FILE w]

puts $fp "target remote localhost:2331"
puts $fp "set mem inaccessible-by-default off"
puts $fp "monitor speed 10000"
puts $fp "monitor clrbp"
puts $fp "monitor reset"
puts $fp "monitor halt"
puts $fp "monitor flash breakpoints 1"
puts $fp "monitor semihosting enable"
puts $fp "symbol-file ${APP_M3_CODE}"
puts $fp "load ${APP_M3_CODE}"

puts $fp "monitor clrbp"
puts $fp "monitor reset"
puts $fp "monitor halt"

puts $fp "set \$CGRA_CLK_SEL_ADDR = 0x40007028"
puts $fp "set \$CLK_GATE_EN_ADDR = 0x40007044"
puts $fp "set \$RESET_REQ_ADDR = 0x4000704C"

puts $fp "set {unsigned int}\$CGRA_CLK_SEL_ADDR = 0x00000000"
puts $fp "set {unsigned int}\$CLK_GATE_EN_ADDR = *(unsigned int)\$CLK_GATE_EN_ADDR & ~(1 << 8)"
puts $fp "set {unsigned int}\$RESET_REQ_ADDR = *(unsigned int)\$RESET_REQ_ADDR & ~(1 << 8)"

foreach d_im ${APP_INPUT_DATA} {
    set imFile  [lindex $d_im 0]
    set imAddr  [lindex $d_im 1]
    puts $fp "restore ${imFile} binary ${imAddr}"
}

puts $fp "monitor clrbp"
puts $fp "monitor reset"
puts $fp "monitor halt"

puts $fp "b main"
puts $fp "continue"
puts $fp "b _exit"
puts $fp "continue"
puts $fp "step"


foreach o_im ${APP_OUTPUT_DATA} {
    set outFile         [lindex $o_im 0]
    set outAddrStart    [lindex $o_im 1]
    set outSize         [lindex $o_im 2]
    set outAddrEnd      [format %08X [expr $outAddrStart + $outSize]]
    puts $fp "dump binary memory ${outFile} ${outAddrStart} 0x${outAddrEnd}"
}

puts $fp "quit"
