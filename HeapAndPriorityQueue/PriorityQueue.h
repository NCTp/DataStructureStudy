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
		item = items.elements[0]; //item�� dequeue�� ���� �ְ�
		items.elements[0] = items.elements[length - 1]; // ������ ���� �ڿ�
		length--; // length�� ����
		items.ReheapDown(0, length - 1); // reheapdown�� ���� max heap�� ���� ����
	}
}

template <class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem) {
	if (IsFull()) {
		throw FullPQ();
	}
	else {
		length++; // ���̸� �÷��ְ�
		items.elements[length - 1] = newItem; // newItem�� �߰�
		items.ReheapUp(0, length - 1); // reheapup�� ���� max heap�� ���� ����
	}
}