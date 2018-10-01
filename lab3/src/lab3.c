/*
===============================================================================
 Name        : lab3.c
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
#define FirstDigit 9
#define SecondDigit 8
#define infrared_sensor 1
#define sw 0
#define A 7
#define B 6
#define C 2
#define D 3
#define E 21
#define F 22
#define G 27

int size = 7;
int dig = 2;
int counter = 0;
int is_interrupt = 0;

int digit[2] = {FirstDigit, SecondDigit};
int seven_segment_pins[7] = {A,B,C,D,E,F,G};
int num[10][7] = {
    { 1,1,1,1,1,1,0 },    // 0
    { 0,1,1,0,0,0,0 },    // 1
    { 1,1,0,1,1,0,1 },    // 2
    { 1,1,1,1,0,0,1 },    // 3
    { 0,1,1,0,0,1,1 },    // 4
    { 1,0,1,1,0,1,1 },    // 5
    { 1,0,1,1,1,1,1 },    // 6
    { 1,1,1,0,0,0,0 },    // 7
    { 1,1,1,1,1,1,1 },    // 8
    { 1,1,1,0,0,1,1 }     // 9
};
int calculateDigits(int n)
{
	int result = 0;
	while(n != 0)
	    {
	        // n = n/10
	        n /= 10;
	        ++result;
	    }
	return result;
}

int getSecondDigit(int n)
{
	int second_digit = 0;
	second_digit = (n%100) / 10;
	if(n < 10 && n > 0){
		second_digit = 0;
	}
	return second_digit;
}

int getFirstDigit(int n)
{
	int first_digit = 0;
	first_digit = (n % 10);
	return first_digit;
}

void EINT3_IRQHandler(void)
{
	if(LPC_GPIOINT->IO0.STATR != 0)
	{
		if(Chip_GPIO_GetPinState(LPC_GPIO,0,infrared_sensor))
		{
			counter += 1;
		}
	}
	else if(LPC_GPIOINT -> IO0.STATF != 0)
	{
		if(!Chip_GPIO_GetPinState(LPC_GPIO,0,sw)){
			counter = 0;

		    for(int i = 0 ; i < 3; i++){
		    	Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[0], false);
		    	Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[1], true);
		    	for(int light = 0 ; light < size; light++){
		    			Chip_GPIO_WritePortBit(LPC_GPIO,0,seven_segment_pins[light], !(num[getSecondDigit(counter)][light]));
		    	}
		    	for(int time = 0; time < 5000000; time++);
		    		Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[0], true);
		    		Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[1], false);
		    		for(int light = 0 ; light < size; light++){
		    			Chip_GPIO_WritePortBit(LPC_GPIO,0,seven_segment_pins[light], !(num[getFirstDigit(counter)][light]));
		    		}
		    	for(int time = 0; time < 1000000; time++);
		    	}
		  }
	}
	Chip_GPIOINT_ClearIntStatus(LPC_GPIOINT, GPIOINT_PORT0, 1 << sw);
	Chip_GPIOINT_ClearIntStatus(LPC_GPIOINT, GPIOINT_PORT0, 1 << infrared_sensor);
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

    /*
    // TODO: insert code here
    int led_pins[4] = {6,7,8,9};
    int sw = 0;
    int size = 4;
    	//Set led pins as output
    for(int i = 0; i < size; i++)
    {
    	Chip_GPIO_SetDir(LPC_GPIO,0,led_pins[i], 1);
    }
    Chip_GPIO_SetDir(LPC_GPIO,0,sw, 0);
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        if(Chip_GPIO_GetPinState(LPC_GPIO,0,sw))
        {
        	for(int i =0 ; i < size; i++)
        	{
        		Chip_GPIO_WritePortBit(LPC_GPIO,0,led_pins[i], true);
        		for(int time = 0; time < 10000000; time++);
        		Chip_GPIO_WritePortBit(LPC_GPIO,0,led_pins[i], false);

        	}
        }
        else
        {
        	for(int i = size ; i>= 0; i--)
        	{
        		Chip_GPIO_WritePortBit(LPC_GPIO,0,led_pins[i], true);
        		for(int time = 0; time < 10000000; time++);
        		Chip_GPIO_WritePortBit(LPC_GPIO,0,led_pins[i], false);
        	}
        }
    }
    */

    Chip_GPIOINT_ClearIntStatus(LPC_GPIOINT, GPIOINT_PORT0, 1 << sw);
    Chip_GPIOINT_ClearIntStatus(LPC_GPIOINT, GPIOINT_PORT0, 1 << infrared_sensor);

    Chip_GPIOINT_SetIntFalling(LPC_GPIOINT, GPIOINT_PORT0, 1 << sw);
    Chip_GPIOINT_SetIntRising(LPC_GPIOINT, GPIOINT_PORT0, 1 << infrared_sensor);
    NVIC_ClearPendingIRQ(EINT3_IRQn);
    NVIC_EnableIRQ(EINT3_IRQn);
    Chip_GPIO_Init(0);

    Chip_GPIO_SetDir(LPC_GPIO,0,infrared_sensor, 0);
    Chip_GPIO_SetDir(LPC_GPIO,0,sw, 0);


    for(int pos = 0 ; pos < dig; pos++)
    {
    	Chip_GPIO_SetDir(LPC_GPIO,0,digit[pos], 1);
    }
    //Set led pins as output
    for(int i = 0; i < size; i++)
    {
    	Chip_GPIO_SetDir(LPC_GPIO,0,seven_segment_pins[i], 1);
    }
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	/*
    	if(counter >= 0 && counter < 100){

    			if(Chip_GPIO_GetPinState(LPC_GPIO,0,infrared_sensor) && !(is_interrupt))
    			{
    				counter += 1;
    				is_interrupt = 1;
    			}
    			if(!Chip_GPIO_GetPinState(LPC_GPIO,0,infrared_sensor))
    			{
    				is_interrupt = 0;

    			}
    			if(!Chip_GPIO_GetPinState(LPC_GPIO,0,sw)){
    			    	    counter = 0;
    			    	    for(int i = 0 ; i < 3; i++){
    							Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[0], false);
    							Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[1], true);
    							for(int light = 0 ; light < size; light++){
    								Chip_GPIO_WritePortBit(LPC_GPIO,0,seven_segment_pins[light], !(num[getSecondDigit(counter)][light]));
    							}
    							for(int time = 0; time < 5000000; time++);
    							Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[0], true);
    							Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[1], false);
    							for(int light = 0 ; light < size; light++){
    								Chip_GPIO_WritePortBit(LPC_GPIO,0,seven_segment_pins[light], !(num[getFirstDigit(counter)][light]));
    							}
    							for(int time = 0; time < 1000000; time++);
    			    	    }
    			}

		*/
    	if(counter >= 0 && counter < 100){
				Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[0], false);
				Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[1], true);
				for(int light = 0 ; light < size; light++){
				   Chip_GPIO_WritePortBit(LPC_GPIO,0,seven_segment_pins[light], !(num[getSecondDigit(counter)][light]));
				   }
				for(int time = 0; time < 100000; time++);
				Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[0], true);
				Chip_GPIO_WritePortBit(LPC_GPIO,0,digit[1], false);
				for(int light = 0 ; light < size; light++){
					Chip_GPIO_WritePortBit(LPC_GPIO,0,seven_segment_pins[light], !(num[getFirstDigit(counter)][light]));
				}
				for(int time = 0; time < 100000; time++);
    	}
    	else
    		counter = 0;

    }
    return 0 ;
}
