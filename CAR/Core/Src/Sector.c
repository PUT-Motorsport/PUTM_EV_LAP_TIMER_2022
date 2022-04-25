/*
 * Sector.c
 *
 *  Created on: 25 Apr 2022
 *      Author: wasyl
 */

#include "Sector.h"

extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef Tx1;
extern Code c1;

uint32_t mailbox = 0;

void Sector_1()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_RESET);
	HAL_CAN_AddTxMessage(&hcan1, &Tx1, &c1.sector, &mailbox);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_SET);
}
void Sector_2()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_SET);
	HAL_CAN_AddTxMessage(&hcan1, &Tx1, &c1.sector, &mailbox);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_SET);
}
void Sector_3()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_RESET);
	HAL_CAN_AddTxMessage(&hcan1, &Tx1, &c1.sector, &mailbox);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_SET);
}

