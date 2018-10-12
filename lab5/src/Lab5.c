/*
===============================================================================
 Name        : lab5.c
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

//Code for IRQ of 5.1
void TIMER1_IRQHandler(void) {
	if(Chip_TIMER_MatchPending(LPC_TIMER1, 1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER1, 1);
		Board_LED_Toggle(0);
	}
}
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

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
        uint32_t timerFreq;

        //5.1
        /*
        Chip_TIMER_Init(LPC_TIMER1);
        timerFreq = Chip_Clock_GetSystemClockRate(); //Get SystemClock will give 96 MHz
        Chip_TIMER_Reset(LPC_TIMER1);
        Chip_TIMER_MatchEnableInt(LPC_TIMER1, 1);
        Chip_TIMER_SetMatch(LPC_TIMER1, 1 , (timerFreq/8) * 5);
        Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, 1);
        Chip_TIMER_Enable(LPC_TIMER1);

        uint32_t scaled = (timerFreq/8) * 5;

        NVIC_ClearPendingIRQ(TIMER1_IRQn);
        NVIC_EnableIRQ(TIMER1_IRQn);

        while(1) {
        	__WFI();
        }
        */

        //Code for 5.2


        Chip_IOCON_Init(LPC_IOCON);	//IOConfiguration to use External Match Register
        timerFreq = Chip_Clock_GetSystemClockRate(); //Initialize System Clock with 96MHz
        Chip_IOCON_PinMux(LPC_IOCON, 0, 6, IOCON_MODE_INACT, IOCON_FUNC3); //Enable OpenDrain for Port0Pin6 -> Pin8 & IOFunction3
        Chip_TIMER_Init(LPC_TIMER2); //Initialize LPC_Timer2
        Chip_TIMER_Reset(LPC_TIMER2); //Reset LPC_Timer2
        Chip_TIMER_MatchEnableInt(LPC_TIMER2, 0);
        Chip_TIMER_ResetOnMatchEnable(LPC_TIMER2, 0);
        Chip_TIMER_ExtMatchControlSet(LPC_TIMER2, 0, TIMER_EXTMATCH_TOGGLE, 0); //Timer_external_match toggle
        Chip_TIMER_SetMatch(LPC_TIMER2, 0, (timerFreq / 8000)); //Cycle = Ton/TPCLK = fPCLK/ fON x 2
        Chip_TIMER_Enable(LPC_TIMER2);

        return 0 ;
}
