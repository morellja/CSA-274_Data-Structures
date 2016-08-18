// asgn11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bag.h"
#include "Set.h"

int _tmain(int argc, _TCHAR* argv[])
{
    Bag<int> *b = new Bag<int>();

	b->add(5);
	b->add(12);
	b->add(25);

	cout << b->memberOf(12) << endl;
	cout << b->memberOf(2) << endl;

	Bag<int> *c = new Bag<int>(*b);

	b->del(12);

	cout << "b: " << *b << endl;
	cout << "c: " << *c << endl;
	
	Bag<int> *d = new Bag<int>();
	*d = *b + *c;
	cout << "d: Union of b and c: " << *d << endl;

	Bag<int> *e = new Bag<int>();
	*e = *b * *c;
	cout << "e: Intersection of b and c: " << *e << endl;

	Bag<int> *f = new Bag<int>();
	*f = *d - *c;
	cout << "f: Subtraction of d and c: " << *f << endl;

	cout << "----------------------------" << endl;

	Set<int> *s = new Set<int>();
	s->add(1);
	s->add(2);
	s->add(4);
	s->add(8);

	cout << "s: " << *s << endl;

	Set<int> *t = new Set<int>();
	t->add(1);
	t->add(3);
	t->add(4);

	cout << "t: " << *t << endl;

	Set<int> *u = new Set<int>();
	*u = *s + *t;
	cout << "u: Union of s and t: " << *u << endl;

	Set<int> *v = new Set<int>();
	*v = *s * *t;
	cout << "v: Intersection of s and t: " << *v << endl;

	Set<int> *w = new Set<int>();
	*w = *s - *t;
	cout << "w: Subtraction of s and t: " << *w << endl;

	return 0;
}

