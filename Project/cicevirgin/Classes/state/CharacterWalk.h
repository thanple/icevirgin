#pragma once 
#include "IState.h"

namespace CharacterState
{
	class CharacterWalk : public IState
	{
	public:

		virtual float getFrameRate()
		{
			return 0.6 / 16.f;
		}
		virtual Action * createActionFromAnimate(CCActionInterval* animate)
		{
			RepeatForever * repeatForever = RepeatForever::create(animate);
			return repeatForever;
		}
		virtual CharacterStateType getStateType()
		{
			return CharacterStateType::FStateWalk;
		}
	};
}