/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 3 - Syntax Checker
 
 SyntaxCheck.h
 */

#ifndef SyntaxCheck_h
#define SyntaxCheck_h

#include <iostream>
using namespace std;

class SyntaxCheck{
public:
    SyntaxCheck();
    ~SyntaxCheck();
    
    int checkChar(string fileName);
};
#endif /* SyntaxCheck_h */
