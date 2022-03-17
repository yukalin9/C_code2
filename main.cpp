#include <string>
#include <iostream>
#include "Tbuffer.h"
using namespace std;
void baseTest();

int main() {
	baseTest();
	cout << "Press any key to continue . . .";
	getchar();
	return 0;
}

void baseTest() {
	Tbuffer<int, 12> ib(0);
	int i_array[10] = { 12, -4, 6, 8, 6, 5, -4, -6, 11, 88 };
	ib.add(7);
	ib.add(12);
	ib.add(17);
	ib.add(i_array, 9);
	cout << "Length: " << ib.getDataLength() << endl;
	ib.print();
	cout << "Sum: " << ib.sum() << endl;
	Tbuffer<double, 10> db(0.0);
	db.add(8.463);
	db.add(3.74);
	db.add(5.231);
	db.add(3.74);
	db.print();
	cout << "Sum: " << db.sum() << endl;
	Tbuffer<string, 10> sb("");
	sb.add("John");
	sb.add("Sarah");
	sb.add("John");
	sb.add("Sarah");
	sb.add("Miguel");
	sb.add("Fred");
	sb.add("Klyde");
	sb.add("Clara");
	sb.print();
	cout << "Sum: " << sb.sum() << endl;
}

