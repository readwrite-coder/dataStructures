#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

class linkedList{

public:
linkedList();

node * head;
node * tail;
int ListCount;

void insert(std::string key, std::string value);
void print();
std::string getFirstItem();

};

#endif
