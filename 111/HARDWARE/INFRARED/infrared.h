#ifndef	__INFRARED_H
#define __INFRARED_H
 
#include "stm32f10x.h"

// 未遇到障碍(未接收到红外光)：对应状态 = 1
// 遇到障碍(接收到红外光)：对应状态 = 0
//****************************************************************
extern u8 Infrared_Input ;		// 三个避障模块的返回值
//****************************************************************
 
// 红外避障情况
//*********************************************************************
#define		Not_Find_Barrier			0x70	// 未发现障碍

#define		Middle_Find_Barrier			0x50	// 中间发现障碍

#define		Left_Find_Barrier			0x60	// 左边发现障碍
#define		Left_Middle_Find_Barrier	0x40	// 左中侧发现障碍

#define		Right_Find_Barrier			0x30	// 右边发现障碍
#define		Right_Middle_Find_Barrier	0x10	// 右中侧发现障碍
 
#define		Left_Right_Find_Barrier		0x20	// 左右测发现障碍
 
#define		All_Find_Barrier			0x00	// 全部发现障碍
//********************************************************************
 
 
void Infrared_Init(void);		    // 红外避障初始化
 
void Infrared_barrier_read(void);	    // 避障模块引脚电平读取函数
 
 
#endif
