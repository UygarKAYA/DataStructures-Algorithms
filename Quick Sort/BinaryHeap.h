#ifndef _BinaryHeap_
#define _BinaryHeap_

class BinaryHeap {

public:
	BinaryHeap(int); // constructor that takes the capacity of the structure
	~BinaryHeap(); // destructor
	
	void insert(int); // inserts a new element to the heap. 
	// The capacity of the heap is assumed to be fixed.
	// Insert the element if size < capacity
	// Do nothing otherwise.
	
	int deleteMin(); // removes the minimum element from the heap and returns it
	// If the size is less than 1, do nothing and stop

	int getMin(); // returns the minimum element int the heap, returns -1 if the heap is empty

private:
	int *heap; // array to store the elements of the heap
	int size; // keeps the number of elements in the heap
	int capacity; // keeps the total capacity of the heap
	void percolateDown(int);
	void percolateUp(int);
	void swap(int, int);
};

#endif