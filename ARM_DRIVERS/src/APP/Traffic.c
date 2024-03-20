/*
 * Traffic.c
 *
 *  Created on: Mar 18, 2024
 *      Author: ahmed tarek
 */
#include "APP/Traffic.h"
#define ENABLE 1
#define DISABLE 0

Traffic_CFG_t TrafficStatus =LED1_Green;

void Traffic_light_init(void)
{
	    RCC_EnableClk(CLOCK_enuHSI,CSS_enuON);
		RCC_SelectSysClk(CLOCK_enuHSI);
		RCC_ControlPeripheral(RCC_AHB1,GPIOA,ENABLE);
		LED_Init();

}

static void GreenLight(void)
{
	LED_SetStatus(LED_1,LED_ON);
	LED_SetStatus(LED_2,LED_OFF);
	LED_SetStatus(LED_3,LED_OFF);

}

static void YellowLight(void)
{
	LED_SetStatus(LED_1,LED_OFF);
	LED_SetStatus(LED_2,LED_ON);
	LED_SetStatus(LED_3,LED_OFF);

}

static void REDLight(void)
{
	LED_SetStatus(LED_1,LED_OFF);
	LED_SetStatus(LED_2,LED_OFF);
	LED_SetStatus(LED_3,LED_ON);

}

void RunnableTraffic(void)
{
	static u32 seconds =0;

	static u8 prev=0;

	seconds+=PERIODICIY_SEC;
	switch (TrafficStatus)
	{
	case LED1_Green:
		GreenLight();
		if (seconds%6==0)
		{
			TrafficStatus=LED2_Yellow;
			prev=LED1_Green;

		} break;
	case LED2_Yellow:
		YellowLight();
			if (seconds%2==0)
			{
				if (prev == LED3_RED) {
				    TrafficStatus = LED1_Green;
				} else {
				    TrafficStatus = LED3_RED;
				}

			} break;


	case LED3_RED:
		REDLight();
					if (seconds%4==0)
					{
						TrafficStatus=LED2_Yellow;
									prev=LED3_RED;

					} break;










	}






}
