
#ifndef  _GameScene_H_
#define  _GameScene_H_
#include "Common.h"
#include "map\SceneMap.h"
#include "character\Player.h"
#include "character\CharacterNpc.h"
#include "ui\GameInfoUI.h"
#include "protocol\SAddCharacter.pb.h"
#include "protocol\SRemoveCharacter.pb.h"
#include "protocol\SCharacterPos.pb.h"


#define MAP_INCLUDE_USER 0x00001100

class GameScene : public CCLayer , SceneMapDelegate
{

private:
	SceneMap * bgMap;	//��ͼ
	Player * player;	//����
	//ʵ������
	CC_SYNTHESIZE(SRequestUserInfo, userBean, SRequestUserInfo);
	list<CharacterNpc *> npcs;	//npc
	CC_SYNTHESIZE_READONLY(GameInfoUI *, gameUI, GameInfoUI); //UI Layer��



	//���ߵ��������
	CC_SYNTHESIZE(SAddCharacter, addCharacter, AddCharacter);
	CC_SYNTHESIZE(SRemoveCharacter, removeCharacter, RemoveCharacter);
	map<int, Character *> charactersMap;	//key=roleid
	CC_SYNTHESIZE(SCharacterPos, characterPos, CharacterPos);
	
public:
	GameScene();
	~GameScene();
	CREATE_FUNC(GameScene);
	bool init();
	void updateScene(float dt);
	void updateOtherCharacters(float dt);	//����ͬ��

	//SceneMapDelegate��ʵ��
	virtual void runMoveActions(std::deque<MapPoint> mapPointsDeque);
	virtual Point getPlayerPosition();
	virtual bool isModal();

private:
	void updatePlayerCenter();


public:
	static GameScene * getInstance();
};

#endif