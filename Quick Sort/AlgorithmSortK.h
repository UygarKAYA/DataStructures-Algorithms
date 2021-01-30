#ifndef _AlgorithmSortK_
#define _AlgorithmSortK_

#include <iostream>
#include "SelectionAlgorithm.h"

using namespace std;

class AlgorithmSortK : public SelectionAlgorithm
{
    public:
        int select();
        AlgorithmSortK(int);
};

#endif 