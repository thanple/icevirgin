
#include "protocol\SRequestRank.pb.h"
#include "ui\GameInfoUI.h"

class _SRequestRank
{
public:
	void process(SRequestRank msg)
	{
		if (GameInfoUI * ui = GameInfoUI::getInstance())
		{
			ui->getRankUI()->setLabelStr(msg.name());
		}

	}
};