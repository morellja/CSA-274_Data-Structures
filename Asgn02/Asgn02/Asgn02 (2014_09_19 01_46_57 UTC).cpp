//
// Name : Jared Morell
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A
// Asgn02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Converter.h"

using namespace std;

// main method used for the program
int main(int argc, char* argv[])
{

	string units;
	string toUnits;
	double rate;
	double amt;

	// user inputs

	cout << "Base Unit? ";
	cin >> units;

	cout << "To Unit? ";
	cin >> toUnits;

	cout << "Rate? ";
	cin >> rate;

	cout << "Amount to exchange? ";
	cin >> amt;

	// instantiates the Converter class and prints out the results.

	Converter c(units,toUnits);
	c.setExchangeRate(rate);

	cout << c << endl;
	cout << amt << " " << c.getFromUnits() << " = " << c.exchangeCurrency(amt) << " " << c.getToUnits() << endl;


	return 0;
}

