#include <iostream>

#include "Tree.h"

int main() {

	Queue queue;
	int item1 = 1;
	int item2 = 7;
	int item3 = 2;
	int item4 = 8;
	int item5 = 9;

	Tree tree;

	std::ofstream file;
	file.open("treetest.txt");
	tree.InsertItem(item2);
	tree.InsertItem(item1);
	tree.InsertItem(item3);
	tree.InsertItem(item4);
	tree.InsertItem(item5);

	tree.Print(file);

	



}