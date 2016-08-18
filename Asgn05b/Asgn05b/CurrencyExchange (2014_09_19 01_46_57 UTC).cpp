#include "StdAfx.h"
#include "CurrencyExchange.h"
#include "Converter.h"
#include <string>
#include <iostream>

using namespace std;

// Name of Method : CurrencyExchange 
// Description : constructor for the class
// Parameters : a string, the base unit
// Return Value : 

CurrencyExchange::CurrencyExchange(string units)
{
	baseUnit = units;
	for (int i = 0; i < CURRENCIES; i++){
		currencies[i] = NULL;
	}
}

// Name of Method : ~CurrencyExchange 
// Description : destructor for the class
// Parameters : void
// Return Value : 

CurrencyExchange::~CurrencyExchange(void)
{
	for (int i = 0; i < CURRENCIES; i++){
		if (currencies[i] != NULL)
			delete currencies[i];
	}
}

// Name of Method : setBaseUnit 
// Description : sets the base unit
// Parameters : a string, the base unit
// Return Value : void

void CurrencyExchange::setBaseUnit(string unit)
{
	this->baseUnit = unit;
}

// Name of Method : getBaseUnit 
// Description : gets the base unit
// Parameters : void
// Return Value : a string, the base unit

string CurrencyExchange::getBaseUnit(void)
{
	return this->baseUnit;
}

// Name of Method : addConverter 
// Description : adds a new Converter instance to the currencies array
// Parameters : a string, the target unit and a double, the exchange rate
// Return Value : void

void CurrencyExchange::addConverter(string target, double rate)
{
	Converter *c = new Converter(baseUnit, target);
	c->setExchangeRate(rate);
	int i = 0;
	while (currencies[i] != NULL)
		i++;
	currencies[i] = c;
}

// Name of Method : getExchangeRate 
// Description : gets the exchange rate for the target unit
//				returns 0.0 if target unit cannot be found
// Parameters : a string, the target unit
// Return Value : a double, the exchange rate

double CurrencyExchange::getExchangeRate(string target)
{ 
	double result = 0.0;
	Converter *c = this->getConverter(target);
	if (c != NULL)
		result = c->getExchangeRate();
	return result;
}

// Name of Method : getConverter 
// Description : gets the instance of the Converter class in the currencies array 
// Parameters : a string, the target unit for the Converter
// Return Value : the instance of the Converter class in the currencies array

Converter* CurrencyExchange::getConverter(string target) const
{
	Converter *c = NULL;
	int i = 0;
	while (currencies[i] != NULL){
		if ((*currencies[i]).getToUnits() == target)
			c = currencies[i];
		i++;
	}
	return c;
}

// Name of Method : convert 
// Description : converts the amount provided to the target currency
// Parameters : a string, the target unit and a double, the amount
// Return Value : a double, the amount in the converted units

double CurrencyExchange::convert(string target, double amt)
{
	double result = 0.0;
	Converter *c = this->getConverter(target);
	if (c != NULL)
		result = c->exchangeCurrency(amt);
	return result;
}

// Name of Method : interactiveConvert 
// Description :  prompts the user for the target and amount and then displays
//					the converted amount. continues prompting user until the user
//					enters "yes" when asked if they are done
// Parameters : void
// Return Value : void

void CurrencyExchange::interactiveConvert(void)
{
	string toUnit;
	string done = "no";
	int amount;
	
	try{
		while(done != "yes"){
			cout << "Target? ";
			cin >> toUnit;
		
			cout << "Amount? ";
			cin >> amount;

			cout << "Local Amount = " << convert(toUnit, amount) << endl;
			
			cout << "Done? ";
			cin >> done;
		}
	}catch(char *s){
		cerr << s << endl;
	}
}

