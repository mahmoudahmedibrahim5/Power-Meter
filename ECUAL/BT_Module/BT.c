/*
 * BT.c
 *
 *  Created on: Jun 17, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "BT.h"

void BT_init(BT_t* bt){
	USART_Config_t BM;
	BM.dataSize = _8_BIT;
	BM.mode = ASYNCHRONOUS;
	BM.overSampling = OVERSAMPLING16;
	BM.transmission = TX_AND_RX;
	BM.parityType = NO_PARITY;
	BM.stopBits = _1_BIT;
	BM.baudrate = bt->baudrate;

	USART_init(bt->USARTn, &BM);
}

void BT_sendData(BT_t* bt, uint8_t* buffer, uint32_t len){
	for(uint32_t i=0; i<len; i++){
		USART_sendData(bt->USARTn, buffer[i]);
	}
}

void BT_receiveData(BT_t* bt, uint8_t* buffer, uint32_t len){
	for(uint32_t i=0; i<len; i++){
		USART_receiveData(bt->USARTn, &buffer[i]);
	}
}
