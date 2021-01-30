#include "Stack.h"

Stack :: Stack() { head = NULL; }
Stack :: ~Stack() { delete head; }

bool Stack :: isEmpty() { return (head == NULL); }

void Stack :: push(StackItem* item)
{
    if (item->isOperator) 
    {
		StackItem* temp_item = new StackItem(true, item -> op);
		temp_item -> op = item -> op;
		temp_item -> next = head;
		head = temp_item;
	}
	else
	{
		StackItem* temp_item = new StackItem(false, item -> op);
		temp_item -> n = item -> n;
		temp_item -> next = head;
		head = temp_item;
	}
}

StackItem* Stack :: pop()
{
    StackItem *temp_stack = head;
    if (head == NULL) 
        cout << "\nStack is empty";
    else
    {
        head = head -> next;
        temp_stack -> next = NULL;
    }
    return temp_stack;
}

StackItem* Stack :: top()
{  
    if (!isEmpty())
        return head; 
    else 
        return 0; 
}