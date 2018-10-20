#include <iostream>
using namespace std;
#include "list.h"


void PrintList (list toPrint, ostream & Out) {
	int nextValue;
	Out << "Printing list contents: " << endl;
	toPrint.goToHead();
	if (!toPrint.moreData()) {
		Out << "List is empty" << endl;
		return;
	}
	while (toPrint.moreData()) {
		nextValue = toPrint.getCurrentData();
		Out << nextValue << " ";
		toPrint.advance();
	}
	Out << endl;
}

int main () {
	// greater number of nodes case
	list testList1, testList2;
	for (int i = 1; i < 4; i++)
		testList1.insert(i);
	cout << "=====GREATER NUMBER OF NODES CASE=====" << endl;
	PrintList(testList1, cout);

	for (int i = 4; i < 10; i++)
		testList2.insert(i);
	PrintList(testList2, cout);

	testList2 = testList1;
	PrintList(testList2, cout);
	cout << "======================================" << endl;


	// equal number of nodes case
	list testList3, testList4;
	for (int i = 20; i < 25; i++)
		testList3.insert(i);
	cout << "=====EQUAL NUMBER OF NODES CASE=====" << endl;
	PrintList(testList3, cout);

	for (int i = 30; i < 35; i++)
		testList4.insert(i);
	PrintList(testList4, cout);

	testList4 = testList3;
	PrintList(testList4, cout);
	cout << "======================================" << endl;

	// lesser number of nodes case
	list testList5, testList6;
	for (int i = 70; i < 80; i++)
		testList5.insert(i);
	cout << "=====GREATER NUMBER OF NODES CASE=====" << endl;
	PrintList(testList5, cout);

	for (int i = 90; i < 95; i++)
		testList6.insert(i);
	PrintList(testList6, cout);

	testList6 = testList5;
	PrintList(testList6, cout);
	cout << "======================================" << endl;


	// empty list case
	list testList7, testList8;
	for (int i = 40; i < 45; i++)
		testList7.insert(i);
	cout << "=====EMPTY LIST CASE=====" << endl;
	PrintList(testList7, cout);

	PrintList(testList8, cout);

	testList8 = testList7;
	PrintList(testList8, cout);
	cout << "======================================" << endl;



}
