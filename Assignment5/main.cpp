/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 5 (BST)

   main.cpp - runs main program
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <deque>
#include "menu.h"


using namespace std;

int main()
{
	Menu* menu = new Menu();
    menu->initDatabases();
    menu->doMenu();
    menu->saveDatabases();

    return 0;
}
