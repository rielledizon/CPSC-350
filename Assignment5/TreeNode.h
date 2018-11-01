/* Theo Balestra and Rielle Dizon
   Student ID: 2288751 and Student ID: 2282971
   Student Emails: balestra@chapman.edu dizon110@mail.chapman.edu
   CPSC 350-02
   Assignment 5 (BST)

   TreeNode.h - Tree node header
*/

#include <iostream>
#include <stdio.h>
#ifndef TreeNode_h
#define TreeNode_h

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(T data):data(data), left(NULL), right(NULL){}; //constructor
    
    ~TreeNode(){ //destructor
        if(left) left = NULL;
        if(right) right = NULL;
    }
};
#endif /* TreeNode_h */

