/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 2 (The Game of Life)

   fileReader: checks if file exists and if file is consistent 
*/

#include "fileReader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

fileReader::fileReader()
{

}

fileReader::fileReader(string f)
{
	file = f;
	ifstream reading(file);
	
	if(reading)
	{
		successful = true;
		readFile();
	} else
	{
		successful = false;
		cout << "File doesn't exist!" << endl;
	}
}

fileReader::~fileReader()
{

}

bool fileReader::isValid()
{
	return successful;
}

int fileReader::getRows()
{
	return rows;
}

int fileReader::getColumns()
{
	return columns;
}

gameBoard* fileReader::getFileBoard()
{
	return fileBoard;
}

void fileReader::readFile()
{
	ifstream reading(file);
	string str;

	if(!(reading >> rows))
	{
		successful = false;
		cout << "ERROR: Could not read file: invalid row" << endl;
	}

	if(!(reading >> columns))
	{
		successful = false;
		cout << "ERROR: Could not read file: invalid column" << endl;
	}

	if(successful)
	{
		fileBoard = new gameBoard(rows,columns);
		
		int rowCount = 0;
		int onRow = 0;
		int onCol = 0;

		while(getline(reading, str))
		{
			if(str.length() == 0) continue;
			onCol = 0;
			rowCount++;
			if(str.length() != columns)
			{
				successful = false;
				cout << "Invalid Column count: The amount of columns in the file does not match the number you indicated" << endl;
				break;
			}else if(rowCount > rows)
			{
				successful = false;
				cout << "Invalid Row Count: The amount of rows in the file does not match the number you indicated" << endl;
				break;
			}else
			{
				for(char& c : str)
				{
					fileBoard->updateBoard(onRow,onCol,c);
					if(c != '-' && c != 'X')
					{
						successful = false;
						cout << "Invalid board! One of the characters in the board isn't a '-' or a 'X'" << endl;
					}else
					{
					}
					onCol++;
				}
			}
			onRow++;
		}
	}
}