#ifndef _TestBed_
#define _TestBed_

#include <iostream>
#include "SelectionAlgorithm.h"

class TestBed
{
    public:
        TestBed();
        ~TestBed();
        void execute();
        void setAlgorithm(int, int);
    private:
        SelectionAlgorithm* algorithm;
};

#endif