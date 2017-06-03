
#include "protocol\SRequestUserInfo.pb.h"
#include "scene\GameScene.h";
#include "scene\FightScene.h"

class _SRequestUserInfo
{
public:
	void process(SRequestUserInfo msg)
	{
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

	};

};