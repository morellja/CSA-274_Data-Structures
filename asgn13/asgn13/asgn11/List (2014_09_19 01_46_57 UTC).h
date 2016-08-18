
// List.h
#pragma once
#include <iostream>
using namespace std;

template <class T> // <class T>  or  <typename T>
class ListNode {

public:
	ListNode(T &obj, ListNode *ptr = NULL) {
		object = &obj;
		next = ptr;
	}
	ListNode(void){
		object = NULL;
		next = NULL;
	}

	ListNode& clone(void){
		T* newt = new T(*object);
		ListNode *ln = new ListNode(*newt, NULL);
		return *ln;
	}

	T* object; 
	class ListNode<T> *next;

};

template <class T>
class GannodList
{

public:
	GannodList(void){
		head = tail = iter = NULL;
		count = 0;
	};
	GannodList(ListNode<T> *h, ListNode<T> *t){
		head = h;
		tail = t;
	}
	virtual ~GannodList(void);
    void addToHead(T &);
    void addToTail(T &);
    T& deleteFromHead(void); // delete the head and return its info;
    T& deleteFromTail(void); // delete the tail and return its info;
	void deleteNode(T& el);
	T& peekHead(void);
	T& peekTail(void);
	int size(void) { return count; }
	void reset(void);
	bool hasNext(void);
	T& next(void);
	int isEmpty() { return head == 0; }
	GannodList<T>& clone(void);
protected:
	friend ostream& operator<< (ostream& o, GannodList<T> &list){
		list.reset();
		while (list.hasNext()){
			o << list.next() << " ";
		}
		return o;
	}

private:
    ListNode<T> *head, *tail, *iter;
	int count;
};

template <class T>
GannodList<T>& GannodList<T>::clone(void){

	ListNode<T> *curr = head;
	ListNode<T> *newHead;
	ListNode<T> *prev = NULL;
	if (curr != NULL){
		prev = &(*curr).clone();
		newHead = prev;
		curr = curr->next;
	}
	while(curr != NULL){
		ListNode<T> *newt = &(*curr).clone();
		(*prev).next = newt;
		prev = newt;
		curr = curr->next;
	}
	GannodList<T> *retval = new GannodList<T>(newHead, prev);
	return *retval;
}

template <class T>
GannodList<T>::~GannodList() {
    for (ListNode<T> *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

template <class T>
void GannodList<T>::addToHead(T& el) {
    head = new ListNode<T>(el,head);
	iter = head;
    if (tail == 0)
       tail = head;
	count++;
}

template <class T>
void GannodList<T>::addToTail(T& el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new ListNode<T>(el);
         tail = tail->next;
    }
	else { 
		head = tail = iter = new ListNode<T>(el);
	}
	count++;
}

template <class T>
T& GannodList<T>::deleteFromHead() {
    T& el = *head->object;
    ListNode<T> *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = iter = 0;
	else {
		if (iter == head)
			iter = head->next;
		head = head->next;

	}
    delete tmp;
	count--;
    return el;
}

template<class T>
T& GannodList<T>::peekHead(void){
	T& el = *head->object;
	return el;
}

template <class T>
T& GannodList<T>::deleteFromTail() {
    T& el = *tail->object;
    if (head == tail) {   // if only one node on the list;
         delete head;
         head = tail = iter = NULL;
    }
    else {                // if more than one node in the list,
         ListNode<T> *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = NULL;
    }
	count--;
    return el;
}

template<class T>
T& GannodList<T>::peekTail(void){
	T& el = *tail->object;
	return el;
}

template<class T>
void GannodList<T>::reset(void){
	iter = head;
}

template<class T>
bool GannodList<T>::hasNext(void){
	return iter != NULL;
}

template<class T>
T& GannodList<T>::next(void){
	ListNode<T> &ret = *iter;
	iter = iter->next;
	return *ret.object;
}

template <class T>
void GannodList<T>::deleteNode(T& el) {
    if (head != 0)                     // if non-empty list;
         if (head == tail && *(head->object) == el) { // if only one
              delete head;                       // node on the list;
              head = tail = 0;
         }
         else if (*(head->object) == el) {  // if more than one node on the list
              ListNode<T> *tmp = head;
              head = head->next;
              delete tmp;              // and old head is deleted;
         }
         else {                        // if more than one node in the list
              ListNode<T> *pred, *tmp;
              for (pred = head, tmp = head->next; // and a non-head node
                   tmp != NULL && !(*(tmp->object) == el);// is deleted;
                   pred = pred->next, tmp = tmp->next);
              if (tmp != NULL) {
                   pred->next = tmp->next;
                   if (tmp == tail)
                      tail = pred;
                   delete tmp;
              }
         }
		 count--;
}