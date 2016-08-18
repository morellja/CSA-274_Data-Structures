#include "Converter.h"

using namespace std;

class CurrencyNode
{
private:
	CurrencyConverter *data;
	CurrencyNode *next;
public:
	CurrencyNode(void);
	// Create a new node with data and next each = NULL
	CurrencyNode(CurrencyConverter *c, CurrencyNode *n);
	// Create a new node with data = c and next = n
	~CurrencyNode(void);
	// Delete this node
	CurrencyNode *getNext(void);
	// Get the next node in the linked list
	void setNext(CurrencyNode *n);
	// Set the next node in the linked list to be
	CurrencyConverter *getData(void) const;
	// Get the data from the node
	void setData(CurrencyConverter *);
	// Set the data for the node
};