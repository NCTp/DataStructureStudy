#include <iostream>

#include "QueueLL.h"

int main() {
	QueType queue;
	int temp;
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(6);
	queue.Enqueue(4);
	queue.Enqueue(11);
	queue.Enqueue(13);
	queue.Enqueue(3);
	queue.Enqueue(77);
	queue.Enqueue(50);

	while (!queue.IsEmpty()) {
		queue.Dequeue(temp);
		std::cout << temp << std::endl;

	}

	std::cout << " ----------------- " << std::endl;

	queue.Enqueue(13);
	queue.Enqueue(3);
	queue.Enqueue(77);
	queue.Enqueue(50);

	while (!queue.IsEmpty()) {
		queue.Dequeue(temp);
		std::cout << temp << std::endl;

	}



}