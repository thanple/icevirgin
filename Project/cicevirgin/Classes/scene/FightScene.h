#pragma once

#include "Common.h"
#include "character\Player.h"
#include "character\Monster.h"

class FightScene : public Layer
{

private:
	Node * rootNode;

	CC_SYNTHESIZE_READONLY(Character * ,player, Player);	//主角(在外部加载)
	Sprite * skillShow;	//技能展示动画
	Monster * monster;	//怪物角色
	bool isAttackerYou;	//是否是你攻击

	//主角血量
	CC_SYNTHESIZE(int, playerBlood, PlayerBlood);
	//怪物血量
	CC_SYNTHESIZE(int, enermyBlood, EnermyBlood);

	//技能点
	CC_SYNTHESIZE(int, skillNum, SkillNum);

	//金币
	CC_SYNTHESIZE(int, money, Money);

	//怪物id
	int monsterId;

	//toast
	string toast;

public:
	FightScene();
	~FightScene();
	CREATE_FUNC(FightScene);
	bool init();

private:
	Button  * btnAttack;
	Button  * btnSkill1;
	Button  * btnSkill2;
	Button  * btnSkill3;
	Button  * btnSkill4;

	void onAttack(Ref* pSender, Widget::TouchEventType type);
	void onSkill1(Ref* pSender, Widget::TouchEventType type);
	void onSkill2(Ref* pSender, Widget::TouchEventType type);
	void onSkill3(Ref* pSender, Widget::TouchEventType type);
	void onSkill4(Ref* pSender, Widget::TouchEventType type);
	void onInstanceClose(Ref* pSender, Widget::TouchEventType type);
	void setButtonEnabled(bool isEnabled);

	//播放特效
	void playSkill(ResourceProvider::Skill::Number skillNumber);

	//攻击完之后处理的逻辑
	void processAfterAttack(int attackType);	//0普攻,技能1,2,3,4

	//怪物攻击
	void onMonsterAttack();

	//void OperationUI::scheduleUpdateUI(float dt)
	void scheduleUpdateUI(float dt);

	//
	bool isClose;


public:
	void createMonster(int monsterId);
	static FightScene * getInstance();
	//ToastShow
	void toastShow(string str);

};