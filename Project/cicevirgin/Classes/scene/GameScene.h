
#ifndef  _GameScene_H_
#define  _GameScene_H_
#include "Common.h"
#include "map\SceneMap.h"
#include "character\Player.h"
#include "character\CharacterNpc.h"
#include "ui\GameInfoUI.h"


#define MAP_INCLUDE_USER 0x00001100

class GameScene : public CCLayer , SceneMapDelegate
{

private:
	SceneMap * bgMap;	//地图
	Player * player;	//主角
	//实体数据
	CC_SYNTHESIZE(SRequestUserInfo, userBean, SRequestUserInfo);
	list<CharacterNpc *> npcs;	//npc
	CC_SYNTHESIZE_READONLY(GameInfoUI *, gameUI, GameInfoUI); //UI Layer层
	
public:
	GameScene();
	~GameScene();
	CREATE_FUNC(GameScene);
	bool init();
	void updateScene(float dt);

	//SceneMapDelegate的实现
	virtual void runMoveActions(std::deque<MapPoint> mapPointsDeque);
	virtual Point getPlayerPosition();
	virtual bool isModal();

private:
	void updatePlayerCenter();


public:
	static GameScene * getInstance();
};

#endif