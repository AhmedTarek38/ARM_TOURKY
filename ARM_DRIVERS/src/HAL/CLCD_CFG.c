/*
 * LCD_CFG.c
 *
 *  Created on: Mar 21, 2024
 *      Author: ahmed tarek
 */
#include "HAL/CLCD_CFG.h"
#include "MCAL/GPIO_Interface.h"


CLCD_CFG_t LCDS[_LCD_NUM]=
{

				[D0]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN0} ,
				[D1]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN1} ,
				[D2]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN2} ,
				[D3]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN3} ,
				[D4]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN4} ,
				[D5]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN5} ,
				[D6]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN6} ,
				[D7]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN7} ,
				[RS]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN8} ,
				[RW]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN9} ,
				[EN]={.Port=GPIOA_BASEADD , .Pin=GPIO_PIN10} ,



};
