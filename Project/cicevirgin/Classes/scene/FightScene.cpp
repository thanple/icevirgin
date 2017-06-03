
#include "FightScene.h"
#include "ui\Toast.h"
#include "util\MyProtoSocket.h"
#include "protocol\CRequestFight.pb.h"
#include "protocol\CFight.pb.h"
#include "scene\GameScene.h"

const Point Fighter_A = Point(200, 200);
const Point Fighter_A_Hurt = Point(300, 200);

const Point Fighter_B = Point(600, 200);
const Point Fighter_B_Hurt = Point(530, 200);


static FightScene * _instance = NULL;
FightScene * FightScene::getInstance()
{
	return _instance;
}

FightScene::FightScene() : player(NULL), skillShow(NULL), isAttackerYou(true),
monsterId(0), monster(NULL)
{
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Skill::PLIST_PATH(ResourceProvider::Skill::Skill_1));
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Skill::PLIST_PATH(ResourceProvider::Skill::Skill_2));
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Skill::PLIST_PATH(ResourceProvider::Skill::Skill_3));
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
		ResourceProvider::Skill::PLIST_PATH(ResourceProvider::Skill::Skill_4));

	playerBlood = 100;
	enermyBlood = 100;

	skillNum = 0;
	isClose = false;

	money = 0;
}
FightScene::~FightScene()
{
	_instance = NULL;
}

//ToastShow
void FightScene::toastShow(string str)
{
	this->toast = str;
}

bool FightScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//����UI
	auto rootNode = CSLoader::createNode("FightScene.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	btnAttack = dynamic_cast<Button*>(rootNode->getChildByName("Attack"));
	btnAttack->addTouchEventListener(CC_CALLBACK_2(FightScene::onAttack, this));

	btnSkill1 = dynamic_cast<Button*>(rootNode->getChildByName("Skill1"));
	btnSkill1->addTouchEventListener(CC_CALLBACK_2(FightScene::onSkill1, this));
	btnSkill2 = dynamic_cast<Button*>(rootNode->getChildByName("Skill2"));
	btnSkill2->addTouchEventListener(CC_CALLBACK_2(FightScene::onSkill2, this));
	btnSkill3 = dynamic_cast<Button*>(rootNode->getChildByName("Skill3"));
	btnSkill3->addTouchEventListener(CC_CALLBACK_2(FightScene::onSkill3, this));
	btnSkill4 = dynamic_cast<Button*>(rootNode->getChildByName("Skill4"));
	btnSkill4->addTouchEventListener(CC_CALLBACK_2(FightScene::onSkill4, this));

	Button * onInstanceClose = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	onInstanceClose->addTouchEventListener(CC_CALLBACK_2(FightScene::onInstanceClose, this));

	//��������
	//player����
	player = Character::create();
	/*player->pBody->setFigureId(ResourceProvider::Character::PLAYER_11001);
	player->pHair->setFigureId(ResourceProvider::Hair::Hair_11001);
	player->pWeapon->setFigureId(ResourceProvider::Weapon::Weapon_10000);*/

	//player->setRoleId(4097);

	player->setPosition(Fighter_B);
	//player->updateFigureActions();
	this->addChild(player);

	//���ض�������
	skillShow = Sprite::create();
	skillShow->setPosition(Fighter_A);
	this->addChild(skillShow);


	//��������
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::ATTACK);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_1);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_2);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_3);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_4);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::MONSTER_ATTACK);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::MONSTER_GIRL);

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::FIGHT_SCENE_MUSIC);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::FIGHT_SCENE_MUSIC);


	//schedule����
	this->schedule(schedule_selector(FightScene::scheduleUpdateUI, 1.6f));

	//��������������
	CRequestFight requestFight;
	requestFight.set_fighthid(-1);
	requestFight.set_fighthtype(1);
	MyProtoSocket::send(1009, requestFight.SerializeAsString());

	_instance = this;

	//this->toastShow(Common::FontToUTF8("�ֵ����ˣ������ɣ��������ǣ�"));
	return true;
}

