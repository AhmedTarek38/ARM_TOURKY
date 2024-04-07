/*
 * CLCD.h
 *
 *  Created on: Mar 21, 2024
 *      Author: ahmed tarek
 */

#ifndef CLCD_H_
#define CLCD_H_


#include "HAL/CLCD_CFG.h"
#include "MCAL/GPIO_Interface.h"

#define MAX_NO_ROWS     2                         // no. of lines
#define MAX_NO_COL     16                         //no. of characters per line (grids)

#define LINE1 0
#define LINE2 1

#define COL1  0
#define COL2  1
#define COL3  2
#define COL4  3
#define COL5  4
#define COL6  5
#define COL7  6
#define COL8  7
#define COL9  8
#define COL10 9
#define COL11 10
#define COL12 11
#define COL13 12
#define COL14 13
#define COL15 14
#define COL16 15




typedef enum
{
   CLCD_enuOK,
   CLCD_enuNOK

}CLCD_enuErrorStatus_t;



CLCD_enuErrorStatus_t CLCD_InitAsynch(void);
CLCD_enuErrorStatus_t CLCD_GetStatus(u8 *Ptr_LcdStatus);
CLCD_enuErrorStatus_t CLCD_ClearDisplayAsynch(void);
CLCD_enuErrorStatus_t CLCD_WriteStringAsynch(u8 * Ptr_string,u8 Length);
CLCD_enuErrorStatus_t CLCD_SetCursorAsynch(u8 XPOS,u8 YPOS);





#endif /* CLCD_H_ */
