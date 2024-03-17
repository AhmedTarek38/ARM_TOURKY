/*
 * LED_Config.c
 *
 *  Created on: Feb 19, 2024
 *      Author: ahmed tarek
 */


#include "MCAL/GPIO_Interface.h"
#include "HAL/LED.h"

LED_CFG_t LEDS [_LED_NUM]=

{
		[LED_1]= {
				.PIN=GPIO_PIN0,
				.PORT=GPIOA_BASEADD,
				.Connection=LED_FORWARD,
				.Default_state=LED_OFF
		},

		[LED_2]= {
					.PIN=GPIO_PIN15,
					.PORT=GPIOB_BASEADD,
					.Connection=LED_FORWARD,
					.Default_state=LED_OFF
		       	}


};





