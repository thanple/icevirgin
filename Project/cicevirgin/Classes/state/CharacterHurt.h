#pragma once 
#include "IState.h"

namespace CharacterState
{
	class CharacterHurt : public IState
	{
	public:

		virtual float getFrameRate()
		{
			return 1 / 8.f;
		}
		virtual Action * createActionFromAnimate(CCActionInterval* animate)
		{
			return animate;
		}
		virtual CharacterStateType getStateType()
		{
			return CharacterStateType::FStateHurt;
		}
	};

}