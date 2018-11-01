/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 5 (BST)

   Student.h - Student header with overloaded operators and student specific methods
*/

#ifndef Student_h
#define Student_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

class Student{
public:
    int studentID;
    int advisorID;
    
    string major;
    string name;
    string level;
    
    double gpa;
    
    //overloaded operators to compare students (usese their ID)
    bool operator == (const Student &other) {return this->studentID == other.studentID;}
    bool operator != (const Student &other) {return this->studentID != other.studentID;}
    bool operator <  (const Student &other) {return this->studentID < other.studentID;}
    bool operator >  (const Student &other) {return this->studentID > other.studentID;}
    
    bool operator == ( const int ID ) { return this->studentID == ID; }
    bool operator != ( const int ID ) { return this->studentID != ID; }
    bool operator <  ( const int ID ) { return this->studentID <  ID; }
    bool operator >  ( const int ID ) { return this->studentID >  ID; }
    
    // Default Constructor
    Student(){
        studentID = 0;
        advisorID = 0;
        major = "unknown";
        name = "unknown";
        level = "unknown";
        gpa = 0.0;
    }
    
    // Constructor that initializes attributes based on given parameters
    Student(int studentID, string name, string level, string major, int advisorID, double gpa){
        this->studentID = studentID;
        this->advisorID = advisorID;
        this->major = major;
        this->name = name;
        this->level = level;
        this->gpa = gpa;
    }
    
    // Stores student info
    Student(string dataRec){
        istringstream data(dataRec);
        data >> studentID >> name >> level >> major >> advisorID >> gpa;
    }
    
    // Destructor
    ~Student(){
        studentID = 0;
        advisorID = 0;
        major = "unknown";
        name = "unknown";
        level = "unknown";
        gpa = 0.0;
    }
    
    void display(){ //displays Student information
        cout << "\nStudent ID..... " << studentID << '\n';
        cout << "Name........... " << name << '\n';
        cout << "Level.......... " << level << '\n';
        cout << "Major.......... " << major << '\n';
        cout << "Advisor ID..... " << advisorID << '\n';
        cout << "GPA............ " << gpa << '\n';
    }
    
    virtual string ToString(){ //print method for Student info
        stringstream s;
        string sep = " ";
        s << studentID << sep << name << sep << level << sep << major << sep << advisorID << sep << gpa << "\n";
        string result = s.str();
        return result;
    }
};

#endif /* Student_h */
