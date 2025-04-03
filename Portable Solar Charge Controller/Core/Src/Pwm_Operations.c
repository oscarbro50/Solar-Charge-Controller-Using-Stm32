/*
 * pwm_operations.c
 *
 *  Created on: Mar 27, 2025
 *      Author: adeel.akhtar
 */
#include <Pwm_Operations.h>
int dutycycle=0;
void set_duty_cycle(int duty_percent){
	dutycycle=(duty_percent/100.0)*3590;

	if (dutycycle < min_ticks)
		{
	        dutycycle = min_ticks;
	    }

	if (dutycycle > max_ticks)
		{
	        dutycycle = max_ticks;
	    }


	TIM1->CCR1 = dutycycle;

}

void decrement_duty_cycle(){

    dutycycle -= IDD_ticks;
    if (dutycycle < min_ticks)
    {
        dutycycle = min_ticks;
    }

    if (dutycycle > max_ticks)
    {
        dutycycle = max_ticks;
    }

    TIM1->CCR1=dutycycle;
}

void increment_duty_cycle(){

    dutycycle += IDD_ticks;

    if (dutycycle < min_ticks)
    {
        dutycycle = min_ticks;
    }

    if (dutycycle > max_ticks)
    {
        dutycycle = max_ticks;
    }

    TIM1->CCR1=dutycycle;
}

void stop_pwm(){

	dutycycle=0;
	TIM1->CCR1=dutycycle;
}
