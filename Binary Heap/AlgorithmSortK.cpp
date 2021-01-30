#include "AlgorithmSortK.h"

AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k) { this->k = k; }

int AlgorithmSortK::select() 
{
    int numOfElements = 0, value = 0;
    cin >> numOfElements;

    int *arr = new int [k];

    int i=0;
    while (i<k) 
    {
        cin >> value;
        arr[i] = value;
        i++;
    }

    int cell, index;  
    
    int j=1;
    while (j<k) 
    {  
        cell = arr[j];  
        index = j-1;  
  
        while (index >= 0 && cell > arr[index]) 
        {  
            arr[index+1] = arr[index];  
            index -= 1;  
        }  
        arr[index+1] = cell; 
        ++j; 
    }

	for (int x=0; x < numOfElements - k; x++) 
    {
		int num;
		cin >> num;

		if (arr[k-1] < num) 
        {
			for (int y=0; y < k; y++) 
            {
				if (arr[y] < num) 
                {
					for(int z = k-1; z >= y; z--)
                    {
						arr[z] = arr[z-1];
					}
					arr[y] = num;
					break;
				}
			}
		}
	}

	int output = arr[k-1]; 
	delete[] arr;
	return output;
}