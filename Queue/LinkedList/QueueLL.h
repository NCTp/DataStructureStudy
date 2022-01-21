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
	QueType(int max); 
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

	while (front != NULL) { //front�� NULL�� �� ������
		tempPtr = front; 
		front = front->next; // front�� next�� �ѱ�鼭 
		delete tempPtr;  // front�� ����� �����͸� ����
	}
	rear = NULL; // rear ���� NULL�� �ٲ��ش�.
}

QueType::~QueType() { //Class Destructor
	MakeEmpty();
}

bool QueType::IsFull() const {
	NodeType* location;
	try {
		location = new NodeType; // ���ο� ���� �Ҵ��غ���
		delete location;
		return false;
	}
	catch (std::bad_alloc) // �Ҵ���� ������ catch
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
		newNode->info = item; // ���ο� ��忡 item�� ���� ����
		newNode->next = NULL; 
		if (rear == NULL) { 
			front = newNode; //rear = NULL, �� ó������ ���� Enqueue�ϴ� ���
		}
		else {
			rear->next = newNode; //rear�� ������ newNode�� ����Ű�� �� �Ŀ�
		}
		rear = newNode; // rear�� newNode�� ����
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
		if (front == NULL) { //front�� rear->next, �� NULL���� ���� ��쿡 rear���� NULL�Ͽ� �� ����Ʈ�� �������.
			rear = NULL;
		}
		delete tempPtr;
	}
}