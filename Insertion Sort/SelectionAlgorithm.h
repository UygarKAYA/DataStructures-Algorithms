#ifndef _SelectionAlgorithm_
#define _SelectionAlgorithm_

#include <iostream>

class SelectionAlgorithm
{
    public:
        virtual int select();
        SelectionAlgorithm(int);
    protected:
        int k;
};

#endif