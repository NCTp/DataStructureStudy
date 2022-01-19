#include <iostream>

#include "SortedList.h"

int main() {
	SortedType<int> list_1;
	bool found;
	int temp = 0;
	list_1.InsertItem(0);
	list_1.InsertItem(10);
	list_1.InsertItem(5);
	list_1.InsertItem(2);
	list_1.InsertItem(400);
	list_1.InsertItem(77);
	list_1.InsertItem(41);
	list_1.InsertItem(2);
	list_1.InsertItem(1);
	list_1.InsertItem(10);

	for (int i = 0; i < 10; i++) {
		
		list_1.GetNextItem(temp);
		std::cout << temp << std::endl;
	}

	list_1.ResetList();

	std::cout << "Reset List" << std::endl;



}