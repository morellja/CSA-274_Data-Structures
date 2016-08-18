// List.h
#pragma once
#include <iostream>
using namespace std;

template <class T> // <class T>  or  <typename T>
class ListNode {

template <class T>
friend class GannodListIterator;

public:
	ListNode(T &obj, ListNode *ptr = NULL) {
		object = &obj;
		next = ptr;
	}
	ListNode(void){
		object = NULL;
		next = NULL;
	}

	T* object; // same as info in IntSLLNode
	class ListNode<T> *next;

};

template <class T>
class GannodList
{

template <class T>
friend class GannodListIterator;

public:
	GannodList(void){
		head = tail = NULL;
	};
	virtual ~GannodList(void);
    void addToHead(T &);
    void addToTail(T &);
    T& deleteFromHead(void); // delete the head and return its info;
    T& deleteFromTail(void); // delete the tail and return its info;
	T& peekHead(void);
	T& peekTail(void);
    //void deleteNode(T &);
    //bool isInList(T &) const;
	int isEmpty() { return head == 0; }
protected:
	friend ostream& operator<< (ostream& o, GannodList<T> &list){
		GannodListIterator<T> iter(list);
		while (iter.hasNext()){
			o << iter.next() << " ";
		}
		return o;
	}

private:
    ListNode<T> *head, *tail;
};

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
    if (tail == 0)
       tail = head;
}

template <class T>
void GannodList<T>::addToTail(T& el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new ListNode<T>(el);
         tail = tail->next;
    }
    else head = tail = new ListNode<T>(el);
}

template <class T>
T& GannodList<T>::deleteFromHead() {
    T& el = *head->object;
    ListNode<T> *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
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
         head = tail = NULL;
    }
    else {                // if more than one node in the list,
         ListNode<T> *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = NULL;
    }
    return el;
}

template<class T>
T& GannodList<T>::peekTail(void){
	T& el = *tail->object;
	return el;
}

//template <class T>
//void GannodList<T>::deleteNode(T& el) {
//    if (head != 0)                     // if non-empty list;
//         if (head == tail && head->object->compare(el) == 0) { // if only one
//              delete head;                       // node on the list;
//              head = tail = 0;
//         }
//         else if (head->object->compare(el) == 0) {  // if more than one node on the list
//              ListNode<T> *tmp = head;
//              head = head->next;
//              delete tmp;              // and old head is deleted;
//         }
//         else {                        // if more than one node in the list
//              ListNode<T> *pred, *tmp;
//              for (pred = head, tmp = head->next; // and a non-head node
//                   tmp != NULL && !(tmp->object->compare(el) == 0);// is deleted;
//                   pred = pred->next, tmp = tmp->next);
//              if (tmp != NULL) {
//                   pred->next = tmp->next;
//                   if (tmp == tail)
//                      tail = pred;
//                   delete tmp;
//              }
//         }
//}

//template <class T>
//bool GannodList<T>::isInList(T& el) const {
//    ListNode<T> *tmp;
//    for (tmp = head; tmp != 0 && !(tmp->object->compare(el) == 0); tmp = tmp->next);
//    return tmp != 0;
//}

template <class T>
class GannodListIterator
{
public:
	GannodListIterator(GannodList<T> &list){
		head = list.head;
		curr = head;
	}
	
	void reset(void){
		curr = head;
	}

	bool hasNext(void){
		return curr != NULL;
	}

	const T& next(void){
		const ListNode<T> &ret = *curr;
		curr = curr->next;
		return *ret.object;
	}

protected:
	ListNode<T> *head;
	ListNode<T> *curr;
};
