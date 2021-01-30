#ifndef _AlgorithmSortQuick_
#define _AlgorithmSortQuick_

#include "SelectionAlgorithm.h"

class AlgorithmSortQuick : public SelectionAlgorithm
{
    public:
        AlgorithmSortQuick(int);
        int select();
        int quickselect(int*, int, int, int);
        void swap(int, int, int*);
};

#endif