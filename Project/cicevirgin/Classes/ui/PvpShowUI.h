
#pragma once

#include "Common.h"
#include "protocol\SRequestPvpRooms.pb.h"

class PvpShowUI : public Layer
{
private:
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);
	CC_SYNTHESIZE(bool, m_iShow, IsShow);

	CC_SYNTHESIZE(SRequestPvpRooms , m_rooms, SRequestPvpRooms);
	CC_SYNTHESIZE(bool, m_join, JoinRoom);

public:
	PvpShowUI();
	~PvpShowUI();
	bool init();
	CREATE_FUNC(PvpShowUI);

public:
	void displayModal();
	void onCloseModal(Ref* pSender, Widget::TouchEventType type);
	void onCreateRoom(Ref* pSender, Widget::TouchEventType type);	//创建房间

};