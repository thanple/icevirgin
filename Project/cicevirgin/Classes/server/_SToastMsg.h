

#pragma once
#include "Common.h"
#include "protocol\SToastMsg.pb.h"
#include "ui\OperationUI.h"
#include "scene\FightScene.h"
#include "ui\GameInfoUI.h"
#include "scene\LoginScene.h"


class _SToastMsg
{
public:

	void process(SToastMsg msg)
	{

		if (GameInfoUI::getInstance() && GameInfoUI::getInstance()->getShopUI()->getIsShow())
		{
			GameInfoUI::getInstance()->getShopUI()->showToast(msg.msg());
		}
		else if(OperationUI * opeUI = OperationUI::getInstance())
		{
			opeUI->showToast(msg.msg());
		}


		if (FightScene * fightScene = FightScene::getInstance())
		{
			fightScene->toastShow(msg.msg());
		}


		if (LoginScene::getInstance() && LoginScene::getInstance()->getRegister()->getIsShow())
		{
			LoginScene::getInstance()->getRegister()->showToast(msg.msg());
		}
		else if (LoginScene::getInstance())
		{
			LoginScene::getInstance()->showToast(msg.msg());
		}

	}
};
