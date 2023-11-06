#ifndef	__INFRARED_H
#define __INFRARED_H
 
#include "stm32f10x.h"

// δ�����ϰ�(δ���յ������)����Ӧ״̬ = 1
// �����ϰ�(���յ������)����Ӧ״̬ = 0
//****************************************************************
extern u8 Infrared_Input ;		// ��������ģ��ķ���ֵ
//****************************************************************
 
// ����������
//*********************************************************************
#define		Not_Find_Barrier			0x70	// δ�����ϰ�

#define		Middle_Find_Barrier			0x50	// �м䷢���ϰ�

#define		Left_Find_Barrier			0x60	// ��߷����ϰ�
#define		Left_Middle_Find_Barrier	0x40	// ���в෢���ϰ�

#define		Right_Find_Barrier			0x30	// �ұ߷����ϰ�
#define		Right_Middle_Find_Barrier	0x10	// ���в෢���ϰ�
 
#define		Left_Right_Find_Barrier		0x20	// ���Ҳⷢ���ϰ�
 
#define		All_Find_Barrier			0x00	// ȫ�������ϰ�
//********************************************************************
 
 
void Infrared_Init(void);		    // ������ϳ�ʼ��
 
void Infrared_barrier_read(void);	    // ����ģ�����ŵ�ƽ��ȡ����
 
 
#endif
