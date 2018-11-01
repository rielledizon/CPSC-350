/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)
*/

#ifndef __GAMEBOARD_H
#define __GAMEBOARD_H
#include <iostream>
#include <string>

using namespace std;

class gameBoard
{
	public:
		gameBoard();
		gameBoard(int r, int c);
		gameBoard(gameBoard* game);
		~gameBoard();

		void updateBoard(int r, int c, char elem);
		void updateBoard(int r, int c, int elem);
		
		int getVal(int r, int c);
		string printBoard();
		
		int getRows();
		int getColumns();
	private:
		int rows;
		int columns;
		int* board;

};

#endif