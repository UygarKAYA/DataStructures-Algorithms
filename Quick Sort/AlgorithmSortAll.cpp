#include "AlgorithmSortAll.h"

AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k) { this->k = k; }

int AlgorithmSortAll::select()
{
    int numOfElements, value;
    cin >> numOfElements;

    int *arr = new int [numOfElements];

    int i=0; 
    while (i<numOfElements) 
    {
        cin>> value;
        arr[i] = value;
        i++;
    }

    int cell, index;

    int j=1;
    while (j<numOfElements) 
    {  
        cell = arr[j];  
        index = j-1;  
  
        while (index >= 0 && arr[index] > cell) 
        {  
            arr[index+1] = arr[index];  
            index -= 1;  
        }  
        arr[index+1] = cell;  
        j++;
    }

    int output = arr[k];
    delete[] arr;
    return output;
}