#include "pwm.h"
#include "usart.h"

void L298N_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;				
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化
	GPIO_ResetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7);	
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;				
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化
	GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);	
}


//void TIM1_PWM_Init(u16 arr,u16 psc)
//{  
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);			// 使能TIM1时钟	
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  			// 使能GPIOB时钟
//			
//    // 配置IO模式
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  				// 复用推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);							// 初始化PA8、PA9、PA10、PA11
//	
//	
//   //初始化TIM1的计数模式、分频值、重装载值等
//	TIM_TimeBaseStructure.TIM_Period = arr; 			// 设置下一个更新事件后，装入自动重装载寄存器的值
//	TIM_TimeBaseStructure.TIM_Prescaler = psc; 	// 设置TIM3时钟预分频值 
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 					// 设置时钟分割:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// 向上计数模式
//	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); 				// 根据参数初始化TIM1
//	
//	//初始化TIM1_CH1、2的PWM
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				// 选择定时器模式:TIM脉冲宽度调制模式1
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// 比较输出使能
//	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputState_Disable;	// 比较输出N不使能
//	TIM_OCInitStructure.TIM_Pulse = 0;								
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		// 输出极性:TIM输出比较极性高
//	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;		
//	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
//	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset ;
//	
//	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  						// 数初始化TIM1_OC1	
//	TIM_OC2Init(TIM1, &TIM_OCInitStructure);						  // 数初始化TIM1_OC2
//	
//	TIM_ARRPreloadConfig(TIM1,ENABLE);								   // 使能TIM1的自动重装载寄存器
//	TIM_CtrlPWMOutputs(TIM1,ENABLE);								// 主输出使能
//	
//	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  				// 使能TIM1在OC1上的预装载寄存器
//	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);				// 使能TIM1在OC2上的预装载寄存器
//	
//	TIM_Cmd(TIM1, ENABLE);  										// 使能TIM1
//	
//}


//void TIM4_PWM_Init(u16 arr,u16 psc)
//{  
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
//	
// 
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);			// 使能TIM4时钟
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  			// 使能GPIOB时钟
//	
//	// 配置IO模式
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  				// 复用推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);							
// 
//	
//	//初始化TIM4的计数模式、分频值、重装载值等
//	TIM_TimeBaseStructure.TIM_Period = arr; 			// 设置下一个更新事件后，装入自动重装载寄存器的值
//	TIM_TimeBaseStructure.TIM_Prescaler = psc; 	// 设置TIM4时钟预分频值 
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 					// 设置时钟分割:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// 向上计数模式
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 				// 根据参数初始化TIM4的计数方式
//	
//	
//	//初始化TIM4_CH1、2的PWM
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				// 选择定时器模式:TIM脉冲宽度调制模式1
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// 比较输出使能
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		// 输出极性:TIM输出比较极性高
//	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  						
//	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
//	
// 
//	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  				// 使能TIM4在OC1上的预装载寄存器
//	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);				// 使能TIM4在OC2上的预装载寄存器
// 
// 
//	TIM_Cmd(TIM4, ENABLE);											// 使能TIM4
//}
