
#pragma once

#include "Common.h"


class ShopUI : public Layer
{
private:
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);
	CC_SYNTHESIZE(bool, m_iShow, IsShow);
public:
	ShopUI();
	~ShopUI();
	bool init();
	CREATE_FUNC(ShopUI);

public:
	string toast;
	void showToast(string str);

	void displayModal();
	void onCloseModal(Ref* pSender, Widget::TouchEventType type);

	void onBuy1(Ref* pSender, Widget::TouchEventType type);
	void onBuy2(Ref* pSender, Widget::TouchEventType type);
	void onBuy3(Ref* pSender, Widget::TouchEventType type);
};

