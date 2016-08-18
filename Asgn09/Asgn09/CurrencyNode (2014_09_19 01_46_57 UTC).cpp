#include "StdAfx.h"
#include "CurrencyNode.h"

CurrencyNode::CurrencyNode(void)
{
	data = NULL;
	next = NULL;
}

CurrencyNode::~CurrencyNode(void)
{
	delete data;
	if (next != NULL)
		delete next;
}

CurrencyNode::CurrencyNode(CurrencyConverter *c, CurrencyNode *n)
{
	data = c;
	next = n;
}

CurrencyNode* CurrencyNode::getNext(void)
{
	return next;
}

void CurrencyNode::setNext(CurrencyNode *n)
{
	next = n;
}

CurrencyConverter* CurrencyNode::getData(void) const
{
	return data;
}

void CurrencyNode::setData(CurrencyConverter *c)
{
	data = c;
}