/*
 * decode.c
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam Wasilewski
 */

#include "decode.hpp"
#include <stdlib.h>

extern Code c1;

uint32_t diff;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim3)
{

	uint64_t diff1 = c1.risingedge[1] - c1.risingedge[0];
	uint64_t diff2 = c1.risingedge[3] - c1.risingedge[2];
	diff = (diff1 + diff2)/(uint32_t)2;


	//Recognize a sector
	if( (diff > 1800) && (diff < 2200))
	{
		c1.last_sector = c1.sector;
		c1.sector = START_FINISH;
		c1.code = CODE_OK;
		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);

	}
	else if((diff > 1700) && (diff < 1900))
	{
		c1.last_sector = c1.sector;
		c1.sector = SECTOR_2_SKIDPAD;
		c1.code = CODE_OK;
		//HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);
	}
	else if((diff > 1300) && (diff < 1500))
	{
		c1.last_sector = c1.sector;
		c1.sector = SECTOR_3_ACC;
		c1.code = CODE_OK;
		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);
	}
	else
	{
		c1.last_sector = c1.sector;
		c1.sector = DEFAULT;
		c1.code = CODE_NOT_OK;
	}
	diff = 0;
}

