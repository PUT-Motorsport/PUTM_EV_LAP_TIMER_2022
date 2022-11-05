# PUTM_EV_LAP_TIMER_2022
## About this project
  Firmware for Laptimer device used on PM-08 racing car developed by PUT Motorsport. 
Written in C/C++ for STM32L4P5RET6 microprocessor, created in STM32CubeIDE 1.8.0
## State Diagram For Base
In-code variable _car_passed_ determine wich state, a microcontroller is currently in.  
_car_passed = 0_ - Power-up, before first pass.  
_car_passed = 1_ - After first detection.  
_car_passed = 2_ - During IR sensor block.  
_car_passed = 3_ - Waiting for car to finish.  
_car_passed = 4_ - Second detection.    
![Lap_timer_base_states](https://user-images.githubusercontent.com/94369639/156034816-96426a1a-2e8b-44eb-8eba-774fa294abea.png)
## Code Block Diagram
![Lap_Timer_Block_Diagram drawio](https://user-images.githubusercontent.com/94369639/165082070-ab102117-6783-4b3d-955e-f2fa73bef53b.png)
## Carrier detect mechanism
  On-track devices sends a modulated square wave, where logic HIGH is a PWM signal with 50% duty cycle and 38kHz frequency:
  
  ![send vs received drawio](https://user-images.githubusercontent.com/94369639/165097963-4b1b91fd-8adb-4fed-9f1d-050a540fc3c4.png)
  
  Duty cycle for each base remains the same, they only differ in T1 and T2 periods:
  
  ![Carriers](https://user-images.githubusercontent.com/94369639/165090463-c8c5cc38-499e-4e8b-b6ae-789264bc9d0d.png)
  
  In order to distinguish these signals, STM32l4P5RET6 microcontroller utilize a Input capture mode with TIM3. It measures a time of occurance of two consecutive rising edges, wich are then substracted from each other to calculate signal period.  
  
  ## Pinout
  1 - GND  
  2 - +24V  
  3 - CAN+  
  4 - CAN-  
  
 
