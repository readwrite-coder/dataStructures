#include "arrayList.h"
#include <iostream>

arrayList::arrayList(){
	arrayCount = 0;
	arrayCapacity = 2;
	start = new int[arrayCapacity];
}

//append to the back of the list;
void arrayList::add(int element){
	if(arrayCount == arrayCapacity){
		int * temp = new int[arrayCapacity*2];
		arrayCapacity *= 2;
		for(int i = 0; i < arrayCount; i++){
			temp[i] = start[i];
		}
		start = temp;
	}
	start[arrayCount] = element;
	arrayCount++;
}

void arrayList::add(int index, int val){
	if(index > this->arrayCount || index < 0){
		return; 
	}
	int * temp = new int[arrayCount + 1];
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
	int * temp_null = start;
	start = temp;
	temp_null = NULL;
	return;
}

int arrayList::get(int index){
	if(index > arrayCount || index < 0){
		return -1;
	}
	return start[index];
}

int arrayList::size(){
	return arrayCount;
}
void arrayList::clear(){
	arrayCount = 0;
	arrayCapacity = 2;
	start = new int[arrayCapacity];
}
bool arrayList::isEmpty(){
	return this->size() == 0;
}
void arrayList::remove(int index){
	if (index >= arrayCount || index < 0){
		return;
	}
	int * temp = new int[arrayCapacity];
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