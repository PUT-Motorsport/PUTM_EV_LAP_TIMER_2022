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
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	SendFrameFlag = 1;
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, 1);
	__HAL_TIM_SET_COUNTER(htim, 0);
	__HAL_TIM_CLEAR_IT(htim ,TIM_IT_UPDATE);
	HAL_TIM_Base_Stop_IT(&htim2);
}
/**
* @brief IR receiver callback
* This function sends CAN frame whenever a pass is detected
* @param: none
* @retval none
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
  if(SendFrameFlag == 1)
  {
	  if((HAL_CAN_AddTxMessage(&hcan1, &Tx1, &pData, &TxMailbox)) == HAL_OK)
	  {
		 while (HAL_CAN_IsTxMessagePending(&hcan1, TxMailbox));
	  	 HAL_GPIO_WritePin(GPIOC, LED_2_Pin, 0);
	  }
	  else
	  {
	  	 Error_Handler();
	  }
  }
  SendFrameFlag = 0;
  HAL_TIM_Base_Start_IT(&htim2);
}
