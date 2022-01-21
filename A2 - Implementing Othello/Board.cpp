#include <iostream>
#include <fstream>
#include <string>
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
	string inputPosition;
	int row;
	int col;
	char playerColor = current.getName().compare(first.getName()) == 0 ? 'B' : 'W';

	while (true)
	{
		//input the position
		cout << "\nTaking turn of " << current.getName() << endl;
		cout << "Choose an (x,y) position (ex: A3):" << endl;
		cin >> inputPosition;

		switch (inputPosition.at(0))
		{
		case 'A':
			col = 0;
			break;
		case 'B':
			col = 1;
			break;
		case 'C':
			col = 2;
			break;
		case 'D':
			col = 3;
			break;
		case 'E':
			col = 4;
			break;
		case 'F':
			col = 5;
			break;
		case 'G':
			col = 6;
			break;
		case 'H':
			col = 7;
			break;
		default:
			col = -1;
			break;
		}

		// "- '0'" is to set the char to int and the "-1" is to set it for array since the board rows start at one
		row = inputPosition.at(1) - '0' - 1; 

		//check for wrong inputs
		if (col == -1 || !(row >= 0 && row <= 7))
		{
			cout << "The position input is wrong. Please enter a right position";
			continue;
		}

		//check if the (x,y) position is empty
		if (board[row][col] != ' ')
		{
			cout << "The position is already taken by a chip. Please enter another position";
			continue;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////check if the move is legal
		bool isLegal = false;
		char oppositeColor = playerColor == 'B' ? 'W' : 'B';

		int tempX = row;
		int tempY = col;
		//check for adjacent piece to the left
		if (row > 0)
		{
			if (board[row - 1][col] == oppositeColor)
			{
				while (tempX > 0)
				{
					tempX--;

					if (board[tempX][col] == oppositeColor)
					{
						continue;
					}
					else if (board[tempX][col] == playerColor)
					{
						isLegal = true;
						cout << "left True";
						break;
					}
					else if (board[tempX][col] == ' ' || board[tempX][col] == '*')
					{
						break;
					}
				}
			}
		}
		
		//check for adjacent piece to the top
		if (col > 0)
		{
			tempX = row;
			tempY = col;
			
			if (board[row][col - 1] == oppositeColor)
			{
				while (tempY > 0)
				{
					tempY--;

					if (board[row][tempY] == oppositeColor)
					{
						continue;
					}
					else if (board[row][tempY] == playerColor)
					{
						isLegal = true;
						cout << "TOP True";
						break;
					}
					else if (board[row][tempY] == ' ' || board[row][tempY] == '*')
					{
						break;
					}
				}
			}
		}

		//check for adjacent piece to the right
		if (row < 7)
		{
			tempX = row;
			tempY = col;
			
			if (board[row + 1][col] == oppositeColor)
			{
				while (tempX < 7)
				{
					tempX++;

					if (board[tempX][col] == oppositeColor)
					{
						continue;
					}
					else if (board[tempX][col] == playerColor)
					{
						isLegal = true;
						cout << "right true";
						break;
					}
					else if (board[tempX][col] == ' ' || board[tempX][col] == '*')
					{
						break;
					}
				}
			}
		}

		//check for adjacent piece to the bottom
		if (col < 7)
		{
			tempX = row;
			tempY = col;
			
			if (board[row][col + 1] == oppositeColor)
			{
				while (tempY < 7)
				{
					tempY++;

					if (board[row][tempY] == oppositeColor)
					{
						continue;
					}
					else if (board[row][tempY] == playerColor)
					{
						isLegal = true;
						cout << "bottom true";
						break;
					}
					else if (board[row][tempY] == ' ' || board[row][tempY] == '*')
					{
						break;
					}
				}
			}
		}

		if (!isLegal)
		{
			cout << "row:" << row << " col:" << col;
			cout << "The position is not playable according to the rules. Please enter another position";
			continue;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		//play it there
		board[row][col] = playerColor;

		//flip if needed
		flip(row,col);


		cout << "X: " << row << " Y: " << col << endl;

		break;
	}

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

	play();

	return Board();
}

void Board::play()
{
	int option=3;
	while (option==3)
	{
		drawBoard();
		showPoints();

		if (!canPlay(first) && !canPlay(second))
		{
			cout << "Nobody can move." << endl;

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
				cout << (nbOfBlack > nbOfWhite ? first.getName() : second.getName()) << " won! Congratulations!!!" << endl;
			}

			option = -1;
		}
		else if (current.getName().compare(first.getName()) == 0)
		{
			cout << endl << first.getName() << ", what do you want to do?" << endl;
			cout << "1.Save \n2.Concede" << endl;
			if (canPlay(first))
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
				cout << "3.Skip turn" << endl << "You cannot move" << endl;
				cin >> option;
				switch (option)
				{
				case 1: save(); option = -1; break;
				case 2: cout << current.getName() << " conceded and have lost :(" << endl; option = -1; break;
				case 3: 
					// change the name of the current user
					if (current.getName().compare(first.getName()) == 0) {
						current.setName(second.getName());
					}
					else {
						current.setName(first.getName());
					}
					break;
				default: break;
				}
			}
		}

		else if(current.getName().compare(second.getName()) == 0)
		{
			cout << endl << second.getName() << ", what do you want to do?" << endl;
			cout << "1.Save \n2.Concede" << endl;
			if (canPlay(second))
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
				cout << "3.Skip turn" << endl << "You cannot move" << endl;
				cin >> option;
				switch (option)
				{
				case 1: save(); option = -1; break;
				case 2: cout << current.getName() << " conceded and have lost :(" << endl; option = -1; break;
				case 3: 
					// change the name of the current user
					if (current.getName().compare(first.getName()) == 0) {
						current.setName(second.getName());
					}
					else {
						current.setName(first.getName());
					}
					break;
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

bool Board::canPlay(Player p)
{
	//check which player it is
	char playerColor = p.getName().compare(first.getName()) == 0 ? 'B' : 'W';
	char oppositeColor = playerColor == 'B' ? 'W' : 'B';
	
	//check every square
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//for every piece of the player
			if (board[i][j] == playerColor) 
			{


				int tempX = i; 
				int tempY = j;
				//check for adjacent piece to the left
				if (i > 0)
				{
					if (board[i - 1][j] == oppositeColor)
					{
						while (tempX > 0)
						{
							tempX--;

							if (board[tempX][j] == oppositeColor)
							{
								continue;
							}
							else if (board[tempX][j] == playerColor)
							{
								break;
							}
							else if (board[tempX][j] == ' ')
							{
								return true;
							}
						}
					}
				}
				

				if (j > 0)
				{
					tempX = i;
					tempY = j;
					//check for adjacent piece to the top
					if (board[i][j - 1] == oppositeColor)
					{
						while (tempY > 0)
						{
							tempY--;

							if (board[i][tempY] == oppositeColor)
							{
								continue;
							}
							else if (board[i][tempY] == playerColor)
							{
								break;
							}
							else if (board[i][tempY] == ' ')
							{
								return true;
							}
						}
					}
				}

				if (i < 7)
				{
					tempX = i;
					tempY = j;
					//check for adjacent piece to the right
					if (board[i + 1][j] == oppositeColor)
					{
						while (tempX < 7)
						{
							tempX++;

							if (board[tempX][j] == oppositeColor)
							{
								continue;
							}
							else if (board[tempX][j] == playerColor)
							{
								break;
							}
							else if (board[tempX][j] == ' ')
							{
								return true;
							}
						}
					}
				}

				if (j < 7)
				{
					tempX = i;
					tempY = j;
					//check for adjacent piece to the bottom
					if (board[i][j + 1] == oppositeColor)
					{
						while (tempY < 7)
						{
							tempY++;

							if (board[i][tempY] == oppositeColor)
							{
								continue;
							}
							else if (board[i][tempY] == playerColor)
							{
								break;
							}
							else if (board[i][tempY] == ' ')
							{
								return true;
							}
						}
					}
				}
			}
		}
	}

	return false;
}

void Board::flip(int row, int col)
{
	//check which player it is
	char playerColor = current.getName().compare(first.getName()) == 0 ? 'B' : 'W';
	char oppositeColor = playerColor == 'B' ? 'W' : 'B';
	
	int tempX = row;
	int tempY = col;

	//check for adjacent piece to the left
	if (row > 0)
	{
		if (board[row - 1][col] == oppositeColor)
		{
			while (tempX > 0)
			{
				tempX--;

				if (board[tempX][col] == oppositeColor)
				{
					continue;
				}
				else if (board[tempX][col] == playerColor)
				{
					//go back and change color
					while (tempX < row)
					{
						tempX++;
						board[tempX][col] = playerColor;
					}
					break;
				}
				else if (board[tempX][col] == ' ' || board[tempX][col] == '*')
				{
					break;
				}
			}
		}
	}

	//check for adjacent piece to the top
	if (col > 0)
	{
		tempX = row;
		tempY = col;

		if (board[row][col - 1] == oppositeColor)
		{
			while (tempY > 0)
			{
				tempY--;

				if (board[row][tempY] == oppositeColor)
				{
					continue;
				}
				else if (board[row][tempY] == playerColor)
				{
					//go back and change color
					while (tempY < col)
					{
						tempY++;
						board[row][tempY] = playerColor;
					}
					break;
				}
				else if (board[row][tempY] == ' ' || board[row][tempY] == '*')
				{
					break;
				}
			}
		}
	}

	//check for adjacent piece to the right
	if (row < 7)
	{
		tempX = row;
		tempY = col;

		if (board[row + 1][col] == oppositeColor)
		{
			while (tempX < 7)
			{
				tempX++;

				if (board[tempX][col] == oppositeColor)
				{
					continue;
				}
				else if (board[tempX][col] == playerColor)
				{
					//go back and change color
					while (tempX > row)
					{
						tempX--;
						board[tempX][col] = playerColor;
					}
					break;
				}
				else if (board[tempX][col] == ' ' || board[tempX][col] == '*')
				{
					break;
				}
			}
		}
	}

	//check for adjacent piece to the bottom
	if (col < 7)
	{
		tempX = row;
		tempY = col;
		
		if (board[row][col + 1] == oppositeColor)
		{
			while (tempY < 7)
			{
				tempY++;

				if (board[row][tempY] == oppositeColor)
				{
					continue;
				}
				else if (board[row][tempY] == playerColor)
				{
					//go back and change color
					while (tempY > col)
					{
						tempY--;
						board[row][tempY] = playerColor;
					}
					break;
				}
				else if (board[row][tempY] == ' ' || board[row][tempY] == '*')
				{
					break;
				}
			}
		}
	}
}

void Board::showPoints()
{
	int blackPoints = 0;
	int whitePoints = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'B')
			{
				blackPoints++;
			}
			else if (board[i][j] == 'W')
			{
				whitePoints++;
			}
		}
	}

	cout << "-----Points-----" << endl
		 << "Black (" << first.getName() << "): " << blackPoints << endl
		 << "White (" << second.getName() << "): " << whitePoints << endl;
}
