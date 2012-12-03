/*
 * TestADTList.cpp
 *
 *  Created on: 2012-10-31
 *      Author: lzero
 */
#include "Test.h"
#include "ADTList.h"
#include <iostream>
#include <string>

template<typename T>
bool equal(T & e1, T & e2) {
	return e1 == e2;
}

template<typename T>
void unionList(adttest::ADTList<T> & la, const adttest::ADTList<T> & lb) {
	T temp;
	int la_len = la.Length();
	int lb_len = lb.Length();
	bool (*f)(T &, T &);
	f = equal;
	for (int i = 0; i <= lb_len; ++i) {
		lb.GetElem(i, temp);
		if (!la.LocateElem(temp, f)) {
			la.ListInsert(la_len++, temp);
		}
	}
}

template<typename T>
void MergeList(const adttest::ADTList<T> & la, const adttest::ADTList<T> & lb,
		adttest::ADTList<T> & lc) {
	lc.ClearList();
	int i = 0, j = 0, k = 0;
	int la_len = la.Length();
	int lb_len = lb.Length();
	T ai, bi;
	while ((i < la_len) && (j < lb_len)) {
		la.GetElem(i, ai);
		lb.GetElem(j, bi);
		if (ai <= bi) {
			lc.ListInsert(k++, ai);
			i++;
		} else {
			lc.ListInsert(k++, bi);
			j++;
		}
	}
	while (i < la_len) {
		la.GetElem(i++, ai);
		lc.ListInsert(k++, ai);
	}
	while (j < lb_len) {
		lb.GetElem(j++, bi);
		lc.ListInsert(k++, bi);
	}
}

template<typename T>
bool showItem(T & item) {
	std::cout << item << " ";
	return true;
}

void TestADTList() {
	/*adttest::ADTList<std::string> list1;
	 adttest::ADTList<std::string> list2;

	 list1.ListInsert(0, "Test");
	 list2.ListInsert(0, "Test222");

	 unionList(list1, list2);

	 std::string t;
	 list1.GetElem(1, t);
	 std::cout << t << std::endl;*/
	adttest::ADTList<int> list1;
	adttest::ADTList<int> list2;
	adttest::ADTList<int> list3;

	list1.ListInsert(0, 3);
	list1.ListInsert(1, 5);
	list1.ListInsert(2, 8);
	list1.ListInsert(3, 11);

	list2.ListInsert(0, 2);
	list2.ListInsert(1, 6);
	list2.ListInsert(2, 8);
	list2.ListInsert(3, 9);
	list2.ListInsert(4, 11);
	list2.ListInsert(5, 15);
	list2.ListInsert(6, 20);

	list1.ListTraverse(showItem);
	std::cout << std::endl;
	list2.ListTraverse(showItem);

	std::cout << std::endl;
	int t;
	list1.GetElem(1, t);
	std::cout << t << std::endl;

//	unionList(list1, list2);
//	list1.ListTraverse(showItem);
//	std::cout << t << std::endl;

	MergeList(list1, list2, list3);
	list3.ListTraverse(showItem);
	std::cout << std::endl;
}
