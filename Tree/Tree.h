#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "QueueLL.h"

typedef int ItemType;
struct TreeNode {
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

class Tree {
public:
	Tree(); // constructor
	~Tree(); // destructor

	bool IsEmpty() const;
	bool IsFull() const;
	void MakeEmpty();
	int LengthIs() const;
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetTree(OrderType order);
	void GetNextItem(ItemType& item, OrderType order, bool& finished);
	void Print(std::ofstream& outFile) const;
	
	
private:
	TreeNode* root; // Tree root
	Queue preQue; // 순서에 따라 저장되는 queue
	Queue inQue;
	Queue postQue;
};

void Destroy(TreeNode*& tree) {
	if (tree != NULL) {
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

Tree::Tree() {
	root = NULL;
}

Tree::~Tree() {
	Destroy(root);
}

bool Tree::IsFull() const {
	TreeNode* location;
	try {
		location = new TreeNode;
		delete location;
		return false;
	}
	catch (std::bad_alloc) {
		return true;
	}
}

bool Tree::IsEmpty() const {
	return root == NULL;
}

void Tree::MakeEmpty() {
	Destroy(root);
	root = NULL;
}

int CountNodes(TreeNode* tree) {
	if (tree == NULL) {
		return 0;
	}
	else {
		return CountNodes(tree->left) + CountNodes(tree->right) + 1; // 재귀함수를 통한 노드의 수 세기
	}
}

int Tree::LengthIs() const{
	return CountNodes(root);
}

void Retrieve(TreeNode* tree, ItemType& item, bool& found) {
	if (tree == NULL) {
		found = false;
	}
	else if (item < tree->info) {
		Retrieve(tree->left, item, found);
	}
	else if (item > tree->info) {
		Retrieve(tree->right, item, found);
	}
	else {
		item = tree->info;
		found = true;
	}
}

void Tree::RetrieveItem(ItemType& item, bool& found) { // find the item
	Retrieve(root, item, found);
}

void Insert(TreeNode*& tree, ItemType item) { //pointer, reference
	if (tree == NULL) { // 트리가 비어있을 경우
		tree = new TreeNode;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}
	else if(item < tree->info){ 
		Insert(tree->left, item);
	}
	else {
		Insert(tree->right, item);
	}
}

void Tree::InsertItem(ItemType item) {
	Insert(root, item);
}

void GetPredecessor(TreeNode* tree, ItemType& data) { // find the rightmost node
	while (tree->right != NULL) {
		tree = tree->right;
	}
	data = tree->info;
}

void Delete(TreeNode*& tree, ItemType item);

void DeleteNode(TreeNode*& tree) {
	ItemType data;
	TreeNode* tempPtr;

	tempPtr = tree;
	if (tree->left == NULL) {
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL) {
		tree = tree->left;
		delete tempPtr;
	}
	else {
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);
	}
}

void Delete(TreeNode*& tree, ItemType item) {
	if (item < tree->info) {
		Delete(tree->left, item);
	}
	else if (item > tree->info) {
		Delete(tree->right, item);
	}
	else {
		DeleteNode(tree);
	}
}

void Tree::DeleteItem(ItemType item) {
	Delete(root, item);
}

void PrintTree(TreeNode* tree, std::ofstream& outFile) { // 텍스트 파일에 값을 작은 값부터 print
	if (tree != NULL) {
		PrintTree(tree->left, outFile);
		outFile << tree->info;
		PrintTree(tree->right, outFile);
	}
}

void Tree::Print(std::ofstream& outFile) const {
	PrintTree(root, outFile);
}

void PreOrder(TreeNode* tree, Queue& preQue) {  // node -> left -> right
	if (tree != NULL) {
		preQue.Enqueue(tree->info);
		PreOrder(tree->left, preQue);
		PreOrder(tree->right, preQue);
	}
}

void InOrder(TreeNode* tree, Queue& inQue) { // left -> node -> right
	if (tree != NULL) {
		InOrder(tree->left, inQue);
		inQue.Enqueue(tree->info);
		InOrder(tree->right, inQue);
	}
}

void PostOrder(TreeNode* tree, Queue& postQue) { // left -> right -> node
	if (tree != NULL) {
		PostOrder(tree->left, postQue);
		PostOrder(tree->right, postQue);
		postQue.Enqueue(tree->info);
	}
}

void Tree::GetNextItem(ItemType& item, OrderType order, bool& finished) { 
	finished = false;
	switch (order) {
	case PRE_ORDER: 
		preQue.Dequeue(item);
		if (preQue.IsEmpty()) {
			finished = true;
		}
		break;
	case IN_ORDER:
		inQue.Dequeue(item);
		if (inQue.IsEmpty()) {
			finished = true;
		}
		break;
	case POST_ORDER:
		postQue.Dequeue(item);
		if (postQue.IsEmpty()) {
			finished = true;
		}
		break;
	}
}