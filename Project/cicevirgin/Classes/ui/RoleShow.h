#pragma once

#include "Common.h"
#include "character\Player.h"

class RoleShowUI : public Layer
{
private:
	Character * character;
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);
	CC_SYNTHESIZE(bool, m_iShow, IsShow);

public:
	RoleShowUI();
	~RoleShowUI();
	bool init();
	CREATE_FUNC(RoleShowUI);

	void displayModal();
	void onCloseModal(Ref* pSender, Widget::TouchEventType type);

private:
	void onChangeDirection(Ref* pSender, Widget::TouchEventType type);
	void onAttack(Ref* pSender, Widget::TouchEventType type);
	void onRun(Ref* pSender, Widget::TouchEventType type);
	void onStand(Ref* pSender, Widget::TouchEventType type);

	void onWalk(Ref* pSender, Widget::TouchEventType type);
	void onSkill(Ref* pSender, Widget::TouchEventType type);
	void onHurt(Ref* pSender, Widget::TouchEventType type);
	void onDeath(Ref* pSender, Widget::TouchEventType type);
};