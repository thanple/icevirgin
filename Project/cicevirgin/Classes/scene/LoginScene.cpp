
#include "LoginScene.h"
#include "ui\Toast.h"
#include "protocol\CLogin.pb.h"
#include "util\MyProtoSocket.h"

#include "scene\GameScene.h"


static LoginScene * _instance;

LoginScene * LoginScene::getInstance()
{
	return _instance;
}


LoginScene::LoginScene() : m_register(NULL), rootNode(NULL), m_loginFlag(false)
{
	toast = "";
}

LoginScene::~LoginScene()
{
	_instance = NULL;
}

void LoginScene::onExit()
{
	Layer::onExit();
	_instance = NULL;
}

bool LoginScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("Login.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	//注册按钮
	Button * registerBtn = dynamic_cast<Button*>(rootNode->getChildByName("Register"));
	registerBtn->addTouchEventListener(CC_CALLBACK_2(LoginScene::onRegister, this));

	//登录按钮
	Button * loginBtn = dynamic_cast<Button*>(rootNode->getChildByName("Login"));
	loginBtn->addTouchEventListener(CC_CALLBACK_2(LoginScene::onLogin, this));

	//register模块
	m_register = Register::create();
	this->addChild(m_register);

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::LOGIN_BACKMUSIC);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::LOGIN_BACKMUSIC, true);



	this->schedule([this](float f){
		if (toast != "")
		{
			auto toastShow = Toast::create(toast.c_str());
			this->addChild(toastShow);
			toast = "";
		}

		if (m_loginFlag) {
			Director::getInstance()->replaceScene(Common::scene(GameScene::create()));
		}

	}, 1.6f, "logintoast");

	_instance = this;
	return true;
}


void LoginScene::onRegister(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	m_register->displayModal();
}

void LoginScene::showToast(string str)
{
	toast = str;
}

void LoginScene::onLogin(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	TextField * txtNumber = dynamic_cast<TextField *>(rootNode->getChildByName("Number"));
	TextField * txtPassword = dynamic_cast<TextField *>(rootNode->getChildByName("Password"));

	if (txtNumber->getString() == "" || txtPassword->getString() == "")
	{
		auto show = Toast::create(Common::FontToUTF8("请将信息填写完整"));
		this->addChild(show);
		return;
	}

	CLogin cMsg;
	cMsg.set_number(txtNumber->getString());
	cMsg.set_password(txtPassword->getString());

	MyProtoSocket::send(1020,cMsg.SerializeAsString());


}