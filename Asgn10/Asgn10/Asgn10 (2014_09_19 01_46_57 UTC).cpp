// Asgn10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "------Stack------" << endl;

	Stack <int> *stack = new Stack<int>();
	stack->push(*(new int(5)));
	stack->push(*(new int(13)));
	cout << "Top: " << stack->top() << endl;
	cout << "Size: " << stack->size() << endl;
	stack->push(*(new int(7)));
	stack->push(*(new int(34)));
	cout << "Size: " << stack->size() << endl;

	cout << *stack << endl;

	try{
		cout << stack->pop() << endl;
		cout << stack->pop() << endl;
		cout << stack->pop() << endl;
		cout << "Here is my stack now: " << *stack << endl;
		cout << "Size: " << stack->size() << endl;
		cout << stack->pop() << endl;
	}catch(char *s){
		cout << s << endl;
	}

	cout << "------Queue------" << endl;
	
	Queue <char> *queue = new Queue<char>();
	queue->enQueue(*(new char('5')));
	queue->enQueue(*(new char('n')));
	cout << "Peek: " << queue->peek() << endl;
	cout << "Size: " << queue->size() << endl;
	queue->enQueue(*(new char('J')));
	queue->enQueue(*(new char('6')));
	cout << "Size: " << queue->size() << endl;

	cout << *queue << endl;

	try{
		cout << queue->deQueue() << endl;
		cout << queue->deQueue() << endl;
		cout << queue->deQueue() << endl;
		cout << "Here is my queue now: " << *queue << endl;
		cout << "Size: " << queue->size() << endl;
		cout << queue->deQueue() << endl;
		cout << queue->deQueue() << endl;
	}catch(char *s){
		cout << s << endl;
	}

	return 0;
}

