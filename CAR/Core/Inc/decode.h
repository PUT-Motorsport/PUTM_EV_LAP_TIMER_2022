/*
 * decode.h
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam
 */

#ifndef INC_DECODE_H_
#define INC_DECODE_H_

#include "main.h"

typedef enum{
	CODE_OK,
	CODE_NOT_OK
}Valid_Code;

typedef enum{
	SECTOR_1,
	SECTOR_2,
	SECTOR_3,
	DEFAULT
}Sector;


typedef struct {

	uint32_t risingedge[2];
	Valid_Code code;
	Sector sector;

}Code;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim);


#endif /* INC_DECODE_H_ */
