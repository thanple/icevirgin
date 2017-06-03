
#include "protocol\SRequestTaskStatus.pb.h"
#include "scene\GameScene.h"

class _SRequestTaskStatus
{
public:
	static void process(SRequestTaskStatus msg)
	{
		GameScene * scene = GameScene::getInstance();
		if (scene)
		{
			::SRequestTaskStatus_Status status = msg.status();

			if (status == SRequestTaskStatus_Status::SRequestTaskStatus_Status_NOT_START)
			{
				scene->getGameInfoUI()->getNpcUI()->setShownpcId(msg.type());
			}
			
		}
	}
};