
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
	int mapId;	//��ͼ��id
	TMXTiledMap * _miniMap; //Mini��ͼ
	float miniMapWith;
	float miniMapHeight;

	Sprite * sceneWatcher;	//������ͼ�۲��
	
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