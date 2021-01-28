#include "LinkedList.h"

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "The Linked List: ";
    list.printList();
    
    return 0;
}