#include "StdAfx.h"
#include "Converter.h"

// Name of Method : 
// Description : 
// Parameters :
// Return Value : 
// Assumptions :
// Usage : 
CurrencyConverter::CurrencyConverter(string from, string to)
{
   fromUnits = from;
   toUnits = to;
}

// Name of Method : 
// Description : 
// Parameters :
// Return Value : 
// Assumptions :
// Usage : 
void CurrencyConverter::setExchangeRate(double exRate)
{
   exchangeRate = exRate;
}

// Name of Method : 
// Description : 
// Parameters :
// Return Value : 
// Assumptions :
// Usage : 
double CurrencyConverter::getExchangeRate(void)
{
   return exchangeRate;
}

// Name of Method : 
// Description : 
// Parameters :
// Return Value : 
// Assumptions :
// Usage : 
double CurrencyConverter::exchangeCurrency(double amount)
{
   return amount * exchangeRate;
}

// Name of Method : 
// Description : 
// Parameters :
// Return Value : 
// Assumptions :
// Usage : 
string CurrencyConverter::getFromUnits(void)
{
   return fromUnits;
}

// Name of Method : 
// Description : 
// Parameters :
// Return Value : 
// Assumptions :
// Usage : 
string CurrencyConverter::getToUnits(void)
{
   return toUnits;
}

