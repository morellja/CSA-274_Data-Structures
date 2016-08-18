// Asgn14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void makeChange(int);

int _tmain(int argc, _TCHAR* argv[])
{
	makeChange(141);
	return 0;
}

void makeChange(int amt){
	if(amt-100>=0){
		cout << "Dollar, ";
		makeChange(amt-100);
	}else if(amt-25>=0){
		cout << "Quarter, ";
		makeChange(amt-25);
	}else if(amt-10>=0){
		cout << "Dime, ";
		makeChange(amt-10);
	}else if(amt-5>=0){
		cout << "Nickel, ";
		makeChange(amt-5);
	}else if(amt-1>=0){
		cout << "Penny, ";
		makeChange(amt-1);
	}else{
		cout << "Done." << endl;
	}

}
