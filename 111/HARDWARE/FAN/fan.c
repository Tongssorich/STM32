#include "fan.h"
#include "usart.h"

void Fan_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PB�˿�ʱ��
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;				
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��
	GPIO_ResetBits(GPIOC,GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);
}

void Fan_start(void)
{
	FANAIN1=1;
	FANAIN2=0;
	FANBIN1=0;
	FANBIN2=1;
}

void Fan_shut(void)
{
	FANAIN1=0;
	FANAIN2=0;
	FANBIN1=0;
	FANBIN2=0;
}
