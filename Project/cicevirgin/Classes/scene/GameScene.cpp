#include "GameScene.h"
#include "util\MyProtoSocket.h"
#include "protocol\CRequestUserInfo.pb.h"
#include "protocol\CRequestTaskStatus.pb.h"
#include "protocol\CRequestAddCharacter.pb.h"
#include "protocol\CCharacterPos.pb.h"

static GameScene * _instce = NULL;
GameScene * GameScene::getInstance()
{
	return _instce;
}
GameScene::GameScene() :gameUI(NULL), bgMap(NULL), player(NULL)
{
	userBean.set_id(-1);
	removeCharacter.set_id(-1);
}
GameScene::~GameScene()
{
	_instce = NULL;
}
bool GameScene::init()
{
	
	if (!CCLayer::init())
	{
		return false;
	}

	//加载地图
	bgMap = SceneMap::create(1);
	bgMap->setDelegate(this);
	this->addChild(bgMap);

	//这个player还是加到map的孩子节点吧，算相对坐标省事
	//this->addChild(player);
	player = Player::sharePlayer();
	//player->setPosition(bgMap->getPlayerBornPoint().getCCPointValue());
	player->setPosition(3000,1800);
	player->setTag(MAP_INCLUDE_USER);
	bgMap->getMap()->addChild(player);	//这里一点要先addChild，否则会被cocos2d垃圾回收机制回收

	//加载NPC
	list<NpcMapNode> & npcList = bgMap->getNpcList();
	for (list<NpcMapNode>::iterator iter = npcList.begin(); iter != npcList.end(); iter++)
	{
		NpcMapNode node = * iter;
		CharacterNpc * pNpc = CharacterNpc::create();
		pNpc->setNpcId(node.npdId);
		pNpc->setPosition(node.p);
		pNpc->setNpcPath(node.path);
		pNpc->runAction();

		npcs.push_back(pNpc);
		bgMap->getMap()->addChild(pNpc);	//加到地图里面，和主角一样
	}


	//加载鼠标点击动画
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(ResourceProvider::MouseAction::PLIST_PATH);
	Sprite * _mouseAt = Sprite::create();
	this->addChild(_mouseAt);
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = [this, _mouseAt](EventMouse * event){
		do
		{
			float x = event->getCursorX(), y = event->getCursorY();
			CC_BREAK_IF(this->bgMap->getMiniMap()->isContainPoint(x, y));
			CC_BREAK_IF(y < 100 || x>750);
			CC_BREAK_IF(this->isModal());

			_mouseAt->stopActionByTag(TAG_MOUSE_ACTION);
			Action * pAction = Common::createActionsFromCache(ResourceProvider::MouseAction::PATH);
			pAction->setTag(TAG_MOUSE_ACTION);
			_mouseAt->runAction(pAction);
			_mouseAt->setPosition(x, y);
		} while (0);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);


	//加入GameInfoUI
	gameUI = GameInfoUI::create();
	this->addChild(gameUI);


	//定时更新
	this->schedule(schedule_selector(GameScene::updateScene, 1.6f));

	//更新其他玩家的数据同步
	this->schedule(schedule_selector(GameScene::updateOtherCharacters, 1.8f));


	//加载背景音乐
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::GAME_SCENE_MUSIC);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::GAME_SCENE_MUSIC, true);


	_instce = this;
	return true;
}

void GameScene::updateOtherCharacters(float dt)
{
	
	//在场景中增加角色
	int count = 0;
	for (::google::protobuf::RepeatedPtrField<::SAddCharacter_CharacterItem>::const_iterator & it
		 = addCharacter.characters().begin(); it != addCharacter.characters().end(); it++)
	{
		::SAddCharacter_CharacterItem item = * it;
		if (item.id() > 0 && item.id() != userBean.id() && !charactersMap[item.id()])
		{
			Character * pCharacter = Character::create();
			pCharacter->pBody->setFigureId(item.body());
			pCharacter->pHair->setFigureId(item.hair());
			pCharacter->pWeapon->setFigureId(item.weapon());
			pCharacter->setIState(CharacterStateType::FStateStand);
			pCharacter->setPosition(3000, 1800);

			bgMap->getMap()->addChild(pCharacter);
			charactersMap[item.id()] = pCharacter;
		}
		count++;
	}
	if (count > 0)
	{
		addCharacter = SAddCharacter();
	}

	//更新角色坐标
	if (characterPos.id() > 0)
	{
		Character * pCharacter = charactersMap[characterPos.id()];
		if (pCharacter)
		{
			pCharacter->setPosition(characterPos.x(), characterPos.y());
			if (pCharacter->getIState()->getStateType() != characterPos.status())
			{
				pCharacter->setIState(CharacterStateType(characterPos.status()) );
			}
			pCharacter->setDirectionType(CharacterDirectionType(characterPos.direction() ));

			characterPos.set_id(-1);
		}

	}


	//删除场景中的角色
	if (removeCharacter.id() > 0)
	{
		Character * pCharacter = charactersMap[removeCharacter.id()];
		if (pCharacter)
		{
			pCharacter->removeFromParentAndCleanup(true);
			//charactersMap[removeCharacter.id()] = NULL;
			map<int, Character *>::iterator pos = charactersMap.find(removeCharacter.id());
			if (pos != charactersMap.end())
			{
				charactersMap.erase(pos);
			}
			removeCharacter.set_id(-1);
		}
	}
}

