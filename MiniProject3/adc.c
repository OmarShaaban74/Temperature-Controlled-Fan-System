/*
 * adc.c
 *
 *  Created on: Oct 12, 2023
 *      Author: omars
 */


#include <avr/io.h> /*to use I/O registers*/
#include "Common_Macros_OS.h" /*to use macros like SET_BIT*/
#include "adc.h"


/*
 * Description:
 * Choose working voltage AVCC,VREF,V_INTERNAL
 * Choose working prescaler
 * Enable the ADC
 * */
void ADC_init(const ADC_ConfigType * Config_Ptr){
	ADMUX=(ADMUX& (0x3F))|((Config_Ptr->ref_volt)<<6); /*select the volt*/
	SET_BIT(ADCSRA,ADEN); /*ADC Enable*/
	ADCSRA=(ADCSRA&(0xF8))|(Config_Ptr->prescaler); /*select the prescaler*/

}


/*
 * Description:
 * Return the value that ADC read
 * */
uint16 ADC_readChannel(uint8 channel){
	ADMUX= (ADMUX&0xE0) | (channel&0x07); /*select the channel*/
	SET_BIT(ADCSRA,ADSC); /*Start conversion*/
	/*Polling*/
	while(GET_BIT(ADCSRA,ADIF)==0); /*Check the flag that indicates that the conversion has finished*/
	SET_BIT(ADCSRA,ADIF); /*Remove the flag*/
	return ADC;
}
