/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 6 - Sorting Algorithms
 
 fileReader.cpp – checks if file exists
 */

#include "fileReader.h"

fileReader::fileReader()
{
    
}

fileReader::fileReader(string fileName)
{
    file = fileName;
    ifstream reading(file);
    
    if(reading)
    {
        successful = true;
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