void FightScene::scheduleUpdateUI(float dt)
{
	//���¹���
	if (NULL == monster)
	{
		if (monsterId > 0)
		{
			//���ع���
			monster = Monster::create();
			monster->setFigureId(monsterId);
			monster->setPosition(Fighter_A);
			monster->updateFigureActions();
			this->addChild(monster);
		}
	}

	//����UI
	ui::TextBMFont * enermyBloodLabel = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("EnermyBlood"));
	enermyBloodLabel->setString(to_string(enermyBlood));

	ui::TextBMFont * myBloodLabel = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("MyBlood"));
	myBloodLabel->setString(to_string(playerBlood));

	if (this->toast != "")
	{
		auto toastShow = Toast::create(toast.c_str());
		this->addChild(toastShow);
		toast = "";
	}

	//���¼��ܵ�
	ui::TextBMFont * skill_num = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("skill_num"));
	skill_num->setString(to_string(skillNum));
	
	//���½�Ǯ
	ui::TextBMFont * money_num = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("money"));
	money_num->setString(to_string(money));


	isClose = enermyBlood <= 0 || playerBlood <= 0;

	if (isClose){
		if (enermyBlood <=0 && monster->getIState()->getStateType() != CharacterStateType::FStateDeath)
		{
			monster->setIState(CharacterStateType::FStateDeath);
		}
		if (playerBlood <= 0 && player->getIState()->getStateType() != CharacterStateType::FStateDeath)
		{
			player->setIState(CharacterStateType::FStateDeath);
		}

	}
	
}


void FightScene::onAttack(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	if (isClose)	return;
	
	/**
	*��������·�������Աߣ���һ������ת��ԭ·����
	*/

	Vector<FiniteTimeAction *> array;
	//����
	array.pushBack(CCCallFunc::create([this](){
		player->setDirectionType(CharacterDirectionType::FDirLeft);
		player->setIState(CharacterStateType::FStateRun);
	}));

	//�ߵ������Ա�
	int xDistance = (Fighter_B - Fighter_A_Hurt).x;
	CCMoveTo * moveToEnermyr = CCMoveTo::create(xDistance / 30 * 0.3f, Fighter_A_Hurt);
	array.pushBack(moveToEnermyr);
	
	//��һ��
	array.pushBack(CCCallFunc::create([this](){
		player->setIState(CharacterStateType::FStateAttack);
		SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::ATTACK);

		CFight cfight;
		cfight.set_fighthtype(1);
		cfight.set_skilltype(0);
		cfight.set_fighthid(player->getRoleId());

		MyProtoSocket::send(1008, cfight.SerializeAsString());

	}));	
	
	//�������˺ͻ�ԭ
	array.pushBack(CCCallFunc::create([this](){

		//0.6����������״̬
		monster->runAction(Sequence::create(DelayTime::create(0.6f), CallFunc::create([this](){
			monster->setIState(CharacterStateType::FStateHurt);
		}), NULL));
		monster->runAction(Sequence::create(DelayTime::create(1.2f), CallFunc::create([this](){
				this->monster->setIState(CharacterStateType::FStateStand);
			}), NULL));
			
	}));

	array.pushBack(DelayTime::create(1.6f));

	//��ת
	array.pushBack(CCCallFunc::create([this](){
		player->setDirectionType(CharacterDirectionType::FDirRight);
		player->setIState(CharacterStateType::FStateRun);
	}));
	
	//�߻�ԭ��
	int xDistance2 = ( Fighter_B - Fighter_A_Hurt).x;
	CCMoveTo * moveToSource = CCMoveTo::create(xDistance2 / 30 * 0.3f, Fighter_B);
	array.pushBack(moveToSource);

	//վ��
	array.pushBack(CCCallFunc::create([this](){
		player->setDirectionType(CharacterDirectionType::FDirDownAndLeft);
		player->setIState(CharacterStateType::FStateStand);
	}));

	array.pushBack(DelayTime::create(1.f));
	array.pushBack(CCCallFunc::create([this](){
		if (enermyBlood > 0)
		{
			this->toastShow(Common::FontToUTF8("���﹥��״̬"));
			this->onMonsterAttack();
		}

	}));
	
	ActionInterval *  actions = Sequence::create(array);
	player->runAction(actions);

	this->processAfterAttack(0);
}
void FightScene::onSkill1(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	if (skillNum < 2)	{
		toastShow(Common::FontToUTF8("���ܵ㲻��!"));
		return;
	}

	player->setIState(CharacterStateType::FStateCaster);

	this->playSkill(ResourceProvider::Skill::Skill_1);

	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_1);

	this->processAfterAttack(1);
}
void FightScene::onSkill2(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	if (skillNum < 5)	{
		toastShow(Common::FontToUTF8("���ܵ㲻��!"));
		return;
	}

	player->setIState(CharacterStateType::FStateCaster);

	this->playSkill(ResourceProvider::Skill::Skill_2);

	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_2);

	this->processAfterAttack(2);
}
void FightScene::onSkill3(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	if (skillNum < 7)	{
		toastShow(Common::FontToUTF8("���ܵ㲻��!"));
		return;
	}
	player->setIState(CharacterStateType::FStateCaster);

	this->playSkill(ResourceProvider::Skill::Skill_3);

	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_3);

	this->processAfterAttack(3);
}
void FightScene::onSkill4(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	if (skillNum < 10)	{
		toastShow(Common::FontToUTF8("���ܵ㲻��!"));
		return;
	}

	player->setIState(CharacterStateType::FStateCaster);

	this->playSkill(ResourceProvider::Skill::Skill_4);

	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_4);

	this->processAfterAttack(4);
}

