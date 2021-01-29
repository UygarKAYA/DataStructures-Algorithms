#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() 
{  
    BinarySearchTree bst;
    cout << "Enter a set of numbers (-2 to remove numbers, -1 to stop):" << endl;
    bool insertMode = true;
    int input = 0;
    
    do {
        cin >> input;   
        if (input == -2)
            insertMode = false;
        if (insertMode && input != -1)
            bst.insert(input);
        else
            bst.remove(input);
    } while (input != -1);

    cout << "PreOrder: ";
    bst.printPreorder();
    cout << endl;
    cout << "InOrder: ";
    bst.printInorder();
    cout << endl;
    cout << "PostOrder: ";
    bst.printPostOrder();
    
    return 0; 
}