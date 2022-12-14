################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/amberm3-hal/amberm3vx_hal_cgra.c \
../system/src/amberm3-hal/amberm3vx_hal_dma.c \
../system/src/amberm3-hal/amberm3vx_hal_msp_template.c \
../system/src/amberm3-hal/amberm3vx_hal_ptfmctrl.c \
../system/src/amberm3-hal/amberm3vx_hal_uart.c 

OBJS += \
./system/src/amberm3-hal/amberm3vx_hal_cgra.o \
./system/src/amberm3-hal/amberm3vx_hal_dma.o \
./system/src/amberm3-hal/amberm3vx_hal_msp_template.o \
./system/src/amberm3-hal/amberm3vx_hal_ptfmctrl.o \
./system/src/amberm3-hal/amberm3vx_hal_uart.o 

C_DEPS += \
./system/src/amberm3-hal/amberm3vx_hal_cgra.d \
./system/src/amberm3-hal/amberm3vx_hal_dma.d \
./system/src/amberm3-hal/amberm3vx_hal_msp_template.d \
./system/src/amberm3-hal/amberm3vx_hal_ptfmctrl.d \
./system/src/amberm3-hal/amberm3vx_hal_uart.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/amberm3-hal/%.o: ../system/src/amberm3-hal/%.c system/src/amberm3-hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAMBERM3V1 -DUSE_HAL_DRIVER -DHSE_VALUE=100000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/amberm3-hal" -std=gnu11 -Wno-unused-parameter -Wno-conversion -Wno-sign-conversion -Wno-bad-function-cast -Wno-unused-variable -Wno-implicit-function-declaration -Wno-sign-compare -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


