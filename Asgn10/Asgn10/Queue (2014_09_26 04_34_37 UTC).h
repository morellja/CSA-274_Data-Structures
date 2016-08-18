// Jared Morell
// Dr. Gannod
// CSA 274 A
// Queue.h

#pragma once
#include <iostream>
#include "List.h"
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
	GannodList<T> *qu;
	int count;
protected:
	friend ostream& operator<< (ostream& o, Queue<T> &list){
		o << *(list.qu);
		return o;
	}
};

template <class T>
Queue<T>::Queue(){
	 qu = new GannodList<T>;
	 count = 0;
}

template <class T>
Queue<T>::~Queue(){
	qu->~GannodList();
}

template <class T>
bool Queue<T>::isEmpty(){
	return qu->isEmpty();
}

template <class T>
int Queue<T>::size(){
	return count;
}

template <class T>
T& Queue<T>::peek(){
	if(qu->isEmpty())
		throw "Empty queue exception";
	return qu->peekTail();
}

template <class T>
T& Queue<T>::enQueue(T& e){
	count++;
	qu->addToHead(e);
	return e;
}

template <class T>
T& Queue<T>::deQueue(){
	if(qu->isEmpty())
		throw "Empty queue exception";
	count--;
	return qu->deleteFromTail();
}