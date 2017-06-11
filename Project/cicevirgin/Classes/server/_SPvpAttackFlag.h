
#include "protocol\SPvpAttackFlag.pb.h"
#include "scene\PvpFightScene.h"

class _SPvpAttackFlag
{
public:
	void process(SPvpAttackFlag msg)
	{
		if (auto scene = PvpFightScene::getInstance())
		{
			scene->setSPvpAttackFlag(msg);
		}
	}
};