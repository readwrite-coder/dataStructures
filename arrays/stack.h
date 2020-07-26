#ifndef STACK_H
#define STACK_H
#include "arrayList.h"

template<typename T>
class stack {	
	public:
	stack();
	//______________________
	int size() const;
	bool empty() const;
	//______________________
	void push(const T& v);
	T top() ;
	void pop();
	//______________________
	private:
	arrayList<T> mylist_; // or LList mylist_; all stack operations are O(1) for linkedList implementation. 
	int numElements;
		
};
template<typename T>
stack<T>::stack(){
	numElements = 0;
}
template<typename T>
int stack<T>::size() const {
	return numElements;
}
template<typename T>
bool stack<T>::empty() const {
	return (numElements == 0);
}
template<typename T>
void stack<T>::push(const T& val){
	mylist_.push_back(val);
	numElements++;
}
template<typename T>
T stack<T>::top() {
	return mylist_.get(numElements-1);
}
template<typename T>
void stack<T>::pop() {
	numElements--;
}

#endif