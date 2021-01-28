#ifndef _Node_
#define _Node_

#include <iostream> 
using namespace std;

class Node
{
    public:
        Node(int);
        int data;
        Node *next;
};

#endif