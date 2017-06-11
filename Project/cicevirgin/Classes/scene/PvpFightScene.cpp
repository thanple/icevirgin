
#include "PvpFightScene.h"
#include "scene\GameScene.h"
#include "protocol\CDestroyRoom.pb.h"
#include "util\MyProtoSocket.h"
#include "ui\Toast.h"
#include "protocol\CFight.pb.h"
#include "protocol\CRequestUserInfo.pb.h"

const Point Fighter_A = Point(200, 200);
const Point Fighter_A_Hurt = Point(300, 200);

const Point Fighter_B = Point(600, 200);
const Point Fighter_B_Hurt = Point(530, 200);

static PvpFightScene * _instance = NULL;
PvpFightScene * PvpFightScene::getInstance()
{
	return _instance;
}

PvpFightScene::PvpFightScene() : player(NULL), enermy(NULL), skillShow_A(NULL),
skillShow_B(NULL), rootNode(NULL)
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

	skillNum = -1;
	money = -1;
	isClose = false;

	enermyInfo.set_body(-1);
	toast = "";
	sPvpAttackFlag.set_skilltype(-1);
}
PvpFightScene::~PvpFightScene()
{
	_instance = NULL;
}
void PvpFightScene::toastShow(string str)
{
	this->toast = str;
}
bool PvpFightScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//加载UI
	auto rootNode = CSLoader::createNode("FightScene.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);

	//加载player和enermy
	player = Character::create();
	player->setPosition(Fighter_B);
	this->addChild(player);

	enermy = Character::create();
	enermy->setPosition(Fighter_A);
	this->addChild(enermy);

	//控件初始化响应
	btnAttack = dynamic_cast<Button*>(rootNode->getChildByName("Attack"));
	btnAttack->addTouchEventListener(CC_CALLBACK_2(PvpFightScene::onAttack, this));

	btnSkill1 = dynamic_cast<Button*>(rootNode->getChildByName("Skill1"));
	btnSkill1->addTouchEventListener(CC_CALLBACK_2(PvpFightScene::onSkill1, this));
	btnSkill2 = dynamic_cast<Button*>(rootNode->getChildByName("Skill2"));
	btnSkill2->addTouchEventListener(CC_CALLBACK_2(PvpFightScene::onSkill2, this));
	btnSkill3 = dynamic_cast<Button*>(rootNode->getChildByName("Skill3"));
	btnSkill3->addTouchEventListener(CC_CALLBACK_2(PvpFightScene::onSkill3, this));
	btnSkill4 = dynamic_cast<Button*>(rootNode->getChildByName("Skill4"));
	btnSkill4->addTouchEventListener(CC_CALLBACK_2(PvpFightScene::onSkill4, this));

	Button * onInstanceClose = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	onInstanceClose->addTouchEventListener(CC_CALLBACK_2(PvpFightScene::onInstanceClose, this));

	//加载动画精灵
	skillShow_A = Sprite::create();
	skillShow_A->setPosition(Fighter_A);
	skillShow_B = Sprite::create();
	skillShow_B->setPosition(Fighter_B);
	this->addChild(skillShow_A);
	this->addChild(skillShow_B);

	//加载音乐
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::ATTACK);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_1);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_2);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_3);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::SKILL_4);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::MONSTER_ATTACK);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::MONSTER_GIRL);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::FIGHT_SCENE_MUSIC);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::FIGHT_SCENE_MUSIC);

	//schedule更新
	this->schedule(schedule_selector(PvpFightScene::scheduleUpdateUI, 0.8f));

	_instance = this;
	return true;
}

