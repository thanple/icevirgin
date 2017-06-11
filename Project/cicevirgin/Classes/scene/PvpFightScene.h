
#pragma once
#include "Common.h"
#include "character\Player.h"
#include "protocol\SPvpRoomEnermyInfo.pb.h"
#include "protocol\SPvpAttackFlag.pb.h"

class PvpFightScene : public Layer
{

private:
	Node * rootNode;

	CC_SYNTHESIZE_READONLY(Character *, player, Player);	//����(���ⲿ����)
	CC_SYNTHESIZE_READONLY(Character *, enermy, Enermy);	//��
	CC_SYNTHESIZE(SPvpRoomEnermyInfo, enermyInfo, SPvpRoomEnermyInfo);	//��������
	CC_SYNTHESIZE(int, playerBlood, PlayerBlood);	//����Ѫ��
	CC_SYNTHESIZE(int, enermyBlood, EnermyBlood);	//����Ѫ��
	CC_SYNTHESIZE(int, skillNum, SkillNum);	//���ܵ�
	CC_SYNTHESIZE(int, money, Money);	//���
	CC_SYNTHESIZE(SPvpAttackFlag, sPvpAttackFlag, SPvpAttackFlag);	//������־
	
private:
	bool isClose;	//�Ƿ�ر�
	string toast;	//��Ϣչʾ
	Sprite * skillShow_A;	//����չʾ����
	Sprite * skillShow_B;	//����չʾ����

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
	void scheduleUpdateUI(float dt);	//����UI
	void playSkill(ResourceProvider::Skill::Number skillNumber , Character * character);

	void updateEnermyAttack(int skillType);	//�з�������ͬ��
	void onAttackPlayEffect(Character * attacker, Character * hurter, CharacterDirectionType forward, CharacterDirectionType stand);	//�չ�Ч������

public:
	PvpFightScene();
	~PvpFightScene();
	CREATE_FUNC(PvpFightScene);
	bool init();
	static PvpFightScene * getInstance();
	void setButtonEnabled(bool isEnabled);
	void toastShow(string str);
};