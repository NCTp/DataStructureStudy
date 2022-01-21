#pragma once
#include <iostream>

const int max = 100;
class FullQueue
{};

class EmptyQueue
{};

template <class ItemType>
class Queue {
public:
	Queue(); //class constructor
	~Queue(); //class destructor

	bool IsFull() const; // check the list is full
	bool IsEmpty() const; // check the list is empty
	void Dequeue(ItemType& item); // dequeue the item
	void Enqueue(ItemType item); // enqueue the item

private:
	
	ItemType* info;
	int front;
	int rear;
};

template <class ItemType>
Queue<ItemType>::Queue() {
	info = new ItemType[max];
	front = max - 1;
	rear = max - 1;
	
}

template <class ItemType>
Queue<ItemType>::~Queue() {
	delete[] info;
}

template <class ItemType>
bool Queue<ItemType>::IsFull() const {
	return ((rear + 1) % max == front);
}

template <class ItemType>
bool Queue<ItemType>::IsEmpty() const {
	return (rear == front);
}

template <class ItemType>
void Queue<ItemType>::Enqueue(ItemType item) {
	if (IsFull()) {
		throw FullQueue();
	}
	else {
		rear = (rear + 1) % max;
		info[rear] = item;
	}
}

template <class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item){
	if (IsEmpty()) {
		throw EmptyQueue();
	}
	else{
		front = (front + 1) % max;
		item = info[front];

	}
}