void GameScene::updateScene(float dt)
{

	//player创建player->getRoleId() < 0 &&
	//player = Player::sharePlayer();// && bgMap->getMap()->getChildByTag(MAP_INCLUDE_USER) == NULL
	if (player->getRoleId() < 0 && userBean.id() > 0) {

		SRequestUserInfo info = userBean;

		player->setRoleId(info.id());
		player->pBody->setFigureId(info.body());
		player->pHair->setFigureId(info.hair());
		player->pWeapon->setFigureId(info.weapon());
		player->setIState(CharacterStateType::FStateStand);
		this->updatePlayerCenter();

		//自己角色好了再请求其他玩家的数据
		CRequestAddCharacter addCharacterRequest;
		MyProtoSocket::send(1024, addCharacterRequest.SerializeAsString());


		auto node = gameUI->getRootNode();
		Text * Name = dynamic_cast<Text*>(node->getChildByName("Name"));
		Name->setString(userBean.name());
	}

	//没拿到数据之前不断请求
	if (player->getRoleId() < 0)
	{
		//请求user数据
		MyProtoSocket::send(1012, CRequestUserInfo().SerializeAsString());
	}
	else
	{
		CCharacterPos characterPos;
		characterPos.set_direction(player->getDirectionType());
		Point p = player->getPosition();
		characterPos.set_x(p.x);
		characterPos.set_y(p.y);
		characterPos.set_status(player->getIState()->getStateType());

		MyProtoSocket::send(1026, characterPos.SerializeAsString());
	}

	if (bgMap->getMap()->getChildByTag(MAP_INCLUDE_USER) == NULL)
		return;

	if (gameUI && gameUI->getShowCenter())
	{
		this->updatePlayerCenter();
	}

	if (!gameUI->isModal() && player && player->getIState() == CharacterState::CharacterStateProvider::getInstance()->getStateFromType(CharacterStateType::FStateStand))
	{
		for (list<CharacterNpc *>::iterator iter = npcs.begin(); iter != npcs.end(); iter++)
		{
			CharacterNpc * node = * iter;
			MapPoint npcMapPoint = MapPoint(node->getPosition());
			MapPoint playerMapPoint = MapPoint(player->getPosition());

			if (npcMapPoint.x >= playerMapPoint.x - 1 && npcMapPoint.x <= playerMapPoint.x + 1
				&& npcMapPoint.z >= playerMapPoint.z && npcMapPoint.z <= playerMapPoint.z + 2)
			{
				CRequestTaskStatus request;
				request.set_type(node->getNpcId());
				MyProtoSocket::send(1014, request.SerializeAsString());
				//gameUI->getNpcUI()->displayModal(node->getNpcId());
			}
		}
		
	}

	//更新UI
	if (userBean.id() > 0)
	{
		auto node = gameUI->getOperationUI()->getRootNode();
		TextBMFont * skillNum = dynamic_cast<TextBMFont*>(node->getChildByName("skill_num"));
		skillNum->setString(to_string(userBean.nskill()));
		
		TextBMFont * money = dynamic_cast<TextBMFont*>(node->getChildByName("money"));
		money->setString(to_string(userBean.money()));

		TextBMFont * exp = dynamic_cast<TextBMFont*>(gameUI->getRootNode()->getChildByName("Exp"));
		exp->setString(to_string(userBean.exp()));
	}

	//CCLOG("player point{%f,%f}", player->getPosition().x, player->getPosition().y);
}

void GameScene::updatePlayerCenter()
{
	Point playerInScene = player->getPosition() + bgMap->getPosition();
	Point center = winSize / 2;

	Point delta = playerInScene - center;

	bgMap->updateMapPosition(bgMap->getPosition() + delta);

}

void GameScene::runMoveActions(std::deque<MapPoint> mapPointsDeque)
{
	player->stopActionByTag(TAG_MOVET);
	player->setIState(CharacterStateType::FStateRun);

	Vector<FiniteTimeAction*> & arrays = player->actionsWithMoveTo(mapPointsDeque);
	ActionInterval *  actions = Sequence::create(arrays);

	actions->setTag(TAG_MOVET);
	player->runAction(actions);
}

Point GameScene::getPlayerPosition()
{
	return player->getPosition();
}

bool GameScene::isModal()
{
	return this->gameUI->isModal();
}