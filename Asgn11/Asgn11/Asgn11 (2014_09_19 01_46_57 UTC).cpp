// Asgn11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Queue <int> *queue = new Queue<int>();
	
	cout << "--Enqueue--" << endl;
	
	cout << queue->enQueue(*(new int(1))) << endl;
	cout << queue->enQueue(*(new int(2))) << endl;
	cout << "Peek: " << queue->peek() << endl;
	cout << "Size: " << queue->size() << endl;
	cout << queue->enQueue(*(new int(3))) << endl;
	cout << queue->enQueue(*(new int(4))) << endl;
	cout << "Size: " << queue->size() << endl;

	cout << *queue << endl;
	
	cout << "--Dequeue--" << endl;

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

