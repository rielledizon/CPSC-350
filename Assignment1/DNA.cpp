//
//  DNA.cpp
//  Assignment1
//
//  Created by Rielle Dizon on 2/11/18.
//  Copyright © 2018 Rielle Dizon. All rights reserved.
//

#include "DNA.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <ctime>

DNA::DNA() //resets data everytime new file is inputted
{
    charCount = 0; //equivalent to sum
    lineCount = 0;
    squaredUsed = 0;//variable used for calculating variance
    mean = 0;
    variance = 0;
    stdDev = 0;
    
    countA = 0; //nucleotide counts
    countT = 0;
    countC = 0;
    countG = 0;
    
    bigramAA = 0; //bigram counts
    bigramAT = 0;
    bigramAC = 0;
    bigramAG = 0;
    bigramTA = 0;
    bigramTT = 0;
    bigramTC = 0;
    bigramTG = 0;
    bigramCA = 0;
    bigramCT = 0;
    bigramCC = 0;
    bigramCG = 0;
    bigramGA = 0;
    bigramGT = 0;
    bigramGC = 0;
    bigramGG = 0;
    
    probA = 0; //probabilities of nucleotides occuring
    probT = 0;
    probC = 0;
    probG = 0;
    
    probAA = 0; //probabilities of bigrams occuring
    probAT = 0;
    probAC = 0;
    probAG = 0;
    probTA = 0;
    probTT = 0;
    probTC = 0;
    probTG = 0;
    probCA = 0;
    probCT = 0;
    probCC = 0;
    probCG = 0;
    probGA = 0;
    probGT = 0;
    probGC = 0;
    probGG = 0;
    
    dnaPrint = ""; //1000 DNA strings
}
DNA::~DNA()
{
    
}

