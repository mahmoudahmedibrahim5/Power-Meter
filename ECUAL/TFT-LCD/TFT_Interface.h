/*
 * TFT_Interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Mahmoud Ahmed
 */

#ifndef TFT_LCD_TFT_INTERFACE_H_
#define TFT_LCD_TFT_INTERFACE_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"

#include "TFT_Private.h"
#include "TFT_Config.h"

typedef struct{
	st_SPI_RegDef_t* SPIn;
	EN_Port_t port;
	u8 CSX;
	u8 DCX;
}TFT_t;

void TFT_voidInit(TFT_t* tft);
void TFT_voidSendCommand(TFT_t* tft, u8 cmd);
void TFT_voidWrite(TFT_t* tft);
#endif /* TFT_LCD_TFT_INTERFACE_H_ */
