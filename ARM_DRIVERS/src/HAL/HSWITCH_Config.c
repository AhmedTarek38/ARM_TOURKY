/*
 * HSWITCH_Config.c
 *
 *  Created on: Apr 13, 2024
 *      Author: ahmed tarek
 */
#include "MCAL/GPIO_Interface.h"
#include "HAL/HSWITCH.h"

/*ARRAY FOR CONFIGURATION OF THE SWITCHES(pin,port,connection) based on the gpio driver*/

HSWITCH_CFG_t HSWITCHES [_HSWITCH_NUM]=

{
		[HSWITCH_1]= {
				.PIN=GPIO_PIN5,
				.PORT=GPIOB_BASEADD,
				.Connection=GPIO_INPUT_PU

		},

		[HSWITCH_2]= {
				.PIN=GPIO_PIN6,
				.PORT=GPIOB_BASEADD,
				.Connection=GPIO_INPUT_PU

		       	},
		[HSWITCH_3]= {
						.PIN=GPIO_PIN7,
						.PORT=GPIOB_BASEADD,
						.Connection=GPIO_INPUT_PU

				       	}


};

