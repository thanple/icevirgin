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
//这一块在namespace里用static变量或者方法，在外部调用的时候一定会有编译错误，至今未解决
//2017-5-31 纪念在此浪费的时间-一个下午，C++ namespace is bull shit!!!
//static UI2::OperationUI * _operationUI_insance = NULL;
