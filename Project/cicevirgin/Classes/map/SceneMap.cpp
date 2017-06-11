
#include "SceneMap.h"
#include "PathAStar.h"

SceneMap::SceneMap(int mapId) :mapId(mapId), _tileMap(NULL), _miniMap(NULL), m_delegate(NULL),
map(NULL)
{

}

SceneMap::~SceneMap()
{
	if (NULL != _tileMap)
	{
		CC_SAFE_DELETE(_tileMap);
	}
	if (NULL != map)
	{
		delete[] map;
		map = NULL;
	}
}

bool SceneMap::init()
{
	//���ص�ͼ
	CCString mapStr;
	mapStr.appendWithFormat("map/%d.tmx", this->mapId);
	_tileMap = TMXTiledMap::create(mapStr.getCString());
	this->addChild(_tileMap);
	this->updateMapPosition( Point(0,0) );

	//���ص�ͼ����
	CCTMXLayer * tmxLayer = _tileMap->layerNamed("barrier");
	tmxLayer->setVisible(false);
	Size mapSize = this->_tileMap->getMapSize();	//���ٿ�
	Size tileSize = this->_tileMap->getTileSize();	//ÿ�������
	map = new unsigned char*[(int)mapSize.height];
	for (unsigned int i = 0; i<(int)mapSize.height; i++)
	{
		map[i] = new unsigned char[(int)mapSize.width];
		for (unsigned int j = 0; j < (int)mapSize.width; j++)
		{
			Sprite * grid = tmxLayer->tileAt(ccp(j, mapSize.height-1-i));
			if (NULL != grid)
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}

		}
	}
	
	CCLOG("[tiledMap load grid] :\n");
	for (unsigned int i = 0; i < (int)mapSize.height; i++)
	{
		string buff;
		for (unsigned int j = 0; j < (int)mapSize.width; j++)
		{
			buff += to_string(map[i][j]);
			buff += " ";
		}
		CCLOG("%s", buff.c_str());
	}

	//����npc
	CCTMXObjectGroup * npc = _tileMap->objectGroupNamed("npc");
	ValueVector values = npc->getObjects();
	for (ValueVector::iterator iter = values.begin(); iter != values.end(); iter++)
	{
		ValueMap valueMap = iter->asValueMap();
		float x = valueMap["x"].asFloat();
		float y = valueMap["y"].asFloat();
		int npcId = valueMap["npcid"].asInt();
		int path = valueMap["path"].asInt();

		NpcMapNode node;
		node.p = Point(x, y);
		node.npdId = npcId;
		node.path = path;

		this->m_npcList.push_back(node);
	}


	//����mini��ͼ
	_miniMap = MiniMap::create(this->mapId);
	_miniMap->setDelegate(this);	//����mini��ͼ�����¼�֪ͨ��
	this->addChild(_miniMap);


	//����player
	m_playerBornPoint.x = 100;
	m_playerBornPoint.z = 60;

	//��ͼ�����Ӧ
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = [this](EventMouse * event){
		
		do
		{
			float x = event->getCursorX(), y = event->getCursorY();
			CC_BREAK_IF(this->_miniMap->isContainPoint(x, y));
			CC_BREAK_IF(y < 100 || x>750);
			CC_BREAK_IF(this->m_delegate->isModal());
			
			MapPoint mp = this->getMapPointFromCusor( x, y);

			//�Զ�Ѱ·
			Size mapSize = this->_tileMap->getMapSize();	//���ٿ�
			Size tileSize = this->_tileMap->getTileSize();	//ÿ�������
			/*unsigned char ** map = new unsigned char*[(int)mapSize.height];
			for (unsigned int i = 0; i<(int)mapSize.height; i++)
			{
				map[i] = new unsigned char[(int)mapSize.width];
				for (unsigned int j = 0; j < (int)mapSize.width; j++)
				{
					map[i][j] = 0;
				}
			}*/

			MapPoint currentPoint(m_delegate->getPlayerPosition());

			CC_BREAK_IF(currentPoint == mp);

			std::deque<MapPoint> array = PathAStar::findPathByAStar(this->map,
				
				mapSize.width,
				mapSize.height,

				4096, currentPoint, mp);

			if (array.size() <= 0)	return;
			CCLOG("find");
			m_delegate->runMoveActions(array);

		} while (0);
		
	};
	mouseListener->onMouseUp = [this](EventMouse * event){};
	mouseListener->onMouseMove = [this](EventMouse * event){};
	mouseListener->onMouseScroll = [this](EventMouse * event){};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	return true;
}

MapPoint SceneMap::getMapPointFromCusor(int cursorX, int cursorY)
{
	Point cusorPoint(cursorX, cursorY);
	Point mapPositon = this->_tileMap->getPosition();
	MapPoint mp(cusorPoint - mapPositon);
	return mp;
}

Point SceneMap::getScenePointFromMapPoint(MapPoint mp)
{
	Point p = mp.getCCPointValue();
	Point position = _tileMap->getPosition();
	return p + position;
}

SceneMap * SceneMap::create(int mapId)
{
	SceneMap* map = new SceneMap(mapId);
	if (map && map->init())
	{
		map->autorelease();
		return map;
	}
	CC_SAFE_DELETE(map);
	return NULL;
}

void SceneMap::updateFromMini(Point p, Point scale)	//��������p�������ͼ�е�����,scaleΪx,y������
{
	float sceneX = p.x / scale.x - winSize.width / 2;
	float sceneY = p.y / scale.y - winSize.height / 2;
	this->updateMapPosition(Point(sceneX, sceneY));
}

void SceneMap::updateMapPosition(Point p)	//�����ǵ�ͼ�����꣬�����ǵ�ͼ�ڳ���������
{
	Size mapSize = _tileMap->getMapSize();	//���ٿ�
	Size tileSize = _tileMap->getTileSize();	//ÿ�������
	int tileMapWidth = mapSize.width * tileSize.width;
	int tileMapHeight = mapSize.height * tileSize.width;

	p.x = MAX(0, p.x);
	p.x = MIN(tileMapWidth - winSize.width, p.x);

	p.y = MAX(0, p.y);
	p.y = MIN(tileMapHeight - winSize.height, p.y);

	position.x = p.x;
	position.y = p.y;

	//����ƫ��
	_tileMap->setPosition(Point(-p.x, -p.y));
	
}

