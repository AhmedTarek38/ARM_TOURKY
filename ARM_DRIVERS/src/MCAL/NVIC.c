/*
 * NVIC.c
 *
 *  Created on: Mar 5, 2024
 *      Author: ahmed tarek
 */

#include "MCAL/NVIC.h"


#define BITS_PER_REG            32
#define NO_OF_IP_FIELDS_PER_REG  4
#define BITS_PER_IPR             8
#define FOUR_BITS_LOW            4
#define PRIORITY_GROUP_MASK      0x5FA0300
#define DIVISION_FACTOR_PRIORITY 256
#define CLR_MASK                 0x0000000F

#define NVIC_BASE_ADDRESS 0xE000E100
#define SCB_BASE_ADDRESS  0xE000ED00

typedef struct
{

    /*ISER0 -> ISER7  */
   u32 NVIC_ISER[8];
    /* Reserved 1 */
   u32 RESERVED1[24];
    /* ICER0->ICER7 */
   u32 NVIC_ICER[8];
    /* Reserved 2 */
   u32 RESERVED2[24];
    /* ISPR0->ISPR7 */
   u32 NVIC_ISPR[8];
    /* Reserved 3 */
   u32 RESERVED3[24];
    /* ICPR0->ICPR7*/
   u32 NVIC_ICPR[8];
    /* Reserved 4 */
   u32 RESERVED4[24];
    /*IABR0->IAPR7 */
   u32 NVIC_IABR[8];
    /* Reserved 5 */
   u32 RESERVED5[56];
    /* IPR0->IPR9  */
   u32 NVIC_IPR[60];
    /* Reserved 6 */
   u32 RESERVED6[580];
    /* STIR */
   u32 NVIC_STIR;
} NVIC_PERI_t;

typedef struct
{
   u32 CPUID;
    u32 ICSR;
    u32 VTOR;
    u32 AIRCR;
    u32 SCR;
    u32 CCR;
    u32 SHPR1;
    u32 SHPR2;
    u32 SHPR3;
    u32 SHCSR;
    u32 CFSR;
    u32 HFSR;
    u32 reserved;
    u32 MMAR;
    u32 BFAR;
    u32 AFSR;
} SCB_PERI_t;

volatile NVIC_PERI_t *const NVIC = (volatile NVIC_PERI_t *)NVIC_BASE_ADDRESS;
volatile SCB_PERI_t *const SCB = (volatile SCB_PERI_t *)SCB_BASE_ADDRESS;

NVIC_enuErrorStatus_t  Enable_NVIC_IRQ(IRQn_t IRQn)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;

	/*get the index of the register ISER0 ->ISER7 and save it in local variable*/
	u8 Loc_REGIndex=(IRQn/BITS_PER_REG);

	if (IRQn >= _INT_Num)
	{
		Ret_enuErrorStatusNVIC = NVIC_enuNOK;
	}
	else
	{
		/*set the corresponding bit by 1 to enable the interrupt in  ISER0 ->ISER7 */
		NVIC->NVIC_ISER[Loc_REGIndex]= (1<<(IRQn % BITS_PER_REG));
	}
	return Ret_enuErrorStatusNVIC;
}


NVIC_enuErrorStatus_t  Disable_NVIC_IRQ(IRQn_t IRQn)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;
	u8 Loc_REGIndex=(IRQn/BITS_PER_REG);

	if (IRQn >= _INT_Num)
	{
		Ret_enuErrorStatusNVIC = NVIC_enuNOK;
	}
	else
	{

		NVIC->NVIC_ICER[Loc_REGIndex]= (1<<(IRQn % BITS_PER_REG));
	}
	return Ret_enuErrorStatusNVIC;

}


NVIC_enuErrorStatus_t  SetPendingIRQ(IRQn_t IRQn)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;
	u8 Loc_REGIndex=(IRQn/BITS_PER_REG);

	if (IRQn >= _INT_Num)
	{
		Ret_enuErrorStatusNVIC = NVIC_enuNOK;
	}
	else
	{

		NVIC->NVIC_ISPR[Loc_REGIndex]= (1<<(IRQn % BITS_PER_REG));
	}
	return Ret_enuErrorStatusNVIC;


}


NVIC_enuErrorStatus_t  ClearPendingIRQ(IRQn_t IRQn)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;
	u8 Loc_REGIndex=(IRQn/BITS_PER_REG);

	if (IRQn >= _INT_Num)
	{
		Ret_enuErrorStatusNVIC = NVIC_enuNOK;
	}
	else
	{

		NVIC->NVIC_ICPR[Loc_REGIndex]= (1<<(IRQn % BITS_PER_REG));
	}
	return Ret_enuErrorStatusNVIC;


}


NVIC_enuErrorStatus_t  GetPendingIRQ(IRQn_t IRQn, u8 *ptr_status)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;
		u8 Loc_REGIndex=(IRQn/BITS_PER_REG);

		if (IRQn >= _INT_Num)
		{
			Ret_enuErrorStatusNVIC = NVIC_enuNOK;
		}
		else if (ptr_status==NULL)
		{

			Ret_enuErrorStatusNVIC = NVIC_enuNOK;

		}
		else
		{

			*ptr_status=(NVIC->NVIC_ISPR[Loc_REGIndex]>>(IRQn % BITS_PER_REG))& 0x01;

		}

		return Ret_enuErrorStatusNVIC;
}


