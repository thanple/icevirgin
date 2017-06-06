
#include "protocol\SRemoveCharacter.pb.h"
#include "scene\GameScene.h"

class _SRemoveCharacter
{
public:
	void process(SRemoveCharacter msg)
	{
		if (GameScene * instance = GameScene::getInstance())
		{
			instance->setRemoveCharacter(msg);
		}
	}
};