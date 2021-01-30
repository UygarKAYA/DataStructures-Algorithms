#include "Calculator.h"
#include <algorithm>

Calculator::Calculator(string infixExp) 
{
	reverse(infixExp.begin(), infixExp.end());
	infixExp += " ;";
	infixExpression = infixExp;
	stack = new Stack();

	for (int i=0; i<infixExpression.size(); i++) 
	{
		if (infixExpression[i] == '(')
			infixExpression[i] = ')';
		else if (infixExpression[i] == ')')
			infixExpression[i] = '(';
	}

	istringstream istrstrm(infixExpression);
	string element;
	istrstrm >> element;
	istrstrm >> element;
	while (element.compare(";") != 0)
	{
		StackItem* item = new StackItem(element);
		if (!(item->isOperator))
			prefixExpression += element + " ";	

		else if (item->isOperator)
		{
			if (stack->isEmpty())
				stack->push(item);
			else
			{
				if (item->op == 0)
					stack->push(item);
				else if (item->op == 1) 
				{
					while (!(stack->isEmpty()))
					{
						if(stack->top()->op == 0) 
							break;
						else
						{
							StackItem* temp_stackItem = stack->pop();
							prefixExpression += temp_stackItem->toString() + " ";
							delete temp_stackItem;
						}
					}
					stack->pop();
				}
				else if (item->op == 5 || item->op == 4)
				{
					while (!(stack->isEmpty()))
					{
						if (stack->top()->op == 0 || stack->top()->op == 2 || stack->top()->op == 3) 
							break; 
						else
						{
							StackItem* temp_stackItem = stack->pop();
							prefixExpression += temp_stackItem->toString() + " ";
							delete temp_stackItem;
						}
					}
					stack->push(item);
				}
				else if (item->op == 3 || item->op == 2)
				{
					while (!(stack->isEmpty()))
					{
						if (stack->top()->op == 0) 
							break;
						else
						{
							StackItem* temp_stackItem = stack->pop();
							prefixExpression += temp_stackItem->toString() + " ";
							delete temp_stackItem;
						}	
					}
					stack->push(item);
				}
			}
		}		
		istrstrm >> element;
	}
	if (!(stack->isEmpty()))
	{
		while (!(stack->isEmpty()))
		{
			StackItem* temp_stackItem = stack->pop();
			prefixExpression += temp_stackItem->toString() + " ";
			delete temp_stackItem;
		}
	}
	reverse(prefixExpression.begin(), prefixExpression.end()); 
	prefixExpression += " ;";
}

int Calculator::calculate() 
{
	reverse(prefixExpression.begin(), prefixExpression.end());
	prefixExpression += " ;";
	istringstream istrstrm(prefixExpression);
	string element;
	istrstrm >> element;
	istrstrm >> element;
	while (element.compare(";") != 0) 
	{
		StackItem* item = new StackItem(element);
		if (!(item->isOperator))
			stack->push(item);
		else
		{
			int number1 = stack->pop()->n;
			int number2 = stack->pop()->n;
		
			if (item->op == 5) 
			{
				int multi_Value = (number1 * number2);
				StackItem* stack_item = new StackItem(to_string(multi_Value));
				stack->push(stack_item);
			}
			else if (item->op == 4)
			{
				int div_Value = (number1 / number2); 
				StackItem* stack_item = new StackItem(to_string(div_Value));
				stack->push(stack_item);
			}
			else if (item->op == 3) 
			{
				int addition_Value = (number1 + number2);
				StackItem* stack_item = new StackItem(to_string(addition_Value));
				stack->push(stack_item);
			}
			else if (item->op == 2) 
			{
				int sub_Value = (number1 - number2);
				StackItem* stack_item = new StackItem(to_string(sub_Value));
				stack->push(stack_item);
			}
		}
		istrstrm >> element;
	}
	return stack->pop()->n;
}
string Calculator::getPrefix() { return prefixExpression; }
Calculator :: ~Calculator() { delete stack; }