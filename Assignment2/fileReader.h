/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)
*/

#ifndef __FILEREADER_H
#define __FILEREADER_H
#include "gameBoard.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class fileReader
{
	public:
		fileReader();
		fileReader(string f);
		~fileReader();
		
		int getRows();
		int getColumns();
		gameBoard* getFileBoard();

		bool isValid();
	private:
		void readFile();

		string file;
		bool successful;
		int rows;
		int columns;
		gameBoard* fileBoard;
};

#endif