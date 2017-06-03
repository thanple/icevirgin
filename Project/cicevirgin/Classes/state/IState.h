
#pragma once
#include "Common.h"

/**
* ��״̬���г���: ������վ�������ߣ��ܶ����˺�������
*/

typedef enum
{
	FStateDeath = 7,
	FStateHurt = 6,
	FStateCaster = 5,
	FStateAttack = 4,
	FStateRun = 3,
	FStateWalk = 2,
	FStateStand = 1,
	FStateNone = 0
}CharacterStateType;

class IState
{
public:
	virtual CharacterStateType getStateType() = 0;	//��ȡ״̬���
	virtual float getFrameRate() = 0;	//��ȡˢ����
	virtual Action * createActionFromAnimate(CCActionInterval* animate) = 0; //״̬�Ķ���
};

