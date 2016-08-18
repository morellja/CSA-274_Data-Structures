#pragma once

// Name: Stack class
// This class implements the following operations:
// bool isEmpty()
// int size()
// T& top();
// T& push(T& e);
// T& pop();
// 
// The class is templated and uses the GannodList class
// as the underlying implementation
#include "List.h"

template <class T>
class Stack
{
public:
	Stack(void) { theStack = new GannodList<T>(); count = 0; }
	
	virtual ~Stack(void) { delete theStack; }
	
	bool isEmpty(void) { return (*theStack).isEmpty(); }
	
	T& top(void) { 
		if (isEmpty())
			throw "Stack underflow exception";
		else
			return (*theStack).peekHead(); 
	}

	T& pop(void) { 		
		if (isEmpty())
			throw "Stack underflow exception";
					
		T& ret = (*theStack).peekHead(); 
		(*theStack).deleteFromHead();
		count = count - 1;
		return ret;
	}

	T& push(T& el) {

		(*theStack).addToHead(el);
		count = count + 1;
		T& ret = (*theStack).peekHead(); 
		return ret;
	}

	int size(void) {

		return count;
	}

protected:
	friend ostream& operator << (ostream& o, Stack<T> &st){

		o << *(st.theStack);
		return o;
	}

private:
	GannodList<T> *theStack;
	int count;
};
