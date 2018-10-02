/*
===============================================================================
 Name        : Lab5.c
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

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

#define TICKRATE_HZ1 (50)	/* 11 ticks per second */

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	Handle interrupt from 32-bit timer
 * @return	Nothing
 */
void TIMER0_IRQHandler(void)
{
	if (Chip_TIMER_MatchPending(LPC_TIMER0, 1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER0, 1);
		Board_LED_Toggle(0);
	}
}

void  myTimerIsr_0(void)
{
	Board_LED_Toggle(0);
}

void  myTimerIsr_1(void)
{
	Board_LED_Toggle(0);
}

/**
 * @brief	main routine for blinky example
 * @return	Function should not exit.
 */
//int main(void)
//{
////	uint32_t timerFreq;
////
////	/* Generic Initialization */
////	SystemCoreClockUpdate();
////	Board_Init();
////
////	/* Enable timer 1 clock */
////	Chip_TIMER_Init(LPC_TIMER0);
////
////	/* Timer rate is system clock rate */
////	timerFreq = Chip_Clock_GetSystemClockRate();
////
////	/* Timer setup for match and interrupt at TICKRATE_HZ */
////	Chip_TIMER_Reset(LPC_TIMER0);
////	Chip_TIMER_MatchEnableInt(LPC_TIMER0, 1);
////	Chip_TIMER_SetMatch(LPC_TIMER0, 1, (timerFreq / TICKRATE_HZ1));
////	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER0, 1);
////	Chip_TIMER_Enable(LPC_TIMER0);
////
////	/* Enable timer interrupt */
////	NVIC_ClearPendingIRQ(TIMER0_IRQn);
////	NVIC_EnableIRQ(TIMER0_IRQn);
//
//	  TIMER_Init(0,100000);                  /* Configure timer0 to generate 100ms(100000us) delay*/
//	    TIMER_Init(1,500000);                  /* Configure timer1 to generate 500ms(500000us) delay*/
//
//	    TIMER_AttachInterrupt(0,myTimerIsr_0);  /* myTimerIsr_0 will be called by TIMER0_IRQn */
//	    TIMER_AttachInterrupt(1,myTimerIsr_1);  /* myTimerIsr_1 will be called by TIMER1_IRQn */
//
//	    TIMER_Start(0);                         /* Start the Timers */
//	    TIMER_Start(1);
//
//	/* LEDs toggle in interrupt handlers */
//	while (1) {
//		__WFI();
//	}
//
//	return 0;
//}


#define PRESCALE (25000-1) //25000 PCLK clock cycles to increment TC by 1

void delayMS(unsigned int milliseconds);
void initTimer0(void);

int main(void)
{
	//SystemInit(); //called by Startup Code before main(), hence no need to call again.
	initTimer0(); //Initialize Timer0

	while(1)
	{
		Board_LED_Toggle(0);
		delayMS(500); //0.5 Second(s) Delay
		Board_LED_Toggle(0);
		delayMS(500);
	}

	//return 0; //normally this wont execute ever
}

void initTimer0(void)
{
	/*Assuming that PLL0 has been setup with CCLK = 100Mhz and PCLK = 25Mhz.*/
	LPC_SC->PCONP |= (1<<1); //Power up TIM0. By default TIM0 and TIM1 are enabled.
	LPC_SC->PCLKSEL0 &= ~(0x3<<3); //Set PCLK for timer = CCLK/4 = 100/4 (default)

	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = PRESCALE; //Increment LPC_TIM0->TC at every 24999+1 clock cycles
	//25000 clock cycles @25Mhz = 1 mS

	LPC_TIM0->TCR = 0x02; //Reset Timer
	}

void delayMS(unsigned int milliseconds) //Using Timer0
{
	LPC_TIM0->TCR = 0x02; //Reset Timer
	LPC_TIM0->TCR = 0x01; //Enable timer

	while(LPC_TIM0->TC < milliseconds); //wait until timer counter reaches the desired delay

	LPC_TIM0->TCR = 0x00; //Disable timer
}

