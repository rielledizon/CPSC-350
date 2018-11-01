/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 3 - Syntax Checker
 
 fileReader.h
 */

#ifndef fileReader_h
#define fileReader_h
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
    
    bool isValid();
private:
    string file;
    bool successful;
};

#endif /* fileReader_h */
