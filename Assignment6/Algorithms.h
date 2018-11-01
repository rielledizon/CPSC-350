/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 6 - Sorting Algorithms
 
 Algorithms.h - Algorithms header
*/

#ifndef Algorithms_h
#define Algorithms_h

#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>

using namespace std;

class Algorithms{
public:
    Algorithms();
    ~Algorithms();
    
    void readFile(string fileName);
    
    void bubbleSort(double array[]);
    void insertionSort(double array[]);
    void quickSort(double array[], int lo, int hi);
    int merge(double array[], int lo, int hi);
    void shellSort(double array[]);
    
    void runtime();

//private:
    int numItems;
    
    double *bubbleSortArray;
    double *insertionSortArray;
    double *quickSortArray;
    double *shellSortArray;
};
#endif /* Algorithms_h */

/*string solution(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    string temp = "";
    string reformatted ="";
    string toPrint = "";
    for(int i = S.length() - 1; i >= 0; --i)
    {
        if (S[i] != '-')
        {
            temp += toupper(S[i]);
        }
    }
    
    int count = 0;
    for (char c:temp)
    {
        if (count==K)
        {
            reformatted += '-';
            count = 0;
        }
        reformatted+=c;
        count++;
    }
    
    for (int i = reformatted.length()-1; i>=0; --i)
    {
        toPrint+=reformatted[i];
    }
    return toPrint;
}
*/
