#pragma once
#include "protocol\SFightBlood.pb.h"
#include "scene\FightScene.h"

class _SFightBlood
{
public:
	void process(SFightBlood msg)
	{
	
		int fightType = msg.fighthtype();

		if (fightType == 1)
		{
			SFightBlood_FighterInfo playerInfo = msg.info(0);
			SFightBlood_FighterInfo enermyInfo = msg.info(1);

			FightScene * fightScene = FightScene::getInstance();
			fightScene->setPlayerBlood(playerInfo.blood());
			fightScene->setEnermyBlood(enermyInfo.blood());
		}
		else
		{

		}

	};

};