
#include "protocol\SLogin.pb.h"
#include "scene\LoginScene.h"

class _SLogin
{
public:
	void process(SLogin sMsg)
	{
		if (LoginScene * scene = LoginScene::getInstance())
		{
			scene->setLoginFlag(true);
		}
	}
};