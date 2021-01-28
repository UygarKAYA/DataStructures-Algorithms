#include "LinkedList.h"

LinkedList :: LinkedList() { head = 0;}

void LinkedList :: insert(int data)
{
    Node* node = new Node(data);
    node->data = data;
    node->next = head;
    head = node;
} 

void LinkedList :: remove(Node* currentNode)
{
    Node* dnode = currentNode->next;
    currentNode->next = dnode->next;
    delete dnode;
}

void LinkedList :: printList()
{
    Node* n = head;

    while(n != 0)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void LinkedList :: find(int data)
{
    Node* node = head;

    do 
    {
        if(node->data == data)
            cout << "True which is " << node->data << endl;
        else if (node->data != data)
            cout << "False" << endl;
        node = node->next;
    } while (node != 0);
}

LinkedList :: ~LinkedList()
{
    Node* dnode = head;

    while(dnode != 0)
    {
        head = dnode->next;
        delete dnode;
        dnode = head;
    }
}