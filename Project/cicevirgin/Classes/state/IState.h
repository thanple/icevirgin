
#pragma once
#include "Common.h"

/**
* 对状态进行抽象: 攻击，站立，行走，跑动，伤害，死亡
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
	virtual CharacterStateType getStateType() = 0;	//获取状态编号
	virtual float getFrameRate() = 0;	//获取刷新率
	virtual Action * createActionFromAnimate(CCActionInterval* animate) = 0; //状态的动画
};

