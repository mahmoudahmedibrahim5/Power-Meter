/*
 * RCC_Registers.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef RCC_RCC_REGISTERS_H_
#define RCC_RCC_REGISTERS_H_

typedef struct{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t reserved1[2];
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t reserved2[2];
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t reserved3[2];
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t reserved4[2];
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t reserved[2];
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t reserved6[2];
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t reserved7[2];
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
	uint32_t reserved8;
	uint32_t DCKCFGR;
}st_RCC_RegDef_t;

#define RCC		((volatile st_RCC_RegDef_t *)RCC_BASE_ADDR)

/* CR Register Bits */
#define RCC_CR_HSI_ON	0
#define RCC_CR_HSE_ON	16
#define RCC_CR_PLL_ON	24

/* CFGR Register Bits */
#define RCC_CFGR_HSI	0
#define RCC_CFGR_HSE	1
#define RCC_CFGR_PLL	2

#endif /* RCC_RCC_REGISTERS_H_ */
