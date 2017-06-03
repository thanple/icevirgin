#include "MiniMap.h"

MiniMap::MiniMap(int mapId) : mapId(mapId)
{
	miniMapWith = 3600 * 0.07f;
	miniMapHeight = 2400 * 0.07f;
	m_bMouseDown = false;
}

MiniMap::~MiniMap()
{
	if (NULL != _miniMap)
	{
		CC_SAFE_DELETE(_miniMap);
	}
}

bool MiniMap::init()
{
	//加载mini地图
	CCString mapStr;
	mapStr.appendWithFormat("map/%d.tmx", this->mapId);
	_miniMap = TMXTiledMap::create(mapStr.getCString());
	
	Point scale = this->getMapScale();
	_miniMap->setScale(scale.x, scale.y);
	_miniMap->setPosition(winSize.width - miniMapWith,
		winSize.height - miniMapHeight);
	this->addChild(_miniMap);

	//加载观察框
	sceneWatcher = Sprite::create("map/tray_self.png");
	Size mapSize = _miniMap->getMapSize();	//多少块
	Size tileSize = _miniMap->getTileSize();	//每块的像素
	float winSizeScaleX = winSize.width / (mapSize.width * tileSize.width);
	float winSizeScaleY = winSize.height / (mapSize.height * tileSize.height);
	sceneWatcher->setScale(winSizeScaleX * miniMapWith / 180,
		winSizeScaleY * miniMapHeight / 90);
	this->setPosition(0, 0);
	this->addChild(sceneWatcher);

	//增加鼠标响应(这里貌似只能用Lambda表达式，不能用重写虚函数的方法)
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = [this](EventMouse * event){
		m_bMouseDown = true;
		this->onMousePoint(event->getCursorX(), event->getCursorY());
	};
	mouseListener->onMouseUp = [this](EventMouse * event){
		m_bMouseDown = false;
	};
	mouseListener->onMouseMove = [this](EventMouse * event){
		if (this->m_bMouseDown)
		{
			this->onMousePoint(event->getCursorX(), event->getCursorY());
		}	
	};
	mouseListener->onMouseScroll = [this](EventMouse * event){};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	return true;
}

//Mini地图占图片的比例
Point MiniMap::getMapScale()
{
	Size mapSize = _miniMap->getMapSize();	//多少块
	Size tileSize = _miniMap->getTileSize();	//每块的像素

	return Point(miniMapWith / (mapSize.width * tileSize.width),
		miniMapHeight / (mapSize.height * tileSize.height));
}

MiniMap * MiniMap::create(int mapId)
{
	MiniMap* map = new MiniMap(mapId);
	if (map && map->init())
	{
		map->autorelease();
		return map;
	}
	CC_SAFE_DELETE(map);
	return NULL;
}

void MiniMap::onMousePoint(float cursorX, float cursorY)
{
	if (cursorX < (winSize.width - this->miniMapWith) || cursorY < (winSize.height - this->miniMapHeight))
		return;

	//更新观察框
	Size mapSize = _miniMap->getMapSize();	//多少块
	Size tileSize = _miniMap->getTileSize();	//每块的像素
	float winSizeScaleX = winSize.width / (mapSize.width * tileSize.width);
	float winSizeScaleY = winSize.height / (mapSize.height * tileSize.height);
	

	float sceneWatcherX = cursorX;
	float sceneWatcherY = cursorY;
	if( (cursorX - winSizeScaleX * miniMapWith / 2) < (winSize.width - this->miniMapWith) )
	{
		sceneWatcherX = (winSize.width - this->miniMapWith) + winSizeScaleX * miniMapWith / 2;
	}
	if ((cursorX + winSizeScaleX * miniMapWith / 2) > winSize.width)
	{
		sceneWatcherX = winSize.width  - winSizeScaleX * miniMapWith / 2;
	}

	if ((cursorY - winSizeScaleY * miniMapHeight / 2) < (winSize.height - this->miniMapHeight))
	{
		sceneWatcherY = (winSize.height - this->miniMapHeight) + winSizeScaleY * miniMapHeight / 2;
	}
	if (cursorY + winSizeScaleY * miniMapHeight / 2 > winSize.height)
	{
		sceneWatcherY = winSize.height - winSizeScaleY * miniMapHeight / 2;
	}

	this->sceneWatcher->setPosition(Point(sceneWatcherX, sceneWatcherY));
	

	//得到在迷你地图中的相对坐标
	float x = cursorX - (winSize.width - this->miniMapWith);
	float y = cursorY - (winSize.height - this->miniMapHeight);

	//通知delegate处理事件
	this->m_delegate->updateFromMini(Point(x, y), this->getMapScale());
}

bool MiniMap::isContainPoint(float cursorX, float cursorY)
{
	Rect rect(winSize.width - this->miniMapWith, winSize.height - this->miniMapHeight,
		this->miniMapWith, this->miniMapHeight
		);

	return rect.containsPoint(Point(cursorX, cursorY));
}