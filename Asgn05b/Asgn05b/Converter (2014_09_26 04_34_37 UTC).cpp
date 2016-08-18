#include "StdAfx.h"
#include "Converter.h"

// Name of Method : Converter 
// Description : constructor for the class
// Parameters : 2 strings, the base unit and the target unit
// Return Value : 

Converter::Converter(string from, string to)
{
   fromUnits = from;
   toUnits = to;
}

// Name of Method : setExchangeRate
// Description : sets the exchange rate
// Parameters : a double, the exchange rate
// Return Value : void

void Converter::setExchangeRate(double exRate)
{
   exchangeRate = exRate;
}

// Name of Method : getExchangeRate
// Description : gets the exchange rate
// Parameters : void
// Return Value : a double, the exchange rate

double Converter::getExchangeRate(void)
{
   return exchangeRate;
}

// Name of Method : exchangeCurrency
// Description : calculates the amount to be exchanged
// Parameters : a double, the amount in the base unit
// Return Value : a double, the amount in the target unit

double Converter::exchangeCurrency(double amount)
{
   return amount * exchangeRate;
}

// Name of Method : getFromUnits
// Description : gets the base unit
// Parameters : void
// Return Value : a string, the base unit

string Converter::getFromUnits(void)
{
   return fromUnits;
}

// Name of Method : getToUnits
// Description : gets the target unit
// Parameters : void
// Return Value : a string, the target unit

string Converter::getToUnits(void)
{
   return toUnits;
}

