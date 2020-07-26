#ifndef STACK_H
#define STACK_H
#include "arrayList.h"
class stack {	
	public:
	stack();
	int size() const;
	bool empty() const;
	void push(const int& v);
	const int& top() const;
	void pop();
	private:
	arrayList mylist_;
	int arraySize;
	int numElements;
		// or LList mylist_; all stack operations are O(1) for linkedList implementation. 
};
#endif