#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "car.h"
#include "infrared.h"
#include "pwm.h"

//void car_straight_drive(void)
//{
//	TIM_SetCompare1(TIM1,3000);
//	TIM_SetCompare1(TIM4,3000);
//}

//void car_left_drive(void)
//{
//	TIM_SetCompare1(TIM1,0);
//	TIM_SetCompare1(TIM4,3000);
//}

//void car_right_drive(void)
//{
//	TIM_SetCompare1(TIM1,3000);
//	TIM_SetCompare1(TIM4,0);
//}

//void car_backoff_drive(void)
//{
//	TIM_SetCompare1(TIM4,3000);
//	TIM_SetCompare1(TIM1,0);
//}

//void car_stop_drive(void)
//{
//	TIM_SetCompare1(TIM1,0);
//	TIM_SetCompare1(TIM4,0);
//}


void go_straight(void)
{
	AIN1 = 1;
	AIN2 = 0;
	BIN1 = 0;
	BIN2 = 1;
}
 
void go_back(void)
{
	AIN1 = 0;
	AIN2 = 1;
	BIN1 = 1;
	BIN2 = 0;
}
 
void turn_right(void)
{
	AIN1 = 1;
	AIN2 = 0;
	BIN1 = 0;
	BIN2 = 0;
}
 
void turn_left(void)
{
	AIN1 = 0;
	AIN2 = 0;
	BIN1 = 0;
	BIN2 = 1;
}
 
void stop(void)
{
	AIN1 = 0;
	AIN2 = 0;
	BIN1 = 0;
	BIN2 = 0;
}

