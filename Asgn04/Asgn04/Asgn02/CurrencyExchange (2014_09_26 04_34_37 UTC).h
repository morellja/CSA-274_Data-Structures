#pragma once
//
// Name : Jared Morell	
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A
// CurrencyExchange.h
//

#include "Converter.h"
#include <string>
using namespace std;

class CurrencyExchange
{
private:
	static const int CURRENCIES = 48;	// List has 48 elements

	Converter *currencies[CURRENCIES];	// Array of pointers; initialize with NULL

	string baseUnit;					// Unit of the exchanger

	Converter* getConverter(string) const;	// Get the converter for the given unit
										// return NULL if can't find target currency

public:
	CurrencyExchange(string);			// Constructor; input is base unit for all Converters

	~CurrencyExchange(void);			// Destructor; delete all objects in currencies array

	void setBaseUnit(string);			// Set base unit

	string getBaseUnit(void);			// Get base unit

	void addConverter(string, double);	// Add converter; create an instance of a Converter class
										// and add it to the currencies array 
	
	double convert(string, double);		// Convert input amount to the given unit; return 0.0
										// if can't find target currency

	double getExchangeRate(string);		// Get exchange rate for two currencies
										// return 0.0 if can't find target currency
};
