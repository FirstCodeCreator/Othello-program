#pragma once

#include <string>
#include "Player.h"
#include "Position.h"
using namespace std;

class Board
{
private:
	char board[8][8] = {};
	Player first;
	Player second;
	Player current;
	void save();
	void takeTurn();
	string fileName;
public:
	Board();
	Board(Player p1, Player p2, int start);
	Board(string save_file);
	void drawBoard();
	Board load();
	void play();
	void setBoard(char boardValue[8][8]);
	char* getBoard();

	bool canPlay(Player p);
	void flip(int row,int col);
	void showPoints();
};

