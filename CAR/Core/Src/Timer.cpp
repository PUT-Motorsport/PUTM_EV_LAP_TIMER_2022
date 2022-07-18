/*
 * Timer.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */
#include <Timer.hpp>

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;

static struct time acc_time;
static struct time lap_time;
/**
* @brief Timer callback
* This function keeps track of lap time.
* @param: Pointer to timer handler
* @retval none
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIM2)
	{
		acc_time.miliseconds++;
		if(acc_time.miliseconds == 1000)
			{
				acc_time.seconds++;
				acc_time.miliseconds = 0;
			}
		if(acc_time.seconds == 60)
			{
				HAL_GPIO_TogglePin(LED_6_GPIO_Port, LED_6_Pin);
				acc_time.minute++;
				acc_time.seconds = 0;
			}
	}
	if(htim->Instance == TIM4)
	{
		lap_time.miliseconds++;
		if(lap_time.miliseconds == 1000)
		{
			lap_time.seconds++;
			lap_time.miliseconds = 0;
		}
		if(lap_time.seconds == 60)
		{
				HAL_GPIO_TogglePin(LED_6_GPIO_Port, LED_6_Pin);
				lap_time.minute++;
				lap_time.seconds = 0;
		}
	}
}
time Return_Lap_Time()
{
	return lap_time;
}

time Measure_Acc(bool Is_acc_measured)
{
	if(Is_acc_measured == true)
	{
		Reset();
		HAL_TIM_Base_Start_IT(&htim2);
	}
	else
	{
		 HAL_TIM_Base_Stop_IT(&htim2);
		 return acc_time;
	}
	time t2 = {};
	return t2;
}
/**
* @brief Reset
* This function Reset timer, calculate best time and induces function that display time on LCD.
* @param: none
* @retval none
*/
void Reset(void)
{
	acc_time.miliseconds = 0;
	acc_time.seconds = 0;
	acc_time.minute = 0;
}
