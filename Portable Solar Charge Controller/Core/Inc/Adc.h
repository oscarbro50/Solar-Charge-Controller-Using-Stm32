/*
 * Adc.h
 *
 *  Created on: Apr 3, 2025
 *      Author: adeel.akhtar
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_
#include "stm32h7xx_hal.h"
#include "stm32h7xx_nucleo.h"
#include <stdio.h>
void MX_ADC1_Init(void);
void get_calibrated_voltage();
#endif /* INC_ADC_H_ */
