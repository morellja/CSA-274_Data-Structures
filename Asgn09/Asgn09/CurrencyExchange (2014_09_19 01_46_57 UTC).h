#pragma once
//
// Name : 
// Instructor Name :
// Course Number and Section :
// CurrencyExchange.h
//

#include "Converter.h"
#include "CurrenciesList.h"
#include <string>
#include <iostream>
using namespace std;

class CurrencyExchange
{
private:

	CurrenciesList *currencies;

	string baseUnit;					// Unit of the exchanger

	CurrencyConverter* getConverter(string) const;	// Get the converter for the given unit

public:
	CurrencyExchange(string);			// Constructor; input is base unit for all Converters

	~CurrencyExchange(void);			// Destructor

	void setBaseUnit(string);			// Set base unit

	string getBaseUnit(void);			// Get base unit

	void addConverter(string, double);	// Add converter; create an instance of a Converter class
										// and add it to the currencies array 
	
	double convert(string, double);		// Convert input amount to the given unit

	double getExchangeRate(string);		// Get exchange rate for two currencies

	void interactiveConvert(void);		// Prompt user for amounts to convert
};

