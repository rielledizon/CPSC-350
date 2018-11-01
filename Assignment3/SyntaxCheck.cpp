/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 3 - Syntax Checker
 
 SyntaxCheck.cpp – checks for delimiters within files
 */

#include "SyntaxCheck.h"
#include "GenStack.h"
#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

SyntaxCheck::SyntaxCheck()
{
    
}
SyntaxCheck::~SyntaxCheck()
{
    
}

int SyntaxCheck::checkChar(string fileName)
{
    GenStack<char> tempStack; //temp stack
    fileReader* fileData = NULL;
    bool loop = true;
    
    while (loop){
        ifstream inFile(fileName);
        string line;
        
        int lineNum = 1; //line where error is;
        while (getline(inFile, line))
        {
            for(int i = 0; i < line.length(); ++i)
            {
                if(line[i] == '(' || line[i] == ')' || line[i] == '{' || line[i] == '}' || line[i] == '[' || line[i] == ']') //checks if delimiter exists
                {
                    if (tempArray.peek() == '(' && line[i] == ')')
                    {
                        tempArray.pop();
                    }
                    else if (tempArray.peek() == '[' && line[i] == ']')
                    {
                        tempArray.pop();
                    }
                    else if (tempArray.peek() == '{' && line[i] == '}')
                    {
                        tempArray.pop();
                    }
                    else if (tempArray.peek() == '(' && (line[i] == '}' || line[i] == ']'))
                    {
                        cout << "ERROR LINE " << lineNum << "\n\tExpected: )\n\tFOUND: " << line[i]<< endl;
                        return 0;
                    }
                    else if (tempArray.peek() == '{' && (line[i] == ')' || line[i] == ']'))
                    {
                        cout << "ERROR LINE " << lineNum << "\n\tExpected: }\n\tFOUND: " << line[i]<< endl;
                        return 0;

                    }
                    else if (tempArray.peek() == '[' && (line[i] == ')' || line[i] == '}'))
                    {
                        cout << "ERROR LINE " << lineNum << "\n\tExpected: ]\n\tFOUND: " << line[i]<< endl;
                        return 0;
                    }
                    else if (line[i] == '(' || line[i] == '{' || line[i] == '[')
                    {
                        tempArray.push(line[i]);
                    }
                }
            }
            lineNum++;
        }
        if (inFile.eof() && !tempArray.isEmpty())
        {
            cout << "Missing delimiter at LINE " << lineNum << endl;
        }
        else if (inFile.eof() && tempArray.isEmpty()) // check end of file
        {
            bool fileAgain = true;
            string again;
            cout << "No missing delimiters in source code. Done checking file."<< endl;
            while (fileAgain)
            {
                cout << "\nCheck another file ? [Y/N]" << endl;
                cin >> again;
                
                if (again[0] == 'Y' || again[0] == 'y')
                {
                    cout << "Name of new file ?"<<endl;
                    while(true)
                    {
                        if (!(cin >> fileName))
                        {
                            cout<< "Enter the name of the new file: " << endl;
                        }
                        else
                        {
                            fileData = new fileReader(fileName);
                            if (!fileData -> isValid())
                            {
                                cout<< "Please enter an existing file"<<endl;
                            }
                            else
                            {
                                fileAgain = false;
                                break;
                            }
                        }
                    }
                    
                }
                else if (again[0] == 'N' || again[0] == 'n')
                {
                    cout << "End of Program" << endl;
                    fileAgain = false;
                    loop = false;
                }
                else
                {
                    cout << "INVALID INPUT";
                }
            }
        }
    }
    return 0;
}
