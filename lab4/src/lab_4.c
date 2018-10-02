/*
===============================================================================
 Name        : lab_4.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#define FirstDigit 9
#define SecondDigit 8
#define A 7
#define B 6
#define C 0
#define D 1
#define E 18
#define F 17
#define G 15
#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here
int main(void) {
    // TODO: insert code here

	int size = 7;
	int digit = {FirstDigit, SecondDigit};
	int seven_segment_pins[7] = {A,B,C,D,E,F,G};
	int num[10][7]= {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,1,0,1,1,0,1},{1,0,1,1,1,1,1}
	, {1,1,1,0,0,0,0},{1,1,1,1,1,1,1}, {1,1,1,1,0,1,1} };
	//Set led pins as output

    // Enter an infinite loop, just incrementing a counter
    while(1) {
        for(int i = 0; i < 10; i++)
        {
        	for(int j = 0; j < 7; j++)
        	{
        		Chip_GPIO_WritePortBit(LPC_GPIO,0,seven_segment_pins[j], num[i][j]);
        	}
        	for(int time = 0; time < 10000000; time++);
        }
    }
    return 0 ;
}
