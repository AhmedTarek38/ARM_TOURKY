/*
 * USART.h
 *
 *  Created on: Apr 13, 2024
 *      Author: ahmed tarek
 */

#ifndef USART_H_
#define USART_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/USART_CFG.h"




#define USART_1ID        0
#define USART_2ID        1
#define USART_3ID        2

typedef void (*Cb)(void);

typedef enum
{
	USART_enuOK,
	USART_enuNOK,

}USART_enuErrorStatus_t;

typedef struct
{
	u8  USART_ID;
	u32 BAUD_RATE;
	u32 WORD_LENGTH;
	u32 PARITY_EN;
	u32 PARITY_TYPE;
	u32 STOP_BITS;
	u32 OVER_SAMPLING_MODE;

}USART_Config_t;

typedef struct
{
	u8  USART_ID;
    u8 *Ptr_Buffer;
    u32 Buff_Length;
    Cb Buffer_cb;

}USART_UserReq_t;

USART_enuErrorStatus_t USART_Init(void);
USART_enuErrorStatus_t USART_SendByte(USART_UserReq_t *Ptr_UserReq);
USART_enuErrorStatus_t USART_GetByte(USART_UserReq_t *Ptr_UserReq);
USART_enuErrorStatus_t USART_TxBufferAsyncZC(USART_UserReq_t *Ptr_UserReq);
USART_enuErrorStatus_t USART_RxBufferAsyncZC(USART_UserReq_t *Ptr_UserReq);
USART_enuErrorStatus_t USART_TxDone(u8 USART_ID,u8 *Ptr_Status);
USART_enuErrorStatus_t USART_IsRX(u8 USART_ID,u8 *Ptr_Status);

#endif /* USART_H_ */