NVIC_enuErrorStatus_t  GetActiveStatusIRQ(IRQn_t IRQn, u8 *ptr_status)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;
			u8 Loc_REGIndex=(IRQn/BITS_PER_REG);

			if (IRQn >= _INT_Num)
			{
				Ret_enuErrorStatusNVIC = NVIC_enuNOK;
			}
			else if (ptr_status==NULL)
			{

				Ret_enuErrorStatusNVIC = NVIC_enuNOK;

			}
			else
			{

				*ptr_status=(NVIC->NVIC_IABR[Loc_REGIndex]>>(IRQn % BITS_PER_REG))& 0x01;

			}

			return Ret_enuErrorStatusNVIC;


}


NVIC_enuErrorStatus_t  SetPriority(IRQn_t IRQn, u8 PreemptionGroup ,u8 SubpriorityGroup ,u32 Priority )

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;

	 if (PreemptionGroup > 15     ||
	     SubpriorityGroup > 15    ||
	        IRQn > _INT_Num       ||
	        (Priority < PRIORITY_GROUP0)                ||
	        (Priority > PRIORITY_GROUP4)                )
	    {
	        Ret_enuErrorStatusNVIC = NVIC_enuNOK;
	    }
	 else
	 {
         /* get the index of the register*/
	u8 Loc_REGIndex=(IRQn/NO_OF_IP_FIELDS_PER_REG);

    /*Variable that will represent the High 4 bits for the preemprion group and subgroup priority
      based on the priority grouping value the user will enter by oring the subgroup priority bits
       with the result of the preemtion group shifted left by the subtraction between the priority grouping value user entered
       and 0x5FA0300 divided by 256*/

	/*EX
	 * IRQn = x
	 * PreemptionGroup=1;
	 * SubpriorityGroup=1;
	 * Priority=PRIORITY_GROUP1; //3 bits for pree , 1 bit for sub
	 * 	u32 Loc_priority= SubpriorityGroup|(PreemptionGroup <<((Priority  - PRIORITY_GROUP_MASK)/DIVISION_FACTOR_PRIORITY));
	 *  u32 Loc_priority=         1       |       0001      <<((0x5FA0400 -     0x5FA0300     )/256
	 *  u32 Loc_priority=         1       |       0001      <<((0x100     )/256   //0x100=256
	 *  u32 Loc_priority=         1       |       0001      << 1
	 *  u32 Loc_priority=         1       |       0001      << 1
	 *  u32 Loc_priority=         1       |       0010
	    u32 Loc_priority=       [0011] // 3 bits for group so group 1, 1 bit for sub so subgroup 1
	 *
	 */
	u32 Loc_priority= SubpriorityGroup|(PreemptionGroup <<((Priority - PRIORITY_GROUP_MASK)/DIVISION_FACTOR_PRIORITY));

	/*the index of the required Reg according to IRQn*/

	u8 Loc_Shift_value = ((IRQn % NO_OF_IP_FIELDS_PER_REG) * BITS_PER_IPR) + FOUR_BITS_LOW;

    u32 Loc_TempReg = NVIC->NVIC_IPR[Loc_REGIndex] ;
    Loc_priority=Loc_priority<<Loc_Shift_value;
    Loc_TempReg &= ~(CLR_MASK<<Loc_Shift_value);
    Loc_TempReg = Loc_priority;


	NVIC->NVIC_IPR[Loc_REGIndex]=Loc_TempReg;

	SCB->AIRCR= Priority;

	 }

	return Ret_enuErrorStatusNVIC;


}


NVIC_enuErrorStatus_t  GetPriority(IRQn_t IRQn, u8 *ptr_status)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;

	if (IRQn>_INT_Num)
	{
		Ret_enuErrorStatusNVIC=NVIC_enuNOK;
	}

	else if(ptr_status==NULL)
	{
		Ret_enuErrorStatusNVIC=NVIC_enuNOK;

	}
	else
	{

	u8 Loc_REGIndex=(IRQn/NO_OF_IP_FIELDS_PER_REG);

	u8 Loc_Shift_value = ((IRQn % NO_OF_IP_FIELDS_PER_REG) * BITS_PER_IPR) + FOUR_BITS_LOW;

	*ptr_status=((NVIC->NVIC_IPR[Loc_REGIndex])>>Loc_Shift_value)&0x0F;
	}
 return Ret_enuErrorStatusNVIC;
}


NVIC_enuErrorStatus_t  Generate_SW_Interrupt(IRQn_t IRQn)

{
	NVIC_enuErrorStatus_t Ret_enuErrorStatusNVIC = NVIC_enuOK;

	if (IRQn>_INT_Num)
		{
			Ret_enuErrorStatusNVIC=NVIC_enuNOK;
		}
	else
	{

	NVIC->NVIC_STIR=IRQn;
	}

	 return Ret_enuErrorStatusNVIC;


}



