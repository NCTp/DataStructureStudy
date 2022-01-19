#pragma once
#include <iostream>

const int MAX_ITEMS = 100;

template <class ItemType>
class SortedType {
public:
	SortedType(); // class constructor

	bool IsFull() const; //Check the list is full
	int LengthIs() const; //return the length of list
	void RetrieveItem(ItemType item, bool& found); //find the item in the list
	void InsertItem(ItemType item); //insert the item in the list
	void DeleteItem(ItemType item); //delete the item in the list
	void ResetList(); //reset the currentPos of list
	void GetNextItem(ItemType& item); //return the info[currrentPos]

private:
	int length;
	int info[MAX_ITEMS];
	int currentPos;

};

template <class ItemType>
SortedType<ItemType>::SortedType() { // class constructor
	length = 0;
	currentPos = -1;
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const { //Check the list is full
	if (length == MAX_ITEMS) {
		std::cout << "List is Full" << std::endl;
		return true;
	}
	else {
		return false;
	}
}

template <class ItemType>
int SortedType<ItemType>::LengthIs() const { //return the length of list
	return length;
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType item, bool& found) { //find the item user want in the list

	int midPoint;
	int first = 0;
	int last = length - 1;

	bool search = first <= last;
	found = false;

	while (search && !found) {

		midPoint = (first + last) / 2;
		if (info[midPoint] > item) {
			first = midPoint + 1;
			search = first <= last;

		}
		else if (info[midPoint] < item) {
			last = midPoint - 1;
			search = first <= last;
		}
		else {
			found = true;
			std::cout << "Item is in the list" << std::endl;
		}
	}
	
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item) { //insert the item in the list

	bool found = false;
	int index = 0;
	bool search = index < length;

	while (!found && search) {
		if (info[index] > item) {
			index++;
			found = false;
			bool search = index < length;
		}
		else {
			found = true;
		}
	}
	
	for (int i = length; i > index; i--) {
		info[i] = info[i - 1];
		
	}
	info[index] = item;
	length++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) { //delete item user want

	int index = 0;
	ItemType temp;
	bool search = true;
	bool found = false;

	while (!found && search) {
		if (info[index] != item) {
			index++;
			search = index < length;
			found = false;
		}
		else {
			found = true;
		}
	}
	for (int i = index; i < length; i++) {
		info[i] = info[i + 1];

	}
	length--;
}

template <class ItemType>
void SortedType<ItemType>::ResetList() { // reset the currentPos to -1
	currentPos = -1;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item) { //return the info[currrentPos]
	currentPos++;
	item = info[currentPos];
}