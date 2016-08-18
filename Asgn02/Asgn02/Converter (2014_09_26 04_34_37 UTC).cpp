#include "stdafx.h"
#include "Converter.h"
#include <string>

// Converter. Constructor for the class. The two parameters are the names of
// the source conversion unit and the destination conversion unit. 
Converter::Converter(std::string sourceUnit, std::string destinationUnit){
	fromUnits = sourceUnit;
	toUnits = destinationUnit;
}

// setExchangeRate. Setter method for the rate of exchange. The parameter is the
// rate of exchange between the source conversion unit and the destination
// conversion unit.
void Converter::setExchangeRate(double rate){
	exchangeRate = rate;
}

// getExchangeRate. Getter method for the rate of exchange. Returns the exchange rate
// between the source conversion unit and the destination conversion unit.
double Converter::getExchangeRate(void){
	return exchangeRate;
}

// exchangeCurrency. Takes in the parameter of the amount of money to be converted.
// Uses this value, multiplied with the exchange rate to return the converted currency.
double Converter::exchangeCurrency(double amtExchange){
	double currency;
	currency = amtExchange*getExchangeRate();
	return currency;
}

// getFromUnits. Returns the units for the source currency.
string Converter::getFromUnits(void){
	return fromUnits;
}

// getToUnits. Returns the units for the destination currency.
string Converter::getToUnits(void){
	return toUnits;
}
