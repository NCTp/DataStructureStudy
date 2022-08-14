# DataStructureStudy
나볼라고 만든 자료구조 복습
 
 + C++  


# 다음과 같은 자료구조를 공부합니다.   
(★ 표시는 소스코드 업로드시 표기)   
 + UnsortedList ★    
 + SortedList ★    
 + Stack ★    
 + Queue ★    
 + Graph ★    
 + Tree ★   
 + Priority Queue ★      
 + Heap ★     
 + HashTable   

# 데이터를 저장하는 방법   

데이터를 자료구조에 저장하는 방법 중 Array를 이용하는 방법과 Linked-List를 사용하는 방법을 알아보자.   
   
Array을 사용할 때는 언어에서 제공하는 Array를 사용하여 데이터들을 관리한다.   
Array의 장점은   
 + 데이터별 접근이 빠르다. (Linked-List와는 다르게 무작위 접근이 가능)   

반면 단점은   
 + 용량을 미리 정해두기 때문에 리스트의 크기에 크기에 제한이 있다.
 + 삽입과 삭제가 어렵다. (많은 연산 필요)   
 
   
Linked-List로 데이터를 관리할 때는 Node를 선언한다.   
Node에는 데이터의 값을 저장하는 Info와 그 다음 데이터를 가리키는 Next를 포인터로 선언하여 사용한다.   
여기서 Back을 포인터로 추가로 지정해주면 양쪽 방향을 가리키는 Double-Linked-List가 된다.   
   
Linked Structure를 사용할 때 장점으론
 + 동적 메모리 할당이 가능하다. ( 리스트의 크기의 영향 X )   
 + 간단한 삽입/삭제처리가 가능해진다. ( 포인터의 값만 바꿔주면 끝 )   

반대로 단점은
 + 미리 사용할 메모리를 정해놓는 Array와 달리 사용하는 데이터가 많아질수록 사용하는 메모리가 많아진다는 단점이 있다.   
 + Next 포인터를 통해 데이터들이 연결되어 있으므로 순차 검색만이 허용된다.   
   

# Unsorted List, Sorted List   

데이터들이 정렬되어 들어있는 자료구조가 Sorted List, 정렬되지 않은 자료구조가 Unsorted List이다.   
Sorted List는 정해놓은 Key value에 따라서 데이터를 삽입하거나 빼낼 때 값들이 정렬되야 한다.   


#  Stack   

Stack은 새로운 데이터들을 구조의 가장 위(Top)에 추가할 수 있는 자료구조다.   
Stack에서 자료를 뺄 때에는 데이터들 중 가장 위(Top)에 있는 데이터만을 빼서 사용할 수 있다.   
마지막에 넣은 데이터가 가장 먼저 나온다. 이를 Last in, First out (LIFO)라고 부른다.   

예를 들어, 데이터를 순서대로 1, 2, 3, 4, 5, 6, 7을 삽입했을 때,    
데이터를 다시 빼올 때에는 7, 6, 5, 4, 3, 2, 1의 순서로 데이터를 뺄 수 있다.


#  Queue   

Queue는 Stack과는 다르게 가장 먼저 넣은 데이터값을 가장 먼저 뺄 수 있는 자료구조다.   
Queue에서 자료를 뺄 때 데이터들 중에 가장 앞(front)에 존재하는 데이터를 빼서 사용하고,   
데이터를 삽입할 때는 꼬리(rear)부분에 데이터를 삽입하게 된다.
처음으로 넣은 데이터가 가장 먼저 나온다. 이를 First in, First out (FIFO)라고 부른다.

예를 들어, 데이터를 순서대로 1, 2, 3, 4, 5, 6, 7을 삽입했을 때,   
데이터를 다시 빼올 때에는 1, 2, 3, 4, 5, 6, 7의 순서로 데이터를 빼내게 된다.


