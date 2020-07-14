#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class arrayList {

int * start;
int arrayCount; 
int arrayCapacity;

public:
arrayList();

void add (int val); //append the value at the end of the list. 
void add (int index, int val); //append the value at the specified index. 
int get (int index); //return the value at the specified index of the list.
int size(); //return the size of the current list.
bool isEmpty(); //returns true if the list is empty.
void clear(); //delete the entire list.
void remove(int index); //remove the list item at the specified index. 

//we want our arrayList to store integer values 
//we want to be able to insert an element into our arraylist
//we want our arrayList to dynamically grow when it runs out of size. 
//we want to be able to retrieve an int element at its index.
//we want to be able to delete an int element at its index. 

};


#endif