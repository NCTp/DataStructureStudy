#pragma once


template <class ItemType>
struct HeapType { // MAX HEAP
	void ReheapDown(int root, int bottom);
	void ReheapDown_nonre(int root, int bottom);
	void ReheapUp(int root, int bottom);
	void ReheapUp_nonre(int root, int bottom);
	
	ItemType* elements;
	int numElements;
};

template <class ItemType>
void Swap(ItemType& first, ItemType& second) {
	ItemType temp;
	temp = first;
	first = second;
	second = temp;
}

template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom) {
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    if (leftChild <= bottom) // ���� root���� ���� ��Ұ� bottom���� ���� ��, (heap���� ��Ҹ� ä�� �� ���ʺ��� ä��� ������ leftChild�� ��)
    {
        if (leftChild == bottom) // bottom�� ���ٸ� 
            maxChild = leftChild; // maxChild, �� ���� ū child�� leftchild�� �ȴ�.
        else // bottom�� ���� ���� ��
        {
            if (elements[leftChild] <= elements[rightChild]) //left�� right�� ��
                maxChild = rightChild; // ū ���� maxChild�� �ȴ�.
            else
                maxChild = leftChild; 
        }
        if (elements[root] < elements[maxChild]) // root�� ������ maxchild�� ���� �� ũ�ٸ�
        {
            Swap(elements[root], elements[maxChild]); // root�� �Ʒ��� ������
            ReheapDown(maxChild, bottom); // ����Լ��� ��� ����
        }
    }
	
}

template <class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom) {
    int parent;

    if (bottom > root) {
        parent = (bottom - 1) / 2; //parent ��� ����
        if (elements[parent] < elements[bottom]) { //parent����� ������ bottom����� ���� ũ��
            Swap(elements[parent], elements[bottom]); //bottom�� ���� parent�� ���� ��ġ�� �ٲ��ش�.
            ReheapUp(root, parent); // ����Լ��� ��� ����
        }
    }

}