################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/amberm3vx_hal_msp.c \
../src/main.c \
../src/write.c 

OBJS += \
./src/amberm3vx_hal_msp.o \
./src/main.o \
./src/write.o 

C_DEPS += \
./src/amberm3vx_hal_msp.d \
./src/main.d \
./src/write.d 


# Each subdirectory must supply rules for building sources it contributes
src/amberm3vx_hal_msp.o: ../src/amberm3vx_hal_msp.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAMBERM3V1 -DUSE_HAL_DRIVER -DHSE_VALUE=100000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/amberm3-hal" -std=gnu11 -Wno-padded -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAMBERM3V1 -DUSE_HAL_DRIVER -DHSE_VALUE=100000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/amberm3-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


