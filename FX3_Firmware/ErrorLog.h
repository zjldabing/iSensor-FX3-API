/**
  * Copyright (c) Analog Devices Inc, 2018 - 2019
  * All Rights Reserved.
  *
  * THIS SOFTWARE UTILIZES LIBRARIES DEVELOPED
  * AND MAINTAINED BY CYPRESS INC. THE LICENSE INCLUDED IN
  * THIS REPOSITORY DOES NOT EXTEND TO CYPRESS PROPERTY.
  *
  * Use of this file is governed by the license agreement
  * included in this repository.
  *
  * @file		ErrorLog.h
  * @date		12/6/2019
  * @author		A. Nolan (alex.nolan@analog.com)
  * @brief Header file for error logging capabilities
 **/

#ifndef ERRORLOG_H_
#define ERRORLOG_H_

/* Include the main header file */
#include "main.h"

/* Defines */

/** The log start address in flash (start at 64KB to leave size for bootloader) */
#define LOG_BASE_ADDR							(0x10000)

/** The max log capacity for the ring buffer (128KB / 32 bytes per entry) */
#define LOG_CAPACITY							(4095)

/** The flash address of the current log count (64KB - 4bytes) */
#define LOG_COUNT_ADDR							(0xFFFC)

/** The max allowed write address in flash */
#define FLASH_SIZE								(0x40000)

/** Enum to identify the source file which threw an error. More RAM efficient than the __LINE__ directive (gives full path) */
typedef enum FileIdentifier
{
	Unknown = 0,
	Main_c = 1,
	AppThread_c = 2,
	StreamThread_c = 3,
	PinFunctions_c = 4,
	SpiFunctions_c = 5,
	StreamFunctions_c = 6,
	Flash_c = 7,
	ErrorLog_c = 8
}FileIdentifier;

/**
  * @brief Structure which holds all information about a given error event
  *
  * This struct contains all pertinent information about a given hard crash event. This struct is
  * generated By AdiLogError, and stored to flash in a ring buffer. The total size of this
  * struct is 25 bytes, stored in 32 byte increments.
 **/
typedef struct __attribute__((__packed__)) ErrorMsg
{
	/** The line which caused the error. Should be set by __LINE__ macro in AdiLogError call */
	uint32_t Line;

	/** The error code from the set of cypress defined error codes */
	uint32_t ErrorCode;

	/** The Unix time stamp for when the instance of the FX3 booted */
	uint32_t BootTimeCode;

	/** The file which originated the error. Is a FileIdentifier cast into byte to save flash size */
	uint8_t File;

	/** The firmware version number */
	uint8_t FirmwareVersion[12];
}ErrorMsg;

/* External functions */
void AdiLogError(FileIdentifier File, uint32_t Line, uint32_t ErrorCode);

#endif /* ERRORLOG_H_ */
