/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)
*/

#ifndef __GAME_OF_LIFE_H
#define __GAME_OF_LIFE_H
#include "fileReader.h"
#include "gameBoard.h"
#include <iostream>
#include <string>

using namespace std;

class game_of_life
{
	public:
		game_of_life();
		game_of_life(fileReader* f);
		game_of_life(int r, int c, double dens);
		virtual ~game_of_life();
		
		int playAGen();
		virtual int neighborCount(gameBoard* board, int r, int c);
		gameBoard* getBoard();
		
		void setDensity(double dens);
			
	private:

		void createBoard();
		void randBoard();

		gameBoard* pBoard;
		gameBoard* tpBoard;

		char playType;
		double density;
};

#endif