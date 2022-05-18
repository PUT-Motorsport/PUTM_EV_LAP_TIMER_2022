/*
 * decode.h
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam Wasilewski
 */

#ifndef INC_DECODE_HPP_
#define INC_DECODE_HPP_

#include "main.h"



enum struct Sector{
	SECTOR_1,
	SECTOR_2,
	SECTOR_3,
	DEFAULT
};


struct Code{
	uint32_t risingedge[2];
	bool valid_code;
	Sector sector;
};

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim);


#endif /* INC_DECODE_HPP_ */
