//
// Name : Jared Morell
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A 
// Asgn02.cpp : Defines the entry point for the console application.
//
#pragma once

#include <string>

using namespace std;

class Converter
{
private:
	double exchangeRate;
	string fromUnits;
	string toUnits;

public:
	Converter(string sourceUnit, string destinationUnit);
	void setExchangeRate(double rate);
	double getExchangeRate(void);
	double exchangeCurrency(double amtExchange);
	string getFromUnits(void);
	string getToUnits(void);


	// Print the object
	// Implement inline
	friend ostream & operator << (ostream &o, Converter &c)
	{
		// Assumes attributes called "fromUnits", "toUnits", and "exchangeRate"
		o << c.fromUnits << " to " << c.toUnits << " = " << c.exchangeRate;
		return o;
	}

};
