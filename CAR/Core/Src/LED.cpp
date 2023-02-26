#include "LED.hpp"

void Set_Start_Finish()
{
	 HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET);
	 HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_RESET);
}
void Set_Sector2_Skidpad()
{
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_SET);
}
void Set_Sector3_ACC()
{
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_RESET);
}
void Clear_Sector()
{
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_SET);
}
void Set_Working()
{
	HAL_GPIO_WritePin(GPIOC, LED_1_Pin, GPIO_PIN_RESET);
}
void Checkup()
{
	const int delay = 100;
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOC, LED_1_Pin, GPIO_PIN_SET);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOC, LED_3_Pin, GPIO_PIN_SET);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOC, LED_4_Pin, GPIO_PIN_SET);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_SET);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOC, LED_6_Pin, GPIO_PIN_SET);
}
void Set_Detecion()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_RESET);
}
void Reset_Detecion()
{
	HAL_GPIO_WritePin(GPIOC, LED_5_Pin, GPIO_PIN_SET);
}










