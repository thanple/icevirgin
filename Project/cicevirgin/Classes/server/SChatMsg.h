
#pragma once
#include "Common.h"
#include "protocol\SChatMsg.pb.h"

#include "ui\OperationUI.h"
//class OperationUI;

class _SChatMsg
{
public:

	void process(SChatMsg msg)
	{
		//这一块在namespace里用static变量或者方法，在外部调用的时候一定会有编译错误，至今未解决
		//2017-5-31 纪念在此浪费的时间-一个下午，C++ namespace is bull shit!!!
		//UI2::_operationUI_insance->updateLabel(msg.msg());
		//UI::OperationUI::getInstance2()->updateLabel(msg.msg());
		/*UI::OperationUI * operationUI = UI::OperationUI::getInstance();
		if (operationUI != NULL)
		{
			operationUI->updateLabel(msg.msg());
		}*/

		//GameScene * gm = GameScene::_instance;
		/*if (gameScene)
		{
			gameScene->getGameInfoUI()->getOperationUI()->updateLabel(msg.msg());
		}*/

		OperationUI * opeUI = OperationUI::getInstance();
		if (opeUI)
		{
			opeUI->updateLabel(msg.msg());
		}
	}
};
