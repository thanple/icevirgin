
#include "protocol\SAddCharacter.pb.h"
#include "scene\GameScene.h"

class _SAddCharacter
{
public:
	void process(SAddCharacter msg)
	{
		if (GameScene * instance = GameScene::getInstance())
		{
			instance->setAddCharacter(msg);
		}
	}
};