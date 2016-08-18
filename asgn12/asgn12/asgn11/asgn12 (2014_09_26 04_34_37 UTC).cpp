// asgn11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bag.h"
#include "Set.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{

	Bag<int> *bag = new Bag<int>();
	bag->add(5);
	int x = 10;
	bag->add(x);
	Set<int> *set = new Set<int>();
	set->add(5);
	set->add(5);
	set->add(x);
	set->add(15);
	set->add(12);
	while (set->hasNext()){
		cout << set->next() << endl;
	}
	set->del(12);
	cout << *set << ":" << set << endl;
	Set<int> s(*set);
	cout << s << ":" << &s << endl;



	return 0;
}

