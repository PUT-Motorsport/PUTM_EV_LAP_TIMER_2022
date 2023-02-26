/*
 * decode.c
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam Wasilewski
 */
#include "decode.hpp"
#include "LED.hpp"
#include <stdlib.h>
#include <limits>
#include <vector>

#define NUM_OF_PERIODS 5

extern Code c1;

constexpr uint32_t uint32max = std::numeric_limits<uint32_t>::max();

int sum;
int counter;

void Decode(int, TIM_HandleTypeDef* htim3);

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim3)
{
	uint32_t diff = 0;
	int div = 0;
	for (int i = 0; i < NUM_OF_SAMPLES-1; i++)
	{
		uint32_t diff_tmp = (c1.risingedge[i + 1] - c1.risingedge[i])%uint32max;
	    if(diff_tmp < 10000)
	    {
	        diff += diff_tmp;
	        div++;
	    }
	}

	if(div != 0)
	{
		diff = diff/div;
	}

	sum += diff;
	counter++;
	if(counter == NUM_OF_PERIODS)
	{
		Decode(sum/counter, htim3);
		counter = 0;
		sum = 0;
	}

}
void Decode(int diff, TIM_HandleTypeDef* htim3)
{
	//Recognize a sector
 	if( (diff > 3000) && (diff < 4500))
	{
		c1.last_sector = c1.sector;
		c1.sector = START_FINISH;
		c1.code = CODE_OK;
		Set_Detecion();
		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);
	}
 	else if((diff > 4500) && (diff < 6500))
 	{
 		c1.last_sector = c1.sector;
 		c1.sector = SECTOR_2_SKIDPAD;
 		c1.code = CODE_OK;
 		Set_Detecion();
 		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);
 	}
 	else if((diff > 6500) && (diff < 9000))
 	{
 		c1.last_sector = c1.sector;
 		c1.sector = SECTOR_3_ACC;
 		c1.code = CODE_OK;
 		Set_Detecion();
 		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);
 	}
	else
	{
		c1.last_sector = c1.sector;
		c1.sector = DEFAULT;
		c1.code = CODE_NOT_OK;
	}
}

