#include "TestBed.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include "AlgorithmSortHeap.h"
#include "AlgorithmSortQuick.h"
#include <ctime>

void TestBed::execute()
{
// Time stamp before the computations
clock_t start = clock();
int expectedResult = algorithm->select();
// Time stamp after the computations
clock_t end = clock();
double cpu_time = static_cast<double>( end - start ) /CLOCKS_PER_SEC;

cout << "Result: " << expectedResult << endl;
cout << "Duratation (sec): " << cpu_time << endl; 
}

void TestBed::setAlgorithm(int AlgorithmType, int k) 
{
    if (AlgorithmType == 1) 
        algorithm = new AlgorithmSortAll(k);

    else if (AlgorithmType == 2)
        algorithm = new AlgorithmSortK(k);

    else if (AlgorithmType == 3)
        algorithm = new AlgorithmSortHeap(k);

    else if (AlgorithmType == 4)
        algorithm = new AlgorithmSortQuick(k);
}

TestBed::TestBed() { }
TestBed::~TestBed() { delete algorithm; }