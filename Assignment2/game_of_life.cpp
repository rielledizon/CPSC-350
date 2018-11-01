/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)

   game_of_life: parent class for all gameModes
*/

#include "game_of_life.h"
#include "fileReader.h"
#include "gameBoard.h"
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h> 
#include <random>

using namespace std;

game_of_life::game_of_life()
{

}

game_of_life::game_of_life(fileReader* f)
{
	pBoard = f->getFileBoard();
}

game_of_life::game_of_life(int r, int c, double dens)
{
	pBoard = new gameBoard(r,c);
	density = dens;
	createBoard();
}

game_of_life::~game_of_life()
{
	delete pBoard;
}

int game_of_life::neighborCount(gameBoard* board, int r, int c)
{
	return 0;
}

int game_of_life::playAGen()
{
	int numChange = 0;
	gameBoard* myBoard = getBoard();

	tpBoard = new gameBoard(myBoard);

	int rows = myBoard->getRows();
	int columns = myBoard->getColumns();

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < columns; c++)
		{
			int nCount = neighborCount(tpBoard,r,c);

			int curVal = myBoard->getVal(r,c);
			
			if(nCount == 4)
			{
				if(curVal != 0)
				{
					numChange++;
					myBoard->updateBoard(r,c,'-');
				}
			}else if(nCount == 3)
			{
				if(curVal != 1)
				{
					numChange++;
					myBoard->updateBoard(r,c,'X');
				}
			}else if(nCount != 2)
			{
				if(curVal != 0)
				{
					numChange++;
					myBoard->updateBoard(r, c,'-');
				}
			}
		}
	}

	delete tpBoard;
	return numChange;
}

gameBoard* game_of_life::getBoard()
{
	return pBoard;
}

void game_of_life::createBoard()
{	
	if(density > 0.00)
	{
		for(int i = 0; i < pBoard->getRows(); i++)
		{
			for(int j = 0; j < pBoard->getColumns(); j++)
			{
				double which = (double)(rand() % 10000)/100;
				if(which < (density * 100)) pBoard->updateBoard(i,j,'X');
				else pBoard->updateBoard(i,j,'-');
			}
		}
	}
}