#ifndef _StackItem_
#define _StackItem_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// constant definitions for operator types
#define OPERATOR_LEFTPAR		0
#define OPERATOR_RIGHTPAR		1
#define OPERATOR_MINUS			2
#define OPERATOR_PLUS			3
#define OPERATOR_DIVISION		4
#define OPERATOR_MULTIPLICATION 5

class StackItem
{
    private:
        void init(bool, int); 
        
    public:
        bool isOperator;
        int op;
        int n;
        StackItem* next;

        StackItem(bool, int);
        StackItem(string);
        string toString();
};

#endif