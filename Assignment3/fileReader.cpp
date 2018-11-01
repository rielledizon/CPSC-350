/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 3 - Syntax Checker
 
 fileReader.cpp – checks if file exists
 */

#include "fileReader.h"
#include "SyntaxCheck.h"
#include "GenStack.h"
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

