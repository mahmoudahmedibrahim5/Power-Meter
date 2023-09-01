/*
 * SPI_Registers.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SPI_SPI_REGISTERS_H_
#define SPI_SPI_REGISTERS_H_

#define SPI1_BASE_ADDR					0x40013000U
#define SPI2_BASE_ADDR					0x40003800U
#define SPI3_BASE_ADDR					0x40003C00U
#define SPI4_BASE_ADDR					0x40013400U

typedef volatile struct{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}st_SPI_RegDef_t;

#define SPI1		((st_SPI_RegDef_t *)SPI1_BASE_ADDR)
#define SPI2		((st_SPI_RegDef_t *)SPI2_BASE_ADDR)
#define SPI3		((st_SPI_RegDef_t *)SPI3_BASE_ADDR)
#define SPI4		((st_SPI_RegDef_t *)SPI4_BASE_ADDR)

#endif /* SPI_SPI_REGISTERS_H_ */
