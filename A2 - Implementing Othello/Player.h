#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string name;
public:
	Player();
	Player(string name);
	void setName(string nameValue);
	string getName();
};

