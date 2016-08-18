// Jared Morell
// Dr. Gannod
// CSA 274 A
// Assignment 8

#include "StdAfx.h"
#include "IntSLList.h"

// Name of Method : ~IntSLList
// Description : destructor for clas
// Parameters : 
// Return Value : 
IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

// Name of Method : addToHead
// Description : adds an element to the head of the list
// Parameters : an int, the element to be added
// Return Value : void
void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el,head);
    if (tail == 0)
       tail = head;
}

// Name of Method : addToTail
// Description : adds an element to the tail of the list
// Parameters : an int, the element
// Return Value : void
void IntSLList::addToTail(int el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new IntSLLNode(el);
         tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

// Name of Method : deleteFromHead
// Description : deletes an element from the head of the list
// Parameters : 
// Return Value : an int, the element that was deleted
int IntSLList::deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

// Name of Method : deleteFromTail
// Description : deletes an element from the tail of the list
// Parameters :
// Return Value : an int, the element that was deleted
int IntSLList::deleteFromTail() {
    int el = tail->info;
    if (head == tail) {   // if only one node on the list;
         delete head;
         head = tail = 0;
    }
    else {                // if more than one node in the list,
         IntSLLNode *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = 0;
    }
    return el;
}

// Name of Method : deleteNode
// Description : deletes node from list
// Parameters :	element to be deleted
// Return Value : 
void IntSLList::deleteNode(int el) {
    if (head != 0)                     // if non-empty list;
         if (head == tail && el == head->info) { // if only one
              delete head;                       // node on the list;
              head = tail = 0;
         }
         else if (el == head->info) {  // if more than one node on the list
              IntSLLNode *tmp = head;
              head = head->next;
              delete tmp;              // and old head is deleted;
         }
         else {                        // if more than one node in the list
              IntSLLNode *pred, *tmp;
              for (pred = head, tmp = head->next; // and a non-head node
                   tmp != 0 && !(tmp->info == el);// is deleted;
                   pred = pred->next, tmp = tmp->next);
              if (tmp != 0) {
                   pred->next = tmp->next;
                   if (tmp == tail)
                      tail = pred;
                   delete tmp;
              }
         }
}

// Name of Method : isInList
// Description : checks if element is in list
// Parameters : the element
// Return Value : boolean value
bool IntSLList::isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

// Name of Method : printAll
// Description : prints the list
// Parameters :
// Return Value : 
void IntSLList::printAll() const {
    for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
        cout << tmp->info << " ";
	cout << endl;
}

// Name of Method : insertOrdered
// Description : inserts a node into the list, so that the element is ordered
// Parameters : an int, the element
// Return Value : void
void IntSLList::insertOrdered(int el){
	IntSLLNode *tmp; 

	if(tail == 0){
		addToTail(el);
	}else if (tail == head){
		if(el > tail->info)
			addToTail(el);
		else
			addToHead(el);
	}else{
		if(el < head->info)
			addToHead(el);
		else if( el >= tail->info)
			addToTail(el);
		else{
			IntSLLNode *newNode = new IntSLLNode(el);
			for(tmp = this-> head; tmp != 0; tmp = tmp->next){
				if((el > tmp->info) && (el <= tmp->next->info)){
					newNode->next = tmp ->next;
					tmp->next = newNode;
				}
			}
		}
	}
}

// Name of Method : count
// Description : counts the number of occurrences of a number in the list
// Parameters : an int, the number
// Return Value : an int, the number of occurrences
int IntSLList::count(int el){
	int count = 0;
	IntSLLNode *tmp = this->head;
	while(tmp != NULL){
		if(tmp->info == el)
			count++;
		tmp = tmp->next;
	}
	return count;
}
