// Jared Morell
// Dr. Gannod
// CSA 274 A
// Asgn05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string baseUnit;
	string targetUnit;
	string exchangeRate;
	string unwanted;
	int comma;
	double rate;

	ifstream inFile("USD.dat", ios::in);
	if (!inFile){
		cerr << "File could not be opened" << endl;
	} else {
		while (!inFile.eof()){
			inFile >> unwanted >> baseUnit >> unwanted >> targetUnit >> exchangeRate;
			
			exchangeRate = exchangeRate.substr(1,exchangeRate.find(")",0)-1);
			comma = exchangeRate.find(",",0);
			
			if(comma != string::npos){
				exchangeRate.erase(comma,1);
			}
			rate = strtod(exchangeRate.c_str(),NULL);
			
			cout << baseUnit << " : " << targetUnit << " : " << rate << endl;
		}
	}
	
	return 0;
}

