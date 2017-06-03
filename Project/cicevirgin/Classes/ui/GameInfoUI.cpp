
#include "GameInfoUI.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui\Toast.h"

static GameInfoUI * _instance;
GameInfoUI * GameInfoUI::getInstance()
{
	return _instance;
}

GameInfoUI::GameInfoUI() : m_npcUI(NULL), m_operUI(NULL), m_shopUI(NULL),
m_RankUI(NULL), m_RoleShowUI(NULL), m_taskUI(NULL)
{

}
GameInfoUI::~GameInfoUI()
{
	_instance = NULL;
}

bool GameInfoUI::init()
{
	m_showCenter = false;
	if (!Layer::init())
		return false;

	auto rootNode = CSLoader::createNode("MainScene.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	Button * btnShow = dynamic_cast<Button*>(rootNode->getChildByName("showPersonCenter"));
	btnShow->addTouchEventListener(CC_CALLBACK_2(GameInfoUI::onShowCenter, this));

	//加上ChatUI
	//m_chatUI = ChatUI::create();
	//this->addChild(m_chatUI);

	//加上功能UI
	m_operUI = OperationUI::create();
	this->addChild(m_operUI);

	//Npc的UI对话框
	m_npcUI = NpcUI::create();
	this->addChild(m_npcUI);

	//商场UI
	m_shopUI = ShopUI::create();
	this->addChild(m_shopUI);

	//Rank UI
	m_RankUI = RankUI::create();
	this->addChild(m_RankUI);

	//人物Show
	m_RoleShowUI = RoleShowUI::create();
	this->addChild(m_RoleShowUI);

	//任务
	m_taskUI = TaskUI::create();
	this->addChild(m_taskUI);


	_instance = this;
	return true;
}

void GameInfoUI::onShowCenter(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	m_showCenter = !m_showCenter;

	if (m_showCenter) 
	{
		this->addChild(Toast::create(Common::FontToUTF8("已开启主角视角")));
	}
	else
	{
		this->addChild(Toast::create(Common::FontToUTF8("已关闭主角视角")));
	}
}

//是否有模态对话框
bool GameInfoUI::isModal()
{
	return m_npcUI->getIsShow() || m_shopUI->getIsShow() || m_RankUI->getIsShow()
		|| m_RoleShowUI->getIsShow() || m_taskUI->getIsShow();
}