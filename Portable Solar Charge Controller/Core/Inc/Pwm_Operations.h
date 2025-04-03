/*
 * pwm_operations.h
 *
 *  Created on: Mar 27, 2025
 *      Author: adeel.akhtar
 */

#include"Timer.h"


#ifndef INC_PWM_OPERATIONS_H_
#define INC_PWM_OPERATIONS_H_
#define IDD_ticks 7.2				//For Increment and Decrement DutyCycle by 0.2 percent
#define max_ticks 3231				//Max Dutycycle is 90% of 50Us (44.8us)

#define min_ticks 0					//Min Dutycycle is 0Us


extern int dutycycle;


void set_duty_cycle(int duty_percent);
void increment_duty_cycle();
void decrement_duty_cycle();
void stop_pwm();
#endif /* INC_PWM_OPERATIONS_H_ */
