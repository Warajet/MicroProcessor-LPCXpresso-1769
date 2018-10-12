################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/board.c \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/exit.c \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/mbed_interface.c \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/pinmap_common.c \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/rtc_time.c \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/semihost_api.c \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/us_ticker_api.c \
/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/wait_api.c 

OBJS += \
./capi/board.o \
./capi/exit.o \
./capi/mbed_interface.o \
./capi/pinmap_common.o \
./capi/rtc_time.o \
./capi/semihost_api.o \
./capi/us_ticker_api.o \
./capi/wait_api.o 

C_DEPS += \
./capi/board.d \
./capi/exit.d \
./capi/mbed_interface.d \
./capi/pinmap_common.d \
./capi/rtc_time.d \
./capi/semihost_api.d \
./capi/us_ticker_api.d \
./capi/wait_api.d 


# Each subdirectory must supply rules for building sources it contributes
capi/board.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/board.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

capi/exit.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/exit.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

capi/mbed_interface.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/mbed_interface.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

capi/pinmap_common.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/pinmap_common.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

capi/rtc_time.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/rtc_time.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

capi/semihost_api.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/semihost_api.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

capi/us_ticker_api.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/us_ticker_api.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

capi/wait_api.o: /Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi/wait_api.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DTOOLCHAIN_GCC_CR -DTARGET_LPC1768 -D__CODE_RED -DCPP_USE_HEAP -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/app_led" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi/LPC1768" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/capi" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/cpp" -I"/Users/wara_1234/Documents/LPCXpresso_8.2.2/workspace/mbed/libraries/mbed/vendor/NXP/cmsis/LPC1768" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


