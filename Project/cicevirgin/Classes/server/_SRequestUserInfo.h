
#include "protocol\SRequestUserInfo.pb.h"
#include "scene\GameScene.h";
#include "scene\FightScene.h"
#include "scene\PvpFightScene.h"

class _SRequestUserInfo
{
public:
	void process(SRequestUserInfo msg)
	{

		while (!GameScene::getInstance() && !FightScene::getInstance() && !PvpFightScene::getInstance());

		GameScene * gamescene = GameScene::getInstance();
		if (gamescene)
		{
			gamescene->setSRequestUserInfo(msg);
		}

		if (FightScene * fightScene = FightScene::getInstance())
		{
			fightScene->setSkillNum(msg.nskill());
			fightScene->setMoney(msg.money());
		}

		if (PvpFightScene * pvpfightScene = PvpFightScene::getInstance())
		{
			pvpfightScene->setSkillNum(msg.nskill());
			pvpfightScene->setMoney(msg.money());
		}

	};

};