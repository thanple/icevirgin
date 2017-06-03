#pragma once 
#include "IState.h"

namespace CharacterState
{
	class CharacterAttack : public IState
	{
	public:
		virtual float getFrameRate()
		{
			return 1 / 8.f;
		}
		virtual Action * createActionFromAnimate(CCActionInterval* animate)
		{
			/*CCDelayTime* delayTime = CCDelayTime::create(animate->getDuration() / 2);
			//CCCallFunc* callFunc1 = CallFunc::create(this, callfunc_selector(Figure::attacking));
			CCCallFunc* callFunc2 = CallFunc::create([this](){
				
			});
			CCSequence * sequence = CCSequence::create(delayTime, callFunc2, NULL);
			*/
			//return Sequence::create( animate,delayTime);
			return animate;
			//return sequence;
			//RepeatForever * repeatForever = RepeatForever::create(animate);
			//return repeatForever;
		}

		virtual CharacterStateType getStateType()
		{
			return CharacterStateType::FStateAttack;
		}

	};
}