string DNA:: calculations (string fileName) //sum, mean, variance, standard deviation
{
    ifstream inFile (fileName);
    while (getline(inFile, line))
    {
        lineCount ++;
        int charInLine = 0; //variable specific to calculating variance and standard deviation
        
        for (int i = 0; i < line.length(); ++i)
        {
            char nucleotide = toupper(line[i]);
            char secondary = toupper(line[i+1]);
            
            if (nucleotide == 'A')
            {
                countA++;
                charInLine++;
                if (secondary == 'A')
                {
                    bigramAA++;
                }
                else if (secondary == 'T')
                {
                    bigramAT++;
                }
                else if (secondary == 'C')
                {
                    bigramAC++;
                }
                else if (secondary == 'G')
                {
                    bigramAG++;
                }
            }
            else if (nucleotide == 'T')
            {
                countT++;
                charInLine++;
                if (secondary == 'A')
                {
                    bigramTA++;
                }
                else if (secondary == 'T')
                {
                    bigramTT++;
                }
                else if (secondary == 'C')
                {
                    bigramTC++;
                }
                else if (secondary == 'G')
                {
                    bigramTG++;
                }
            }
            else if (nucleotide == 'C')
            {
                countC++;
                charInLine++;
                if (secondary == 'A')
                {
                    bigramCA++;
                }
                else if (secondary == 'T')
                {
                    bigramCT++;
                }
                else if (secondary == 'C')
                {
                    bigramCC++;
                }
                else if (secondary == 'G')
                {
                    bigramCG++;
                }
            }
            else if (nucleotide == 'G')
            {
                countG++;
                charInLine++;
                if (secondary == 'A')
                {
                    bigramGA++;
                }
                else if (secondary == 'T')
                {
                    bigramGT++;
                }
                else if (secondary == 'C')
                {
                    bigramGC++;
                }
                else if (secondary == 'G')
                {
                    bigramGG++;
                }
            }
        }
        squaredUsed += pow(charInLine,2);
    }
    
    charCount += countA + countT + countC + countG;     //sum
    mean = (double)charCount / (double)lineCount;
    variance = ((double)squaredUsed - (pow(charCount,2)/(double)lineCount))/((double)lineCount-1);
    stdDev = sqrt(variance);
    
    probA = (double)countA / (double)charCount;
    probT = (double)countT / (double)charCount;
    probC = (double)countC / (double)charCount;
    probG = (double)countG / (double)charCount;
    probAA = (double)bigramAA / (double)(charCount - lineCount);
    probAT = (double)bigramAT / (double)(charCount - lineCount);
    probAC = (double)bigramAC / (double)(charCount - lineCount);
    probAG = (double)bigramAG / (double)(charCount - lineCount);
    probTA = (double)bigramTA / (double)(charCount - lineCount);
    probTT = (double)bigramTT / (double)(charCount - lineCount);
    probTC = (double)bigramTC / (double)(charCount - lineCount);
    probTG = (double)bigramTG / (double)(charCount - lineCount);
    probCA = (double)bigramCA / (double)(charCount - lineCount);
    probCT = (double)bigramCT / (double)(charCount - lineCount);
    probCC = (double)bigramCC / (double)(charCount - lineCount);
    probCG = (double)bigramCG / (double)(charCount - lineCount);
    probGA = (double)bigramGA / (double)(charCount - lineCount);
    probGT = (double)bigramGT / (double)(charCount - lineCount);
    probGC = (double)bigramGC / (double)(charCount - lineCount);
    probGG = (double)bigramGG / (double)(charCount - lineCount);
    
    stringstream text;
    text <<"STATISTICS:\n\tSUM: " << charCount << "\n\tMEAN: " << mean << "\n\tVARIANCE: " << variance << "\n\tSTANDARD DEVIATION: " << stdDev << '\n' << "NUCLEOTIDE PROBABILITIES:\n\tA: " << setprecision(4) << fixed << probA * 100 << "%\tT: " << setprecision(4) << fixed << probT * 100 << "%\tC: " << setprecision(4) << fixed << probC * 100 << "%\tG: " << setprecision(4) << fixed << probG * 100 << "%\n\n" << "BIGRAM PROBABILITIES:\n\tAA: " << setprecision(4) << fixed << probAA * 100 << "%\tAT: " << setprecision(4) << fixed << probAT  * 100 << "%\tAC: " << setprecision(4) << fixed << probAC * 100 << "%\tAG: " << setprecision(4) << fixed << probAG * 100<< "%\n" << "\tTA: " << setprecision(4) << fixed << probTA  * 100 << "%\tTT: " << setprecision(4) << fixed << probTT * 100 << "%\tTC: " << setprecision(4) << fixed << probTC  * 100 << "%\tTG: " << setprecision(4) << fixed << probTG * 100<< "%\n" << "\tCA: " << setprecision(4) << fixed << probCA  * 100 << "%\tCT: " << setprecision(4) << fixed << probCT  * 100 << "%\tCC: " << setprecision(4) << fixed << probGC  * 100 << "%\tCG: " << setprecision(4) << fixed << probCG * 100<< "%\n" << "\tGA: " << setprecision(4) << fixed << probGA  * 100 << "%\tGT: " << setprecision(4) << fixed << probGT  * 100 << "%\tGC: " << setprecision(4) << fixed << probGC  * 100 << "%\tGG: " << setprecision(4) << fixed << probGG * 100<< "%\n" <<endl;
    return text.str();
}

string DNA:: generateDNA(string fileName)
{
    ifstream inFile (fileName);
    
    srand((unsigned int)time(NULL)); //seed random number generator; random at each run
    for (int i = 0; i < 1000; ++i)
    {
        double a = (double)rand()/RAND_MAX;
        double b = (double)rand()/RAND_MAX;
        
        double c = sqrt(-2 * log (a)) * cos (2*M_PI*b);
        
        double d = stdDev*c + mean;
        
        string dnaStrand = "\t";
        for (int j = 0; j < d; ++j)
        {
            double randChar = (double)rand()/RAND_MAX;
            if (randChar <= probA)
            {
                dnaStrand += "A";
            }
            else if (randChar <= (probA + probT))
            {
                dnaStrand += "T";
            }
            else if (randChar <= (probA + probT + probC))
            {
                dnaStrand += "C";
            }
            else if (randChar <= 1)
            {
                dnaStrand += "G";
            }
        }
        dnaStrand += '\n';
        dnaPrint += dnaStrand;
    }
    stringstream text;
    text << "1000 DNA STRINGS:\n" << dnaPrint << endl;
    return text.str();
}




