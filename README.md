# PUTM_EV_LAP_TIMER_2022
## About this project
  Firmware for Laptimer device used on PM-08 racing car developed by PUT Motorsport. 
Written in C/C++ for STM32L4P5RET6 microprocessor, created in STM32CubeIDE 1.8.0
## State Diagram For Base
In-code variable _car_passed_ determine wich state, a microcontroller is currently in. \n
_car_passed = 0_ - Power-up, before first pass.
_car_passed = 1_ - After first detecion.
_car_passed = 2_ - During IR sensor block.
_car_passed = 3_ - Waiting for car to finish.
_car_passed = 4_ - Second detecion.
![Lap_timer_base_states](https://user-images.githubusercontent.com/94369639/156034816-96426a1a-2e8b-44eb-8eba-774fa294abea.png)
## Block Diagram
![Lap_Timer_Block_Diagram drawio](https://user-images.githubusercontent.com/94369639/156026390-378947ad-38d6-482e-b2fa-1bb3afe6d8b1.png)
