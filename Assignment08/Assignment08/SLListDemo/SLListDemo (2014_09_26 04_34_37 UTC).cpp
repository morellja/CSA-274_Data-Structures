// SLListDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntSLList.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	IntSLList list;

	list.insertOrdered(5);
	list.insertOrdered(8);
	list.insertOrdered(1);
	list.insertOrdered(9);
	list.insertOrdered(11);
	list.insertOrdered(0);
	list.insertOrdered(10);
	list.insertOrdered(9);
	list.insertOrdered(11);
	list.insertOrdered(0);
	list.printAll();

	cout << list.count(9) << endl;

	return 0;
}

