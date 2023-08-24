/**********************************************************************************************
* Name            : ArcadeApp.cpp
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       :
* Update          : 08/23/2023
* Description     : Project Arcade App in C++
*
**********************************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
#include "Vec2D.h"
using namespace std;

class DynamicIntArray
{
private:
	int* moptrData;
	size_t mSize;
	size_t mCapacity;
	static const size_t INITIAL_CAPACITY = 10;

public:
	DynamicIntArray(): moptrData(nullptr), mSize(0), mCapacity(0){}
	DynamicIntArray(const DynamicIntArray& otherArray);

	DynamicIntArray& operator=(const DynamicIntArray& otherArray);
	// should clean up the memory
	~DynamicIntArray();

	inline size_t Size() const { return mSize; }
	inline size_t Capacity() const { return mCapacity; }

	// Allocates the dynamic array
	bool Init(size_t capacity = INITIAL_CAPACITY);
	bool Reserve(size_t capacity);
	bool Resize(size_t newSize);

	bool PushBack(int newVal);
	bool PopBack(int& value);

	const int& operator[](size_t index) const;
	int& operator[](size_t index);
};


DynamicIntArray::DynamicIntArray(const DynamicIntArray& otherArray)
{
	bool result = Init(otherArray.mCapacity);
	assert(result);
	mSize = otherArray.mSize;

	for (size_t i = 0; i < mSize; ++i)
		moptrData[i] = otherArray.moptrData[i];
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& otherArray)
{
	if (this == &otherArray)
		return *this;
	if (moptrData != nullptr)
		delete[] moptrData;

	bool result = Init(otherArray.mCapacity);
	assert(result);

	mSize = otherArray.mSize;

	for (size_t i = 0; i < mSize; ++i)
		moptrData[i] = otherArray.moptrData[i];

	return *this;
}


void FuncFoo(DynamicIntArray copiedDynamicArray)
{

}

int main(int argc, const char* argv[])
{
	DynamicIntArray dynArray;
	int element0 = dynArray[0];
	dynArray[2] = 10;

	cout << "!!!Dynamic Memory!!!" << endl;

	/*
	Vec2D aVec{3,7};
	Vec2D resultVec = aVec * 3;
	cout << resultVec << endl;
	*/

	cout << endl;
	system("Pause");
	return 0;
}

