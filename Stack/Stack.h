#pragma once
#include <iostream>

const int MAX_ITEMS = 10;

class FullStack

{};

class EmptyStack

{};

template <class ItemType>
class Stack {
public:
	Stack(); // class constructor
	bool IsEmpty() const; // check the list is empty
	bool IsFull() const; // check the list is full
	void Push(ItemType item); // push the item in the list
	void Top(ItemType &item); // get an item in the top of the list
	ItemType Pop(); // down the top

private:
	int top;
	ItemType info[MAX_ITEMS];

};

template <class ItemType>
Stack<ItemType>::Stack() {
	top = -1;
}

template <class ItemType>
bool Stack<ItemType>::IsEmpty() const {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

template <class ItemType>
bool Stack<ItemType>::IsFull() const {
	if (top == MAX_ITEMS - 1) {
		return true;
	}
	else {
		return false;
	}
}

template <class ItemType>
void Stack<ItemType>::Push(ItemType item) {
	if (IsFull()) {
		throw FullStack();
	}
	top++;
	info[top] = item;
	
}

template <class ItemType>
void Stack<ItemType>::Top(ItemType& item) {
	if (IsEmpty()) {
		throw EmptyStack();
	}
	item = info[top];
}

template <class ItemType>
ItemType Stack<ItemType>::Pop() {
	if (IsEmpty())
		throw EmptyStack();
	top--;
}
