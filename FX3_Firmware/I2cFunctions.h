/**
  * Copyright (c) Analog Devices Inc, 2018 - 2020
  * All Rights Reserved.
  *
  * THIS SOFTWARE UTILIZES LIBRARIES DEVELOPED
  * AND MAINTAINED BY CYPRESS INC. THE LICENSE INCLUDED IN
  * THIS REPOSITORY DOES NOT EXTEND TO CYPRESS PROPERTY.
  *
  * Use of this file is governed by the license agreement
  * included in this repository.
  *
  * @file		I2cFunctions.c
  * @date		5/13/2020
  * @author		A. Nolan (alex.nolan@analog.com)
  * @brief 		Header file for USB-I2C interfacing module
 **/

#ifndef I2CFUNCTIONS_H_
#define I2CFUNCTIONS_H_

/* Public functions */
void AdiI2CReadHandler(uint16_t RequestLength);
void AdiI2CWriteHandler(uint16_t RequestLength);
void AdiI2CInit(uint32_t BitRate);

#endif /* I2CFUNCTIONS_H_ */
