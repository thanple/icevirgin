
#include "protocol\SRequestPvpRooms.pb.h"
#include "ui\GameInfoUI.h"

class _SRequestPvpRooms
{
public:
	void process(SRequestPvpRooms msg)
	{
		if (GameInfoUI * ui = GameInfoUI::getInstance())
		{
			ui->getPvpShowUI()->setSRequestPvpRooms(msg);
		}

	}
};