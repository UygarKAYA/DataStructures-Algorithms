#ifndef _LinkedList_
#define _LinkedList_

#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
    public:
        Node* head;

        LinkedList();
        void insert(int);
        void remove(Node*);
        void printList();
        void find(int);
        ~LinkedList();
};

#endif