/*
 * send_start_stop_frame.c
 *
 *  Created on: Feb 26, 2022
 *      Author: Adam Wasilewski
 */

#include "send_start_stop_frame.h"

uint8_t pData = 0xff;
uint32_t TxMailbox = 0;

uint8_t SendFrameFlag = 1;

extern CAN_HandleTypeDef hcan1;
extern TIM_HandleTypeDef htim2;

//Declare CAN Tx message header.
const static CAN_TxHeaderTypeDef Tx1()
{
	CAN_TxHeaderTypeDef Tx1;
	Tx1.StdId = 0x0a;
	Tx1.ExtId = 0;
	Tx1.IDE = CAN_ID_STD;
	Tx1.RTR = CAN_RTR_DATA;
	Tx1.DLC = 8;
	return Tx1;
}
/**
* @brief Timer callback
* This function prevents multiple CAN frames from being sent, by utilizing time blockade.
* @param: Pointer to timer handler
* @retval Bool. True if its data, false if its a toggle frame.
*/
void HAL_TIM_PeriodElapsedCallback1(TIM_HandleTypeDef* htim2)
{
	SendFrameFlag = 1;
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, 1);
	__HAL_TIM_SET_COUNTER(htim2, 0);
	__HAL_TIM_CLEAR_IT(htim2 ,TIM_IT_UPDATE);
	HAL_TIM_Base_Stop_IT(&htim2);
}
