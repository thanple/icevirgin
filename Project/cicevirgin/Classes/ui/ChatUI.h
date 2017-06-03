#pragma once

#include "Common.h"


#define CHAT_TAG_WORLD 0Xf01
#define CHAT_TAG_GUILD 0Xf02
#define CHAT_TAG_SYSTEM 0Xf03

class ChatUI : public Layer
{

public:
	ChatUI();
	~ChatUI();
	CREATE_FUNC(ChatUI);
	bool init();
	void hide();
	void show();

};