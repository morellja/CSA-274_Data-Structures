#include "StdAfx.h"
#include "CurrencyExchange.h"

CurrencyExchange::CurrencyExchange(string units)
{
	baseUnit = units;

	currencies = new CurrenciesList();
}

CurrencyExchange::~CurrencyExchange(void)
{
	delete currencies;
}

void CurrencyExchange::setBaseUnit(string unit)
{
	this->baseUnit = unit;
}

string CurrencyExchange::getBaseUnit(void)
{
	return this->baseUnit;
}

void CurrencyExchange::addConverter(string target, double rate)
{
	CurrencyConverter *c = new CurrencyConverter(baseUnit, target);
	c->setExchangeRate(rate);

	currencies->add(c);
}

double CurrencyExchange::getExchangeRate(string target)
{ 
	double result = 0.0;
	CurrencyConverter *c = this->getConverter(target);
	if (c != NULL)
		result = c->getExchangeRate();
	return result;
}

CurrencyConverter* CurrencyExchange::getConverter(string target) const
{
	CurrencyConverter *c = NULL;

	c = currencies->find(target);
	return c;
}

double CurrencyExchange::convert(string target, double amt)
{
	double result = 0.0;
	CurrencyConverter *c = this->getConverter(target);
	if (c != NULL)
		result = c->exchangeCurrency(amt);
	return result;
}

void CurrencyExchange::interactiveConvert(void)
{
		// Use the tool to convert base unit to target unit
	bool done = false;
	while (!done){
	
		string target;
		string targetAmount;
		double amount = -1;

		// get the conversion info
		cout << "Target? ";
		cin >> target;
		cout << "Amount? ";
		cin >> targetAmount;

		amount = strtod(targetAmount.c_str(),NULL);

		// convert the input amount to the specified target currency
		if (this->getExchangeRate(target) == 0){
			throw "Target Currency Unknown";
		}

		if (amount == 0.0){
			throw "Invalid Exchange Amount Entered";
		}

		double local = this->convert(target, amount);
		cout << "Local Amount = " << local << endl;
		cout << "Done? ";

		// Are we done yet?
		string fini;
		cin >> fini;
		if (fini == "yes")
			done = true;

	}
}

