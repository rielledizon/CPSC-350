/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 6 - Sorting Algorithms
 
 Algorithms.cpp – creates arrays, has all the algorithms, and calculates runtime
 */

#include "Algorithms.h"

Algorithms::Algorithms()
{
    
}

Algorithms::~Algorithms()
{
    delete [] bubbleSortArray;
    delete [] insertionSortArray;
    delete [] quickSortArray;
    delete [] shellSortArray;
}

void Algorithms::readFile(string fileName)
{
    ifstream reading(fileName);    
    string numberItems;
    string line;
    double item;
    int numLine = 1;
    
    getline(reading, numberItems);
    
    numItems = atoi(numberItems.c_str()); //convert string into int
    
    bubbleSortArray = new double [numItems];
    insertionSortArray = new double [numItems];
    quickSortArray = new double [numItems];
    shellSortArray = new double [numItems];
    
    for (int i = 0; i < numItems; ++i)
    {
        getline (reading, line);
        
        if (numLine < numItems)
        {
            continue;
        }
        else if (numLine == numItems)
        {
            item = atof(line.c_str()); //convert string to float
            numLine++;
        }
        else //greater than numItems, exit program
        {
            cout << "INVALID FORMAT: Number of items declared to be sorted does not match number of items present." << numItems << ""<< numLine << endl;
            exit(0);
        }
        bubbleSortArray[i] = item;
        insertionSortArray[i] = item;
        quickSortArray[i] = item;
        shellSortArray[i] = item;
    }
    runtime();
}
void Algorithms:: bubbleSort(double array[])
{
    for (int i = 0; i < numItems; ++i)
    {
        double temp = 0;
        for (int j=i; j<numItems-1; ++j)
        {
            if (array[j] > array [j+1])
            {
                temp = array [j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void Algorithms:: insertionSort(double array[])
{
    for (int i = 1; i < numItems; ++i) //marker
    {
        double temp = array[i]; //store marked item
        int marker = i; //where to start shifting
        while (marker > 0 && array[i-1] >= temp) //while the thing to the left is larger, shift
        {
            array[i] = array[i-1];
            --marker;
        }
        array[marker] = temp; // put marked item in right spot
    }
}

void Algorithms:: quickSort(double array[], int lo, int hi)
{
    int marker = merge(array, lo, hi);
    if(lo < marker - 1)
    {
        quickSort(array, lo, marker - 1);
    }
    if(hi > marker)
    {
        quickSort(array, marker, hi);
    }
}

int Algorithms:: merge(double array[], int lo, int hi)
{
    int pivot = array[(lo + hi) / 2];
    
    while (lo <= hi)
    {
        while (array[lo] < pivot) //low end
        {
            lo++;
        }
        while (array[hi] > pivot) //high end
        {
            hi--;
        }
        if (lo <= hi) //swap low and high
        {
            double temp = array[lo];
            array[lo] = array[hi];
            array[hi] = temp;
            lo++;
            hi--;
        }
    }
    return lo;
}
void Algorithms::shellSort(double array[])
{
    for (int gap = numItems/2; gap > 0; gap /= 2) //setting and reducing gap
    {
        for (int i = gap; i < numItems; ++i)
        {
            double temp = array[i];
            for (int j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
                array[j] = temp;
            }
        }
    }
}

void Algorithms::runtime()
{
    clock_t startTime;
    clock_t endTime;
    float runTime;
    
    cout << "\nRUNTIMES TO SORT " <<numItems<<" ITEMS: \n"<<endl;
    /*------------------------bubble sort------------------------*/
    startTime = clock();
    bubbleSort(bubbleSortArray);
    endTime = clock();
    runTime = (float(endTime - startTime)/CLOCKS_PER_SEC) * 1000;
    cout << "\tBubble Sort: " << runTime << "ms" <<endl;
    
    /*------------------------insertion sort------------------------*/
    startTime = clock();
    insertionSort(insertionSortArray);
    endTime = clock();
    runTime = (float(endTime - startTime)/CLOCKS_PER_SEC) * 1000;
    cout << "\tInsertion Sort: " << runTime << "ms" <<endl;
    
    /*------------------------quick sort------------------------*/
    startTime = clock();
    quickSort(quickSortArray, 0, numItems-1);
    endTime = clock();
    runTime = (float(endTime - startTime)/CLOCKS_PER_SEC) * 1000;
    cout << "\tQuick Sort: " << runTime << "ms" <<endl;
    
    /*------------------------shell sort------------------------*/
    startTime = clock();
    shellSort(shellSortArray);
    endTime = clock();
    runTime = (float(endTime - startTime)/CLOCKS_PER_SEC) * 1000;
    cout << "\tShell Sort: " << runTime << "ms" <<endl;
    
    cout <<"\nEND PROGRAM\n"<<endl;
}

