/*
 * tempsensor.h
 *
 *  Created on: Oct 7, 2023
 *      Author: omars
 */

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include "Standerd_Types_OS.h"

/***********************************Definitions**********************/

#define MAX_VOLT_SENSOR 1.5
#define MAX_TEMP 150
#define SENSOR_CHANNEL_ID 2

/**********************************Functions Prototype*****************/


/*
 * Description:
 * read ADC value and calculate the real temperature
 * */
uint8 LM35_getTemperature(void);

#endif /* TEMPSENSOR_H_ */
