
#include "protocol\SCharacterPos.pb.h"
#include "scene\GameScene.h"

class _CharacterPos
{
public:
	void process(SCharacterPos msg)
	{
		if (GameScene * instance = GameScene::getInstance())
		{
			instance->setCharacterPos(msg);
		}
	}
};