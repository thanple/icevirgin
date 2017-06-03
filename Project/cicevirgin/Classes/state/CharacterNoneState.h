#pragma once 
#include "IState.h"

namespace CharacterState
{

	class CharacterNoneState : public IState
	{
	public:

		virtual float getFrameRate()
		{
			return 0.5f;
		}
		virtual Action * createActionFromAnimate(CCActionInterval* animate)
		{
			return NULL;
		}
		virtual CharacterStateType getStateType()
		{
			return CharacterStateType::FStateNone;
		}
	};

}