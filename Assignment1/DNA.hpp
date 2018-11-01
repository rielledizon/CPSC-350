//
//  DNA.hpp
//  Assignment1
//
//  Created by Rielle Dizon on 2/11/18.
//  Copyright © 2018 Rielle Dizon. All rights reserved.
//

#ifndef DNA_hpp
#define DNA_hpp

#include <iostream>

using namespace std;

class DNA
{
private:
    
    string line;
    
    string dnaPrint;
    
    int charCount, lineCount, squaredUsed;
    double mean, variance, stdDev;
    
    int countA, countT, countC, countG;
    
    int bigramAA, bigramAT, bigramAC, bigramAG;
    int bigramTA, bigramTT, bigramTC, bigramTG;
    int bigramCA, bigramCT, bigramCC, bigramCG;
    int bigramGA, bigramGT, bigramGC, bigramGG;
    
    double probA, probT, probC, probG;
    
    double probAA, probAT, probAC, probAG;
    double probTA, probTT, probTC, probTG;
    double probCA, probCT, probCC, probCG;
    double probGA, probGT, probGC, probGG;
    
public:
    DNA();
    ~DNA();
    string calculations (string fileName);
    string generateDNA(string fileName);
};
#endif /* DNA_hpp */
