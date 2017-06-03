
#include "ChatUI.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

ChatUI::ChatUI()
{
}

ChatUI::~ChatUI()
{
}

bool ChatUI::init()
{
	if (!Layer::init())
	{
		return false;
	}
	this->setTouchEnabled(true);


	auto rootNode = CSLoader::createNode("ChatScene.csb");
	this->addChild(rootNode);

	return true;

}


void ChatUI::hide()
{

}
void ChatUI::show()
{

}