/*
 * decode.h
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam Wasilewski
 */

#ifndef INC_DECODE_HPP_
#define INC_DECODE_HPP_

#include "main.h"

typedef enum{
	CODE_OK,
	CODE_NOT_OK
}Valid_Code;

typedef enum{
	START_FINISH,
	SECTOR_2_SKIDPAD,
	SECTOR_3_ACC,
	DEFAULT,
}Sector;


typedef struct {

	uint32_t risingedge[NUM_OF_SAMPLES];
	Valid_Code code;
	Sector sector;
	Sector last_sector;
	bool is_time_being_measured = false;
}Code;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim);


#endif /* INC_DECODE_HPP_ */
