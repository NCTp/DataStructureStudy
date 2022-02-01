# DataStructureStudy
2학년 2학기 자료구조에 대한 복습입니다.   
 
소스코드는 C++로 작성합니다.   


# 다음과 같은 자료구조를 공부합니다.   
(★ 표시는 소스코드 업로드시 표기)   
-UnsortedList ★    
-SortedList ★    
-Stack ★    
-Queue ★    
-Graph ★    
-Tree ★   
-Priority Queue ★      
-Heap ★     
-HashTable   

# 데이터를 저장하는 방법   

데이터를 자료구조에 저장하는 방법 중 Array를 이용하는 방법과 Linked-List를 사용하는 방법을 알아보자.   
   
Array를 사용할 때는 언어에서 제공하는 Array를 사용하여 데이터들을 관리한다.   
Array의 장점은 데이터별 접근이 빠르다.   
반면 단점은 용량을 미리 정해둔다는 점과 삽입과 삭제가 어렵다는 점이다.   
   
Linked-List로 데이터를 관리할 때는 Node를 선언한다.   
Node에는 데이터의 값을 저장하는 Info와 그 다음 데이터를 가리키는 Next를 포인터로 선언하여 사용한다.   
여기서 Back을 포인터로 추가로 선언해주면 양쪽 방향을 가리키는 Double-Linked-List가 된다.   
   
Linked Structure를 사용할 때 장점은 동적 메모리 할당이 가능해지고,   
간단한 삽입/삭제처리가 가능해진다. ( 포인터의 값만 바꿔주면 끝 )   
반대로 단점은 미리 사용할 메모리를 정해놓는 Array와 달리 사용하는 데이터가 많아질수록   
사용하는 메모리가 많아진다는 단점이 있다.   
   

# Unsorted List, Sorted List   

데이터들이 정렬되어 들어있는 자료구조가 Sorted List, 정렬되지 않은 자료구조가 Unsorted List이다.   
Sorted List는 정해놓은 Key value에 따라서 데이터를 삽입하거나 빼낼 때 값들이 정렬되야 한다.   


#  Stack   

Stack은 새로운 데이터들을 구조의 가장 위(TOP)에 추가할 수 있는 자료구조다.   
Stack에서 자료를 뺄 때에는 데이터들 중 가장 위(Top)에 있는 데이터만을 빼서 사용할 수 있다.   
이를 Last in, First out (LIFO)라고 부른다.   

예를 들어, 데이터를 순서대로 1, 2, 3, 4, 5, 6, 7을 삽입했을 때,    
데이터를 다시 빼올 때에는 7, 6, 5, 4, 3, 2, 1의 순서로 데이터를 뺄 수 있다.


#  Queue   

Queue는 Stack과는 다르게 가장 먼저 넣은 데이터값을 가장 먼저 뺄 수 있는 자료구조다.   
Queue에서 자료를 뺄 때 데이터들 중에 가장 앞(front)에 존재하는 데이터를 빼서 사용하고,   
데이터를 삽입할 때는 꼬리(rear)부분에 데이터를 삽입하게 된다.
이를 First in, First out (FIFO)라고 부른다.

예를 들어, 데이터를 순서대로 1, 2, 3, 4, 5, 6, 7을 삽입했을 때,   
데이터를 다시 빼올 때에는 1, 2, 3, 4, 5, 6, 7의 순서로 데이터를 빼내게 된다.

#  Tree   

Graph의 일종인 Tree는 여러 노드가 한 노드를 가리키지 않고, 노드끼리 연결되는 길이 단 하나인 자료구조다.   
Tree는 가장 위의 노드인 Root Node를 시작점으로 하여 밑으로 뻗어나가는 자료구조다.   
     
A노드가 있고 B노드가 있을 때, A -> B 일 경우 A가 Parent Node, B가 Child Node가 된다.      
Tree에서 각 Child 노드들은 단 하나의 Parent 노드만을 갖는다.   
이 때 트리구조 가장 아래에 있는, 즉 Child Node를 갖지 않는 노드들을 Leaf Nodes라고 한다.



