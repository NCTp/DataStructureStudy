#pragma once
#include <iostream>
const int MAX_ITEMS = 10;

class FullStack {};

class EmptyStack {};

template <class ItemType>
struct NodeType { // Linked List Type
	ItemType info; // 값을 저장하는 포인터
	NodeType* next; // 다음 노드를 가리키는 포인터
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
		NodeType<ItemType>* newNode; //새로운 노드 생성
		newNode = new NodeType<ItemType>;
		newNode->info = item; //정보 입력
		newNode->next = top; //새 노드의 next가 지금의 top을 지목
		top = newNode; //newNode를 새로운 top으로 지정
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
		NodeType<ItemType>* newNode; //새로운 노드 생성
		newNode = top; //현재 top을 newNode에 저장
		top = top->next; //top이 다음 노드를 가리킴
		delete newNode; //top이었던 포인터 할당 해제
	}
}




