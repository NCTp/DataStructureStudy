#pragma once
#include <iostream>
#include "Heap.h"
class FullPQ {};
class EmptyPQ {};

template <class ItemType>
class PQType {

public:
	PQType(int); //class constructor
	~PQType();

	void MakeEmpty(); // make the queue empty
	bool IsEmpty() const; // check the queue is empty
	bool IsFull() const; // check the queue is full
 	void Enqueue(ItemType newItem); // enqueue the item
	void Dequeue(ItemType& item); // dequeue the item

private:
	int length;
	HeapType<ItemType> items;
	int maxItems;
};

template <class ItemType>
PQType<ItemType>::PQType(int max) {
	maxItems = max;
	items.elements = new ItemType[max];
	length = 0;
}

template <class ItemType>
PQType<ItemType>::~PQType() {
	delete[] items.elements;
}

template <class ItemType>
void PQType<ItemType>::MakeEmpty() {
	length = 0;
}

template <class ItemType>
bool PQType<ItemType>::IsEmpty() const {
	return length == 0;
}

template <class ItemType>
bool PQType<ItemType>::IsFull() const {
	return length == maxItems;
}

template <class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item) {
	if (IsFull()) {
		throw EmptyPQ();
	}
	else {
		item = items.elements[0]; //item에 dequeue할 값을 넣고
		items.elements[0] = items.elements[length - 1]; // 끝으로 보낸 뒤에
		length--; // length를 줄임
		items.ReheapDown(0, length - 1); // reheapdown을 통해 max heap의 형태 유지
	}
}

template <class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem) {
	if (IsFull()) {
		throw FullPQ();
	}
	else {
		length++; // 길이를 늘려주고
		items.elements[length - 1] = newItem; // newItem을 추가
		items.ReheapUp(0, length - 1); // reheapup을 통해 max heap의 형태 유지
	}
}