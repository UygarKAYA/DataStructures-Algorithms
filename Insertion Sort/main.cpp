//  Created by Uygar KAYA on 30.10.2020.

#include <iostream>
#include <string>
#include <fstream>

#include "TestBed.h"

int main(int argc, char *argv[]) {

	std::string testfile;

	if (argc < 2) 
    	{
		std::cout << "Enter a test file name:" << std::endl;
		std::cin >> testfile;
	}
	else 
        	testfile = argv[1];

	std::ifstream file(testfile.c_str());
	if (file.is_open())
		std::cin.rdbuf(file.rdbuf());
	else 
    	{
		std::cout << "Error: cannot read the test file!" << std::endl;
		return -1;
	}

	int algorithmType = 0;
	int k = 0;
	
	// Numbers are obtained from the file line by line with cin
    	std::cin >> algorithmType; 
	std::cin >> k;
	
	// Create a TestBed object, initialize and execute the algorithm
	TestBed* testbed = new TestBed();
	testbed->setAlgorithm(algorithmType, k);
	testbed->execute();
	delete testbed;
	//testbed->~TestBed();

	return 0;
}
