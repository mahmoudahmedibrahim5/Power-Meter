/*
 * INA219_Program.c
 *
 *  Created on: Jul 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "INA219_Interface.h"

I2C_Config_t INA219_I2C_config = {I2C_STANDARD, I2C_7_BIT, 100, 0x61, I2C_ACK_EN};

void INA219_init(INA219_t* config)
{
	// Initialize I2C
	I2C_init(config->I2Cn, &INA219_I2C_config);

	// Adjust Configuration Register
	// Working by default configuration for now

	// Adjust Calibration Register
	// Cal = 40 for MAX_CURRENT = 100 mA and Shunt Resistance = 330 Ω
	// Cal = 4194 for MAX_CURRENT = 3.2 A and Shunt Resistance = 100 mΩ
	// Cal = FFFF for maximum resolution MAX_CURRENT = 200 mA and LSB = 6.25 uA

	// 1000*1000 because Shunt resistance is in mΩ and Max current is in mA
	uint16_t calbReg = ((0.04096*1000*1000) * 32768)/(INA219_MAX_CURRENT*INA219_SHUNT_RESISTANCE);
	uint8_t data[3] = {INA219_REG_CALIBRATION, (calbReg>>8), (calbReg & 0xFF)};

	// Send the Address of Shunt Voltage Register
	I2C_masterSendData(config->I2Cn, config->slaveAddress, data, 3, I2C_RS_DISABLE);
}


sint16_t INA219_readShuntVoltage(INA219_t* config)
{
	uint8_t data[2];
	uint8_t address = INA219_REG_SHUNT_VOLTAGE;

	// Send the Address of Shunt Voltage Register
	I2C_masterSendData(config->I2Cn, config->slaveAddress, &address, 1, I2C_RS_DISABLE);

	// Read 16-bit register
	I2C_masterReceiveData(config->I2Cn, config->slaveAddress, data, 2, I2C_RS_DISABLE);
	sint16_t regRead = ((data[0]<<8) | data[1]);

	return regRead;
}

uint16_t INA219_readBusVoltage(INA219_t* config)
{
	uint8_t data[2];
	uint8_t address = INA219_REG_BUS_VOLTAGE;

	// Send the Address of Bus Voltage Register
	I2C_masterSendData(config->I2Cn, config->slaveAddress, &address, 1, I2C_RS_DISABLE);

	// Read 16-bit register
	I2C_masterReceiveData(config->I2Cn, config->slaveAddress, data, 2, I2C_RS_DISABLE);
	uint16_t regRead = ((data[0]<<8) | data[1]);

	// LSB = 4 mV
	return (4*(regRead>>3));
}

sint16_t INA219_readCurrent(INA219_t* config)
{
	uint8_t data[2];
	uint8_t address = INA219_REG_CURRENT;

	// Send the Address of Bus Voltage Register
	I2C_masterSendData(config->I2Cn, config->slaveAddress, &address, 1, I2C_RS_DISABLE);

	// Read 16-bit register
	I2C_masterReceiveData(config->I2Cn, config->slaveAddress, data, 2, I2C_RS_DISABLE);
	uint16_t regRead = ((data[0]<<8) | data[1]);

	return regRead * ((INA219_MAX_CURRENT*1000)/32768);
}

uint16_t INA219_readPower(INA219_t* config)
{
	uint8_t data[2];
	uint8_t address = INA219_REG_POWER;

	// Send the Address of Bus Voltage Register
	I2C_masterSendData(config->I2Cn, config->slaveAddress, &address, 1, I2C_RS_DISABLE);

	// Read 16-bit register
	I2C_masterReceiveData(config->I2Cn, config->slaveAddress, data, 2, I2C_RS_DISABLE);
	uint16_t regRead = ((data[0]<<8) | data[1]);

	return regRead;
}
