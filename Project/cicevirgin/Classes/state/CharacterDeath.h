#pragma once 
#include "IState.h"

namespace CharacterState
{
	class CharacterDeath : public IState
	{
	public:

		virtual float getFrameRate()
		{
			return 1 / 4.f;
		}
		virtual Action * createActionFromAnimate(CCActionInterval* animate)
		{
			return animate;
		}
		virtual CharacterStateType getStateType()
		{
			return CharacterStateType::FStateDeath;
		}
	};

}