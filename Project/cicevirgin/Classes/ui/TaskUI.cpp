
#include "TaskUI.h"
#include "scene\FightScene.h"
#include "character\Player.h"

TaskUI::TaskUI()
{

}
TaskUI::~TaskUI()
{

}
bool TaskUI::init()
{
	if (!Layer::init())
		return false;


	auto rootNode = CSLoader::createNode("TaskScene.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	Button * closeBtn = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(TaskUI::onCloseModal, this));

	Button * onTask1 = dynamic_cast<Button*>(rootNode->getChildByName("Task1"));
	onTask1->addTouchEventListener(CC_CALLBACK_2(TaskUI::onTask1, this));

	this->setVisible(false);
	m_iShow = false;

	return true;
}

void TaskUI::displayModal()
{
	this->setVisible(true);
	m_iShow = true;
}
void TaskUI::onCloseModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	this->setVisible(false);

	//这一块必须延时，不然关闭后就自动寻路了
	this->scheduleOnce([this](float f){
		m_iShow = false;
	}, 0.5f, "closeModalTaskUI");
}


void TaskUI::onTask1(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	auto fightScene = FightScene::create();
	Character * character = fightScene->getPlayer();
	Player * player = Player::sharePlayer();
	character->setRoleId(player->getRoleId());
	character->pBody->setFigureId(player->pBody->getFigureId());
	character->pHair->setFigureId(player->pHair->getFigureId());
	character->pWeapon->setFigureId(player->pWeapon->getFigureId());
	character->setIState(CharacterStateType::FStateStand);
	character->setDirectionType(CharacterDirectionType::FDirDownAndLeft);

	Director::getInstance()->replaceScene(Common::scene(fightScene));
}