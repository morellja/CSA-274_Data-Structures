// Jared Morell
// Dr. Gannod
// CSA 274 A
// Set.h

#pragma once
#include "Bag.h"

template <class T>
class Set : public Bag<T>
{
public:

	Set(void) : Bag() { }

	Set(Set &s) : Bag((Bag<T> &)s) { }

	void add(T obj){
		if (!memberOf(obj)){
			Bag<T>::add(obj);
		}
	}

protected:
	friend ostream& operator << (ostream &o, Set &set){
		o << "Set: ";
		o << ((Bag &)set);
		return o;
	}
	
	// sets the '+' operator to get the union of two sets
	friend Set<T> & operator +(Set<T> &set0, Set<T> &set1){
		Set<T> *setZero = new Set<T>(set0);
		Set<T> *setOne = new Set<T>(set1);
		Set<T> *retSet0 = new Set<T>();
		setZero->reset();
		setOne->reset();
		while(setZero->hasNext()){
			retSet0->add(setZero->next());
		}
		while(setOne->hasNext()){
			retSet0->add(setOne->next());
		}
		delete setZero;
		delete setOne;
		return *retSet0;
	}

	// sets the '*' operator to get the intersection of two sets
	friend Set<T> & operator *(Set<T> &set0, Set<T> &set1){
		Set<T> *setZero = new Set<T>(set0);
		Set<T> *setOne = new Set<T>(set1);
		Set<T> *retSet1 = new Set<T>();
		setZero->reset();
		setOne->reset();
		while(setZero->hasNext()){
			T el = setZero->next();
			if(setOne->memberOf(el)){
				retSet1->add(el);
			}
		}
		delete setZero;
		delete setOne;
		return *retSet1;
	}

	// sets the '-' operator to get the subtraction of two sets
	friend Set<T> & operator -(Set<T> &set0, Set<T> &set1){
		Set<T> *setZero = new Set<T>(set0);
		Set<T> *setOne = new Set<T>(set1);
		Set<T> *retSet2 = new Set<T>(set0);
		setZero->reset();
		setOne->reset();
		while(setZero->hasNext()){
			T el = setZero->next();
			if(setOne->memberOf(el)){
				retSet2->del(el);
			}
		}
		delete setZero;
		delete setOne;
		return *retSet2;
	}
};