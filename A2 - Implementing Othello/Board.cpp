#include <iostream>
#include <fstream>
#include "Board.h"
using namespace std;

Board::Board()
{
	fileName = "test.txt";
	first = Player();
	second = Player();
	current = Player();
}

Board::Board(Player p1, Player p2, int start)
{
	fileName = "test.txt";
	first = p1;
	second = p2;
	if (start==1){
		current = p1;
	}
	else {
		current = p2;
	}

}

Board::Board(string save_file)
{

	fileName = save_file;
	first = Player();
	second = Player();
	current = Player();
	load();
}

void Board::save()
{
	cout << "Choose a filename:";
	cin >> fileName;

	ofstream f;
	f.open(fileName);

	f << first.getName() << endl << second.getName() << endl << current.getName() << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j]==' ') {
				f << 'x';
			}
			else
			{
				f << board[i][j];
			}
		}

	}
	f.close();
	cout << "The game in saved in the file " << fileName;
}

void Board::takeTurn()
{
	cout << "Taking turn of " << current.getName() << endl;


	// change the name of the current user
	if (current.getName().compare(first.getName()) == 0){
		current.setName(second.getName());
	}
	else {
		current.setName(first.getName());
	}
}


void Board::drawBoard()
{
	cout << "      A    B    C    D    E    F    G    H\n\n";
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << "   ";
		for (int j = 0; j < 8; j++)
		{
			cout << " |" << board[i][j] << "| ";
		}
		cout << "\n     ---------------------------------------\n";
	}
}


Board Board::load()
{
	ifstream f;
	f.open(fileName);
	string temp;
	f >> temp;
	first.setName(temp);
	f >> temp;
	second.setName(temp);
	f >> temp;
	current.setName(temp);

	char c;
	f.get(c);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			f.get(c);
			if (c == 'x') {
				board[i][j] = ' ';
			}
			else
			{
				board[i][j] = c;
			}
		}

	}
	f.close();
	cout << "Name of player 1: " << first.getName() << endl;
	cout << "Name of player 2: " << second.getName() << endl;
	cout << "Name of current player: " << current.getName() << endl;
	drawBoard();

	play();

	return Board();
}

void Board::play()
{
	int option=3;
	while (option==3)
	{
		if (false) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////nobody canmove)
		{
			cout << "Nobody can move :(" << endl;

			int nbOfWhite = 0;
			int nbOfBlack = 0;

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (board[i][j] == 'W') {
						nbOfWhite++;
					}
					else if (board[i][j] == 'B') {
						nbOfBlack++;
					}
				}
			}

			if (nbOfBlack == nbOfWhite) {
				cout << "It is a tie.";
			}
			else {
				cout << (nbOfWhite > nbOfBlack ? first.getName() : second.getName()) << " won! Congratulations!!!" << endl;
			}

			cout << "Nobody can move :(" << endl;
			option = -1;
		}
		else if (current.getName().compare(first.getName()) == 0)
		{
			cout << first.getName() << ", what do you want to do?" << endl;
			cout << "1.Save \n2.Concede" << endl;
			if (true)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////canmove)
			{
				cout << "3.Move" << endl;
			}
			else 
			{
				cout << "You cannot move" << endl;
			}
			cin >> option;
			switch (option)
			{
			case 1: save(); option = -1; break;
			case 2: cout << current.getName() << " conceded and have lost :(" << endl; option = -1; break;
			case 3: takeTurn(); break;
			default: break;
			}
		}

		else if(current.getName().compare(second.getName()) == 0)
		{
			cout << second.getName() << ", what do you want to do?" << endl;
			cout << "1.Save \n2.Concede" << endl;
			if (true)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////canmove)
			{
				cout << "3.Move" << endl;
				cin >> option;
				switch (option)
				{
				case 1: save(); option = -1; break;
				case 2: cout << current.getName() << " conceded and have lost :(" << endl; option = -1; break;
				case 3: takeTurn(); break;
				default: break;
				}
			}
			else
			{
				cout << "You cannot move" << endl;
				cin >> option;
				switch (option)
				{
				case 1: save(); option = -1; break;
				case 2: cout << current.getName() << "conceded and have lost :(" << endl;; option = -1; break;
				default: break;
				}
			}
		}
	}
}

void Board::setBoard(char boardValue[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = boardValue[i][j];
		}
	}
}

char* Board::getBoard()
{
	return *board;
}
