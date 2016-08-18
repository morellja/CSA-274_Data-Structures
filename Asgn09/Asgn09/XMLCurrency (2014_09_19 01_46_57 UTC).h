#include "stdafx.h"
#include <string>
#using <mscorlib.dll>
#using <System.Xml.dll>

using namespace std;
using namespace System;

using namespace System::Xml;

ref class XMLCurrency {

private:
	String^ URLString;
	XmlTextReader ^reader;
public:
	XMLCurrency (string);
	string getExchangeDataFromRSS(void);

};

