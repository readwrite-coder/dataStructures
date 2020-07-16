//#include "string"
#include "node.h"
#include "linkedList.h"
#include <iostream>

linkedList::linkedList(){
	head = NULL;
	tail = NULL;
	ListCount = 0;
}
std::string linkedList::getFirstItem(){
	node * temp = head;
	if (temp == NULL){
		return "0";
	}
	return head->value;
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
		std::cout << temp->key << " " << temp->value << ", ";
		temp = temp->next;
		i++;
	}
	std::cout<<std::endl;
}