
#pragma once 
#include "Common.h"

class MiniMapDelegate
{
public:
	virtual void updateFromMini(Point p , Point scale) = 0;
};

class MiniMap : public Node
{
private:
	int mapId;	//地图的id
	TMXTiledMap * _miniMap; //Mini地图
	float miniMapWith;
	float miniMapHeight;

	Sprite * sceneWatcher;	//场景地图观察框
	
	MiniMap(int mapId);
	~MiniMap();

	Point getMapScale();


public:
	
	bool init();
	static MiniMap * create(int mapId);
	CC_SYNTHESIZE(MiniMapDelegate *, m_delegate, Delegate);

	void onMousePoint(float mouseX, float mouseY);

	bool isContainPoint(float x, float y);

private :
	bool m_bMouseDown;
};