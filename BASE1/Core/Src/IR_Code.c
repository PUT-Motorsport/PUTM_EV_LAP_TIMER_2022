

#include "IR_Code.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

void leading_pulse(void);

void Send_Code()
{
	leading_pulse();
	Send_Zero();
	Send_One();
	end();
}
void Send_Zero()
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	delay_us(562.5);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
	delay_us(562.5);
}
void Send_One()
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	delay_us(562.5);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
	delay_us(1687.5);
}
void end()
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	delay_us(1000);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
	delay_us(500);
}
void leading_pulse()//H2ms, L1ms
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	delay_us(1000);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
	delay_us(500);
}
void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // wait for the counter to reach the us input in the parameter
}
