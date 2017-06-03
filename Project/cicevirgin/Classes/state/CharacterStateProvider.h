
#pragma once
#include "Common.h"
#include "state\IState.h"

#include "state\CharacterAttack.h"
#include "state\CharacterCaster.h"
#include "state\CharacterDeath.h"
#include "state\CharacterHurt.h"
#include "state\CharacterNoneState.h"
#include "state\CharacterRun.h"
#include "state\CharacterStand.h"
#include "state\CharacterWalk.h"

using namespace CharacterState;

/**
*	��ɫ��״̬�ṩ�ߣ���Ԫģʽ
*	key: CharacterStateType , value: IState *
**/

namespace CharacterState
{
	class CharacterStateProvider
	{
	private :
		CharacterStateProvider();
		std::map<CharacterStateType, IState *> statesMap;
	
	public:
		IState * getStateFromType(CharacterStateType type);
		static CharacterStateProvider * getInstance();
	};
};





