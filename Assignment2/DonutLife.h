/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)
*/

#ifndef __DONUTLIFE_H
#define __DONUTLIFE_H
#include "fileReader.h"
#include "game_of_life.h"
#include <iostream>
#include <string>

using namespace std;

class DonutLife : public game_of_life
{
	public:
		DonutLife();
		DonutLife(fileReader* f);
		DonutLife(int r, int c, double dens);		
		virtual ~DonutLife();

		int neighborCount(gameBoard* board, int r, int c);

	private:
		gameBoard* tpBoard;

};

#endif