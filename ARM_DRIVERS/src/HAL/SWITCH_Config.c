/*
 * SWITCH_Config.c
 *
 *  Created on: Feb 20, 2024
 *      Author: ahmed tarek
 */

#include "MCAL/GPIO_Interface.h"
#include "HAL/SWITCH_Interface.h"

/*ARRAY FOR CONFIGURATION OF THE SWITCHES(pin,port,connection) based on the gpio driver*/

SWITCH_CFG_t SWITCHES [_SWITCH_NUM]=

{
		[SWITCH_1]= {
				.PIN=GPIO_PIN5,
				.PORT=GPIOA_BASEADD,
				.Connection=GPIO_INPUT_PU

		},

		[SWITCH_2]= {
				.PIN=GPIO_PIN4,
				.PORT=GPIOB_BASEADD,
				.Connection=GPIO_INPUT_PU

		       	}


};

