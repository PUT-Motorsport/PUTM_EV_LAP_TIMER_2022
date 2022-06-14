/*
 * Sector.c
 *
 *  Created on: 25 Apr 2022
 *      Author: Adam Wasilewski
 */

#include "Sector.hpp"
#include "can_interface.hpp"

extern Code c1;
extern CAN_HandleTypeDef hcan1;


void Sector_1()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_RESET);
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

