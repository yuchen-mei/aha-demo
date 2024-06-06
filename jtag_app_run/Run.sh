#!/bin/bash

# # Launch JLink
# JLinkGDBServerCLExe -if jtag -device CORTEX-M3 -endian little -speed 10000 -port 2331 -swoport 2332 -telnetport 2333 -ir -localhostonly 1 -singlerun -strict -timeout 0 -nogui &
# P1=$!
# sleep 1

# Generate GDB Command Script
# tclsh GenGDBScript.tcl

# Launch GDB with Generated Script
/Users/kalhankoul/Library/xPacks/\@xpack-dev-tools/arm-none-eabi-gcc/13.2.1-1.1.1/.content/bin/arm-none-eabi-gdb < app/new_script.gdb &
P2=$!
wait $P2
# kill -9 $P1
