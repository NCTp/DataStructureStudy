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
    if (leftChild <= bottom) // 만약 root밑의 왼쪽 요소가 bottom보다 작을 때, (heap에서 요소를 채울 때 왼쪽부터 채우기 때문에 leftChild를 비교)
    {
        if (leftChild == bottom) // bottom과 같다면 
            maxChild = leftChild; // maxChild, 즉 가장 큰 child는 leftchild가 된다.
        else // bottom과 같이 않을 때
        {
            if (elements[leftChild] <= elements[rightChild]) //left와 right를 비교
                maxChild = rightChild; // 큰 쪽이 maxChild가 된다.
            else
                maxChild = leftChild; 
        }
        if (elements[root] < elements[maxChild]) // root의 값보다 maxchild의 값이 더 크다면
        {
            Swap(elements[root], elements[maxChild]); // root를 아래로 보내고
            ReheapDown(maxChild, bottom); // 재귀함수로 계속 실행
        }
    }
	
}

template <class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom) {
    int parent;

    if (bottom > root) {
        parent = (bottom - 1) / 2; //parent 노드 지정
        if (elements[parent] < elements[bottom]) { //parent노드의 값보다 bottom노드의 값이 크면
            Swap(elements[parent], elements[bottom]); //bottom의 값을 parent의 값과 위치를 바꿔준다.
            ReheapUp(root, parent); // 재귀함수로 계속 실행
        }
    }

}