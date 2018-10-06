################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/src/cr_startup_lpc175x_6x.c \
../Code/src/sysinit.c \
../Code/src/timer.c 

OBJS += \
./Code/src/cr_startup_lpc175x_6x.o \
./Code/src/sysinit.o \
./Code/src/timer.o 

C_DEPS += \
./Code/src/cr_startup_lpc175x_6x.d \
./Code/src/sysinit.d \
./Code/src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Code/src/%.o: ../Code/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"C:\Users\iamla\Documents\MCUXpressoIDE_10.2.1_795\workspace\lpc_chip_175x_6x\inc" -I"C:\Users\iamla\Documents\MCUXpressoIDE_10.2.1_795\workspace\lpc_board_nxp_lpcxpresso_1769\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


