// Jared Morell
// Dr. Gannod
// CSA 274 A
// Queue.h

#pragma once
#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
class Queue{

public:
	Queue(void);
	virtual ~Queue(void);
	bool isEmpty(void);
	int size(void);
	T& peek(void);
	T& enQueue(T&);
	T& deQueue(void);
private:
	Stack<T> *output; //stack from which elements are deQueued
	Stack<T> *input; //stack from which elements are enQueued
protected:
	friend ostream& operator<< (ostream& o, Queue<T> &list){
		o << *(list.input);
		return o;
	}
};

// Name of Method : Queue
// Description : constructor for class, creates 2 new stacks, output and input
// Parameters : 
// Return Value : 
template <class T>
Queue<T>::Queue(){
	 output = new Stack<T>;
	 input = new Stack<T>;
}

// Name of Method : ~Queue
// Description : destructor for class
// Parameters : 
// Return Value : 
template <class T>
Queue<T>::~Queue(){
	output->~Stack();
	input->~Stack();
}

// Name of Method : isEmpty
// Description : checks if Queue is empty
// Parameters : 
// Return Value	: boolean value 
template <class T>
bool Queue<T>::isEmpty(){
	return input->isEmpty();
}

// Name of Method : size
// Description : returns number of elements in the queue
// Parameters : 
// Return Value : an int, the number of elements
template <class T>
int Queue<T>::size(){
	return input->size();
}

// Name of Method : peek
// Description : returns the element at the front of the queue
// Parameters : 
// Return Value : the element at the front of the queue
template <class T>
T& Queue<T>::peek(){
	if(input->isEmpty())
		throw "Empty queue exception";
	
	while(!input->isEmpty()){
		output->push(input->pop());
	}
	
	T& ret = output->top();
	
	while(!output->isEmpty()){
		input->push(output->pop());
	}
	return ret;
}

// Name of Method : enQueue
// Description : adds an element to the back of the queue
// Parameters : the element to be added
// Return Value : the element that was added
template <class T>
T& Queue<T>::enQueue(T& e){
	input->push(e);
	return e;
}

// Name of Method : deQueue
// Description : removes and returns the element at the front of the queue
// Parameters : 
// Return Value : the element that was removed
template <class T>
T& Queue<T>::deQueue(){
	if(input->isEmpty())
		throw "Empty queue exception";
	
	while(!input->isEmpty()){
		output->push(input->pop());
	}
	
	T& ret = output->pop();
	
	while(!output->isEmpty()){
		input->push(output->pop());
	}
	return ret;
}