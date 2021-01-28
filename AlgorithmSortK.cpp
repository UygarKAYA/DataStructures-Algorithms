#include "AlgorithmSortK.h"

AlgorithmSortK :: AlgorithmSortK(int k) : SelectionAlgorithm(k) { this->k = k; } 

int AlgorithmSortK :: select()
{
    int NumberofElements = 0, value = 0;
    std::cin >> NumberofElements;

    int* array = new int[k];

    for(auto i=0; i<k; ++i)
    {
        std::cin >> value;
        array[i] = value;
    }

    for(auto i=1; i<k; ++i)
    {
        auto key = array[i];
        auto j = i-1;

        while(j>=0 && key > array[j])
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    for(int i=0; i<NumberofElements-k; ++i)
    {
        auto number = 0;
        std::cin >> number;

        if(array[k-1] < number)
        {
            for(int j=0; j<k; ++j)
            {
                if(array[j] < number)
                {
                    for(int z = k-1; z >= j; --z)
                    {
						array[z] = array[z-1];
					}
					array[j] = number;
					break;
                }
            }
        }
    }
    
    int result = array[k-1];
    delete[] array;
    return result;
}