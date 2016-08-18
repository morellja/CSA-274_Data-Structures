// Asgn08.cpp : main project file.

#include "stdafx.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include "CurrencyExchange.h"
#include "XMLCurrency.h"
#include "Marshaler.h"

using namespace std;

int main(int argc, char* argv[]) {

	string currency;
	cout << "Enter Currency Unit: ";
	cin >> currency;

	CurrencyExchange *ce = new CurrencyExchange(currency);
	XMLCurrency^ xc = gcnew XMLCurrency(currency);

	try {
		string mystring;
		while ((mystring = xc->getExchangeDataFromRSS()) != "done"){
		
			string home = mystring.substr(2, 3);
			string target = mystring.substr(8, 3);
			int rateStart = mystring.find("(");
			int rateEnd = mystring.find(")");
			string rate = mystring.substr(rateStart + 1, rateEnd-rateStart-1);
			cout << target << " : ";
			cout << rate << endl;
			double drate = strtod(rate.c_str(),NULL);
			ce->addConverter(target, drate);

		}

		ce->interactiveConvert();
	} 
	catch (char *s){
		cerr << s << endl;
	}
	delete ce;
    return 0;
}


