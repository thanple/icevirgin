
#pragma once
#include "Common.h"

typedef struct
{
	Point p;
	int npdId;
	int path;
} NpcMapNode;

class CharacterNpc : public Sprite
{
private:
	CC_SYNTHESIZE(int, m_cid, NpcId); //id
	CC_SYNTHESIZE(int, m_path, NpcPath); //path

	
public:
	CREATE_FUNC(CharacterNpc);
	bool init();
	CharacterNpc();
	~CharacterNpc();

	void runAction();
};