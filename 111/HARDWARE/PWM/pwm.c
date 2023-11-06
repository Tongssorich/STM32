#include "pwm.h"
#include "usart.h"

void L298N_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;				
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��
	GPIO_ResetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7);	
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;				
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��
	GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);	
}


//void TIM1_PWM_Init(u16 arr,u16 psc)
//{  
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);			// ʹ��TIM1ʱ��	
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  			// ʹ��GPIOBʱ��
//			
//    // ����IOģʽ
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  				// �����������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);							// ��ʼ��PA8��PA9��PA10��PA11
//	
//	
//   //��ʼ��TIM1�ļ���ģʽ����Ƶֵ����װ��ֵ��
//	TIM_TimeBaseStructure.TIM_Period = arr; 			// ������һ�������¼���װ���Զ���װ�ؼĴ�����ֵ
//	TIM_TimeBaseStructure.TIM_Prescaler = psc; 	// ����TIM3ʱ��Ԥ��Ƶֵ 
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 					// ����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// ���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); 				// ���ݲ�����ʼ��TIM1
//	
//	//��ʼ��TIM1_CH1��2��PWM
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				// ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// �Ƚ����ʹ��
//	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputState_Disable;	// �Ƚ����N��ʹ��
//	TIM_OCInitStructure.TIM_Pulse = 0;								
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		// �������:TIM����Ƚϼ��Ը�
//	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;		
//	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
//	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset ;
//	
//	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  						// ����ʼ��TIM1_OC1	
//	TIM_OC2Init(TIM1, &TIM_OCInitStructure);						  // ����ʼ��TIM1_OC2
//	
//	TIM_ARRPreloadConfig(TIM1,ENABLE);								   // ʹ��TIM1���Զ���װ�ؼĴ���
//	TIM_CtrlPWMOutputs(TIM1,ENABLE);								// �����ʹ��
//	
//	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  				// ʹ��TIM1��OC1�ϵ�Ԥװ�ؼĴ���
//	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);				// ʹ��TIM1��OC2�ϵ�Ԥװ�ؼĴ���
//	
//	TIM_Cmd(TIM1, ENABLE);  										// ʹ��TIM1
//	
//}


//void TIM4_PWM_Init(u16 arr,u16 psc)
//{  
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
//	
// 
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);			// ʹ��TIM4ʱ��
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  			// ʹ��GPIOBʱ��
//	
//	// ����IOģʽ
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  				// �����������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);							
// 
//	
//	//��ʼ��TIM4�ļ���ģʽ����Ƶֵ����װ��ֵ��
//	TIM_TimeBaseStructure.TIM_Period = arr; 			// ������һ�������¼���װ���Զ���װ�ؼĴ�����ֵ
//	TIM_TimeBaseStructure.TIM_Prescaler = psc; 	// ����TIM4ʱ��Ԥ��Ƶֵ 
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 					// ����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// ���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 				// ���ݲ�����ʼ��TIM4�ļ�����ʽ
//	
//	
//	//��ʼ��TIM4_CH1��2��PWM
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				// ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// �Ƚ����ʹ��
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		// �������:TIM����Ƚϼ��Ը�
//	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  						
//	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
//	
// 
//	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  				// ʹ��TIM4��OC1�ϵ�Ԥװ�ؼĴ���
//	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);				// ʹ��TIM4��OC2�ϵ�Ԥװ�ؼĴ���
// 
// 
//	TIM_Cmd(TIM4, ENABLE);											// ʹ��TIM4
//}
