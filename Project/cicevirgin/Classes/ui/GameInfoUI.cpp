
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

	//����ChatUI
	//m_chatUI = ChatUI::create();
	//this->addChild(m_chatUI);

	//���Ϲ���UI
	m_operUI = OperationUI::create();
	this->addChild(m_operUI);

	//Npc��UI�Ի���
	m_npcUI = NpcUI::create();
	this->addChild(m_npcUI);

	//�̳�UI
	m_shopUI = ShopUI::create();
	this->addChild(m_shopUI);

	//Rank UI
	m_RankUI = RankUI::create();
	this->addChild(m_RankUI);

	//����Show
	m_RoleShowUI = RoleShowUI::create();
	this->addChild(m_RoleShowUI);

	//����
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
		this->addChild(Toast::create(Common::FontToUTF8("�ѿ��������ӽ�")));
	}
	else
	{
		this->addChild(Toast::create(Common::FontToUTF8("�ѹر������ӽ�")));
	}
}

//�Ƿ���ģ̬�Ի���
bool GameInfoUI::isModal()
{
	return m_npcUI->getIsShow() || m_shopUI->getIsShow() || m_RankUI->getIsShow()
		|| m_RoleShowUI->getIsShow() || m_taskUI->getIsShow();
}