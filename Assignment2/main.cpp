/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)

   main
*/


#include "game_of_life.h"
#include "fileReader.h"
#include "NormalLife.h"
#include "DonutLife.h"
#include "MirrorLife.h"
#include "gameBoard.h"

#include <string>
#include <unistd.h>

#include <sstream>

using namespace std;

int main(int argc, char ** argv)
{
	srand(time(NULL));
	game_of_life* pGame = NULL;
	fileReader* fileData = NULL;

	ofstream outfile;

	string f;
	bool rand = true;
	double density = 0.00; 
	int r = -1;
	int c = -1;
	
	char gameType = ' ';
	char gameMode = ' ';
	char carryOut = ' ';

	string fileOutput = "";

	
	string flatfileHelp = "<# of rows>";
	flatfileHelp += "\n<# of columns>";
	flatfileHelp += "\n<board with number of rows and columns indicated>";
	flatfileHelp += "\n(For the board make sure to denote empty spaces as \"-\" and cells with \"X\")";
	flatfileHelp += "\n\nExample board";
	flatfileHelp += "\n5";
	flatfileHelp += "\n7";
	flatfileHelp += "\n---X--X";
	flatfileHelp += "\n-X--X--";
	flatfileHelp += "\n-----XX";
	flatfileHelp += "\nX-X-X--";
	flatfileHelp += "\n-----XX";

	string description = "Classic Mode:";
	description += "\n\t In this mode, all the locations outside of the grid are considered empty.";
	description += "\nDoughnut mode:";
	description += "\n\t In this mode, the grid goes around itself horizontally and vertically.";
	description += "\n\t For exmaple, any cell on the furthest right side is wrapped to affect the left most column and vice versa.";
	description += "\n\t Equally, same things happens with the top and bottom.";
	description += "\nMirror Mode: ";
	description += "\n\tIn this mode, the references on any extremeties bounce back to itself like the wall is a mirror.";
	description += "\n\tFor example, a cell that is at the top of the grid will directly affect itself";
	
	cout << "Would you like to start the game from a flat file configuration or create with a random configuration (Type f for file or r for random of h to see what a flatfile should look like)" << endl;
	string input;

	while(!(cin >> input) || !(input.length() == 1) || (input[0] != 'F' && input[0] != 'f' && input[0] != 'R' && input[0] != 'r'))
	{
		if(input[0] == 'H' || input[0] == 'h') cout << flatfileHelp << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Type f to start with a flat file, r to start with a random board, or h to see what a flatile should look like" << endl;
	}

	gameType = input[0];

	if(gameType == 'F' || gameType == 'f') rand = false;
	else rand = true;

	if(rand)
	{
		cout << "Enter a decimal value between 0 and 1 for the density of the board" << endl;
		while(!(cin >> density) || (density <= 0.0 || density >= 1.0))
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a valid density value" << endl;
		} 

		cout << "What height board would you like to have?" << endl;

		if(gameType == 'R' || gameType == 'r')
		{
			while(!(cin >> r) || r < 0)
			{
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Please enter a valid value for the height of the board" << endl;
			}

			cout << "What width board would you like to have?" << endl;

			while(!(cin >> c) || c < 0)
			{
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Please enter a valid value for the width of the board" << endl;
			}
		}
	}else
	{
		cout << "Enter the file name you wish you to use for the flat file" << endl;
		while(true)
		{
			if(!(cin >> f))
			{
				cout << "Enter the file name you wish you to use for the flat file" << endl;
			}else
			{
				fileData = new fileReader(f);
				if(!fileData->isValid())
				{
					cout << "Please enter a valid flat file you would like to use" << endl;	
				}else
				{
					cout << "File worked!" << endl;
					break;
				}
			}
		}
	}

	cout << "Type c for a game of Classic Gamemode, d for Doughnut Gamemode, m for Mirror mode, or h for a description for each" << endl;
	while(!(cin >> input) || !(input.length() == 1) || (input[0] != 'C' && input[0] != 'c' && input[0] != 'D' && input[0] != 'd' && input[0] != 'M' && input[0] != 'm'))
	{
		if(input[0] == 'H' || input[0] == 'h') cout << description << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Type c for a game of Classic Gamemode, d for Doughnut Gamemode, m for Mirror mode, or h for a description for each" << endl;
	}

	gameMode = input[0];
	
	cout << "Type p if you want a brief pause between each generation, e to press the \"Enter\" key to run a new generation, or f to output all of it to a file." << endl;
	while(!(cin >> input) || !(input.length() == 1) || (input[0] != 'P' && input[0] != 'p' && input[0] != 'E' && input[0] != 'e' && input[0] != 'F' && input[0] != 'f'))
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Type p if you want a brief pause between each generation, e to press the \"Enter\" key to run a new generation, or f to output all of it to a file." << endl; 
	}
	
	carryOut = input[0];

	if(carryOut == 'F' || carryOut == 'f')
	{
		cout << "What would you like to name the file?" << endl;
		cin >> fileOutput;
		outfile.open(fileOutput);
		cin.ignore(256,'\n');
		cin.clear();
	}

	if(rand)
	{
		if(gameMode == 'C' || gameMode == 'c') pGame = new NormalLife(r,c,density);
		else if(gameMode == 'D' || gameMode == 'd') pGame = new DonutLife(r,c,density);
		else pGame = new MirrorLife(r,c,density);
	}else
	{
		if(gameMode == 'C' || gameMode == 'c') pGame = new NormalLife(fileData);
		else if(gameMode == 'D' || gameMode == 'd') pGame = new DonutLife(fileData);
		else pGame = new MirrorLife(fileData);
	}

	int genCount = 1;

	gameBoard* theBoard = pGame->getBoard();

	if(carryOut == 'F' || carryOut == 'f')
	{
		outfile << "Start Generation: " << endl;
		outfile << theBoard->printBoard() << endl;
	}else
	{
		cout << "Start Generation: " << endl;
		cout << theBoard->printBoard() << endl;
		if(carryOut == 'E' || carryOut == 'e')
		{
			cout << "Press enter to play a generation..." << endl;
			cin.ignore();
		}
	}

	while(pGame->playAGen() != 0)
	{
		if(carryOut == 'F' || carryOut == 'f')
		{
			outfile << "Playing Generation: " << genCount++ << endl;
			outfile << theBoard->printBoard() << endl;
		}else
		{
			cout << "Playing Generation: " << genCount++ << endl;
			cout << theBoard->printBoard() << endl;
		}if(carryOut == 'P' || carryOut == 'p')
		{
			usleep(500000);
		}else if(carryOut == 'E' || carryOut == 'e')
		{
			cout << "Press enter to play a generation..." << endl;
			cin.ignore();
		}
	}

	cout << "The board has stabilized." << endl;
	if(carryOut == 'F' || carryOut == 'f')
	{
		outfile << "Final Generation: " << endl;
		outfile << theBoard->printBoard() << endl;
	}else
	{
		cout << "Final Generation: " << endl;
		cout << theBoard->printBoard() << endl;
	}

	if(carryOut == 'F' || carryOut == 'f') outfile << "The board has stabilized." << endl;
	else if(carryOut == 'P' || carryOut == 'p') cin.ignore(256,'\n');
	cout << "Press enter to exit" << endl;
    cin.get();

	delete pGame;
}