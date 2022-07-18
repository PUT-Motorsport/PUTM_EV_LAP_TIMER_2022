/*
 * Sector.c
 *
 *  Created on: 25 Apr 2022
 *      Author: Adam Wasilewski
 */

#include "Sector.hpp"
#include "can_interface.hpp"
#include "Timer.hpp"

extern Code c1;
extern CAN_HandleTypeDef hcan1;
extern TIM_HandleTypeDef htim4;

void Sector_1()
{
	bool Lap_Time_Available = false;
	if(HAL_TIM_Base_GetState(&htim4) == HAL_TIM_STATE_BUSY)
	{
		//get results down below.
		HAL_TIM_Base_Stop_IT(&htim4);
		Lap_Time_Available = true;
	}
	else
	{
		//start lap timer.
		HAL_TIM_Base_Start_IT(&htim4);
	}

	//Indicate wich sector a car is currently in.
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_RESET);
	//Send sector ID on CAN bus.
	PUTM_CAN::Lap_timer_Pass Pass_Frame{
		.Sector = 0x00,
	};
	auto Lap_timer_frame = PUTM_CAN::Can_tx_message<PUTM_CAN::Lap_timer_Pass>(Pass_Frame, PUTM_CAN::can_tx_header_LAP_TIMER_PASS);
	auto status = Lap_timer_frame.send(hcan1);
	if(status != HAL_StatusTypeDef::HAL_OK)
	{
		Error_Handler();
	}
	HAL_Delay(200);
	//If available, send lap tima on CAN bus.
	if(Lap_Time_Available == true)
	{
		//Send.
		time finished_lap = Return_Lap_Time();
	}
	else
	{
		//do nothing.
	}
}
void Sector_2()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_SET);
	PUTM_CAN::Lap_timer_Pass Pass_Frame{
			.Sector = 0x00,
		};
	auto Lap_timer_frame = PUTM_CAN::Can_tx_message<PUTM_CAN::Lap_timer_Pass>(Pass_Frame, PUTM_CAN::can_tx_header_LAP_TIMER_PASS);
		auto status = Lap_timer_frame.send(hcan1);
		if(status != HAL_StatusTypeDef::HAL_OK)
		{
			Error_Handler();
		}
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_SET);
}
void Sector_3()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_RESET);
	PUTM_CAN::Lap_timer_Pass Pass_Frame{
			.Sector = 0x01,
		};
	auto Lap_timer_frame = PUTM_CAN::Can_tx_message<PUTM_CAN::Lap_timer_Pass>(Pass_Frame, PUTM_CAN::can_tx_header_LAP_TIMER_PASS);
		auto status = Lap_timer_frame.send(hcan1);
		if(status != HAL_StatusTypeDef::HAL_OK)
		{
			Error_Handler();
		}
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_SET);
}
void Send_Acc_Time(time acc)
{
	if(acc.seconds < 1)
	{
		//Lap timer just started measuring time, thus acc time = 0.
	}
	else
	{
		//Send via CAN bus.
	}
}

