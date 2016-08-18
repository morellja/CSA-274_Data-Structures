// Jared Morell
// Dr. Gannod
// CSA 274 A
// Stack.h

#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <class T>
class Stack{

public:
	Stack(void);
	virtual ~Stack(void);
	bool isEmpty(void);
	int size(void);
	T& top(void);
	T& push(T&);
	T& pop(void);
private:
	GannodList<T> *st;
	int count;
protected:
	friend ostream& operator<< (ostream& o, Stack<T> &list){
		o << *(list.st);
		return o;
	}
};

template <class T>
Stack<T>::Stack(){
	 st = new GannodList<T>;
	 count = 0;
}

template <class T>
Stack<T>::~Stack(){
	st->~GannodList();
}

template <class T>
bool Stack<T>::isEmpty(){
	return st->isEmpty();
}

template <class T>
int Stack<T>::size(){
	return count;
}

template <class T>
T& Stack<T>::top(){
	if(st->isEmpty())
		throw "Empty stack exception";
	return st->peekHead();
}

template <class T>
T& Stack<T>::push(T& e){
	count++;
	st->addToHead(e);
	return e;
}

template <class T>
T& Stack<T>::pop(){
	if(st->isEmpty())
		throw "Empty stack exception";
	count--;
	return st->deleteFromHead();
}