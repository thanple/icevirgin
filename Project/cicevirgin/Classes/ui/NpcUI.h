
#pragma once

#include "Common.h"


class NpcUI : public Layer
{
private:
	std::ifstream ifs;
	TextBMFont * labelShow;
	CC_SYNTHESIZE(bool , m_iShow, IsShow);
	CC_SYNTHESIZE(int, m_shownpcId, ShownpcId);
public:
	NpcUI();
	~NpcUI();
	bool init();
	CREATE_FUNC(NpcUI);

public:
	void displayModal(int n);
	void onCloseModal(Ref* pSender, Widget::TouchEventType type);
	void onNextModal(Ref* pSender, Widget::TouchEventType type);
};

