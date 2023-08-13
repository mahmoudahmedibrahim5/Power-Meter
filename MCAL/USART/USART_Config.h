/*
 * USART_Config.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef USART_USART_CONFIG_H_
#define USART_USART_CONFIG_H_

#define F_CPU	16000000

typedef struct{
	uint8_t mode;
	uint8_t transmission;
	uint8_t overSampling;
	uint8_t dataSize;
	uint8_t stopBits;
	uint8_t parityType;
	uint32_t baudrate;
}USART_Config_t;

/* Modes */
#define ASYNCHRONOUS			0
#define HARDWARE_FLOW_CONTROL	1
#define MULTIBUFFER				2
#define MULTIPROCESSOR			3
#define SYNCHRONOUS				4
#define SMARTCARD				5
#define HALF_DUPLEX				6
#define IRDA					7
#define LIN						8
/* Transmission and Reception */
#define TX_ONLY		0
#define	RX_ONLY		1
#define TX_AND_RX	2
/* OverSampling */
#define OVERSAMPLING16	0
#define OVERSAMPLING8	1
/* Data size */
#define _8_BIT		0
#define _9_BIT		1
/* Stop Bits */
#define _1_BIT		0
#define _0_5_BIT	1
#define	_2_BIT		2
#define _1_5_BIT	3
/* Parity Type */
#define EVEN_PARITY	0
#define ODD_PARITY	1
#define NO_PARITY	2
/* BaudRate */

#endif /* USART_USART_CONFIG_H_ */
