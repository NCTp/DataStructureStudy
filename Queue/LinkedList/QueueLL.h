#pragma once
#include <iostream>

class FullQueue {};
class EmptyQueue {};

typedef int ItemType;

struct NodeType { // Linked List Type
	ItemType info;
	NodeType* next;
};

class QueType {
public:

	QueType(); // Constructor
	~QueType(); // Destructor
	
	void MakeEmpty(); // Make the list Empty
	bool IsEmpty() const; // Check the list is Empty
	bool IsFull() const; // Check the list is Full
	void Enqueue(ItemType newItem); // Enqueue the item
	void Dequeue(ItemType& item); // Dequeue the item

private:

	NodeType* front;
	NodeType* rear;
};

QueType::QueType() { // Class Constructor
	front = NULL; // Set the front and rear to NULL
	rear = NULL;
}

void QueType::MakeEmpty() {
	NodeType* tempPtr;

	while (front != NULL) { //front가 NULL이 될 때까지
		tempPtr = front; 
		front = front->next; // front를 next로 넘기면서 
		delete tempPtr;  // front에 저장된 포인터를 삭제
	}
	rear = NULL; // rear 까지 NULL로 바꿔준다.
}

QueType::~QueType() { //Class Destructor
	MakeEmpty();
}

bool QueType::IsFull() const {
	NodeType* location;
	try {
		location = new NodeType; // 새로운 값을 할당해보고
		delete location;
		return false;
	}
	catch (std::bad_alloc) // 할당되지 않으면 catch
	{
		return true;
	}
}

bool QueType::IsEmpty() const {
	return (front == NULL);
}

void QueType::Enqueue(ItemType item) {
	if (IsFull()) {
		throw FullQueue(); 
	}
	else {
		NodeType* newNode; 
		newNode = new NodeType;
		newNode->info = item; // 새로운 노드에 item의 값을 지정
		newNode->next = NULL; 
		if (rear == NULL) { 
			front = newNode; //rear = NULL, 즉 처음으로 값을 Enqueue하는 경우
		}
		else {
			rear->next = newNode; //rear의 다음을 newNode를 가리키게 한 후에
		}
		rear = newNode; // rear를 newNode로 갱신
	}
}

void QueType::Dequeue(ItemType& item) {
	if(IsEmpty()){
		throw EmptyQueue();
	}
	else {
		NodeType* tempPtr;
		tempPtr = front;
		item = front->info;
		front = front->next;
		if (front == NULL) { //front가 rear->next, 즉 NULL까지 닿은 경우에 rear까지 NULL하여 빈 리스트로 만들어줌.
			rear = NULL;
		}
		delete tempPtr;
	}
}
