#include "RoleShow.h"

RoleShowUI::RoleShowUI() :character(NULL)
{
}

RoleShowUI::~RoleShowUI()
{

}
bool RoleShowUI::init()
{
	if (!Layer::init())
		return false;

	auto rootNode = CSLoader::createNode("RoleShow.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);


	Button * closeBtn = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onCloseModal, this));

	Button * onChangeDirection = dynamic_cast<Button*>(rootNode->getChildByName("ChangeDirection"));
	onChangeDirection->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onChangeDirection, this));

	Button * onAttack = dynamic_cast<Button*>(rootNode->getChildByName("Attack"));
	onAttack->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onAttack, this));

	Button * onRun = dynamic_cast<Button*>(rootNode->getChildByName("Run"));
	onRun->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onRun, this));

	Button * onStand = dynamic_cast<Button*>(rootNode->getChildByName("Stand"));
	onStand->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onStand, this));



	Button * onWalk = dynamic_cast<Button*>(rootNode->getChildByName("onWalk"));
	onWalk->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onWalk, this));

	Button * onSkill = dynamic_cast<Button*>(rootNode->getChildByName("onSkill"));
	onSkill->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onSkill, this));

	Button * onHurt = dynamic_cast<Button*>(rootNode->getChildByName("onHurt"));
	onHurt->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onHurt, this));

	Button * onDeath = dynamic_cast<Button*>(rootNode->getChildByName("onDeath"));
	onDeath->addTouchEventListener(CC_CALLBACK_2(RoleShowUI::onDeath, this));


	this->setVisible(false);
	m_iShow = false;

	return true;
}

void RoleShowUI::displayModal()
{
	//这里使用延迟加载策略
	if (NULL == character)
	{		
		Player * player = Player::sharePlayer();
		character = Character::create();
		character->pBody->setFigureId(player->pBody->getFigureId());
		character->pHair->setFigureId(player->pHair->getFigureId());
		character->pWeapon->setFigureId(player->pWeapon->getFigureId());
		character->setIState(CharacterStateType::FStateStand);
		character->setDirectionType(CharacterDirectionType::FDirDownAndLeft);
		character->setPosition(500, 300);
		character->setScale(2.5f);
		this->addChild(character);

		dynamic_cast<TextBMFont*>(rootNode->getChildByName("Body"))->setText(to_string(player->pBody->getFigureId()));
		dynamic_cast<TextBMFont*>(rootNode->getChildByName("Hair"))->setText(to_string(player->pHair->getFigureId()));
		dynamic_cast<TextBMFont*>(rootNode->getChildByName("Weapon"))->setText(to_string(player->pWeapon->getFigureId()));
	}
	this->setVisible(true);
	m_iShow = true;
}
void RoleShowUI::onCloseModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	this->setVisible(false);

	//这一块必须延时，不然关闭后就自动寻路了
	this->scheduleOnce([this](float f){
		m_iShow = false;
	}, 0.5f, "closeModal1");
}


void RoleShowUI::onChangeDirection(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	int direction = character->getDirectionType() % 8 + 1;
	character->setDirectionType(CharacterDirectionType(direction));

}
void RoleShowUI::onAttack(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateAttack);

}
void RoleShowUI::onRun(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateRun);

}

void RoleShowUI::onStand(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateStand);

}

void RoleShowUI::onWalk(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateWalk);
}
void RoleShowUI::onSkill(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateCaster);
}
void RoleShowUI::onHurt(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateHurt);
}
void RoleShowUI::onDeath(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	character->setIState(CharacterStateType::FStateDeath);
}