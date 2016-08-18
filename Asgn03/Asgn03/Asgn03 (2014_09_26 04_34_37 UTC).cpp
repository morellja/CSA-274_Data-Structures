// Asgn03.cpp : Defines the entry point for the console application.
//
// Jared Morell
// Dr. Gannod
// CSA 274 A
// Asgn03

#include "stdafx.h"
#include <iostream>
#include "Simple.h"
#include "Trivial.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "int" << ": " << sizeof(int) << endl;
	cout << "char" << ": " << sizeof(char) << endl;
	cout << "double" << ": " << sizeof(double) << endl;
	cout << "float" << ": " << sizeof(float) << endl;
	cout << "bool" << ": " << sizeof(bool) << endl;
	cout << "Simple" << ": " << sizeof(Simple) << endl;
	cout << "Trivial" << ": " << sizeof(Trivial) << endl;

	int values [10];
	int *p = values;
	
	values[0] = 1986;
	values[1] = 1996;
	values[2] = 2007;
	values[3] = 1998;
	values[4] = 1968;
	values[5] = 2000;
	values[6] = 2006;
	values[7] = 2005;
	values[8] = 1994;
	values[9] = 1988;

	for(int i=0; i<10; i++){
		cout << "values[" << i << "]: " << (p+i) << " : " << *(p+i) << endl;
	}
	
	int *p0 = new int;
	int *p1 = new int;
	int *p2 = new int;
	int *p3 = new int;
	int *p4 = new int;
	int *p5 = new int;
	int *p6 = new int;
	int *p7 = new int;
	int *p8 = new int;
	int *p9 = new int;

	*p0 = values[0];
	*p1 = values[1];
	*p2 = values[2];
	*p3 = values[3];
	*p4 = values[4];
	*p5 = values[5];
	*p6 = values[6];
	*p7 = values[7];
	*p8 = values[8];
	*p9 = values[9];

	cout << "p0: " << p0 << " : " << *p0 << endl;
	cout << "p1: " << p1 << " : " << *p1 << endl;
	cout << "p2: " << p2 << " : " << *p2 << endl;
	cout << "p3: " << p3 << " : " << *p3 << endl;
	cout << "p4: " << p4 << " : " << *p4 << endl;
	cout << "p5: " << p5 << " : " << *p5 << endl;
	cout << "p6: " << p6 << " : " << *p6 << endl;
	cout << "p7: " << p7 << " : " << *p7 << endl;
	cout << "p8: " << p8 << " : " << *p8 << endl;
	cout << "p9: " << p9 << " : " << *p9 << endl;
	
	return 0;
}

