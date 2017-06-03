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
	int mapId;	//��ͼ��id
	Point position;	//�ڳ����е�λ��
	unsigned char ** map;	//��ͼ��ά����

	SceneMap(int mapId);
	~SceneMap();

public:
	MapPoint getMapPointFromCusor(int x, int y);	//���������ת����MapPoint
	Point getScenePointFromMapPoint(MapPoint mp);	//��MapPointת���ɳ�������

public:
	static SceneMap * create(int mapId);
	bool init();
	void updateMapPosition(Point p);	//���µ�ͼλ��
	void updateFromMini(Point p, Point scale);	//����mini��ͼ�ĸ���

public:
	CC_SYNTHESIZE(MapPoint, m_playerBornPoint, PlayerBornPoint); //��ɫ������������
	CC_SYNTHESIZE(list<NpcMapNode>, m_npcList, NpcList); //npc����

	CC_SYNTHESIZE(SceneMapDelegate *, m_delegate, Delegate); 
	CC_SYNTHESIZE(TMXTiledMap *, _tileMap, Map);		//���صĵ�ͼ
	CC_SYNTHESIZE(MiniMap *, _miniMap, MiniMap);		//Mini��ͼ
};