void FightScene::setButtonEnabled(bool isEnabled)
{
	btnAttack->setTouchEnabled(isEnabled);
	btnSkill1->setTouchEnabled(isEnabled);;
	btnSkill2->setTouchEnabled(isEnabled);;
	btnSkill3->setTouchEnabled(isEnabled);;
	btnSkill4->setTouchEnabled(isEnabled);;

	btnAttack->setEnabled(isEnabled);
	btnSkill1->setEnabled(isEnabled);
	btnSkill2->setEnabled(isEnabled);;
	btnSkill3->setEnabled(isEnabled);;
	btnSkill4->setEnabled(isEnabled);;
}

void FightScene::playSkill(ResourceProvider::Skill::Number skillNumber)
{
	//���ż���
	//Sequence * sequence = Sequence::create(Common::createActionsFromCache(ResourceProvider::Skill::PATH(skillNumber), 0));
	//skillShow->runAction(sequence);

	//0.6����������״̬
	Vector<FiniteTimeAction *> array;
	array.pushBack(Common::createActionsFromCache(ResourceProvider::Skill::PATH(skillNumber), 0));
	
	//����
	array.pushBack(CCCallFunc::create([this, skillNumber](){
		monster->setIState(CharacterStateType::FStateHurt);

		CFight cfight;
		cfight.set_fighthtype(1);
		cfight.set_skilltype(skillNumber);
		cfight.set_fighthid(player->getRoleId());

		MyProtoSocket::send(1008, cfight.SerializeAsString());
	}));

	//�ָ�վ��
	array.pushBack(DelayTime::create(0.6f));
	array.pushBack(CCCallFunc::create([this](){
		monster->setIState(CharacterStateType::FStateStand);
	}));

	//1s����￪ʼ����
	array.pushBack(DelayTime::create(1.f));
	array.pushBack(CCCallFunc::create([this](){
		if (enermyBlood > 0)
		{
			this->toastShow(Common::FontToUTF8("���﹥��״̬"));
			this->onMonsterAttack();
		}

	}));

	ActionInterval *  actions = Sequence::create(array);
	skillShow->runAction(actions);


	//�ӳ�ִ�м��ܶ���
/*	ActionInterval * action = Common::createActionsFromCache(
		ResourceProvider::Skill::PATH(skillNumber), 0);
	
	//���ܲ������˺�
	skillShow->runAction(action);

	//Sequence * delayTimeAction = Sequence::create(DelayTime::create(0.6f), action, NULL);
	skillShow->runAction(CCSequence::create(delayTimeAction, CallFunc::create([this](){
		this->monster->setIState(CharacterStateType::FStateStand);
	}), NULL));*/
}


