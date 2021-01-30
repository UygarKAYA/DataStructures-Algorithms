#ifndef _Stack_
#define _Stack_

#include "StackItem.h"
#include <iostream>

using namespace std;

class Stack
{ 
    private:
        StackItem* head;   
    public:
        Stack();
        ~Stack();
        void push(StackItem*);
        StackItem* pop();
        StackItem* top();
        bool isEmpty();           
};

#endif