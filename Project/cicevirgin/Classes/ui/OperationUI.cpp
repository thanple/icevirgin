
#include "OperationUI.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "protocol\CChatMsg.pb.h"
#include "util\MyProtoSocket.h"
#include "ui\Shop.h"

#include "ui\Toast.h"

#include "GameInfoUI.h"


//using namespace UI;
/*UI::OperationUI * UI::OperationUI::getInstance2()
{
	return _OperationUI_instance;
}*/
static OperationUI * _instacne_operatUI = NULL;
OperationUI::OperationUI() : rootNode(NULL)
{
}

OperationUI::~OperationUI()
{
	_instacne_operatUI = NULL;
	//UI2::_operationUI_insance = NULL;
}
OperationUI * OperationUI::getInstance()
{
	return _instacne_operatUI;
}

bool OperationUI::init()
{
	if (!Layer::init())
	{
		return false;
	}
	this->setTouchEnabled(true);

	auto rootNode = CSLoader::createNode("Operation.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	//聊天模块 
	ui::ScrollView * pLabel = dynamic_cast<ui::ScrollView*>(rootNode->getChildByName("Chat_Label"));

	Button * btnSend = dynamic_cast<Button*>(rootNode->getChildByName("Chat_Send"));
	btnSend->addTouchEventListener(CC_CALLBACK_2(OperationUI::onBtnSend, this));

	//商城模块
	Button * btnShop = dynamic_cast<Button*>(rootNode->getChildByName("Shop"));
	btnShop->addTouchEventListener(CC_CALLBACK_2(OperationUI::onShop, this));

	//排行榜模块
	Button * btnRank = dynamic_cast<Button*>(rootNode->getChildByName("Rank"));
	btnRank->addTouchEventListener(CC_CALLBACK_2(OperationUI::onRank, this));

	//人物Show
	Button * btnRoleShow = dynamic_cast<Button*>(rootNode->getChildByName("RoleShow"));
	btnRoleShow->addTouchEventListener(CC_CALLBACK_2(OperationUI::onRoleShow, this));

	//任务
	Button * onTaskShow = dynamic_cast<Button*>(rootNode->getChildByName("Task"));
	onTaskShow->addTouchEventListener(CC_CALLBACK_2(OperationUI::onTaskShow, this));

	_instacne_operatUI = this;
	//UI2::_operationUI_insance = this;

	this->schedule(schedule_selector(OperationUI::scheduleUpdateUI, 1.6f));
	return true;

}

void OperationUI::scheduleUpdateUI(float dt)
{
	ui::ScrollView * pLabel = dynamic_cast<ui::ScrollView*>(rootNode->getChildByName("Chat_Label"));
	Text * text = (Text *)pLabel->getChildByTag(1);
	if (NULL == text)
	{
		text = Text::create("", "Arial", 15);
		text->setTag(1);
		text->ignoreContentAdaptWithSize(false);
		text->setSize(Size(200, 600));
		text->setPosition(Point(100, 0));
		pLabel->addChild(text);
	}
	if (labelStr != text->getString()){

		text->setString(labelStr);
	}	
	
	if (toast != "")
	{
		auto toastShow = Toast::create(toast.c_str());
		this->addChild(toastShow);
		toast = "";
	}

	
	
}

void OperationUI::onBtnSend(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	
	ui::ScrollView * pLabel = dynamic_cast<ui::ScrollView*>(rootNode->getChildByName("Chat_Label"));
	Text * text = (Text *)pLabel->getChildByTag(1);

	if (NULL == text)
	{
		text = Text::create("", "Arial", 15);
		text->setTag(1);
		text->ignoreContentAdaptWithSize(false);
		text->setSize(Size(200, 600));
		text->setPosition(Point(100, 0));
		pLabel->addChild(text);
	}

	ui::TextField * inputText = dynamic_cast<ui::TextField*>(rootNode->getChildByName("Chat_Input"));
	string inputStr = inputText->getString();

	CChatMsg chatMsg;
	chatMsg.set_msg(inputStr);

	MyProtoSocket::send(1005,chatMsg.SerializeAsString());
}

void OperationUI::updateLabel(string msg)
{
	ui::ScrollView * pLabel = dynamic_cast<ui::ScrollView*>(rootNode->getChildByName("Chat_Label"));
	Text * text = (Text *)pLabel->getChildByTag(1);

	if (NULL == text)
	{
		text = Text::create("", "Arial", 15);
		text->setTag(1);
		text->ignoreContentAdaptWithSize(false);
		text->setSize(Size(200, 200));
		text->setPosition(Point(100, 0));
		pLabel->addChild(text);
	}
	ui::TextField * inputText = dynamic_cast<ui::TextField*>(rootNode->getChildByName("Chat_Input"));
	string beforeStr = labelStr;
	labelStr = beforeStr + msg + "\n";
	inputText->setText("");
}

void OperationUI::showToast(string str)
{
	toast = str;
}

void OperationUI::onShop(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	GameInfoUI::getInstance()->getShopUI()->displayModal();
}

void OperationUI::onRank(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	GameInfoUI::getInstance()->getRankUI()->displayModal();
}

void OperationUI::onRoleShow(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	GameInfoUI::getInstance()->getRoleShowUI()->displayModal();
}

void OperationUI::onTaskShow(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	GameInfoUI::getInstance()->getTaskUI()->displayModal();
}