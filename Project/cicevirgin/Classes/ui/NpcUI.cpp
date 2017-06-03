
#include "NpcUI.h"
//using namespace UI;

NpcUI::NpcUI() :labelShow(NULL)
{
	m_shownpcId = -1;
}
NpcUI::~NpcUI()
{

}
bool NpcUI::init()
{
	if (!Layer::init())
		return false;


	//加上剧情对话
	auto storyNode = CSLoader::createNode("NPCSpeak.csb");
	storyNode->setTag(1);
	this->addChild(storyNode);

	//添加按钮响应
	Button * closeBtn = dynamic_cast<Button*>(storyNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(NpcUI::onCloseModal, this));
	Button * continueBtn = dynamic_cast<Button*>(storyNode->getChildByName("Continue"));
	continueBtn->addTouchEventListener(CC_CALLBACK_2(NpcUI::onNextModal, this));

	//TextBMFont txtShow = dynamic_cast<Button*>(storyNode->getChildByName("BitmapFontLabel_2"));
	labelShow = dynamic_cast<TextBMFont*>(storyNode->getChildByName("BitmapFontLabel_2"));
	labelShow->setString("123");

	this->setVisible(false);
	m_iShow = false;


	//this->displayModal(1);

	this->schedule([this](float f){
		if (m_shownpcId > 0)
		{
			this->displayModal(m_shownpcId);
			m_shownpcId = -1;
		}
	}, 1.6f,"npcModal");

	return true;
}

void NpcUI::displayModal(int n)
{
	this->setVisible(true);
	m_iShow = true;

	string str = "story/" + to_string(n) + ".txt";
	ifs = ifstream(str.c_str());
	string tmp;
	if (getline(ifs, tmp))
	{
		labelShow->setString(tmp);
	};

}

void NpcUI::onCloseModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	this->setVisible(false);
	ifs.close();

	//这一块必须延时，不然关闭后就自动寻路了
	this->scheduleOnce([this](float f){
		m_iShow = false;
	}, 0.5f,"closeModal1");
	
}

void NpcUI::onNextModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	string tmp;
	if (getline(ifs, tmp))
	{
		labelShow->setString(tmp);
	};
}