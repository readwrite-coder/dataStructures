/*
LISTS

Ordered collection of items, which may contain duplicate values, usually accessed based on their position (index)

	– Ordered = Each item has an index and there is a front andback (start and end)
	– Duplicates allowed (i.e. in a list of integers, the value 0 could appear multiple times)
	– Accessed based on their position ( list[0], list[1], etc. )
	– What are some operations you perform on a list?

Operation Description; Input(s), Output(s)   &&    Runtime analysis:

	– push_back / append: Add a new value to the end of the list; input: Value
	– insert: Add a new value at a particular location shifting others back; input: Index : int, Value
	– pop: Remove value at the given location; input: Index : int, output: Value at location
	– at / get: Get value at given location; input: Index : int, output: Value at location
	– empty: Returns true if there are no values in the list; output: bool
	– size: Returns the number of values in the list; output: int
	– remove: Remove a value; input: Value, output: bool : true if removed successfully
	– find: Return the location of a given value; input: Value, output: Int : Index

A List Interface

	– This abstract class (contains pure virtual functions) allows many possible derived implementations
	– A pure virtual function has “=0” after it to specify that implementation is not defined in this class and virtual keyword before it.
	– Any derived implementation must implement these public member functions as specified

	#ifndef ILIST_H
	#define ILIST_H
	class IList {
		public:
		virtual bool empty() const = 0;
		virtual int size() const = 0;
		virtual void push_back(const int& new_val) = 0;
		virtual void insert(int newPosition, const int& new_val) = 0;
		virtual bool remove(const int& val) = 0;
		virtual void pop(int loc) = 0;
		virtual const int& get(int loc) const = 0;
		virtual int& get(int loc) = 0;
	};
	#endif

	The const keyword is used to indicate do not change data, but it placement has different meaning as to what data not changed
		1) After a member function: This member function cannot modify data of the object of the class for which it is a member function
		2) Before a parameter: The data for the parameter cannot be modified by the function
		3) By a return value: The return value data cannot be modified.	

Derived Classes:
	– Linked List
	– Unbounded Dynamic Array (arrayList)

*/