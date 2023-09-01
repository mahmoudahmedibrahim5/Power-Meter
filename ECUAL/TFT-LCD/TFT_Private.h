/*
 * TFT_Registers.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Mahmoud Ahmed
 */

#ifndef TFT_LCD_TFT_REGISTERS_H_
#define TFT_LCD_TFT_REGISTERS_H_

/* COMMANDS in page 104
 *
 * */

#define TFT_CMD_INV_OFF		0x20
#define TFT_CMD_INV_ON		0x21

#define TFT_CMD_DSP_OFF 	0x28
#define TFT_CMD_DSP_ON		0x29
#define TFT_CMD_CASET		0x2A
#define TFT_CMD_RASET		0x2B
#define TFT_CMD_RAM_WR		0x2C
#define TFT_CMD_RAM_RD		0x2E

#define TFT_CMD_MADCTL		0x36
#define TFT_CMD_COLMOD		0x3A

#define TFT_CMD_IDM_OFF		0x38
#define TFT_CMD_IDM_ON		0x39

#define TFT_DCX_PIN_COMMAND	0
#define TFT_DCX_PIN_DATA	1

#endif /* TFT_LCD_TFT_REGISTERS_H_ */
