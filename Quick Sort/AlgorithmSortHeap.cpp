#include "AlgorithmSortHeap.h"

AlgorithmSortHeap :: AlgorithmSortHeap(int k) : SelectionAlgorithm(k) { this-> k = k; }

int AlgorithmSortHeap :: select()
{
    BinaryHeap *binaryHeap = new BinaryHeap(k);

    int number = 0;
    int input = 0;
    cin >> input;
    
    int i=0;
    while(i<k)
    {
        cin >> number;
        binaryHeap->insert(number);
        ++i;
    }

    for (int j=0; j<input-k; ++j)
    {
        cin >> number;
        if (number > binaryHeap->getMin())
        {
            binaryHeap->deleteMin();
            binaryHeap->insert(number);
        }
    }

    int output = binaryHeap->getMin();
    delete binaryHeap;
    return output;
}