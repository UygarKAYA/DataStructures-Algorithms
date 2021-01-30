#ifndef _SelectionAlgorithm_
#define _SelectionAlgorithm_

#include <iostream>
using namespace std;

class SelectionAlgorithm 
{
    public:
        virtual int select();
        SelectionAlgorithm(int);
    protected:
        int k;    
};

#endif 