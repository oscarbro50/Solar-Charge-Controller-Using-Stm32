/*
 * Timer.h
 *
 *  Created on: Mar 27, 2025
 *      Author: adeel.akhtar
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "stm32h7xx_hal.h"
#include "stm32h7xx_nucleo.h"
#include <stdio.h>

extern TIM_HandleTypeDef htim1;
 void MX_TIM1_Init(void);
#endif /* INC_TIMER_H_ */
