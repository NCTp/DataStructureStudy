#include <iostream>

#include "UnsortedList.h"

int main() {
	UnsortedType<int> list_1;
	int temp = 0;
	for (int i = 0; i < 10; i++) {
		list_1.InsertItem(i);

	}
	for (int i = 0; i < 10; i++) {
		
		list_1.GetNextItem(temp);
		std::cout << temp << std::endl;
	}
	
}