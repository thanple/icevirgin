#include "GameScene.h"
#include "util\MyProtoSocket.h"
#include "protocol\CRequestUserInfo.pb.h"
#include "protocol\CRequestTaskStatus.pb.h"

static GameScene * _instce = NULL;
GameScene * GameScene::getInstance()
{
	return _instce;
}
GameScene::GameScene() :gameUI(NULL), bgMap(NULL), player(NULL)
{
	userBean.set_id(-1);
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

	//���ص�ͼ
	bgMap = SceneMap::create(1);
	bgMap->setDelegate(this);
	this->addChild(bgMap);

	//���player���Ǽӵ�map�ĺ��ӽڵ�ɣ����������ʡ��
	//this->addChild(player);
	player = Player::sharePlayer();
	player->setPosition(bgMap->getPlayerBornPoint().getCCPointValue());
	player->setTag(MAP_INCLUDE_USER);
	bgMap->getMap()->addChild(player);	//����һ��Ҫ��addChild������ᱻcocos2d�������ջ��ƻ���

	//����NPC
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
		bgMap->getMap()->addChild(pNpc);	//�ӵ���ͼ���棬������һ��
	}


	//�������������
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


	//����GameInfoUI
	gameUI = GameInfoUI::create();
	this->addChild(gameUI);


	//��ʱ����
	this->schedule(schedule_selector(GameScene::updateScene, 1.6f));


	//���ر�������
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(ResourceProvider::MUSIC::GAME_SCENE_MUSIC);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(ResourceProvider::MUSIC::GAME_SCENE_MUSIC, true);


	_instce = this;
	return true;
}

void GameScene::updateScene(float dt)
{

	//player����player->getRoleId() < 0 &&
	//player = Player::sharePlayer();// && bgMap->getMap()->getChildByTag(MAP_INCLUDE_USER) == NULL
	if (player->getRoleId() < 0 && userBean.id() > 0) {

		SRequestUserInfo info = userBean;

		player->setRoleId(info.id());
		player->pBody->setFigureId(info.body());
		player->pHair->setFigureId(info.hair());
		player->pWeapon->setFigureId(info.weapon());
		player->setIState(CharacterStateType::FStateStand);
		this->updatePlayerCenter();


		auto node = gameUI->getRootNode();
		Text * Name = dynamic_cast<Text*>(node->getChildByName("Name"));
		Name->setString(userBean.name());
	}

	//û�õ�����֮ǰ��������
	if (player->getRoleId() < 0)
	{
		//����user����
		MyProtoSocket::send(1012, CRequestUserInfo().SerializeAsString());
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

	//����UI
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