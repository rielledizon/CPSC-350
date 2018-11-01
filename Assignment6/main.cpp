/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 6 - Sorting Algorithms
 
 Main.cpp – main program
 */

#include <iostream>
#include <fstream>
#include "fileReader.h"
#include "Algorithms.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Algorithms sortFile;
    
    if (argc < 2)
    {
        cout << "Please enter a file input"<<endl;
    }
    else if (argc >= 2)
    {
        string fileName = argv[1];
        fileReader* fileUsed = new fileReader(fileName);
        if (!fileUsed -> isValid())
        {
            cout << "FILE DOES NOT EXIST! Please enter a VALID file input" << endl;
            return 0;
        }
        sortFile.readFile(fileName);
    }
    return 0;
}