void FightScene::processAfterAttack(int attackType)
{
	this->isAttackerYou = false;
	this->setButtonEnabled(false);
}

void FightScene::onMonsterAttack()
{

	if (isClose ){
		return;
	}
	/**
	*�����ң���·�������Աߣ���������ԭ·����
	*/

	Vector<FiniteTimeAction *> array;
	//����
	array.pushBack(CCCallFunc::create([this](){
		monster->setDirectionType(CharacterDirectionType::FDirRight);
		monster->setIState(CharacterStateType::FStateRun);
	}));

	//�ߵ������Ա�
	int xDistance = (Fighter_B_Hurt - Fighter_A).x;
	CCMoveTo * moveToEnermyr = CCMoveTo::create(xDistance / 30 * 0.3f, Fighter_B_Hurt);
	array.pushBack(moveToEnermyr);

	//���﹥��
	array.pushBack(CCCallFunc::create([this](){
		monster->setIState(CharacterStateType::FStateAttack);
		if (monsterId == 40002)
			SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::MONSTER_GIRL);
		else
			SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::MONSTER_ATTACK);

		CFight cfight;
		cfight.set_fighthtype(1);
		cfight.set_skilltype(0);
		cfight.set_fighthid(monsterId);

		MyProtoSocket::send(1008, cfight.SerializeAsString());

	}));

	//�������˺ͻ�ԭ
	array.pushBack(CCCallFunc::create([this](){

		//0.6�����������״̬
		player->runAction(Sequence::create(DelayTime::create(0.6f), CallFunc::create([this](){
			player->setIState(CharacterStateType::FStateHurt);
		}), NULL));

		if (playerBlood <= 0) {
			player->runAction(Sequence::create(DelayTime::create(2.2f), CallFunc::create([this](){
				player->setIState(CharacterStateType::FStateStand);
			}), NULL));
		}

	}));
	array.pushBack(DelayTime::create(1.6f));

	//��ת
	array.pushBack(CCCallFunc::create([this](){
		monster->setDirectionType(CharacterDirectionType::FDirLeft);
		monster->setIState(CharacterStateType::FStateRun);
	}));

	//�߻�ԭ��
	int xDistance2 = (Fighter_B_Hurt - Fighter_A).x;
	CCMoveTo * moveToSource = CCMoveTo::create(xDistance2 / 30 * 0.3f, Fighter_A);
	array.pushBack(moveToSource);

	//վ��
	array.pushBack(CCCallFunc::create([this](){
		monster->setDirectionType(CharacterDirectionType::FDirRight);
		monster->setIState(CharacterStateType::FStateStand);
		
		if (playerBlood > 0)
		{
			this->toastShow(Common::FontToUTF8("�ֵ����ˣ������ɣ��������ǣ�"));
			this->setButtonEnabled(true);
		}

	}));

	ActionInterval *  actions = Sequence::create(array);
	monster->runAction(actions);

	this->isAttackerYou = true;
}

void FightScene::createMonster(int monsterId)
{
	this->monsterId = monsterId;
}

void FightScene::onInstanceClose(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	Director::getInstance()->replaceScene(Common::scene(GameScene::create()));
}