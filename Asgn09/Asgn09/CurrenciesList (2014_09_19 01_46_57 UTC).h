#pragma once

#include "CurrencyNode.h"
#include <string>
using namespace std;

class CurrenciesList
{

private:
	CurrencyNode *head;

public:
	CurrenciesList(void);				  // create a new list, with head = NULL
	CurrenciesList(CurrencyConverter *);  // create a new list, with the given input at the head 
	~CurrenciesList(void);				  // delete the list
	CurrencyConverter* find(string);      // find the converter for the given currency
	void add(CurrencyConverter *);		  // add a currency convert to the list
};
