/*
 * ADTList.h
 *
 *  Created on: 2012-10-30
 *      Author: lzero
 */

#ifndef ADTLIST_H_
#define ADTLIST_H_

#include <iostream>

namespace adttest {

template<typename T>
class ADTList {
private:
	struct Node {
		T item;
		Node * next;
	};
	int curItems;
	Node * front;
	Node * rear;
public:
	ADTList();
	virtual ~ADTList();
	void ClearList();
	bool IsEmpty() const;
	int Length() const;
	void GetElem(int index, T & e) const;
	int LocateElem(T & e, bool (*f)(T &, T &)) const;
	void PriorElem(T cur_e, T & pre_e) const;
	void NextElem(T cur_e, T & next_e) const;
	void ListInsert(int index, T e);
	void ListDelete(int index, T & e);
	bool ListTraverse(bool (*v)(T &)) const;
};

template<typename T>
ADTList<T>::ADTList() :
		curItems(0) {
	// TODO Auto-generated constructor stub
	front = rear = NULL;
}

template<typename T>
ADTList<T>::~ADTList() {
	// TODO Auto-generated destructor stub
	Node * temp;
	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
void ADTList<T>::ClearList() {
	// TODO Auto-generated destructor stub
	Node * temp;
	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}
	curItems = 0;
	front = rear = NULL;
}

template<typename T>
bool ADTList<T>::IsEmpty() const {
	return curItems == 0;
}

template<typename T>
int ADTList<T>::Length() const {
	return curItems;
}

template<typename T>
void ADTList<T>::GetElem(int index, T & e) const {
	if (index >= curItems) {
		return;
	}
	Node * temp = front;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	e = temp->item;
}

template<typename T>
int ADTList<T>::LocateElem(T & e, bool (*f)(T &, T &)) const {
	int index = 0;
	Node * temp = front;
	while (index < curItems) {
		if (f(e, temp->item)) {
			return index;
		}
		temp = temp->next;
		index++;
	}
	return 0;
}

template<typename T>
void ADTList<T>::PriorElem(T cur_e, T & pre_e) const {
	pre_e = NULL;
	if (curItems > 1) {
		Node * tempCur = front->next;
		Node * tempPre = front;
		while (tempCur != NULL) {
			if (tempCur->item == cur_e) {
				pre_e = tempPre->item;
				break;
			}
			tempPre = tempCur;
			tempCur = tempCur->next;
		}
	}
}

template<typename T>
void ADTList<T>::NextElem(T cur_e, T & next_e) const {
	next_e = NULL;
	if (curItems > 1) {
		Node * tempCur = front;
		Node * tempNext = front->next;
		while (tempNext != NULL) {
			if (tempCur->item == cur_e) {
				next_e = tempNext->item;
				break;
			}
			tempCur = tempNext;
			tempNext = tempNext->next;
		}
	}
}

template<typename T>
void ADTList<T>::ListInsert(int index, T e) {
	curItems++;
	Node * temp = front;
	Node * newNode = new Node;
	newNode->item = e;
	newNode->next = NULL;
	if (temp == NULL) {
		front = rear = newNode;
		return;
	}

	if (index == 0) {
		newNode->next = temp;
		front = newNode;
		return;
	}

	Node * tempPre = temp;
	temp = temp->next;
	for (int i = 1; i < curItems - 1; ++i) {
		if (i == index) {
			tempPre->next = newNode;
			newNode->next = temp;
			return;
		}
		tempPre = temp;
		temp = temp->next;
	}

	if (index == (curItems - 1)) {
		tempPre->next = newNode;
		rear = newNode;
		return;
	}
	delete newNode;
	curItems--; //插入失败,要减回1
}

template<typename T>
void ADTList<T>::ListDelete(int index, T & e) {
	if (curItems == 0) {
		return;
	}

	curItems--;
	if (index == 0 && curItems == 1) {
		e = front->item;
		delete front;
		front = rear = NULL;
		return;
	}

	Node * temp = front;

	if (index == 0) {
		e = front->item;
		front = front->next;
		delete temp;
		return;
	}

	Node * tempPre = temp;
	temp = temp->next;
	for (int i = 1; i < curItems; i++) {
		if (i == index) {
			tempPre->next = temp->next;
			delete temp;
			return;
		}
		tempPre = temp;
		temp = temp->next;
	}
	bool ListTraverse(bool (*v)(T &));

	if (index == curItems) {
		tempPre->next = NULL;
		rear = tempPre;
		delete temp;
	}

	curItems++; //删除失败，要加回1
}

template<typename T>
bool ADTList<T>::ListTraverse(bool (*v)(T &)) const {
	bool result = false;
	if (front != NULL) {
		Node * temp = front;
		while (temp != NULL) {
			if (!v(temp->item)) {
				return false;
			}
			temp = temp->next;
		}
		result = true;
	}
	return result;
}

} /* namespace adttest */
#endif /* ADTLIST_H_ */
