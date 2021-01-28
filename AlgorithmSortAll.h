#ifndef _AlgorithmSortAll_
#define _AlgorithmSortAll_

#include <iostream>
#include "SelectionAlgorithm.h"

class AlgorithmSortAll : public SelectionAlgorithm
{
    public:
        int select();
        AlgorithmSortAll(int);
};

#endif