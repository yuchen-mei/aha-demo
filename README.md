# aha_demo

test_app contains the code running on the M3

jtag_app_run contains the scripts to run individual tiles on the chip and stitch the output image back together

# JTAG testing command

JLinkGDBServerCLExe -if jtag -device CORTEX-M3 -endian little -speed 10 -port 2331 -swoport 2332 -telnetport 2333 -ir -localhostonly 1 -singlerun -strict -timeout 0 -nogui
