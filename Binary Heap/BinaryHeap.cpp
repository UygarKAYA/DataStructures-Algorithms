#include "BinaryHeap.h"
#include <climits>

BinaryHeap :: BinaryHeap(int capacity)
{
    size = 0;
    this->capacity = capacity;
    heap = new int[capacity+1];
}

BinaryHeap :: ~BinaryHeap() { delete[] heap; }

void BinaryHeap :: insert(int element)
{
    if (size < capacity) 
	{
		size++;
		heap[size] = element;
        percolateUp(size);
	}
    return;
}

int BinaryHeap :: deleteMin()
{
    if (size < 1)
        return INT_MAX;
    else
    {
        heap[1] = heap[size];
        --size;
        percolateDown(1);
        return heap[1];
    }
}

int BinaryHeap :: getMin()
{
    if (size < 1)
        return -1;
    return heap[1];
}

void BinaryHeap :: swap(int i, int j)
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void BinaryHeap :: percolateDown(int hole)
{
	if (2*hole > size && 2*hole+1 > size)
		return;
	else if (2*hole <= size && 2*hole+1 > size)
	{
		if (heap[2*hole] <= heap[hole]) 
        {
			swap(2*hole, hole);
			percolateDown(2*hole);
		}
		else
			return;
	}
	else if (2*hole <= size && 2*hole+1 <= size)
	{
		if (heap[2*hole] <= heap[hole] && heap[2*hole+1] > heap[hole])
		{
			swap(2*hole, hole);
			percolateDown(2*hole);
		}
		else if (heap[2*hole] > heap[hole] && heap[2*hole+1] <= heap[hole])
		{
			swap(2*hole+1, hole);
			percolateDown(2*hole+1);
		}
		else if (heap[2*hole] <= heap[hole] && heap[2*hole+1] <= heap[hole])
		{
			if (heap[2*hole] <= heap[2*hole+1])
			{
				swap(2*hole, hole);
				percolateDown(2*hole);
			}
			else
			{
				swap(2*hole+1, hole);
				percolateDown(2*hole+1);
			}
		}
		else
			return;
	}
}

void BinaryHeap :: percolateUp(int hole)
{
    while((heap[hole] < heap[hole/2]) & (hole !=1))
	{
		swap(hole, hole/2);
		hole /= 2;
	}
}