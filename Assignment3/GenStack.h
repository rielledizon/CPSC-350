/*
 Rielle Dizon
 2282971
 dizon110@mail.chapman.edu
 CPSC 350-02
 Assignment 3 - Syntax Checker
 
 GenStack.h – general stack implementation for any data type
 */

#ifndef GenStack_h
#define GenStack_h

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class GenStack
{
public:
    GenStack();
    GenStack(int maxSize); //overloaded constructor
    ~GenStack();
    
    void push (T data);
    T pop ();
    T& peek();
    
    bool isFull();
    bool isEmpty();
    
    int top;
    int max;
    T *myArray;
    
};
template <typename T>
GenStack<T>::GenStack() //default constructor
{
    
}
template <typename T>
GenStack<T>::GenStack(int maxSize) //overloaded constructor
{
    myArray = new T[maxSize];
    max = maxSize;
    top = -1;
}
template <typename T>
GenStack<T>::~GenStack()
{
    //delete array
    delete [] myArray;
    myArray = NULL;
    max = 0;
    top = -1;
}
template <typename T>
void GenStack<T>::push(T data)
{
    if (isFull()){
        T* temp = new T[max*2];
        for (int i =0; i<max; ++i){
            temp[i] = myArray[i];
        }
        myArray = temp;
    }
    myArray[++top] = data;
}
template <typename T>
T GenStack<T>::pop()
{
    if (isEmpty()){
        throw ("Stack is empty");
    }
    return myArray[top--];
}
template <typename T>
T& GenStack<T>::peek()
{
    return myArray[top];
}
template <typename T>
bool GenStack<T>::isFull()
{
    return (max-1 == top);
}
template <typename T>
bool GenStack<T>::isEmpty()
{
    return (top == -1);
}
#endif /* GenStack_h */
