#include "graph.h"
#include <iostream>
graph::graph(){
	numberNodes = 0;
	numberEdges = 0;

	matrixCapacity = 2;
	linkedListCapacity = 2;
	vertices = NULL;

	adjacencyMatrix = new int * [2];
	for(int i = 0; i < matrixCapacity; i++){
		adjacencyMatrix[i] = new int[2];
	}

}
void graph::addVertex(std::string vertex){
	if (numberNodes == 0){
		vertices = new linkedList[2];
		linkedList node1;
		node1.insert("vertex", vertex);
		vertices[0] = node1;
		numberNodes++;
		return;
	}
	if (numberNodes >= (linkedListCapacity)){
		linkedListCapacity *= 2;
		linkedList * newArray = new linkedList[linkedListCapacity];
		for(int i = 0; i < numberNodes; i++){
			newArray[i] = vertices[i];
		}
		linkedList * temp = vertices;
		vertices = newArray;
		delete[] temp;
		std::cout<< "the number of nodes: "<< numberNodes << ", number of linkedListCapacity: "<< linkedListCapacity<<std::endl;
	}
	linkedList newNode;
	newNode.insert("vertex", vertex);
	vertices[numberNodes] = newNode;
	numberNodes++;
	return;
}
void graph::addEdge(std::string vertex1, std::string vertex2){
//first check to see if vertices are in the linkedList of vertices. 

	for(int i = 0; i < numberNodes; i++){
		//std::cout<< "first item: " << vertices[i].getFirstItem()<<std::endl;
		if(vertices[i].getFirstItem() == vertex1){
			//std::cout<<"hello world!" <<std::endl;
			vertices[i].insert("edge", vertex2);

		}
		if(vertices[i].getFirstItem() == vertex2){
			vertices[i].insert("edge", vertex1);
		}
	}

}
void graph::print(){
	for(int i = 0; i < numberNodes; i++){
		vertices[i].print();
		std::cout << std::endl;
	}
}