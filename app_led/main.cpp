#include "mbed.h"

DigitalOut digital_out1(P0_9);
PwmOut PWM1(P2_0);
PwmOut PWM2(P2_1);

int main() {
	float i;
	PWM1.period(0.010); //Set PWm_period to 10 ms
	PWM2.period(0.010);

	digital_out1.write(1);
    while(1) {
        for(i =0; i < 1; i += 0.01)
        {
        	PWM1 = i;  //Set duty cycle to PWM1
        	PWM2 = 0.0;
        	wait(0.2);
        }
        PWM1= 0.0;
        PWM2 = 0.0;

        for(i =0; i < 1; i += 0.01)
        {
            PWM1 = 0.0;
            PWM2 = i; //Set duty cycle to PWM2
            wait(0.2);
         }

    }
}
