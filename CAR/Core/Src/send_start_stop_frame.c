/*
 * send_start_stop_frame.c
 *
 *  Created on: Feb 26, 2022
 *      Author: Adam Wasilewski
 */

#include "send_start_stop_frame.h"

CAN_TxHeaderTypeDef Tx1;
uint8_t pData = 0xff;
uint32_t TxMailbox = 0;
extern CAN_HandleTypeDef hcan1;

void Can_Init()
{
	Tx1.StdId = 0x0A;
	Tx1.ExtId = 0;
	Tx1.IDE = CAN_ID_STD;
	Tx1.RTR = CAN_RTR_DATA;
	Tx1.DLC = 1;
	Tx1.TransmitGlobalTime = DISABLE;
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);

  HAL_GPIO_WritePin(GPIOC, LED_1_Pin, 0);
  if((HAL_CAN_AddTxMessage(&hcan1, &Tx1, &pData, &TxMailbox)) == HAL_OK)
  {
	  HAL_Delay(500);
	  HAL_GPIO_WritePin(GPIOC, LED_1_Pin, 0);
  }
  else
  {
	  Error_Handler();
  }


}
