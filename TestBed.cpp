#include "TestBed.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include <ctime>

TestBed :: TestBed() {}
TestBed :: ~TestBed() { delete algorithm; }

void TestBed :: execute()
{
    clock_t start = clock(); // Time stamp before the computations
    auto result = algorithm->select();
    clock_t end = clock(); // Time stamp after the computations
    
    auto cpu_time = static_cast<double>( end - start ) /CLOCKS_PER_SEC;

    std::cout << "Result: " << result << std::endl;
    std::cout << "Duration (sec): " << cpu_time << std::endl;
}

void TestBed :: setAlgorithm(int AlgorithmType, int k)
{
    if (AlgorithmType == 1)
        algorithm = new AlgorithmSortAll(k);
    else if(AlgorithmType == 2)
        algorithm = new AlgorithmSortK(k);    
}