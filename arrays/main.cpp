#include <iostream>
#include "arrayList.h"
//#include "hashMap.h"
//#include "linkedList.h"
//#include "graph.h"


int main () {

arrayList<std::string> myStrinGlist;

myStrinGlist.push_back("Hello");
myStrinGlist.push_back("Hello");
myStrinGlist.push_back("Hello");
myStrinGlist.push_back("Hello");
myStrinGlist.push_back("Hello");
myStrinGlist.push_back("Hello");
myStrinGlist.push_back("Hello");
myStrinGlist.push_back("Hello");
myStrinGlist.insert(0,"first");
myStrinGlist.insert(0,"first");
myStrinGlist.insert(0,"first");
myStrinGlist.insert(0,"first");
myStrinGlist.insert(0,"first");
myStrinGlist.insert(0,"first");
myStrinGlist.insert(0,"first");
myStrinGlist.insert(10,"last");
myStrinGlist.insert(10,"last");
myStrinGlist.insert(10,"last");
myStrinGlist.remove(10);
myStrinGlist.push_back("no");
for(int i = 0; i < myStrinGlist.size(); i++){
	std::cout<< myStrinGlist.get(i) <<std::endl;
}
std::cout<< myStrinGlist.size()<<std::endl;


}
