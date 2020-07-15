//#include "string"
#include "node.h"
#include "linkedList.h"
#include <iostream>

linkedList::linkedList(){
	head = NULL;
	tail = NULL;
	ListCount = 0;
}

void linkedList::insert(std::string key, std::string value){
	if(head == NULL){
		node * temp = new node(key, value);
		head = temp;
		tail = temp;
		return;
	}
	if(tail->prev == NULL){
		node * temp = new node(key, value);
		tail = temp;
		head->next = tail;
		tail->prev = head;
		return;
	}
	node * temp = new node(key, value);
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
	return;
}
void linkedList::print(){
	node * temp = head;
	int i = 0;
	while(temp != NULL){
		std::cout << i << ": " << temp->key << std::endl;
		temp = temp->next;
		i++;
	}
}