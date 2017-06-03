
#pragma once
#include "Common.h"
#include "character\Character.h";


class Register : public Layer
{

private:
	Character * character;
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);
	CC_SYNTHESIZE_READONLY(bool, m_isShow, IsShow);

	int body, hair, weapon, direction;
public:

	CREATE_FUNC(Register);
	Register();
	~Register();
	bool init();
	void displayModal();
	void onCloseModal(Ref* pSender, Widget::TouchEventType type);

private:
	void onChangeBody(Ref* pSender, Widget::TouchEventType type);
	void onChangeHair(Ref* pSender, Widget::TouchEventType type);
	void onChangeWeapon(Ref* pSender, Widget::TouchEventType type);

	void onChangeDirection(Ref* pSender, Widget::TouchEventType type);
	void onAttack(Ref* pSender, Widget::TouchEventType type);
	void onRun(Ref* pSender, Widget::TouchEventType type);
	void onStand(Ref* pSender, Widget::TouchEventType type);

	void onCreateRole(Ref* pSender, Widget::TouchEventType type);

public:
	string toast;
	void showToast(string str);
};