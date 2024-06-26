/*
 * HSWITCH.c
 *
 *  Created on: Apr 13, 2024
 *      Author: ahmed tarek
 */
#include "MCAL/GPIO_Interface.h"
#include "HAL/HSWITCH.h"

extern HSWITCH_CFG_t HSWITCHES [_HSWITCH_NUM];
static u8 HSWITCH_status[_HSWITCH_NUM];

HSWITCH_enuErrorStatus_t HSWITCH_Init(void)
{

	{
		HSWITCH_enuErrorStatus_t Ret_enuErrorStatusHSWITCH = HSWITCH_enuOK;

		GPIO_PinConfig_t Hswtch;
		u8 Loc_iter=0;

		for (Loc_iter=0;Loc_iter<_HSWITCH_NUM;Loc_iter++)

		{
			Hswtch.Pin =  HSWITCHES[Loc_iter].PIN;
			Hswtch.Port = HSWITCHES[Loc_iter].PORT;
			Hswtch.Mode = HSWITCHES[Loc_iter].Connection;
			Ret_enuErrorStatusHSWITCH = GPIO_InitPin(&Hswtch);

		}

	return Ret_enuErrorStatusHSWITCH;

    }
}

HSWITCH_enuErrorStatus_t HSWITCH_GetStatus(HSWITCHES_t HSWITCH_NAME, u8 * ptr_TO_HSWITCHStatus)
{
	HSWITCH_enuErrorStatus_t Ret_enuErrorStatusHSWITCH = HSWITCH_enuOK;

		if (HSWITCH_NAME>_HSWITCH_NUM)
		{

			Ret_enuErrorStatusHSWITCH=HSWITCH_enuNOK;
		}
		else if(ptr_TO_HSWITCHStatus==NULL)
		{

			Ret_enuErrorStatusHSWITCH=HSWITCH_enuNOK;

		}
		else
		{
			*ptr_TO_HSWITCHStatus=HSWITCH_status[HSWITCH_NAME];
		}
			return Ret_enuErrorStatusHSWITCH;

}

void Runnable_HSWITCH(void)
{
	u8  HSWITCH_Previous_STATE[_HSWITCH_NUM];
	u32 HSWITCH_CHANGE_COUNTS[_HSWITCH_NUM];
	u8  HSWITCH_Current_STATE;
	u8 Loc_iterator;

	for (Loc_iterator=0;Loc_iterator<_HSWITCH_NUM;Loc_iterator++)
	{
		GPIO_GetPinValue(HSWITCHES[Loc_iterator].PORT,HSWITCHES[Loc_iterator].PIN,& HSWITCH_Current_STATE);

		if (HSWITCH_Current_STATE==HSWITCH_Previous_STATE[Loc_iterator])
		{
			HSWITCH_CHANGE_COUNTS[Loc_iterator]++;
		}
		else
		{
			HSWITCH_CHANGE_COUNTS[Loc_iterator]=0;

		}
		if (HSWITCH_CHANGE_COUNTS[Loc_iterator]%5 == 0)
		{
			HSWITCH_status[Loc_iterator]=HSWITCH_Current_STATE ^ ((HSWITCHES[Loc_iterator].Connection)>>3);
		}

        HSWITCH_Previous_STATE[Loc_iterator]=HSWITCH_Current_STATE;

	}
}

















