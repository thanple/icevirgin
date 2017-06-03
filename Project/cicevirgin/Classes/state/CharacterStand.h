#pragma once 
#include "IState.h"

namespace CharacterState
{
	class CharacterStand : public IState
	{
	public:

		virtual float getFrameRate()
		{
			return 1 / 3.f;
		}
		virtual Action * createActionFromAnimate(CCActionInterval* animate)
		{
			return animate;
		}
		virtual CharacterStateType getStateType()
		{
			return CharacterStateType::FStateStand;
		}
	};
}