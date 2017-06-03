/*
#include "CharacterAttack.h"

#include "character\Player.h"

Action * CharacterState::CharacterAttack::createActionFromAnimate(CCActionInterval* animate)
{
	CCDelayTime* delayTime = CCDelayTime::create(animate->getDuration() / 2);
	//CCCallFunc* callFunc1 = CallFunc::create(this, callfunc_selector(Figure::attacking));
	Player * player = Player::sharePlayer();
	CCCallFunc* callFunc2 = CallFunc::create([this, player](){
		if (player)
		{
			player->setIState(CharacterStateType::FStateStand);
		}
	});
	CCSequence * sequence = CCSequence::create(delayTime, callFunc2, NULL);

	//return Sequence::create( animate,delayTime);
	//return animate;
	return sequence;
	//RepeatForever * repeatForever = RepeatForever::create(animate);
	//return repeatForever;
}
*/