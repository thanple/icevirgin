#pragma once

#include "Common.h"
#include "ChatUI.h"
#include "OperationUI.h"
#include "NpcUI.h"
#include "Shop.h"
#include "Rank.h"
#include "RoleShow.h"
#include "TaskUI.h"



class GameInfoUI : public Layer
{
public:
	static GameInfoUI * getInstance();
private:
	CC_SYNTHESIZE_READONLY(Node *, rootNode, RootNode);

	CC_SYNTHESIZE_READONLY(ChatUI * , m_chatUI, ChatUI);
	CC_SYNTHESIZE_READONLY(OperationUI *, m_operUI, OperationUI);
	CC_SYNTHESIZE_READONLY(NpcUI *, m_npcUI, NpcUI);
	CC_SYNTHESIZE_READONLY(bool, m_showCenter, ShowCenter);	//是否让主角在中间

	CC_SYNTHESIZE_READONLY(ShopUI *, m_shopUI, ShopUI);
	CC_SYNTHESIZE_READONLY(RankUI *, m_RankUI, RankUI);
	CC_SYNTHESIZE_READONLY(RoleShowUI *, m_RoleShowUI, RoleShowUI);
	CC_SYNTHESIZE_READONLY(TaskUI *, m_taskUI, TaskUI);

public:
	CREATE_FUNC(GameInfoUI);
	GameInfoUI();
	~GameInfoUI();
	bool init();
	bool isModal();	//是否有模态对话框
private:
	void onShowCenter(Ref* pSender, Widget::TouchEventType type);
};