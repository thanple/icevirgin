
#include "CharacterNpc.h"

CharacterNpc::CharacterNpc()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Npc::PLIST_PATH(ResourceProvider::Npc::Npc_10113));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Npc::PLIST_PATH(ResourceProvider::Npc::Npc_10114));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Npc::PLIST_PATH(ResourceProvider::Npc::Npc_10115));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Npc::PLIST_PATH(ResourceProvider::Npc::Npc_10213));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Npc::PLIST_PATH(ResourceProvider::Npc::Npc_10214));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Npc::PLIST_PATH(ResourceProvider::Npc::Npc_10215));
}
CharacterNpc::~CharacterNpc()
{

}


bool CharacterNpc::init()
{
	if (!Sprite::init())
	{
		return false;
	}



	return true;
}

void CharacterNpc::runAction()
{
	Sprite::stopActionByTag(1);

	ActionInterval * pAction = Common::createActionsFromCache(ResourceProvider::Npc::PATH(m_path),0);
	RepeatForever * repeatForever = RepeatForever::create(pAction);
	repeatForever->setTag(1);

	Sprite::runAction(repeatForever);
}