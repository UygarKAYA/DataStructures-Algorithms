#include "AlgorithmSortQuick.h"

#include <iostream>
using namespace std;

AlgorithmSortQuick :: AlgorithmSortQuick(int k) : SelectionAlgorithm(k) { this->k = k; }

int AlgorithmSortQuick :: select()
{
    int number = 0;
	cin >> number;

	int* NumArray = new int[number];

    int i = 0;
    while(i<number)
    {
        cin >> NumArray[i];
        ++i;
    }

	int output = quickselect(NumArray, 0, number-1, k);
	delete[] NumArray;
	return output;
}

int AlgorithmSortQuick :: quickselect(int* numbers, int left, int right, int k)
{	
	if ((right - left) < 10)
	{
		for(int i = left+1; i < right; ++i) 
		{
            while (i > left && numbers[i] > numbers[i-1]) 
			{
                int temp = numbers[i-1];
                numbers[i-1] = numbers[i];
                numbers[i] = temp;
                --i;
            }
        }
        return numbers[left + k-1];
	}
	else
	{
		if (numbers[left] < numbers[right])
			swap(left, right, numbers);
		if (numbers[left] < numbers[(right+left)/2])
			swap(left, (right+left)/2, numbers);
		if (numbers[(right+left)/2] < numbers[right])
			swap((right+left)/2, right, numbers);
		
		swap((right+left)/2, right-1, numbers);

		int i = left, j = right-1;
		int pivot = numbers[right-1];
		
		for (; ; ) 
		{
			while(numbers[++i] > pivot) {}
			while(pivot > numbers[--j]) {}
			if (i < j)
				swap(i,j, numbers);
			else
				break;
		}
		
		swap(i, right-1, numbers);
		int lenght = i-left+1;

		if (k == lenght)
			return numbers[i];
		else if (k < lenght)
			return quickselect(numbers, left, i , k);
		else
			return quickselect(numbers, i+1, right, k-lenght);
	}
}

void AlgorithmSortQuick::swap(int x, int y, int* numbers) 
{
	int temp = numbers[x];
	numbers[x] = numbers[y];
	numbers[y] = temp;
}