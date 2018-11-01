/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)

   gameBoard
*/

#include "gameBoard.h"
#include <iostream>
#include <string>

using namespace std;

gameBoard::gameBoard()
{
}

gameBoard::gameBoard(int r, int c)
{
	rows = r;
	columns = c;
	board = new int[r * c];
}

gameBoard::gameBoard(gameBoard* game)
{
	rows = game->getRows();
	columns = game->getColumns();
	
	board = new int[rows * columns];

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < columns; c++)
		{
			updateBoard(r,c,game->getVal(r,c));
		}
	}
}

gameBoard::~gameBoard()
{
	delete board;
}

void gameBoard::updateBoard(int r, int c, char elem)
{
	if(elem == 'X') board[r * columns + c] = 1;
	else if(elem == '-') board[r * columns + c] = 0;
}

void gameBoard::updateBoard(int r, int c, int elem)
{
	board[r * columns + c] = elem;
}

int gameBoard::getVal(int r, int c)
{
	return board[r * columns + c];
}

string gameBoard::printBoard()
{
	string masterBoard = "";
	for(int i = 0; i < rows; i++)
	{
		string print = "";
		for(int j = 0; j < columns; j++)
		{
			int val = board[i * columns + j];
			if(val == 0) print += "-";
			else print += "X";
		}
		masterBoard += print + "\n";
	}

	return masterBoard;
}

int gameBoard::getRows()
{
	return rows;
}

int gameBoard::getColumns()
{
	return columns;
}