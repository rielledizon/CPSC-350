//
//  main.cpp
//  Assignment1
//
//  Created by Rielle Dizon on 2/10/18.
//  Copyright © 2018 Rielle Dizon. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>


#include "DNA.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    if (!(argc==2)) //checks if txt file was taken as a second argument
    {
        cout << "Yikes do that again by rerunning a.out with the txtfile you want analyzed" << endl;
        exit(0);
    }
    
    string fileName = argv[1];
    while (true) //always looping until user inputs "N"
    {
        cout << "Reading file\n.\n..\n...\n"<< endl;
        ofstream outFile;
        outFile.open("rielledizon.out");
        outFile << "Rielle Dizon\n2282971\ndizon110@mail.chapman.edu\nCPSC 350-02\nAssignment 1: DNA Analyzer\n\n" << endl;
        DNA dna;
        
        outFile << dna.calculations(fileName);
        outFile << dna.generateDNA(fileName);
        outFile.close();
        
        bool again = true;
        while (again) //ask for a new file
        {
            cout << "File read, new file written.\nWould you like another file to be read and overwrite the newly written one? Y or N" <<endl;
            string input;
            cin >> input;
            if (input == "Y" || input == "y")
            {
                cout << "\nEnter txt file" <<endl;
                cin >> fileName;
                again = false;
            }
            if (input == "N" || input == "n")
            {
                cout << "\nDone." << endl;
                return 0;
            }
            else
            {
                cout << "\nPlease enter a valid option" << endl;
            }
        }
    }
}
