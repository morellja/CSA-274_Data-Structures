//
// Name : 
// Instructor Name :
// Course Number and Section :
// Asgn02.cpp : Defines the entry point for the console application.
//
#pragma once

#include <string>

using namespace std;

class CurrencyConverter
{
private:
	double exchangeRate;
	string fromUnits;
	string toUnits;

public:


	// Constructor for the class
	CurrencyConverter(string, string);

	// Sets the exchange rate
	void setExchangeRate(double);

	// Gets the exchange rate
	double getExchangeRate(void);

	// Exchange currency
	double exchangeCurrency(double);

	// Units
	string getFromUnits(void);

	// Units
	string getToUnits(void);

	// Print the object
	// Implement inline
	friend ostream & operator << (ostream &o, CurrencyConverter &c)
	{
		o << c.fromUnits << " to " << c.toUnits << " = " << c.exchangeRate;
		return o;
	}
};
