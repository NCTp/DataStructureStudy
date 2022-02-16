#pragma once
#include <iostream>
const int MAX_ITEMS = 10;

class FullStack {};

class EmptyStack {};

template <class ItemType>
struct NodeType { // Linked List Type
	ItemType info; // ���� �����ϴ� ������
	NodeType* next; // ���� ��带 ����Ű�� ������
};

template <class ItemType>
class StackLL {
public:

	StackLL();
	bool IsEmpty();
	bool IsFull();
	void Push(ItemType item);
	void Top(ItemType &item);
	void Pop();

private:
	int length;
	NodeType<ItemType>* top;
};

template <class ItemType>
StackLL<ItemType>::StackLL() {
	length = 0;
	top = NULL;
}

template <class ItemType>
bool StackLL<ItemType>::IsEmpty() {
	if (top == NULL) {
		//std::cout << "List is Empty" << std::endl;
		return true;
	}
	else {
		//std::cout << "List is not Empty" << std::endl;
		return false;
	}
}

template <class ItemType>
bool StackLL<ItemType>::IsFull() {
	if (length == 10) {
		//std::cout << "List is Full" << std::endl;
		return true;
	}
	else {
		//std::cout << "List is not Full" << std::endl;
		return false;
	}
}

template <class ItemType>
void StackLL<ItemType>::Push(ItemType item) {
	if (IsFull()) {
		throw FullStack();

	}
	else {
		NodeType<ItemType>* newNode; //���ο� ��� ����
		newNode = new NodeType<ItemType>;
		newNode->info = item; //���� �Է�
		newNode->next = top; //�� ����� next�� ������ top�� ����
		top = newNode; //newNode�� ���ο� top���� ����
		length++;

	}
}

template <class ItemType>
void StackLL<ItemType>::Top(ItemType &item) {
	if (IsEmpty()) {
		throw EmptyStack();
	}
	else {
		item = top->info;
	}
}

template <class ItemType>
void StackLL<ItemType>::Pop() {
	if (IsEmpty()) {
		throw EmptyStack();
	}
	else {
		NodeType<ItemType>* newNode; //���ο� ��� ����
		newNode = top; //���� top�� newNode�� ����
		top = top->next; //top�� ���� ��带 ����Ŵ
		delete newNode; //top�̾��� ������ �Ҵ� ����
	}
}




