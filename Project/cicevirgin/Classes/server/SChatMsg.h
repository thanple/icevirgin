
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
		//��һ����namespace����static�������߷��������ⲿ���õ�ʱ��һ�����б����������δ���
		//2017-5-31 �����ڴ��˷ѵ�ʱ��-һ�����磬C++ namespace is bull shit!!!
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
