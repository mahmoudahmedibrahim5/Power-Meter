/*
 * SPI_Config.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SPI_SPI_CONFIG_H_
#define SPI_SPI_CONFIG_H_

typedef struct{
	u8 mode;
	u8 duplex;
	u8 dataSize;
	u8 dataOrder;
	u8 slaveControl;
	u8 clockMode; 	// CPOL and CPHAs
	u8 baudrate;
}SPI_Config_t;

/* Main mode */
#define SPI_SLAVE					0
#define SPI_MASTER					1

/* Duplex */
#define SPI_FULL_DUPLEX				0
#define SPI_HALF_DUPLEX_TX			1
#define SPI_HALF_DUPLEX_RX			2

/* Data size */
#define SPI_DATA_LENGTH_8_BIT		0
#define	SPI_DATA_LENGTH_16_BIT		1

/* Data order */
#define	SPI_FIRST_BIT_MSB			0
#define SPI_FIRST_BIT_LSB			1

/* NSS pin control */
#define SPI_SLAVE_CONTROL_HARDWARE	0
#define SPI_SLAVE_CONTROL_SOFTWARE	1

/* Clock modes */
#define SPI_MODE0					0
#define SPI_MODE1					1
#define SPI_MODE2					2
#define SPI_MODE3					3

/* BaudRate */
#define SPI_PRESCALER2				0
#define SPI_PRESCALER4				1
#define SPI_PRESCALER8				2
#define SPI_PRESCALER16				3
#define SPI_PRESCALER32				4
#define SPI_PRESCALER64				5
#define SPI_PRESCALER128			6
#define SPI_PRESCALER256			7

#endif /* SPI_SPI_CONFIG_H_ */
