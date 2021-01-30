#ifndef _AlgorithmSortAll_
#define _AlgorithmSortAll_

#include <iostream>
#include "SelectionAlgorithm.h"

using namespace std;

class AlgorithmSortAll : public SelectionAlgorithm
{
    public:
        int select();
        AlgorithmSortAll(int); 
};

#endif 