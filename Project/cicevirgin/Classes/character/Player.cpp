
#include "Player.h"

static Player * _player = NULL;
Player* Player::sharePlayer()
{
	if (_player == NULL)
	{
		_player = create();
	}
	return _player;
}


Player::Player(): Character()
{

}
Player::~Player()
{
	_player = NULL;
}
bool Player::init()
{
	if (!Character::init())
		return false;
	return true;
}