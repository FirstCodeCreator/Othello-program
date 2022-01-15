#include "Player.h"

Player::Player()
{
	name = "NO_NAME";
}

Player::Player(string name)
{
	this->name = name;
}

void Player::setName(string nameValue)
{
	name = nameValue;
}

string Player::getName()
{
	return name;
}
