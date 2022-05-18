/*
 * decode.c
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam Wasilewski
 */

#include "decode.hpp"

extern Code c1;
uint32_t diff;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim3)
{
	diff = (c1.risingedge[1] - c1.risingedge[0]);

	if( (diff > 2100) && (diff < 2300))
	{
		c1.sector = Sector::SECTOR_1;
		c1.valid_code = true;
		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);

	}
	else if((diff > 1700) && (diff < 1900))
	{
		c1.sector = Sector::SECTOR_2;
		c1.valid_code = true;
		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);
	}
	else if((diff > 1300) && (diff < 1500))
	{
		c1.sector = Sector::SECTOR_3;
		c1.valid_code = true;
		HAL_TIM_IC_Stop_DMA(htim3, TIM_CHANNEL_3);
	}
	else
	{
		c1.sector = Sector::DEFAULT;
		c1.valid_code = false;
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim2)
{
	HAL_GPIO_TogglePin(GPIOC, LED_6_Pin);
}
