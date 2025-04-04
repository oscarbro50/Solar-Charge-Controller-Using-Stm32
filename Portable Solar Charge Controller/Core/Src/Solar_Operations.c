/*
 * Solar_Operations.c
 *
 *  Created on: Apr 3, 2025
 *      Author: adeel.akhtar
 */
#include "Solar_Operations.h"


// Final Scaled data after scaling use for operations
float scaled_SV=0;                  // scaled solar voltage
float scaled_BV=0;                  //scaled battery voltage
float scaled_BC=0;                  //scaled battery current
float battery_power = 0;

//-----------------------------------------------------------------------------------------------------------------------------------------------
void get_inputs(){
	get_calibrated_voltage();
}
