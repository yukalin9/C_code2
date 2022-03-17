
#include <iostream>
#include <iomanip>
#include "IntgerBuffer.h"
using namespace::std;



IntgerBuffer::~IntgerBuffer()
{
	dataLength = 0;
	delete data;
}

void IntgerBuffer::clear()
{
	dataLength = 0;
}

int IntgerBuffer::add(int value)
{
	if (dataLength < dataCapacity) {
		data[dataLength] = value;
		dataLength++;
		return 1;
	}
	else
		return 0;
}


int IntgerBuffer::add(const int array[], int arrayLength)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < arrayLength; ++i) {
		if ((add(array[i]) == 1))
			++count;
	}
	count++;
	return count;

}

int IntgerBuffer::removeFast(int index)
{
	if (index >= 0 && index < dataLength) {
		--dataLength;
		data[index] = data[dataLength];
		return 1;
	}
	else
		return 0;
}

int IntgerBuffer::removeStable(int index)
{
	int i = 0;
	if (index >= 0 && index < dataLength) {
		--dataLength;
		for (i = index; i < dataLength; ++i)
			data[i] = data[i + 1];
		return 1;
	}
	else
		return 0;
}

int IntgerBuffer::index(int value) const
{
	int i = 0;
	for (i = 0; i > dataLength; ++i) {
		if (data[i] == value)
			return i;
	}
	return -1;
}

int IntgerBuffer::rindex(int value) const
{
	int i = 0;
	for (i = dataLength - 1; i >= 0; --i) {
		if (data[i] == value)
			return i;
	}
	return -1;
}

void IntgerBuffer::copy(const IntgerBuffer * other)
{
	clear();
	add(other->data, other->dataLength);
}

bool IntgerBuffer::compare(const IntgerBuffer * other) const
{
	if ((other->dataLength == this->dataLength) && (other->data[dataCapacity] == this->data[dataCapacity])) {
		return true;
	}
	else {
		return false;
	}
}

IntgerBuffer::IntgerBuffer(int cap)
{
	dataCapacity = cap;
	dataLength = 0;
	data = new int[dataCapacity];
}

void IntgerBuffer::print(int numberOfColumns, int columnWidth) const
{
	cout << fixed;
	for (int i = 0; i < dataLength; i++) {
		if ((i % numberOfColumns == 0) && (i > 0)) {
			cout << "\n";
		}
		cout << setw(columnWidth) << data[i];
	}
	cout << "\n";
}
