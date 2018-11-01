/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)

   NormalLife: classic mode rules
*/

#include "fileReader.h"
#include "NormalLife.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

NormalLife::NormalLife()
{
}

NormalLife::NormalLife(fileReader* f): game_of_life(f)
{
}

NormalLife::NormalLife(int r, int c, double dens): game_of_life(r,c,dens)
{
}

NormalLife::~NormalLife()
{
}

int NormalLife::neighborCount(gameBoard* board, int r, int c)
{
	int neighborCount = 0;
	
	int rows = board->getRows();
	int columns = board->getColumns();

	for(int i = (r - 1); i <= (r + 1); i++)
	{	
		for(int j = (c - 1); j <= (c + 1); j++)
		{
			if(neighborCount >= 4) break;
			if(i == r && j == c) continue;
			if((i >= 0 && i < rows) && (j >= 0 && j < columns)) neighborCount += board->getVal(i,j);
		}

		if(neighborCount >= 4) break;
	}

	return neighborCount;
}