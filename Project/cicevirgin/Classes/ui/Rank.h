
#pragma once

#include "Common.h"


class RankUI : public Layer
{
private:
	CC_SYNTHESIZE(bool, m_iShow, IsShow);
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);
	CC_SYNTHESIZE(string, labelStr, LabelStr);


public:
	RankUI();
	~RankUI();
	bool init();
	CREATE_FUNC(RankUI);
	void scheduleUpdateUI(float f);

public:
	void displayModal();
	void onCloseModal(Ref* pSender, Widget::TouchEventType type);
};

