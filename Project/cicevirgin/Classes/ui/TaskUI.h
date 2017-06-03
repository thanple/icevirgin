#pragma once

#include "Common.h"

class TaskUI : public Layer
{
private:
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);
	CC_SYNTHESIZE(bool, m_iShow, IsShow);

public:
	TaskUI();
	~TaskUI();
	bool init();
	CREATE_FUNC(TaskUI);

public:

	void displayModal();
	void onCloseModal(Ref* pSender, Widget::TouchEventType type);

	void onTask1(Ref* pSender, Widget::TouchEventType type);
};