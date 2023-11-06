#ifndef __PWM_H
#define __PWM_H

#include "sys.h"
 
#define PWMA PBout(6)
#define PWMB PBout(7)
 
#define AIN1 PBout(14)
#define AIN2 PBout(13)
 
#define BIN1 PBout(15)
#define BIN2 PBout(12)

//void TIM1_PWM_Init(u16 arr,u16 psc);
//void TIM4_PWM_Init(u16 arr,u16 psc);
void L298N_GPIO_Init(void);

#endif
