/*
 * SWITCH_Program.c
 *
 *  Created on: Feb 20, 2024
 *      Author: ahmed tarek
 */

#include "MCAL/GPIO_Interface.h"
#include "HAL/SWITCH_Interface.h"

extern SWITCH_CFG_t SWITCHES [_SWITCH_NUM];


SWITCH_enuErrorStatus_t SWITCH_Init(void)

{
	SWITCH_enuErrorStatus_t Ret_enuErrorStatusSWITCH = SWITCH_enuOK;

	GPIO_PinConfig_t swtch;
	u8 Loc_iter=0;

	for (Loc_iter=0;Loc_iter<_SWITCH_NUM;Loc_iter++)

	{
		swtch.Pin = SWITCHES[Loc_iter].PIN;
		swtch.Port = SWITCHES[Loc_iter].PORT;
		swtch.Mode = SWITCHES[Loc_iter].Connection;
        GPIO_InitPin(&swtch);

	}

return Ret_enuErrorStatusSWITCH;


}

SWITCH_enuErrorStatus_t SWITCH_GetStatus(SWITCHES_t SWITCH_NAME, u32 * ptr_TO_SWITCHStatus)

{
	SWITCH_enuErrorStatus_t Ret_enuErrorStatusSWITCH = SWITCH_enuOK;
	u32 pin_status=0;
	if (SWITCH_NAME>_SWITCH_NUM)
	{

		Ret_enuErrorStatusSWITCH=SWITCH_enuNOK;
	}
	else if(ptr_TO_SWITCHStatus==NULL)
	{

		Ret_enuErrorStatusSWITCH=SWITCH_enuNOK;

	}
	else
	{
      GPIO_GetPinValue (SWITCHES[SWITCH_NAME].PORT,SWITCHES[SWITCH_NAME].PIN,&pin_status);


     		 /*            XOR                   PIN_CURRENT STATUS_HIGH(1)			PIN_CURRENT_STATUS_LOW(0)
     		 *
     		 *            (1)
     		 *  SWITCH_CONNECTION_MODE_INTPU 	   SWITCH_RELEASED(0)					SWITCH_PRESSED(1)
     		 *
     		 *            (0)
     		 *  SWITCH_CONNECTION_MODE_INTPD	   SWITCH_PRESSED(1)					SWITCH_RELEASED(0) */


      *ptr_TO_SWITCHStatus=(pin_status ^ (SWITCHES[SWITCH_NAME].Connection)>>3);

	}


return Ret_enuErrorStatusSWITCH;


}
