/*
 * Solar_Operations.h
 *
 *  Created on: Apr 3, 2025
 *      Author: adeel.akhtar
 */

#ifndef INC_SOLAR_OPERATIONS_H_
#define INC_SOLAR_OPERATIONS_H_

//---------these variables are real time variables used--------------------------------------------------
extern float max_battery_current;
extern float scaled_SV;
extern float scaled_BV;
extern float scaled_BC;
extern float solar_cuttoff_voltage;
extern float desire_pwm;
//----------------------------------------------------------------------------------------------------------


void get_inputs();
#endif /* INC_SOLAR_OPERATIONS_H_ */
