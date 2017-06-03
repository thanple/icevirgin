#pragma once
#include "Common.h"
#include "MiniMap.h"
#include "MapPoint.h"
#include "character\CharacterNpc.h"

class SceneMapDelegate
{
public:
	virtual void runMoveActions(std::deque<MapPoint> mapPointsDeque) = 0;
	virtual Point getPlayerPosition() = 0;
	virtual bool isModal() = 0;
};

class SceneMap : public Node, public MiniMapDelegate
{
private :
	int mapId;	//地图的id
	Point position;	//在场景中的位置
	unsigned char ** map;	//地图二维数组

	SceneMap(int mapId);
	~SceneMap();

public:
	MapPoint getMapPointFromCusor(int x, int y);	//将鼠标坐标转换成MapPoint
	Point getScenePointFromMapPoint(MapPoint mp);	//将MapPoint转换成场景坐标

public:
	static SceneMap * create(int mapId);
	bool init();
	void updateMapPosition(Point p);	//更新地图位置
	void updateFromMini(Point p, Point scale);	//来自mini地图的更新

public:
	CC_SYNTHESIZE(MapPoint, m_playerBornPoint, PlayerBornPoint); //角色出生所在坐标
	CC_SYNTHESIZE(list<NpcMapNode>, m_npcList, NpcList); //npc坐标

	CC_SYNTHESIZE(SceneMapDelegate *, m_delegate, Delegate); 
	CC_SYNTHESIZE(TMXTiledMap *, _tileMap, Map);		//加载的地图
	CC_SYNTHESIZE(MiniMap *, _miniMap, MiniMap);		//Mini地图
};