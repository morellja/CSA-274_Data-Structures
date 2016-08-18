#include "stdafx.h"
#include "CurrenciesList.h"
#include "Converter.h"

// Name of Method : CurrenciesList
// Description : constructor for class, creating new list with head = NULL
// Parameters : void
// Return Value : 
CurrenciesList::CurrenciesList(void){
	head = NULL;
}

// Name of Method : CurrenciesList
// Description : constructor for class, creating new list with given input at head
// Parameters : instance of CurrencyConverter
// Return Value : 
CurrenciesList::CurrenciesList(CurrencyConverter *con){
	head->setData(con);
}

// Name of Method : ~CurrenciesList
// Description : destructor for clas
// Parameters : 
// Return Value : 
CurrenciesList::~CurrenciesList(void){
	delete head;
}

// Name of Method : *find
// Description : finds the converter in the list for the given currency
// Parameters : a string, the currency
// Return Value : the converter
CurrencyConverter* CurrenciesList:: find(string currency){
	CurrencyNode *tmp;
	
	for(tmp = head; tmp != 0; tmp = tmp->getNext()){
		if(tmp->getData()->getToUnits() == currency)
			return tmp->getData();
	}
}

// Name of Method : add
// Description : adds a converter to the list
// Parameters : the converter to be added
// Return Value : 
void CurrenciesList::add(CurrencyConverter *con){
	CurrencyNode *tmp = new CurrencyNode(con, head);
	head = tmp;
}