void PvpFightScene::scheduleUpdateUI(float dt)
{
	//消息展示
	if (this->toast != "")
	{
		auto toastShow = Toast::create(toast.c_str());
		this->addChild(toastShow);
		toast = "";
	}
	
	if (money == -1)	MyProtoSocket::send(1012, CRequestUserInfo().SerializeAsString());

	//更新技能点
	ui::TextBMFont * skill_num = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("skill_num"));
	skill_num->setString(to_string(skillNum));

	//更新金钱
	ui::TextBMFont * money_num = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("money"));
	money_num->setString(to_string(money));
	
	//更新UI
	ui::TextBMFont * enermyBloodLabel = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("EnermyBlood"));
	enermyBloodLabel->setString(to_string(enermyBlood));

	ui::TextBMFont * myBloodLabel = dynamic_cast<ui::TextBMFont*>(rootNode->getChildByName("MyBlood"));
	myBloodLabel->setString(to_string(playerBlood));

	//更新enermy
	static bool loadEnermy = false;
	if (enermyInfo.body() > 0)
	{
		enermy->pBody->setFigureId(enermyInfo.body());
		enermy->pHair->setFigureId(enermyInfo.hair());
		enermy->pWeapon->setFigureId(enermyInfo.weapon());
		enermy->setIState(CharacterStateType::FStateStand);
		enermy->setDirectionType(CharacterDirectionType::FDirRightAndDown);

		enermyInfo.set_body(-1);
		loadEnermy = true;
	}
	if (!loadEnermy)	return;

	//敌方的攻击数据同步
	if (sPvpAttackFlag.skilltype() >= 0)
	{
		this->updateEnermyAttack(sPvpAttackFlag.skilltype());
		sPvpAttackFlag.set_skilltype(-1);
	}

	
	//死亡状态更新
	isClose = enermyBlood <= 0 || playerBlood <= 0;
	if (isClose){
		if (enermyBlood <= 0 && enermy->getIState()->getStateType() != CharacterStateType::FStateDeath)
		{
			enermy->setIState(CharacterStateType::FStateDeath);
		}
		if (playerBlood <= 0 && player->getIState()->getStateType() != CharacterStateType::FStateDeath)
		{
			player->setIState(CharacterStateType::FStateDeath);
		}
	}
}

void PvpFightScene::onAttack(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;

	this->onAttackPlayEffect(player, enermy, CharacterDirectionType::FDirLeft, CharacterDirectionType::FDirDownAndLeft); 

	this->setButtonEnabled(false);
}


void PvpFightScene::onAttackPlayEffect(Character * attacker, Character * hurter, CharacterDirectionType forward, CharacterDirectionType stand)
{
	if (isClose)	return;

	Vector<FiniteTimeAction *> array;
	array.pushBack(CCCallFunc::create([attacker,forward, this](){
		attacker->setDirectionType(forward);
		attacker->setIState(CharacterStateType::FStateRun);
	}));

	//走到hurter旁边
	int xDistance = 0;
	Point destiny;
	if (forward == CharacterDirectionType::FDirLeft)
	{
		destiny = Fighter_A_Hurt;
		xDistance = (Fighter_B - Fighter_A_Hurt).x;
	}
		
	else
	{
		destiny = Fighter_B_Hurt;
		xDistance = (Fighter_B_Hurt - Fighter_A).x;
	}
		
	CCMoveTo * moveToEnermyr = CCMoveTo::create(xDistance / 30 * 0.3f, destiny);
	array.pushBack(moveToEnermyr);

	//砍一刀
	array.pushBack(CCCallFunc::create([attacker,this](){
		attacker->setIState(CharacterStateType::FStateAttack);
		SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::ATTACK);

		if (attacker == player)
		{
			CFight cfight;
			cfight.set_fighthtype(2);
			cfight.set_skilltype(0);
			cfight.set_fighthid(-1);

			MyProtoSocket::send(1008, cfight.SerializeAsString());
		}
		
	}));

	//受伤和还原
	array.pushBack(CCCallFunc::create([hurter](){

		//0.6秒后怪物受伤状态
		hurter->runAction(Sequence::create(DelayTime::create(0.6f), CallFunc::create([hurter](){
			hurter->setIState(CharacterStateType::FStateHurt);
		}), NULL));
		hurter->runAction(Sequence::create(DelayTime::create(1.2f), CallFunc::create([hurter](){
			hurter->setIState(CharacterStateType::FStateStand);
		}), NULL));

	}));

	array.pushBack(DelayTime::create(1.6f));

	//返回
	array.pushBack(CCCallFunc::create([attacker, forward](){
		attacker->setDirectionType(CharacterDirectionType(8 - forward));
		attacker->setIState(CharacterStateType::FStateRun);
	}));

	//走回原处
	int xDistance2 = 0;
	Point destiny2;
	if (forward == CharacterDirectionType::FDirLeft)
	{
		destiny2 = Fighter_B;
		xDistance2 = (Fighter_B - Fighter_A_Hurt).x;
	}

	else
	{
		destiny2 = Fighter_A;
		xDistance2 = (Fighter_B_Hurt - Fighter_A).x;
	}
	CCMoveTo * moveToSource = CCMoveTo::create(xDistance2 / 30 * 0.3f, destiny2);
	array.pushBack(moveToSource);

	//站立
	array.pushBack(CCCallFunc::create([attacker,stand](){
		attacker->setDirectionType(stand);
		attacker->setIState(CharacterStateType::FStateStand);
	}));

	array.pushBack(DelayTime::create(1.f));
	array.pushBack(CCCallFunc::create([attacker,this](){
		if (attacker == player && enermyBlood > 0)
		{
			this->toastShow(Common::FontToUTF8("敌方攻击状态"));
		}
		else if (playerBlood > 0)
		{
			this->setButtonEnabled(true);
			this->toastShow(Common::FontToUTF8("轮到你了，干掉他！"));
		}
	}));

	ActionInterval *  actions = Sequence::create(array);
	attacker->runAction(actions);
}

