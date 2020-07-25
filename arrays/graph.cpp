#include "graph.h"
#include <iostream>
graph::graph(){
	numberNodes = 0;
	numberEdges = 0;
	//matrixCapacity = 2;
	linkedListCapacity = 2;
	vertices = NULL;
	//adjacencyMatrix = new int * [2];
	//for(int i = 0; i < matrixCapacity; i++){
		//adjacencyMatrix[i] = new int[2];
	//}
}
void graph::addVertex(std::string vertex){
	if (numberNodes == 0){
		vertices = new linkedList[linkedListCapacity];
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
		//std::cout<< "the number of nodes: "<< numberNodes << ", number of linkedListCapacity: "<< linkedListCapacity<<std::endl;
	}
	linkedList newNode;
	newNode.insert("vertex", vertex);
	vertices[numberNodes] = newNode;
	numberNodes++;
	return;
}
void graph::deleteVertex(std::string nodeValue){
	linkedList * newArray = new linkedList[linkedListCapacity];
	bool found = false;
	for(int i = 0; i < numberNodes; i++){
		if(nodeValue == vertices[i].getFirstItem()){
			found = true;
		}
		if(found == true){
			newArray[i] = vertices[i+1];
		}
		else{
			newArray[i] = vertices[i];
		}
	}
	if(found == true){
		numberNodes--;
		linkedList * temp = vertices;
		vertices = newArray;
		delete[] temp;
	}
	else{
		delete[] newArray;
	}
	return;
}
void graph::addEdge(std::string vertex1, std::string vertex2){
//first check to see if vertices are in the linkedList of vertices. 
	for(int i = 0; i < numberNodes; i++){
		//std::cout<< "first item: " << vertices[i].getFirstItem()<<std::endl;
		if(vertex1 == vertices[i].getFirstItem()){
			vertices[i].insert("edge", vertex2);
		}
		if(vertex2 == vertices[i].getFirstItem()){
			vertices[i].insert("edge", vertex1);
		}
	}
}
bool graph::edgeExists(std::string vertex1, std::string vertex2){
	int indexOfVertex1 = vertexIndex(vertex1);
	int indexOfVertex2 = vertexIndex(vertex2);
	
	bool edgeExists = false;
	bool vertex1Found = false;
	bool vertex2Found = false;

	if(indexOfVertex1 > numberNodes || indexOfVertex2 > numberNodes){
		return edgeExists;
	}

	linkedList temp = vertices[indexOfVertex1];
	node * tempNode = temp.head;
	
	while(tempNode != NULL){
		if(vertex2 == tempNode->value){
			vertex1Found = true;
		}
		tempNode = tempNode->next;
	}

	temp = vertices[indexOfVertex2];
	tempNode = temp.head;

	while(tempNode != NULL){
		if(vertex1 == tempNode->value){
			vertex2Found = true;
		}
		tempNode = tempNode->next;
	}
	if(vertex1Found == true && vertex2Found == true){
		edgeExists = true;
	}
	return edgeExists;
}

int graph::vertexIndex(std::string vertex){
	int index = numberNodes + 1;
	for(int i = 0; i < numberNodes; i++){
		if(vertex == vertices[i].getFirstItem()){
			index = i;
		}
	}
	return index;
}

void graph::print(){
	for(int i = 0; i < numberNodes; i++){
		vertices[i].print();
		std::cout << std::endl;
	}
}