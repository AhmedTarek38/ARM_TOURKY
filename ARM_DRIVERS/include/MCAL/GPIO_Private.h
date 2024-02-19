#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "LIB/STD_TYPES.h"

#define NULL ((void*)0)
#define GPIOA_BASEADD  (void*)(0x40020000)
#define GPIOB_BASEADD  (void*)(0x40020400)
#define GPIOC_BASEADD  (void*)(0x40020800)
#define GPIOD_BASEADD  (void*)(0x40020C00)
#define GPIOE_BASEADD  (void*)(0x40021000)
#define GPIOH_BASEADD  (void*)(0x40021C00)

#define GPIO_GETMODE_MASK       0x00000003
#define GPIO_GETOUT_TYPE_MASK   0x00000004
#define GPIO_GETPULL_TYPE_MASK  0x000000018

#define GPIO_OUT_TYPE_SHIFT         2
#define GPIO_PULL_TYPE_SHIFT        3

#define GPIO_CLEAR_MODE_BITS        0x00000003
#define GPIO_CLEAR_OUTTYPE_BIT      0x00000001
#define GPIO_CLEAR_PUPD_BITS        0x00000003
#define GPIO_CLEAR_SPEED_BITS       0x00000003

#define SHIFT_MULTIPLICATION_FACTOR       					0x00000002



typedef struct
{
    u32 volatile GPIO_MODER;
    u32 volatile GPIO_OTYPER;
    u32 volatile GPIO_OSPEEDR;
    u32 volatile GPIO_PUPDR;
    u32 volatile GPIO_IDR;
    u32 volatile GPIO_ODR;
    u32 volatile GPIO_BSRR;
    u32 volatile GPIO_LCKR;
    u32 volatile GPIO_AFRL;
    u32 volatile GPIO_AFRH;
}GPIO_PortRegisters;

#define GPIO_A							((volatile GPIO_PortRegisters*)(GPIOA_BASEADD))
#define GPIO_B							((volatile GPIO_PortRegisters*)(GPIOB_BASEADD))
#define GPIO_C							((volatile GPIO_PortRegisters*)(GPIOC_BASEADD))
#define GPIO_D							((volatile GPIO_PortRegisters*)(GPIOD_BASEADD))
#define GPIO_E							((volatile GPIO_PortRegisters*)(GPIOE_BASEADD))
#define GPIO_H							((volatile GPIO_PortRegisters*)(GPIOH_BASEADD))




#endif
