#include "arrayList.h"
#include <iostream>
#include "string"
/*
arrayList::arrayList(){
	arrayCount = 0;
	arrayCapacity = 2;
	start = new std::string[arrayCapacity];
}
int arrayList::size(){
	return arrayCount;
}
bool arrayList::empty(){
	return this->size() == 0;
}

//append to the back of the list;
void arrayList::push_back(std::string element){
	if(arrayCount == arrayCapacity){
		std::string * temp = new std::string[arrayCapacity*2];
		arrayCapacity *= 2;
		for(int i = 0; i < arrayCount; i++){
			temp[i] = start[i];
		}
		start = temp;
	}
	start[arrayCount] = element;
	arrayCount++;
}

void arrayList::insert(int index, std::string val){
	if(index > this->arrayCount || index < 0){
		return; 
	}
	std::string * temp = new std::string[arrayCount + 1];
	for(int i = 0; i < arrayCount; i++){
		if(i >= index){
			if(i == index){
				temp[i] = val;
				arrayCount++;
			}
			else{
				temp[i] = start[i-1];
			}
		}
		else{
			temp[i] = start[i];
		}
	}
	std::string * temp_null = start;
	start = temp;
	temp_null = NULL;
	return;
}

std::string arrayList::get(int index){
	if(index > arrayCount || index < 0){
		return "0";
	}
	return start[index];
}


void arrayList::clear(){
	arrayCount = 0;
	arrayCapacity = 2;
	start = new std::string[arrayCapacity];
}

void arrayList::remove(int index){
	if (index >= arrayCount || index < 0){
		return;
	}
	std::string * temp = new std::string[arrayCapacity];
	for(int i = 0; i < arrayCount; i++){
		if(i >= index){
			temp[i] = start[i+1];
		}
		else{
			temp[i] = start[i];
		}
	}
	arrayCount--;
	start = temp;
	return;
}
*/