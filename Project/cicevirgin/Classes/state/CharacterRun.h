#pragma once 
#include "IState.h"

namespace CharacterState
{
	class CharacterRun : public IState
	{
	public:

		virtual CharacterStateType getStateType()
		{
			return CharacterStateType::FStateRun;
		}

		virtual float getFrameRate()
		{
			return 0.6 / 16.f;
		}
		virtual Action * createActionFromAnimate(CCActionInterval * animate)
		{
			RepeatForever * repeatForever = RepeatForever::create(animate);
			return repeatForever;
		}
	};
}
