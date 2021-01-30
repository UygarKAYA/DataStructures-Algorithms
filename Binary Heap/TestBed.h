#ifndef _TestBed_
#define _TestBed_

#include <iostream>
#include "SelectionAlgorithm.h"
using namespace std;

class TestBed 
{
    public: 
        void execute();
        void setAlgorithm(int, int);
        TestBed();
        ~TestBed();
    private:
        SelectionAlgorithm *algorithm;
};

# endif