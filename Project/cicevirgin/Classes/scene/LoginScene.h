
#pragma once 
#include "Common.h"
#include "Register.h"

class LoginScene : public Layer
{

private:
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);
	CC_SYNTHESIZE_READONLY(Register *, m_register, Register);

	CC_SYNTHESIZE(bool, m_loginFlag, LoginFlag);
public:

	CREATE_FUNC(LoginScene);
	LoginScene();
	~LoginScene();
	bool init();
	virtual void onExit();

public:
	static LoginScene * getInstance();

private:
	void onRegister(Ref* pSender, Widget::TouchEventType type);
	void onLogin(Ref* pSender, Widget::TouchEventType type);

public:
	string toast;
	void showToast(string str);
};