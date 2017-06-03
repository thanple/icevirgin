#pragma once

#include "Common.h"
#include "character\Player.h"
#include "character\Monster.h"

class FightScene : public Layer
{

private:
	Node * rootNode;

	CC_SYNTHESIZE_READONLY(Character * ,player, Player);	//����(���ⲿ����)
	Sprite * skillShow;	//����չʾ����
	Monster * monster;	//�����ɫ
	bool isAttackerYou;	//�Ƿ����㹥��

	//����Ѫ��
	CC_SYNTHESIZE(int, playerBlood, PlayerBlood);
	//����Ѫ��
	CC_SYNTHESIZE(int, enermyBlood, EnermyBlood);

	//���ܵ�
	CC_SYNTHESIZE(int, skillNum, SkillNum);

	//���
	CC_SYNTHESIZE(int, money, Money);

	//����id
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

	//������Ч
	void playSkill(ResourceProvider::Skill::Number skillNumber);

	//������֮������߼�
	void processAfterAttack(int attackType);	//0�չ�,����1,2,3,4

	//���﹥��
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