void PvpFightScene::onSkill1(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	if (skillNum < 2)	{
		toastShow(Common::FontToUTF8("技能点不足!"));
		return;
	}
	player->setIState(CharacterStateType::FStateCaster);
	this->playSkill(ResourceProvider::Skill::Skill_1, enermy);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_1);
	this->setButtonEnabled(false);

}
void PvpFightScene::onSkill2(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	if (skillNum < 5)	{
		toastShow(Common::FontToUTF8("技能点不足!"));
		return;
	}
	player->setIState(CharacterStateType::FStateCaster);
	this->playSkill(ResourceProvider::Skill::Skill_2, enermy);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_2);
	this->setButtonEnabled(false);
}
void PvpFightScene::onSkill3(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	if (skillNum < 7)	{
		toastShow(Common::FontToUTF8("技能点不足!"));
		return;
	}
	player->setIState(CharacterStateType::FStateCaster);
	this->playSkill(ResourceProvider::Skill::Skill_3, enermy);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_3);
	this->setButtonEnabled(false);

}
void PvpFightScene::onSkill4(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	if (skillNum < 10)	{
		toastShow(Common::FontToUTF8("技能点不足!"));
		return;
	}
	player->setIState(CharacterStateType::FStateCaster);
	this->playSkill(ResourceProvider::Skill::Skill_4,enermy);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::SKILL_4);
	this->setButtonEnabled(false);
}
void PvpFightScene::onInstanceClose(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	Director::getInstance()->replaceScene(Common::scene(GameScene::create()));

	//发送销毁副本信息
	MyProtoSocket::send(1029, CDestroyRoom().SerializeAsString());
}
void PvpFightScene::setButtonEnabled(bool isEnabled)
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

void PvpFightScene::playSkill(ResourceProvider::Skill::Number skillNumber , Character * character)
{
	//再播放效果
	Vector<FiniteTimeAction *> array;
	array.pushBack(Common::createActionsFromCache(ResourceProvider::Skill::PATH(skillNumber), 0));

	//受伤
	array.pushBack(CCCallFunc::create([this,character, skillNumber](){
		character->setIState(CharacterStateType::FStateHurt);

		if (character == this->enermy)
		{
			CFight cfight;
			cfight.set_fighthtype(2);
			cfight.set_skilltype(skillNumber);
			cfight.set_fighthid(-1);

			MyProtoSocket::send(1008, cfight.SerializeAsString());
		}
		
	}));

	//恢复站立
	array.pushBack(DelayTime::create(0.6f));
	array.pushBack(CCCallFunc::create([character,this](){
		character->setIState(CharacterStateType::FStateStand);

		if (character == enermy && enermyBlood > 0)
		{
			this->toastShow(Common::FontToUTF8("敌方攻击状态"));
		}
		else if (playerBlood > 0)
		{
			this->setButtonEnabled(true);
			this->toastShow(Common::FontToUTF8("轮到你了，干掉他！"));
		}
	}));

	ActionInterval *  actions = Sequence::create(array);
	if (character == enermy)
		skillShow_A->runAction(actions);
	else
		skillShow_B->runAction(actions);
}


void PvpFightScene::updateEnermyAttack(int skillType)
{
	if (skillType != 0)
	{
		enermy->setIState(CharacterStateType::FStateCaster);
		this->setButtonEnabled(true);
		this->playSkill(ResourceProvider::Skill::Number(skillType), player);
	}
	else
	{
		this->onAttackPlayEffect(enermy, player, CharacterDirectionType::FDirRight, CharacterDirectionType::FDirRightAndDown);
	}
}