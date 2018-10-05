/*
===============================================================================
 Name        : Lab03_0.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define TICKRATE_HZ1 (10)

void stepRight();

void stepLeft();

volatile int ledOn = 0;

void (*ledStep)(void) = &stepRight;

void SysTick_Handler(void)
{
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 9 - ledOn, false);
	(*ledStep)();
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 9 - ledOn, true);
}

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    Chip_GPIO_Init(0);
    int i;
    for (i = 9; i >= 6; i--){
    	Chip_GPIO_SetDir(LPC_GPIO, 0, i, 1);
    }
    Chip_GPIO_SetDir(LPC_GPIO, 0, 0, 0);

    SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

    while (1) {
    	if (Chip_GPIO_GetPinState(LPC_GPIO,0, 0)) { // If button is pressed
    		ledStep = &stepRight;
    	} else {
    		ledStep = &stepLeft;
    	}
    	for (i = 0; i < 10000000; i++);
    }
    return 0 ;
}


void stepRight() {
	ledOn++;
	if (ledOn > 3) {
		ledOn = 0;
	}
}

void stepLeft() {
	ledOn--;
	if (ledOn < 0) {
		ledOn = 3;
	}
}
