/*
 * app.c
 *
 *  Created on: Oct 12, 2023
 *      Author: omars
 */

#include "lcd.h"
#include "motor.h"
#include "tempsensor.h"
#include "adc.h"


int main(void){
	uint8 temperature=0;
	LCD_init();
	ADC_ConfigType configure={Internal,F_CPU_8};
	ADC_init(&configure); /*Setup the ADC to work by internal voltage =2.56 and with clock Fcpu/8*/
	DcMotor_Init();
	LCD_displayStringRowColumn(0,4,"Fan is ");
	LCD_displayStringRowColumn(1,4,"Temp =    C");
	while(1){
	temperature=LM35_getTemperature();
	if(temperature<30){
		LCD_displayStringRowColumn(0,11,"OFF");
		LCD_moveCursor(1,11);
		LCD_intgerToString(temperature);
		LCD_displayCharacter(' ');
		DcMotor_Rotate(STOP,SPEED0); /*Zero speed by PWM signal with zero duty cycle*/
	}
	else if(temperature>=30 && temperature<60){
		LCD_displayStringRowColumn(0,11,"ON ");
		LCD_moveCursor(1,11);
		LCD_intgerToString(temperature);
		LCD_displayCharacter(' ');
		DcMotor_Rotate(CW,SPEED1); /*25% of the maximum speed PWM signal with 25% duty cycle*/
	}
	else if(temperature>=60 && temperature<90){
			LCD_displayStringRowColumn(0,11,"ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,SPEED2); /*50% of the maximum speed PWM signal with 50% duty cycle*/
		}
	else if(temperature>=90 && temperature<120){
			LCD_displayStringRowColumn(0,11,"ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temperature);
			if(temperature<100){
			LCD_displayCharacter(' ');
			}
			DcMotor_Rotate(CW,SPEED3); /*75% of the maximum speed PWM signal with 75% duty cycle*/
		}
	else if(temperature>=120){
			LCD_displayStringRowColumn(0,11,"ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW,SPEED4); /*100% of the maximum speed PWM signal with 100% duty cycle*/
		}
	}

}
