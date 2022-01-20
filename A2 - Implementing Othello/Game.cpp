#include <iostream>
#include "Game.h"
#include "UnplayablePosition.h"



Game::Game(Player p1, Player p2)
{
	board = Board(p1,p2,1);
}

void Game::start()
{
	int position;
	cout << "What standard position do you want?" << endl;
	cout << "1.Standard position \n2.Offset Position\n";
	cin >> position;
	if (position==1)
	{
		char arr[8][8] ={	{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::WHITE,Position::BLACK,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::BLACK,Position::WHITE,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE}};
		board.setBoard(arr);
	}
	else if (position == 2) {
		cout << "Which offset value do you want?"<<endl;
		cout << "1.Standard position \n2.Offset Position" << endl;

		char arr1[8][8] = { {UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::WHITE,Position::BLACK,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::BLACK,Position::WHITE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE} };
		board.setBoard(arr1);
		board.drawBoard();
		cout << "\n";

		char arr2[8][8] = { {UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::WHITE,Position::BLACK,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::BLACK,Position::WHITE,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE} };
		board.setBoard(arr2);
		board.drawBoard();
		cout << "\n";

		char arr3[8][8] = { {UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::WHITE,Position::BLACK,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::BLACK,Position::WHITE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE} };
		board.setBoard(arr3);
		board.drawBoard();
		cout << "\n";

		/*char arr4[8][8] = {{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::WHITE,Position::BLACK,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::BLACK,Position::WHITE,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE} };*/
		
		// used to test the if the white cannot move
		char arr4[8][8] = {{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::WHITE,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::WHITE,Position::BLACK,Position::WHITE,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::WHITE,Position::BLACK,Position::WHITE,Position::EMPTY,Position::EMPTY},
							{Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY},
							{UnplayablePosition::UNPLAYABLE,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,Position::EMPTY,UnplayablePosition::UNPLAYABLE} };
		board.setBoard(arr4);
		board.drawBoard();
		cout << "\n";

		cin >> position;

		if (position == 1){ board.setBoard(arr1); }
		else if (position == 2) { board.setBoard(arr2); }
		else if (position == 3) { board.setBoard(arr3); }
		else if (position == 4) { board.setBoard(arr4); }
	}

	for (int i = 0; i < 10; i++) {
		//printf("\n\n\n\n\n\n\n\n\n\n");
		cout << string(100, '\n');
	}

	board.play();
}

void Game::setBoard(Board b)
{
	board = b;
}

Board Game::getBoard()
{
	return board;
}
