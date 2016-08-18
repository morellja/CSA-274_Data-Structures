//
// Name : Jared Morell	
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A
// Converter.cpp
//

#include "StdAfx.h"
#include "Converter.h"

// Name of Method : Converter
// Description : constructor for the class
// Parameters : a string, "from", that tells what units to convert from
//		and a string, "to", that tells what units to convert to
// Return Value : none
// Assumptions : 
// Usage : 
Converter::Converter(string from, string to)
{
   fromUnits = from;
   toUnits = to;
}

// Name of Method : setExchangeRate
// Description : sets the exchange rate
// Parameters : a double that is the exchange rate to be used
// Return Value : void
// Assumptions :
// Usage : 
void Converter::setExchangeRate(double exRate)
{
   exchangeRate = exRate;
}

// Name of Method : getExchangeRate
// Description : gets the exchange rate
// Parameters : void
// Return Value : a double that is the exchange rate
// Assumptions :
// Usage : 
double Converter::getExchangeRate(void)
{
   return exchangeRate;
}

// Name of Method : exchangeCurrency
// Description : computes the currency that is exchanged
// Parameters : a double that is the amount of money to be exchanged
// Return Value : a double that is the exchanged currency
// Assumptions :
// Usage : 
double Converter::exchangeCurrency(double amount)
{
   return amount * exchangeRate;
}

// Name of Method : getFromUnits
// Description : gets the base unit
// Parameters : void
// Return Value : a string that tells the base unit
// Assumptions :
// Usage : 
string Converter::getFromUnits(void)
{
   return fromUnits;
}

// Name of Method : getToUnits
// Description : gets the target unit
// Parameters : void
// Return Value : a string that tells the target unit
// Assumptions :
// Usage : 
string Converter::getToUnits(void)
{
   return toUnits;
}

