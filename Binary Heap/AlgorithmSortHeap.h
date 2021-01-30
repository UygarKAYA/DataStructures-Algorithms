#ifndef _AlgorithmSortHeap_
#define _AlgorithmSortHeap_

#include "SelectionAlgorithm.h"
#include "BinaryHeap.h"

#include<iostream>
using namespace std;

class AlgorithmSortHeap : public SelectionAlgorithm
{
    public:
        AlgorithmSortHeap(int);
        int select();
};

#endif