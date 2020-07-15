#include "string"
#include "node.h"


node::node(std::string Key, std::string val){
	key = Key;
	value = val;

	next = NULL;
	prev = NULL;
}
node::node(std::string Key, std::string val, node * Next, node * Prev){
	key = Key;
	value = val;

	next = Next;
	prev = Prev;
}