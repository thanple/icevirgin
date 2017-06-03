#include "Toast.h"
Toast::Toast(void)
{
}

Toast::~Toast(void)
{
}

bool Toast::init()
{
	if (!Layer::init()) {
		return false;
	}
	//���ô�С����ʾλ��
	this->setContentSize(Size::ZERO);
	auto size = Director::getInstance()->getVisibleSize();
	Vec2 pos = Vec2(size.width / 2, size.height / 2);
	this->setPosition(pos);

	return true;
}

//����������ʾ��
Toast* Toast::create(const char* text, int fontsize, float time)
{
	Toast* toast = Toast::create();
	toast->setLocalZOrder(INT_MAX);
	toast->setText(text, fontsize, time);
	toast->setBackgound();
	return toast;
}

//��������
void Toast::setText(const char* text, int fontsize, float time)
{
	m_label = Label::createWithSystemFont(text, "", fontsize);
	this->addChild(m_label, 3);

	Sequence * ation = Sequence::create(ScaleTo::create(time, 1.0), CallFunc::create(CC_CALLBACK_0(Toast::removeSelf, this)), NULL);
	this->runAction(ation);
}

//���ñ���
void Toast::setBackgound(){
	m_backgound = LayerColor::create(Color4B(0, 0, 0, 0));
	this->addChild(m_backgound, 2);
	m_backgound->ignoreAnchorPointForPosition(false);
	m_backgound->setContentSize(Size::ZERO);
	m_backgound->setAnchorPoint(Vec2(0.5f, 0.5f));
	m_backgound->setOpacity(150);
	if (m_label){
		Size size = Size(m_label->getContentSize().width + m_label->getSystemFontSize(), m_label->getContentSize().height + m_label->getSystemFontSize() / 2);
		m_backgound->setContentSize(size);
		m_backgound->setPosition(m_label->getPosition());
	}
}

//�Ƴ�Toast
void Toast::removeSelf(){
	this->removeFromParentAndCleanup(true);
}