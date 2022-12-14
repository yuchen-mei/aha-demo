################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/cmsis/system_amberm3vx.c \
../system/src/cmsis/vectors_amberm3v1.c 

OBJS += \
./system/src/cmsis/system_amberm3vx.o \
./system/src/cmsis/vectors_amberm3v1.o 

C_DEPS += \
./system/src/cmsis/system_amberm3vx.d \
./system/src/cmsis/vectors_amberm3v1.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/cmsis/system_amberm3vx.o: ../system/src/cmsis/system_amberm3vx.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAMBERM3V1 -DUSE_HAL_DRIVER -DHSE_VALUE=100000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/amberm3-hal" -std=gnu11 -Wno-padded -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/cmsis/%.o: ../system/src/cmsis/%.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAMBERM3V1 -DUSE_HAL_DRIVER -DHSE_VALUE=100000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/amberm3-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