#  Graph    
Graph는 Vertex와 Edge들의 집합으로 이루어진다. 이 때 Vertex들은 Finite하고, Non-empty 해야한다.  
|용어|내용|   
|---|---|
|Node|노드|
|Edge|노드 사이를 연결하는 선|
|Vertex|노드의 위치를 의미, Node와 혼용가능|
|Adjacent Vertex, Adjacent Nodes|Edge를 통해 연결된 Vertex를 의미|
|Directed graphs, Undirected graphs|Edge의 방향이 있는가 없는가에 따라 다름|
|Weighted graph|Edge가 가중치를 가지고 있음|
|Graph Searching|그래프 탐색|
|Depth-First-Search(DFS)|깊이를 우선하여 탐색, 다음 분기로 넘어가기 전 해당 분기의 모든 노드를 탐색, Stack이용이 권장됨|
|Breadth-First-Search(BFS)|넓이를 우선하여 탐색, 인접한 노드들을 우선탐색, Queue이용이 권장됨|


#  Tree   

Graph의 일종인 Tree는 여러 노드가 한 노드를 가리키지 않고, 노드끼리 연결되는 길이 단 하나인 자료구조다.   
Tree는 가장 위의 노드인 Root Node를 시작점으로 하여 밑으로 뻗어나가는 자료구조다.   
     
A노드가 있고 B노드가 있을 때, A -> B 일 경우 A가 Parent Node, B가 Child Node가 된다.      
Tree에서 각 Child 노드들은 단 하나의 Parent 노드만을 갖는다.   
이 때 트리구조 가장 아래에 있는, 즉 Child Node를 갖지 않는 노드들을 Leaf Nodes라고 한다.

Tree Traversal(트리 탐색)은 크게 Pre-Order, Post-Order, In-Order 세가지로 나뉜다.   

 + Pre-Order = Root -> Left -> Right   
 + Post-Order = Left -> Right -> Root   
 + In-Order = Left -> Root -> Right   
   

|용어|내용|   
|---|---|
|Level|Tree의 각 단계를 의미|
|Height|Tree의 높이를 의미|
|Full Tree|꽉 찬 트리를 의미, 모든 노드가 0개 혹은 2개의 자식 노드를 가질 때|
|Complete Tree|오른쪽 제일 아래가 비어있는 트리, 마지막 level(leaf nodes)에서의 요소들이 왼쪽부터 채워진다.|
|Binary Tree|이진 트리, 모든 노드의 자식이 최대 두개이고, 노드 간에는 단 하나의 길로만 연결됨|


# Heap  
Binary Tree이면서 모양과 순서에 조건이 있는 경우다. 조건은 다음과 같다.   
Shape Property(모양): complete binery tree이어야 한다.
Order Property(순서): 해당 노드의 값은 자식보다 크거나 같아야 한다. (Max Heap일 경우.)      
가장 큰 값이 Root에 존재하는 경우가 Max Heap,   
가장 작은 값이 Root에 존재하는 경우가 Min Heap 이다.    
당연히 Max Heap라면 부모 노드의 값이 자식 노드의 값보다 크고, Min Heap이라면 그 반대이다.   

# Hash Table   
Key-Value Structure (Dictionary)   
먼저 Dictionary란 데이터를 (Key, Value)로 저장하는 자료구조이다.   
   
|Key|Value|
|---|---|
|Key_0|Value_0|
|Key_1|Value_1|
|Key_2|Value_2|
|...|...|

Hash Function을 통해 Value에 대응하는 고유한 Key값을 생성한다.   
   
일반적으로 배열에서 값을 찾을 때 선형 탐색을 하므로 시간복잡도가 O(n)이 되지만,   
Hash Table의 경우에는 어떤 데이터를 찾더라도 Key에 대응하는 Value를 찾는 한 단계만 거치므로 평균 시간복잡도가 O(1)이라는 장점이 있다. (Collision이 없을 경우에)      
즉, 데이터 탐색이 매우 빠른 자료구조이다.   
   
Hash Function이 다른 Key에 대하여 다른 값을 준 경우, 이를 해시 충돌(Hash Collision)이라고 한다.   
이 때 해결법은 해당 인덱스에 배열을 추가하여 여러 값을 저장하는 방식이 있는데,   
이 경우에 값을 찾을 때 배열을 선형탐색하게될 것이므로 시간복잡도가O(n)까지 증가할 수 있다. 이 방법을 분리 연결법(Separate Chaning)이라고 한다.   
또 하나의 해결법이 있는데, 이 방법은 개방 주소법(Open Addressing)이라고 한다.   
이 때는 중복되는 인덱스 안에 여러 값을 저장하는 것이 아니라 해시 테이블 내의 비어있는 다른 공간을 사용하여 중복되는 데이터를 저장하는 방식이다.   



