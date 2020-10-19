/*
*MyArray.cpp
* Lab: 4 Exercise A
* Completed by Ziad Chemali
* Submission Date: October 18,2020
*/


#include "MyArray.h"
#include <iostream>
MyArray::MyArray() {
	sizeM = 0;
	storageM = new EType[0];
}
MyArray::MyArray(const EType* builtin, int sizeA) {
	if (sizeA >= 0 && builtin != nullptr) {
		sizeM = sizeA;
		delete[] storageM;
		storageM = new EType[sizeM];
		for (int i = 0;i < sizeA ;i++) {
			storageM[i] = builtin[i];
		}


	}
	else
		std::cout << "Error, cant copy an empty array\n";
}
MyArray::MyArray(const MyArray& source) {
	if (source.storageM !=nullptr) {
		delete[] storageM;
		sizeM = source.sizeM;
		storageM = new EType[sizeM];
		for (int i = 0;i < source.sizeM ;i++) {
			storageM[i] = source.storageM[i];
		}
	}
}
MyArray&  MyArray :: operator =(const MyArray& rhs) {
	if (this != &rhs)
	{
		delete[] storageM;
		sizeM = rhs.sizeM;
		storageM = new EType[sizeM];
		for (int i = 0;i < rhs.sizeM ;i++) {
			storageM[i] = rhs.storageM[i];
		}
	}
	return *this;
}
MyArray::  ~MyArray() {
	delete[] storageM;
}
int MyArray::size() const {
	return this->sizeM;
}
EType MyArray::at(int i) const {
	return this->storageM[i];
}

void MyArray::set(int i, EType new_value)
{
	if (i >= 0 && i < this->size()) {
		storageM[i] = new_value;
}
}

void MyArray::resize(int new_size)
{
	if (new_size >= 0) {
		sizeM = new_size;
		EType *temp = new EType[new_size];
		for (int i = 0;i < new_size ;i++) {
			temp[i] = this->storageM[i];
		}
		delete[] storageM;
		storageM = temp;

	}
}

