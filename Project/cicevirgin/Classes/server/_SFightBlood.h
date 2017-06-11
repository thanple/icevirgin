#pragma once
#include "protocol\SFightBlood.pb.h"
#include "scene\FightScene.h"
#include "scene\PvpFightScene.h"

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
			SFightBlood_FighterInfo player1 = msg.info(0);
			SFightBlood_FighterInfo player2 = msg.info(1);

			PvpFightScene * fightScene = PvpFightScene::getInstance();
			if (player1.id() == fightScene->getPlayer()->getRoleId())
			{
				fightScene->setPlayerBlood(player1.blood());
				fightScene->setEnermyBlood(player2.blood());
			}
			else
			{
				fightScene->setPlayerBlood(player2.blood());
				fightScene->setEnermyBlood(player1.blood());
			}


		}

	};

};