#pragma once
#include "List.h"
#include <iostream>

template <class T>
class Bag {

public:
	// Constructor/Destructor
	Bag(void);
	Bag(const Bag<T> &);
	~Bag(void);
	// Bag operation
	bool memberOf(T);
	virtual void add(T);  // resets iterator
	void del(T);  // resets iterator
	int size(void);
	int countOccurrences(T);
	// Iterator operations
	void reset(void);
	bool hasNext(void);
	const T& next(void);

protected:
	friend ostream& operator << (ostream& o, Bag<T> &b){
		o << "Bag: ";
		o << *b.bag;
		return o;
	}

private:
	GannodList<T> *bag;

};

template <class T>
bool Bag<T>::hasNext(void){
   return bag->hasNext();
}

template <class T>
const T& Bag<T>::next(void){
   return bag->next();
}

template <class T>
void Bag<T>::reset(void){
   bag->reset();
}

template <class T>
Bag<T>::Bag(void){
	bag = new GannodList<T>();
}

template <class T>
Bag<T>::Bag(const Bag<T> &b){
	bag = &(b.bag->clone());  // deep copy
}

template <class T>
Bag<T>::~Bag(void){
	delete bag;
}

template <class T>
bool Bag<T>::memberOf(T e){

	bool result = false;
	bag->reset();
	while(bag->hasNext()){
		if (bag->next() == e)
			result = true;
	}
	return result;

}

template <class T>
void Bag<T>::add(T e){

	T *newt = new T(e);
	bag->addToHead(*newt);
	bag->reset();

}

template <class T>
void Bag<T>::del(T e){

   bag->deleteNode(e);
   bag->reset();

}

template <class T>
int Bag<T>::size(void){

	return bag->size();

}

template <class T>
int Bag<T>::countOccurrences(T e){

	int result = 0;
	bag->reset();
	while (bag->hasNext()){
		if (bag->next() == e)
			result++;
	}
	return result;

}
