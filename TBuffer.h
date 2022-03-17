
#include <iostream>
#include <iomanip>
#pragma once
using namespace std;
template <class T, int dataCapacity>
class Tbuffer
{
protected:
	T* data;
	int dataLength;
	T nullValue;
public:
	Tbuffer(T nullValue) {
		cout << " Constructor called on " << this << " " << endl;
		dataLength = 0;
		data = new T[dataCapacity];
		nullValue = nullValue;
	}
	int add(T value) {

		if (dataLength < dataCapacity) {
			data[dataLength] = value;
			dataLength++;
			return 1;
		}
		else
			return 0;


	}
	T add(const T array[], int arrayLength) {
		int i = 0;
		int count = 0;
		for (i = 0; i < arrayLength; ++i) {
			if ((add(array[i]) == 1))
				++count;
		}
		return count;

	}
	int getDataLength() { return dataLength; }
	void print()
	{
		for (int i = 0; i < dataLength; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

	T sum(){
		T temp = nullValue;
		for (int i = 0; i < dataLength; i++) {
			temp = temp + data[i];
		}
		return temp;
	}
};

