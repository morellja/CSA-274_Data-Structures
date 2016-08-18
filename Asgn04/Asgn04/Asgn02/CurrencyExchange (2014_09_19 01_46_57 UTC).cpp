//
// Name : Jared Morell	
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A
// CurrencyExchange.cpp
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CurrencyExchange.h"
#include "Converter.h"

using namespace std;

// Name of Method : CurrencyExchange
// Description : constructor for the class
// Parameters : a string that is the base unit to be used
// Return Value : none
CurrencyExchange::CurrencyExchange(string base){
	setBaseUnit(base);
	for(int i=0; i<CURRENCIES; i++)
		currencies[i]=NULL;
}

// Name of Method : ~CurrencyExchange
// Description : destructor for the class
// Parameters : void
// Return Value : none
CurrencyExchange::~CurrencyExchange(void){
	for(int i=0; i!=NULL; i++)
		delete currencies[i];
}

// Name of Method : setBaseUnit
// Description : sets the base unit to be used
// Parameters : a string that is the base unit
// Return Value : void
void CurrencyExchange::setBaseUnit(string base){
	(*this).baseUnit=base;
}

// Name of Method : getBaseUnit
// Description : gets the base unit
// Parameters : void
// Return Value : a string that is the base unit
string CurrencyExchange::getBaseUnit(void){
	return (*this).baseUnit;
}

// Name of Method : addConverter
// Description : adds a new instance of the converter class to the
//		currencies array and sets its target unit and the exchange rate
// Parameters : a string, the target unit and a double, the exchange rate
// Return Value : void
void CurrencyExchange::addConverter(string target, double rate){
	for(int i=0; i<CURRENCIES; i++){
		if(currencies[i]==NULL){
			currencies[i]=new Converter(baseUnit, target);
			(*currencies[i]).setExchangeRate(rate);
			i=CURRENCIES;
		}
	}
}

// Name of Method : convert
// Description : converts the amount of money provided to the target currency
// Parameters : a string, the target currency and a double, the amount to be exchanged
// Return Value : a double, the amount exchanged (in the target units). returns 0.0
//		if the target currency cannot be found
double CurrencyExchange::convert(string target, double amount){
	for(int i=0; i<CURRENCIES; i++){
		if((*currencies[i]).getToUnits()==target){
			return (*currencies[i]).exchangeCurrency(amount);
		}
	}
	return 0.0;
}

// Name of Method : getExchangeRate
// Description : gets the exchange rate for the input target unit from the base unit
// Parameters : a string, the target unit
// Return Value : a double, the target unit's exchange rate. returns 0.0 if the 
//		target currency cannot be found
double CurrencyExchange::getExchangeRate(string target){
	for(int i=0; i<CURRENCIES; i++){
		if((*currencies[i]).getToUnits()==target){
			return (*currencies[i]).getExchangeRate();
		}
	}
	return 0.0;
}