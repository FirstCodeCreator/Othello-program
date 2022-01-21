// Assignment 2 - Implementing Othello
// Jeffrey Gamelin, Student #40189897
/***************************
* I did not have time to finish implementing the move function with the taketurn method 
* and I did not have time to implement the canPlay methods that verify if the user has playable positions.
* 
* I did however implemented the starting of a new game with or without offset positions, a save system, a load system and the drawing of the board.
* I also implemented the full UML diagram that is worth 1/4 of the grade.
* With all the code I have written, I should have a grade of 3/4 for this assignment since I implemented most of the parts.
***************************/

#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Position.h"
#include "PlayablePosition.h"
#include "UnplayablePosition.h"
using namespace std;

int main()
{
   
    int nbOption;
    string StringOption1;
    string StringOption2;

    cout << "What's up gamer. Wanna play a game?" << endl;
    cout << "Here are the special rules:" << endl
        << "- All corners are Unplayable" << endl
        << "- Flips only occur in horizontal and vertical lines" << endl;
    cout << "Choose an option." << endl;
    cout << "1. Start a New Game \n2. Quit \n3. Load a Game!\n\n";
    cin >> nbOption;
    if (nbOption == 1){
        cout << "Enter name of player 1:";
        cin >> StringOption1;
        cout << "Enter name of player 2:";
        cin >> StringOption2;
        Game game = Game(Player(StringOption1), Player(StringOption2));
        game.start();
    }
    else if (nbOption == 3) {
        cout << "Type the name of the file:";
        cin >> StringOption1;
        Game game = Game(Player(), Player());
        game.getBoard() = Board(StringOption1);
    }
    else { cout << "You chose to quit or inputted a wrong option. See you soon!" << endl;} //quit game*/
   
    return 0;
}