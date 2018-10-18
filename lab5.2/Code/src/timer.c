#include "board.h"
#include <stdio.h>

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

#define TICKRATE_KHZ1 (8000)

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
 * @brief	main routine for Lab5-2
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t timerFreq;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Init timer 2 */
	Chip_TIMER_Init(LPC_TIMER2);

	/* Enable pin */
	Chip_IOCON_PinMux(LPC_IOCON, 0, 6, IOCON_MODE_PULLUP, IOCON_FUNC3);

	/* Timer rate is system clock rate */
	timerFreq = Chip_Clock_GetSystemClockRate();

	/* Timer setup for match and interrupt at TICKRATE_HZ */
	Chip_TIMER_Reset(LPC_TIMER2);
	Chip_TIMER_SetMatch(LPC_TIMER2, 0, (timerFreq / TICKRATE_KHZ1));
	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER2, 0);
	Chip_TIMER_ExtMatchControlSet(LPC_TIMER2, TIMER_EXTMATCH_DO_NOTHING, TIMER_EXTMATCH_TOGGLE, 0);
	Chip_TIMER_Enable(LPC_TIMER2);

	while (1);

	return 0;
}
