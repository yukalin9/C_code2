#pragma once

class IntgerBuffer
{
protected:
	int dataCapacity;
	int *data;
	int dataLength;
public:
	~IntgerBuffer();
	void clear();
	int add(int value);
	int add(const int array[], int arrayLength);
	int removeFast(int index);
	int removeStable(int index);
	int index(int value) const;
	int rindex(int value) const;
	void print(int numberOfColumns, int columnWidth) const;
	int getCapacity() const { return dataCapacity; }
	int getLength() const { return dataLength; }
	void copy(const IntgerBuffer *other);
	bool compare(const IntgerBuffer *other) const;
	IntgerBuffer(int cap);
};



