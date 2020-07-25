#include <iostream>
#include "arrayList.h"
#include "hashMap.h"
#include "linkedList.h"
#include "graph.h"


int main () {


graph blob;

blob.addVertex("Alex Bauer");
blob.addVertex("Georgia Calhoun");
blob.addVertex("Ellen Furgis");
blob.addVertex("Kate McEvilly");
blob.addVertex("Andrew Trinh");
blob.addVertex("Teddy Kurtz");
blob.addVertex("Jack Hill");
blob.addVertex("Taylor Dolenga");
blob.addVertex("Xander Nanji");
blob.addVertex("Meg Knox");
blob.addVertex("Adrienne Alvarado");
blob.addVertex("Bobby Abrahamson");
blob.addVertex("Kevin Ulman");
blob.addVertex("Kiley Cassidy");


blob.addEdge("Andrew Trinh", "Jack Hill");

if(blob.edgeExists("Andrew Trinh", "Jack Hill") ){
	std::cout << "edge exists" << std::endl;
}



blob.print();


}
