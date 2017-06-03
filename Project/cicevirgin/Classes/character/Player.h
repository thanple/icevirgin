
#pragma once
#include "Common.h"
#include "Character.h"

class Player : public Character
{

public:
	Player();
	~Player();
	bool init();

	static Player * sharePlayer();
	CREATE_FUNC(Player);

	
};