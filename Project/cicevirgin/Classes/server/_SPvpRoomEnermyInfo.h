
#include "protocol\SPvpRoomEnermyInfo.pb.h"
#include "scene\PvpFightScene.h"

class _SPvpRoomEnermyInfo
{
public:
	void process(SPvpRoomEnermyInfo msg)
	{
		PvpFightScene * scene = NULL;
		while ((scene = PvpFightScene::getInstance()) == NULL)
		{
		}	

		scene->setSPvpRoomEnermyInfo(msg);
	}
};