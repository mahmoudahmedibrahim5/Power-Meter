/*
 * SPI_Interface.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_

#include "../../Std Libraries/STD_TYPES.h"
#include "../GPIO/GPIO_Interface.h"
#include "SPI_Registers.h"
#include "SPI_Config.h"

void SPI_voidInit(st_SPI_RegDef_t* SPIn, SPI_Config_t* config);
void SPI_voidEnable(st_SPI_RegDef_t* SPIn);
void SPI_voidDisable(st_SPI_RegDef_t* SPIn, u8 duplex);

void SPI_voidSendData(st_SPI_RegDef_t* SPIn, u8 data);
void SPI_voidReceiveData(st_SPI_RegDef_t* SPIn, u8* data);

void SPI_voidBiderctionalUpdate(st_SPI_RegDef_t* SPIn, SPI_Config_t* config);

#endif /* SPI_SPI_INTERFACE_H_ */
