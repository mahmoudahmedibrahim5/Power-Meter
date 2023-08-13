/*
 * INA219_Interface.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef INA219_INA219_INTERFACE_H_
#define INA219_INA219_INTERFACE_H_

#include "../../MCAL/I2C/I2C_Interface.h"
#include "INA219_Registers.h"
#include "INA219_Config.h"

void INA219_init(INA219_t* config);
sint16_t INA219_readShuntVoltage(INA219_t* config);
uint16_t INA219_readBusVoltage(INA219_t* config);
sint16_t INA219_readCurrent(INA219_t* config);
uint16_t INA219_readPower(INA219_t* config);


#endif /* INA219_INA219_INTERFACE_H_ */
