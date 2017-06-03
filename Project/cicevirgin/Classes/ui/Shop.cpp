
#include "Shop.h"
#include "util\MyProtoSocket.h"
#include "protocol\CBuy.pb.h"
#include "ui\Toast.h"

ShopUI::ShopUI()
{
	toast = "";
}
ShopUI::~ShopUI()
{

}
bool ShopUI::init()
{
	if (!Layer::init())
		return false;

	auto rootNode = CSLoader::createNode("Shop.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	Button * closeBtn = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(ShopUI::onCloseModal, this));


	Button * buy1 = dynamic_cast<Button*>(rootNode->getChildByName("Buy1"));
	buy1->addTouchEventListener(CC_CALLBACK_2(ShopUI::onBuy1, this));
	Button * buy2 = dynamic_cast<Button*>(rootNode->getChildByName("Buy2"));
	buy2->addTouchEventListener(CC_CALLBACK_2(ShopUI::onBuy2, this));
	Button * buy3 = dynamic_cast<Button*>(rootNode->getChildByName("Buy3"));
	buy3->addTouchEventListener(CC_CALLBACK_2(ShopUI::onBuy3, this));

	this->setVisible(false);
	m_iShow = false;

	
	this->schedule([this](float f){
		if (toast != "")
		{
			auto toastShow = Toast::create(toast.c_str());
			this->addChild(toastShow);
			toast = "";
		}

	}, 1.6f, "toast");
	
	return true;
}

void ShopUI::displayModal()
{
	this->setVisible(true);
	m_iShow = true;
}
void ShopUI::onCloseModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	this->setVisible(false);

	//这一块必须延时，不然关闭后就自动寻路了
	this->scheduleOnce([this](float f){
		m_iShow = false;
	}, 0.5f, "closeModal1");
}

void ShopUI::onBuy1(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	CBuy buyMsg;
	buyMsg.set_shop(1);
	MyProtoSocket::send(1016, buyMsg.SerializeAsString());
}
void ShopUI::onBuy2(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	CBuy buyMsg;
	buyMsg.set_shop(2);
	MyProtoSocket::send(1016, buyMsg.SerializeAsString());
}
void ShopUI::onBuy3(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	CBuy buyMsg;
	buyMsg.set_shop(3);
	MyProtoSocket::send(1016, buyMsg.SerializeAsString());
}

void ShopUI::showToast(string str)
{
	toast = str;
}