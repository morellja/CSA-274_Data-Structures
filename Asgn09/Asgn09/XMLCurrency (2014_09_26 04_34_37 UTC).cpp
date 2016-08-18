#include "stdafx.h"
#include "XMLCurrency.h"
#include "Marshaler.h"

XMLCurrency::XMLCurrency(string currency){

	string url = "http://feeds.currencysource.com/" + currency + ".xml";

	URLString = gcnew String(url.c_str());
    reader = gcnew XmlTextReader (URLString);

}


string XMLCurrency::getExchangeDataFromRSS(void){

	bool f1 = false;
	bool f2 = false;

	try {
		while (reader->Read()) {
			switch (reader->NodeType) {
				case XmlNodeType::Element: // The node is an element.
					if (reader->Name == "item") f1 = true;
					if (f1 && reader->Name == "title") f2 = true;
					break;
				case XmlNodeType::Text: //Display the text in each element.
					if (f1 && f2){
					   string mystring;
					   MarshalString(reader->Value, mystring);
					   return mystring;
					   f1 = false;
					   f2 = false;
					}
					break;
				case XmlNodeType::EndElement: //Display the end of the element.
					break;
			}
		}
	} catch (System::Net::WebException^ ex){
		System::Console::WriteLine("Exception Caught: " + ex->Message);
		String^ s = "Error reading XML feed for " + URLString + ":" + ex->Message;
		throw "Error reading XML feed.";

	}
	return "done";
}