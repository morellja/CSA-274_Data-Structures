// Jared Morell
// Dr. Gannod
// CSA 274 A
// Bag.h

#pragma once
#include "List.h"

template <class T>
class Bag {

public:
	Bag(void) {
		bag = new GannodList<T>();
	}

	Bag(const Bag<T> &b1){
		bag = &(b1.bag->clone());
	}

	~Bag(void){
		delete bag;
	}

	bool memberOf(T e){
		bag->reset();
		bool result = false;
		while (bag->hasNext()){
			if (bag->next() == e){
				result = true;
			}
		}
		return result;
	}

	virtual void add(T e){
		T *newt = new T(e);
		bag->addToHead(*newt);
		this->reset();
	}

	void del(T e){
        bag->deleteNode(e);
	}

	int size(void){
		return bag->size();
	}

	int countOccurrences(T e){
		int result = 0;
		bag->reset();
		while (bag->hasNext()){
			if (bag->next() == e){
				result++;
			}
		}
		return result;
	}

	void reset(void){ bag->reset(); }
	bool hasNext(void){ return bag->hasNext(); }
	const T& next(void){ return bag->next(); }

protected:
	friend ostream& operator << (ostream& o, Bag<T> &b){
		o << "Bag: ";
		o << *(b.bag) << endl;
		return o;
	}

	// sets the '+' operator to get the union of two bags
	friend Bag<T> & operator +(Bag<T> &bag0, Bag<T> &bag1){
		Bag<T> *bagZero = new Bag<T>(bag0); //copy of bag0
		Bag<T> *bagOne = new Bag<T>(bag1); //copy of bag1
		Bag<T> *retBag0 = new Bag<T>();
		bagZero->reset();
		bagOne->reset();
		while(bagZero->hasNext()){
			retBag0->add(bagZero->next());
		}
		while(bagOne->hasNext()){
			retBag0->add(bagOne->next());
		}
		delete bagZero;
		delete bagOne;
		return *retBag0;
	}

	// sets the '*' operator to get the intersection of two bags
	friend Bag<T> & operator *(Bag<T> &bag0, Bag<T> &bag1){
		Bag<T> *bagZero = new Bag<T>(bag0); //copy of bag0
		Bag<T> *bagOne = new Bag<T>(bag1); //copy of bag1
		Bag<T> *retBag1 = new Bag<T>(); 
		bagZero->reset();
		bagOne->reset();
		while(bagZero->hasNext()){
			T el = bagZero->next();
			if(bagOne->memberOf(el)){
				retBag1->add(el);
				bagOne->del(el);
			}
		}
		delete bagZero;
		delete bagOne;
		return *retBag1;
	}

	// sets the '-' operator to get the subtraction of two bags
	friend Bag<T> & operator -(Bag<T> &bag0, Bag<T> &bag1){
		Bag<T> *bagZero = new Bag<T>(bag0); //copy of bag0
		Bag<T> *bagOne = new Bag<T>(bag1); //copy of bag1
		Bag<T> *retBag2 = new Bag<T>(bag0); //copy of bag0
		bagZero->reset();
		bagOne->reset();
		while(bagZero->hasNext()){
			T el = bagZero->next();
			if(bagOne->memberOf(el)){
				retBag2->del(el);
				bagOne->del(el);
			}
		}
		delete bagZero;
		delete bagOne;
		return *retBag2;
	}

private:
	GannodList<T> *bag;
};


