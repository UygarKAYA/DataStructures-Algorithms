#ifndef _AlgorithmSortK_
#define _AlgorithmSortK_

#include <iostream>
#include "SelectionAlgorithm.h"

class AlgorithmSortK : public SelectionAlgorithm
{
    public:
        int select();
        AlgorithmSortK(int);
};

#endif