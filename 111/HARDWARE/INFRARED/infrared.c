#include "infrared.h"
  
u8 Infrared_Input = 0 ;		// 三个红外避障模块的返回值
 
 
// 红外避障初始化(将PA4、PA5、PA6初始化为上拉输入)
// 避障—左 -- PA4
// 避障—中 -- PA5
// 避障—右 -- PA6c
void Infrared_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			// GPIOA时钟使能
	
	// 避障：Elude--PA4、PA5、PA6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;	// Elude--PA4、PA5、PA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 					// 上拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);							
	
}
 
// 红外避障读取引脚电平函数
// 读取[PA4、PA5、PA6]的状态值，分别对应左、中、右
// 未遇到障碍(未接收到红外光)：对应状态 = 1
// 遇到障碍(接收到红外光)：对应状态 = 0
void Infrared_barrier_read(void)
{
	Infrared_Input = 0 ;
	
	Infrared_Input = (((u8)GPIOA->IDR) & 0x70);
}
