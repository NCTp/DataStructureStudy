const int MAX_ITEMS = 100;
#include <iostream>
template <class ItemType>
class UnsortedType
{
public:
	UnsortedType(); //Class constructor

	bool IsFull() const; //Check the list is full
	int LengthIs() const; //return the length of list
	void RetrieveItem(ItemType item, bool& found); //find the item in the list
	void InsertItem(ItemType item); //insert the item in the list
	void DeleteItem(ItemType item); //delete the item in the list
	void ResetList(); //reset the currentPos of list
	void GetNextItem(ItemType& item); //return the info[currrentPos]

private:
	int length;
	ItemType info[MAX_ITEMS];
	int currentPos;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
	length = 0;
	currentPos = -1;
}

template <class ItemType>
bool UnsortedType<ItemType>::IsFull() const { //Check the list is full
	if (length == MAX_ITEMS) {
		std::cout << "List is Full" << std::endl;
		return true;
	}
	else {
		
		return false;
	}
}

template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const { //return the length of list
	return length;
}

template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType item, bool& found) { //find the item in the list

	int location = 0;
	bool search = (location < length);
	found = false;

	while (search && !found) {
		if (info[location] == item) {
			found = true;
		}
		else {
			found = false;
			location++;
			search = (location < length);
		}
	}
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) { //insert the item in the list
	if (!IsFull()) {
		if (length == 0) {
			info[0] = item;
			length++;
		}
		else {
			info[length] = item;
			length++;
		}
	}
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) { //delete the item in the list
	bool found = false;
	for (int i = 0; i < length && !found; i++) {
		if (info[i] == item) {
			info[i] = info[length-1];
			length--;
			found = true;
		}
	}
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList() { //reset the currentPos of list
	currentPos = -1;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item) { //return the info[currrentPos]
	currentPos++;
	item = info[currentPos];
}