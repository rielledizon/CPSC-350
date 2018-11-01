/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)

   DonutLife
*/

#include "fileReader.h"
#include "DonutLife.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

DonutLife::DonutLife()
{
}

DonutLife::DonutLife(fileReader* f): game_of_life(f)
{
}

DonutLife::DonutLife(int r, int c, double dens): game_of_life(r,c,dens)
{
}

DonutLife::~DonutLife()
{
}

int DonutLife::neighborCount(gameBoard* board, int r, int c)
{
	int neighborCount = 0;

	int rows = board->getRows();
	int columns = board->getColumns();

	int rowCheck;
	int columnCheck;

	for(int i = (r - 1); i <= (r + 1); i++)
	{	
		for(int j = (c - 1); j <= (c + 1); j++)
		{
			rowCheck = i;
			columnCheck = j;

			if(i < 0) rowCheck = rows - 1;
			else if (i == rows) rowCheck = 0; 
	
			if(j < 0) columnCheck = columns - 1;
			else if(j == columns) columnCheck = 0;
			
			if(neighborCount >= 4) break;

			if(i == r && j == c) continue;

			neighborCount += board->getVal(rowCheck,columnCheck);
		}

		if(neighborCount >= 4) break;
	}

	return neighborCount;
}