#pragma once
#include "Player.h"
#include "Board.h"
class Game
{
private:
	Board board;
public:
	Game(Player p1, Player p2);
	void start();
	void setBoard(Board b);
	Board getBoard();
};

