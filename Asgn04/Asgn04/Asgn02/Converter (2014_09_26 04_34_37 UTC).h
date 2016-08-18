//
// Name : Jared Morell
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A
// Converter.h
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


	// Constructor for the class
	Converter(string, string);

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
	friend ostream & operator << (ostream &o, Converter &c)
	{
		o << c.fromUnits << " to " << c.toUnits << " = " << c.exchangeRate;
		return o;
	}
};
