
#include "Rank.h"
#include "util\MyProtoSocket.h"
#include "protocol\CRequestRank.pb.h"

RankUI::RankUI()
{
	labelStr = "";
}
RankUI::~RankUI()
{

}
bool RankUI::init()
{
	if (!Layer::init())
		return false;

	auto rootNode = CSLoader::createNode("Rank.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	Button * closeBtn = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(RankUI::onCloseModal, this));

	this->setVisible(false);
	m_iShow = false;


	this->schedule(schedule_selector(RankUI::scheduleUpdateUI, 1.6f));

	return true;

}

void RankUI::scheduleUpdateUI(float f)
{
	ui::ScrollView * pLabel = dynamic_cast<ui::ScrollView*>(rootNode->getChildByName("RankList"));
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

	text->setString(labelStr);
}

void RankUI::displayModal()
{
	this->setVisible(true);
	m_iShow = true;

	MyProtoSocket::send(1017, CRequestRank().SerializeAsString());

}
void RankUI::onCloseModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	this->setVisible(false);

	//这一块必须延时，不然关闭后就自动寻路了
	this->scheduleOnce([this](float f){
		m_iShow = false;
	}, 0.5f, "closeModal1");
}
