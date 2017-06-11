
#pragma once
#include "Common.h"
#include "character\Player.h"
#include "protocol\SPvpRoomEnermyInfo.pb.h"
#include "protocol\SPvpAttackFlag.pb.h"

class PvpFightScene : public Layer
{

private:
	Node * rootNode;

	CC_SYNTHESIZE_READONLY(Character *, player, Player);	//主角(在外部加载)
	CC_SYNTHESIZE_READONLY(Character *, enermy, Enermy);	//敌
	CC_SYNTHESIZE(SPvpRoomEnermyInfo, enermyInfo, SPvpRoomEnermyInfo);	//敌人数据
	CC_SYNTHESIZE(int, playerBlood, PlayerBlood);	//主角血量
	CC_SYNTHESIZE(int, enermyBlood, EnermyBlood);	//怪物血量
	CC_SYNTHESIZE(int, skillNum, SkillNum);	//技能点
	CC_SYNTHESIZE(int, money, Money);	//金币
	CC_SYNTHESIZE(SPvpAttackFlag, sPvpAttackFlag, SPvpAttackFlag);	//进攻标志
	
private:
	bool isClose;	//是否关闭
	string toast;	//消息展示
	Sprite * skillShow_A;	//技能展示动画
	Sprite * skillShow_B;	//技能展示动画

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
	void scheduleUpdateUI(float dt);	//更新UI
	void playSkill(ResourceProvider::Skill::Number skillNumber , Character * character);

	void updateEnermyAttack(int skillType);	//敌方的数据同步
	void onAttackPlayEffect(Character * attacker, Character * hurter, CharacterDirectionType forward, CharacterDirectionType stand);	//普攻效果播放

public:
	PvpFightScene();
	~PvpFightScene();
	CREATE_FUNC(PvpFightScene);
	bool init();
	static PvpFightScene * getInstance();
	void setButtonEnabled(bool isEnabled);
	void toastShow(string str);
};