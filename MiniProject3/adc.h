/*
 * adc.h
 *
 *  Created on: Oct 12, 2023
 *      Author: omars
 */

#ifndef ADC_H_
#define ADC_H_

#include "Standerd_Types_os.h"

/***************************************Definitions********************************/
#define VREF 2.56
#define ADC_N 1023

/***************************************Types Declaration********************************/
/* All available voltages*/
typedef enum{
 AREF,AVCC,Internal=3
}ADC_ReferenceVolatge;

/* All available prescalers*/
typedef enum{
	F_CPU_CLOCK,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

/* Structure that setup the ADC in ADC_init function */
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/***************************************Functions Prototype********************************/

/*
 * Description:
 * Choose working voltage AVCC,VREF,V_INTERNAL
 * Choose working prescaler
 * Enable the ADC
 * */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description:
 * Return the value that ADC read
 * */
uint16 ADC_readChannel(uint8 channel);

#endif /* ADC_H_ */
