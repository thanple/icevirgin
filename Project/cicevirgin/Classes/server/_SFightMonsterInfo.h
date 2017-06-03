#pragma once
#include "protocol\SFightMonsterInfo.pb.h"
#include "scene\FightScene.h"

class _SFightMonsterInfo
{
public:
	void process(SFightMonsterInfo msg)
	{
		FightScene * fightScene = FightScene::getInstance();
		fightScene->createMonster(msg.monsterid());
	};

};