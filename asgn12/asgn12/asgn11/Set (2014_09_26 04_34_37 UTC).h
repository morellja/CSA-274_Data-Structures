// Jared Morell
// Dr. Gannod
// CSA 274 A
// Asgn 12 - Set.h

#pragma once
#include "Bag.h"
#include <iostream>

template <class T>
class Set:public Bag<T>{

public:
	// Constructor/Destructor
	Set(void);
	Set(const Set<T> &);
	~Set(void);
	// Set operation
	bool memberOf(T);
	virtual void add(T);  // resets iterator
	void del(T);  // resets iterator
	int size(void);
	// Iterator operations
	void reset(void);
	bool hasNext(void);
	const T& next(void);

private:
	Bag<T> *bag1; // Bag instance

protected:
	// DON'T KNOW HOW TO USE THIS
	friend ostream& operator << (ostream& o, Bag<T> &b){
		o << "Bag: ";
		o << *b.bag;
		return o;
	}
};

// Constructor for the class. Creates a new bag object
template <class T>
Set<T>::Set(){
	bag1 = new Bag<T>();
}


// Also deletes the bag instance
template <class T>
Set<T>::~Set(){
	Bag<T>::~Bag();
	delete bag1;
}

// Adds element to set if the element is not already a member of the set
template <class T>
void Set<T>::add(T e){
	if(!bag1->memberOf(e))
		bag1->add(e);
}