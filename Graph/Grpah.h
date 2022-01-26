#pragma once
#include "Queue.h"
const int NULL_EDGE = 0;

template <class VertexType>
class Graph {
public:
	Graph();
	Graph(int maxV);
	~Graph();

	void AddVertex(VertexType vertex);
	void AddEdge(VertexType fromVertex, VertexType toVertex, int weight);
	int WeightIs(VertexType vertices, VertexType vertex);
	void GetToVertices(VertexType vertex, Queue<VertexType>& adjVertices);
	void DeleteEdge(VertexType fromVertex, VertexType toVertex);
	bool DepthFirstSearch(VertexType startVertex, VertexType endVertex);

private:
	int numVertices;
	int maxVertices;
	VertexType* vertices;
	int edges[50][50];
	bool* marks;
};

template <class VertexType>
Graph<VertexType>::Graph() {
	numVertices = 0;
	maxVertices = 50;
	vertices = new VertexType[50];
	marks = new bool[50]
}

template<class VertexType>
Graph<VertexType>::Graph(int maxV){
	numVertices = 0;
	maxVertices = maxV;
	vertices = new VertexType[maxV];
	marks = new bool[maxV];
}

template<class VertexType>
// Post: arrays for vertices and marks have been deallocated.
Graph<VertexType>::~Graph(){
	delete[] vertices;
	delete[] marks;
}

template<class VertexType>
void Graph<VertexType>::AddVertex(VertexType vertex){
	vertices[numVertices] = vertex;

	for (int index = 0; index < numVertices; index++)
	{
		edges[numVertices][index] = NULL_EDGE;
		edges[index][numVertices] = NULL_EDGE;
	}
	numVertices++;
}

template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex){
	int index = 0;

	while (!(vertex == vertices[index]))
		index++;
	return index;
}

template<class VertexType>
void Graph<VertexType>::AddEdge(VertexType fromVertex,
	VertexType toVertex, int weight){
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	edges[row][col] = weight;
}

template<class VertexType>
int Graph<VertexType>::WeightIs
(VertexType fromVertex, VertexType toVertex){
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	return edges[row][col];
}

template<class VertexType>
void Graph<VertexType>::GetToVertices(VertexType vertex,
	Queue<VertexType>& adjVertices){
	int fromIndex;
	int toIndex;

	fromIndex = IndexIs(vertices, vertex);
	for (toIndex = 0; toIndex < numVertices; toIndex++)
		if (edges[fromIndex][toIndex] != NULL_EDGE)
			adjVertices.Enqueue(vertices[toIndex]);
}

template<class VertexType>
void Graph<VertexType>::DeleteEdge(VertexType fromVertex, VertexType toVertex) {
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	edges[row][col] = NULL_EDGE;

}

template<class VertexType>
bool Graph<VertexType>::DepthFirstSearch(VertexType startVertex, VertexType endVertex) {
	QueType<VertexType> vertexQ;
	if (startVertex == endVertex) { //재귀를 반복하다 startVertex와 endVertex가 같아지는 경우 endVertex를 출력하고 true를 리턴.
		std::cout << endVertex;
		return true;
	}
	GetToVertices(startVertex, vertexQ);

	while (!vertexQ.IsEmpty()) {
		VertexType vertex;
		vertexQ.Dequeue(vertex);
		if (vertex != startVertex) {
			if (DepthFirstSearch(vertex, endVertex)) {
				std::cout << " <- " << vertex;
				return true;
			}
		}
		else {
			continue;
		}
	}
	return false;
}