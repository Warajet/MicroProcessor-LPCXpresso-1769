################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768/GCC_CR/startup_LPC17xx.cpp 

OBJS += \
./cmsis/LPC1768/GCC_CR/startup_LPC17xx.o 

CPP_DEPS += \
./cmsis/LPC1768/GCC_CR/startup_LPC17xx.d 


# Each subdirectory must supply rules for building sources it contributes
cmsis/LPC1768/GCC_CR/startup_LPC17xx.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768/GCC_CR/startup_LPC17xx.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


