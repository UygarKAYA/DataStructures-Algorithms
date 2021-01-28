#include "AlgorithmSortAll.h"

AlgorithmSortAll :: AlgorithmSortAll(int k) : SelectionAlgorithm(k) { this->k = k; }

int AlgorithmSortAll :: select()
{
    int NumberofElements = 0, value = 0;
    std::cin >> NumberofElements;

    int* array = new int[NumberofElements];

    for(auto i=0; i<NumberofElements; ++i)
    {
        std::cin >> value;
        array[i] = value;
    }

    for(auto i=1; i<NumberofElements; ++i)
    {
        auto key = array[i];
        auto j = i-1;

        while(j>=0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    
    auto result = array[k];
    delete[] array;
    return result;
}