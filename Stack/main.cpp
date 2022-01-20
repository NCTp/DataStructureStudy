#include <iostream>

#include "Stack.h"

int main() {
	Stack<int> stack;
	int temp;
	stack.Push(3);
	stack.Push(7);
	stack.Push(9);
	stack.Push(1);
	stack.Push(2);
	stack.Push(11);
	stack.Push(100);
	stack.Push(13);
	stack.Push(19);
	stack.Push(12);

	while (!stack.IsEmpty()) {
		stack.Top(temp);
		std::cout << temp << std::endl;
		stack.Pop();
	}



}