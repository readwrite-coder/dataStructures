#include "string"
#include "hashMap.h"
#include <iostream>

hashMap::hashMap(){
	m = 37;
	array = new std::string[m];
}
void hashMap::add(std::string key, std::string value){
	int index = hash(key);
	array[index] = value;
}
void hashMap::remove(std::string key){

}
std::string hashMap::find(std::string key){
	int index = hash(key);
	std::string value = array[index];
	return value;
}

int hashMap::hash(std::string value){
	int temp = 0;
	for(int i = 0; i < value.size(); i++){
		temp += (int) value[i];
	}
	//std::cout << "temp is: " << temp << std::endl;
	return temp % m;
}

void hashMap::display(){
	for(int i = 0; i < m; i ++){
		std::cout << i << ": " << array[i] << std::endl;
	}
}

