#include "infrared.h"
  
u8 Infrared_Input = 0 ;		// �����������ģ��ķ���ֵ
 
 
// ������ϳ�ʼ��(��PA4��PA5��PA6��ʼ��Ϊ��������)
// ���ϡ��� -- PA4
// ���ϡ��� -- PA5
// ���ϡ��� -- PA6c
void Infrared_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			// GPIOAʱ��ʹ��
	
	// ���ϣ�Elude--PA4��PA5��PA6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;	// Elude--PA4��PA5��PA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 					// ��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);							
	
}
 
// ������϶�ȡ���ŵ�ƽ����
// ��ȡ[PA4��PA5��PA6]��״ֵ̬���ֱ��Ӧ���С���
// δ�����ϰ�(δ���յ������)����Ӧ״̬ = 1
// �����ϰ�(���յ������)����Ӧ״̬ = 0
void Infrared_barrier_read(void)
{
	Infrared_Input = 0 ;
	
	Infrared_Input = (((u8)GPIOA->IDR) & 0x70);
}
