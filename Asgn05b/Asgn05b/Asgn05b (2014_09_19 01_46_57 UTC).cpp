// Name : Jared Morell
// Instructor Name : Dr. Gannod
// Course Number and Section : CSA 274 A
// Asgn05b.cpp

// XMLParser.cpp : main project file.

#include "stdafx.h"
#include <string>
#include <iostream>
#include "CurrencyExchange.h"
#include "XMLCurrency.h"

using namespace std;

int main(int argc, char* argv[]) {

	string baseUnit;
	string data;
	string target;
	string exchangeRate;
	double rate;
	
	cout << "Enter Currency Unit: ";
	cin >> baseUnit;

	CurrencyExchange ce(baseUnit);

	XMLCurrency^ xm = gcnew XMLCurrency(baseUnit);
	data = xm->getExchangeDataFromRSS();

	while(data != "done"){
		data.erase(data.length()-1);
		exchangeRate = data.substr(13);
		target = data.substr(8,3);

		cout << target << " : " << exchangeRate << endl;
		data = xm->getExchangeDataFromRSS();

		rate = strtod(exchangeRate.c_str(),NULL);
		
		ce.addConverter(target,rate);
	}

	ce.interactiveConvert();

    return 0;
}


