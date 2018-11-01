/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 6 - Sorting Algorithms
 
 fileReader.h – fileReader header
 */

#ifndef fileReader_h
#define fileReader_h

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class fileReader
{
public:
    fileReader();
    fileReader(string fileName);
    ~fileReader();
    
    bool isValid();
    
private:
    string file;
    bool successful;
};

#endif /* fileReader_h */
