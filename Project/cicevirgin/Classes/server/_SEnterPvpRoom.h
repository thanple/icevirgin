
#pragma once

#include "protocol\SEnterPvpRoom.pb.h"
#include "ui\GameInfoUI.h"

class _SEnterPvpRoom
{
public:
	void process(SEnterPvpRoom msg)
	{
		if (GameInfoUI * ui = GameInfoUI::getInstance())
		{
			ui->getPvpShowUI()->setJoinRoom(true);
		}
	}
};