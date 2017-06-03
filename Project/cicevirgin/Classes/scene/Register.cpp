
#include "Register.h"
#include "util\ResourceProvider.h"
#include "ui\Toast.h"
#include "protocol\CCreateRole.pb.h"
#include "util\MyProtoSocket.h"

const int BODYS[] = {
	11001,
	11002,
	12001,
	12002,
	13001,
	13002,
	14001,
	14002,
	15001,
	15002,
	16001,
	16002
};

const int HAIRS[] = {
	10001,
	10002,
	11001,
	11002,
	12001,
	12002
};

const int WEAPONS[] = {
	10000,
	11000,
	12000,
	13000,
	14000,
	15000
};





Register::Register() : character(NULL)
{
	body = 0;
	hair = 0;
	weapon = 0;
	direction = CharacterDirectionType::FDirDownAndLeft;

	toast = "";

}
Register::~Register()
{

}
bool Register::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("Register.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	Button * closeBtn = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(Register::onCloseModal, this));

	this->setVisible(false);
	m_isShow = false;


	//加入character
	character = Character::create();
	character->pBody->setFigureId(ResourceProvider::Character::PLAYER_11001);
	character->pHair->setFigureId(ResourceProvider::Hair::Hair_10001);
	character->pWeapon->setFigureId(ResourceProvider::Weapon::Weapon_10000);
	character->setIState(CharacterStateType::FStateStand);
	character->setDirectionType(CharacterDirectionType::FDirDownAndLeft);
	character->setPosition(500,330);
	character->setScale(1.3f);
	this->addChild(character);


	//各个按钮的响应
	Button * onChangeBody = dynamic_cast<Button*>(rootNode->getChildByName("ChangeBody"));
	onChangeBody->addTouchEventListener(CC_CALLBACK_2(Register::onChangeBody, this));

	Button * onChangeHair = dynamic_cast<Button*>(rootNode->getChildByName("ChangeHair"));
	onChangeHair->addTouchEventListener(CC_CALLBACK_2(Register::onChangeHair, this));

	Button * onChangeWeapon = dynamic_cast<Button*>(rootNode->getChildByName("ChangeWeapon"));
	onChangeWeapon->addTouchEventListener(CC_CALLBACK_2(Register::onChangeWeapon, this));

	Button * onChangeDirection = dynamic_cast<Button*>(rootNode->getChildByName("ChangeDirection"));
	onChangeDirection->addTouchEventListener(CC_CALLBACK_2(Register::onChangeDirection, this));

	Button * onAttack = dynamic_cast<Button*>(rootNode->getChildByName("Attack"));
	onAttack->addTouchEventListener(CC_CALLBACK_2(Register::onAttack, this));

	Button * onRun = dynamic_cast<Button*>(rootNode->getChildByName("Run"));
	onRun->addTouchEventListener(CC_CALLBACK_2(Register::onRun, this));

	Button * onStand = dynamic_cast<Button*>(rootNode->getChildByName("Stand"));
	onStand->addTouchEventListener(CC_CALLBACK_2(Register::onStand, this));

	//创建角色按钮
	Button * createRoleBtn = dynamic_cast<Button*>(rootNode->getChildByName("Create"));
	createRoleBtn->addTouchEventListener(CC_CALLBACK_2(Register::onCreateRole, this));

	//加载音乐
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::LOGIN_ACCTACK_MAN);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::LOGIN_ATTACK_GIRL);



	this->schedule([this](float f){
		if (toast != "")
		{
			auto toastShow = Toast::create(toast.c_str());
			this->addChild(toastShow);
			toast = "";
		}

	}, 1.6f, "registertoast");

	return true;

}


void Register::displayModal()
{
	m_isShow = true;
	this->setVisible(true);
}
void Register::onCloseModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	this->setVisible(false);
	m_isShow = false;
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::LOGIN_BACKMUSIC, true);

}


void Register::onChangeBody(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	body = (body + 1) % (sizeof(BODYS)/4);

	character->pBody->setFigureId(BODYS[body]);

	character->updateFigureActions();

	dynamic_cast<TextBMFont*>(rootNode->getChildByName("Body"))->setText(to_string(BODYS[body]));
}
void Register::onChangeHair(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	hair = (hair + 1) % (sizeof(HAIRS)/4);

	character->pHair->setFigureId(HAIRS[hair]);

	character->updateFigureActions();

	dynamic_cast<TextBMFont*>(rootNode->getChildByName("Hair"))->setText(to_string(HAIRS[hair]));
}
void Register::onChangeWeapon(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	weapon = (weapon + 1) % (sizeof(WEAPONS)/4);

	character->pWeapon->setFigureId(WEAPONS[weapon]);

	character->updateFigureActions();

	dynamic_cast<TextBMFont*>(rootNode->getChildByName("Weapon"))->setText(to_string(WEAPONS[weapon]));
}
void Register::onChangeDirection(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	direction = direction % 8 + 1;
	character->setDirectionType(CharacterDirectionType(direction));

}
void Register::onAttack(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateAttack);

	if (BODYS[body] % 10 ==1)
		SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::LOGIN_ACCTACK_MAN);
	else
		SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::LOGIN_ATTACK_GIRL);
}
void Register::onRun(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateRun);

}

void Register::onStand(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateStand);

}

void Register::onCreateRole(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	TextField * txtName = dynamic_cast<TextField *>(rootNode->getChildByName("Name"));
	TextField * txtNumber = dynamic_cast<TextField *>(rootNode->getChildByName("Number"));
	TextField * txtPassword = dynamic_cast<TextField *>(rootNode->getChildByName("Password"));

	if (txtName->getString() == "" || txtNumber->getString() == "" || txtPassword->getString() == "")
	{
		
		Toast * msg = Toast::create(Common::FontToUTF8("请将信息填写完整"));
		this->addChild(msg);
		return;
	}

	CCreateRole cMsg;
	cMsg.set_body(BODYS[body]);
	cMsg.set_hair(HAIRS[hair]);
	cMsg.set_weapon(WEAPONS[weapon]);
	cMsg.set_name(txtName->getString());
	cMsg.set_number(txtNumber->getString());
	cMsg.set_password(txtPassword->getString());

	MyProtoSocket::send(1019, cMsg.SerializeAsString());

}

void Register::showToast(string str)
{
	toast = str;
}