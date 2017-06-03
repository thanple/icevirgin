#pragma once
#include "Common.h"

class OperationUI : public Layer
{
private:
	CC_SYNTHESIZE_READONLY(Node * ,rootNode,RootNode);
	string labelStr;
	string toast;

public:
	OperationUI();
	~OperationUI();
	bool init();
	CREATE_FUNC(OperationUI);
	void updateLabel(string msg);
	void showToast(string str);

private:
	void onBtnSend(Ref* pSender, Widget::TouchEventType type);
	void onShop(Ref* pSender, Widget::TouchEventType type);
	void onRank(Ref* pSender, Widget::TouchEventType type);
	void onRoleShow(Ref* pSender, Widget::TouchEventType type);
	void onTaskShow(Ref* pSender, Widget::TouchEventType type);


	void scheduleUpdateUI(float dt);

public:
	static OperationUI * getInstance();
		
};
//��һ����namespace����static�������߷��������ⲿ���õ�ʱ��һ�����б����������δ���
//2017-5-31 �����ڴ��˷ѵ�ʱ��-һ�����磬C++ namespace is bull shit!!!
//static UI2::OperationUI * _operationUI_insance = NULL;
