//
// Name : Jared Morell	
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A
// Asgn04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CurrencyExchange.h";

using namespace std;

// Name of Method : main method
// Description : entry point of the program
// Parameters : unused
// Return Value : unused
// Assumptions : USD.dat file exist
// Usage : Asgn04 or Asgn04.exe
int main(int argc, char* argv[])
{

	// Read exchange data from file
	ifstream inFile("USD.dat", ios::in);
	CurrencyExchange *ce;
	if (!inFile){
		cerr << "File could not be opened" << endl;
	} else {
	   char fileunit[4];
	   inFile.getline(fileunit, 4);
	   ce = new CurrencyExchange(fileunit);

	   cout << "Base unit is " << ce->getBaseUnit() << endl;

	   while (!inFile.eof()){
	      char tUnit[4];
		  double dRate;
		  inFile >> tUnit >> dRate;  
	      ce->addConverter(tUnit, dRate);
	   }
	}

	// Use the tool to convert base unit to target unit
	bool done = false;
	while (!done){
	
		string target;
		double amount;

		// get the conversion info
		cout << "Target? ";
		cin >> target;
		cout << "Amount? ";
		cin >> amount;

		// convert the input amount to the specified target currency
		double local = ce->convert(target, amount);
		cout << "Local Amount = " << local << endl;
		cout << "Done? ";

		// Are we done yet?
		string fini;
		cin >> fini;
		if (fini == "yes")
			done = true;

	}
	delete ce;

	return 0;
}

