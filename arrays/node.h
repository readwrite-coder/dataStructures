#ifndef NODE_H
#define NODE_H
#include "string"
class node {

public:
node(std::string key, std::string val);
node(std::string key, std::string val, node * Next, node * Prev);

std::string key;
std::string value;

node * next;
node * prev;

};

#endif