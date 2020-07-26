/*
________________________________________Data Type (ADT - abstract data type)______________________________________________

	An abstract data type, or ADT is
		– A model for a grouping data and the operations on that data
		- The model allows us to separate the decision of what data structure to use and how it will be used in our higher level application
		– And the implementation of the specific data structure
	The data types that a computer can encode include integral data types (integers), floating point data type (real numbers), and character data types (characters in the alphabet)
	examples of ADT: List, Dictionary/Map, Set. 

__________________________________________________Data Structure______________________________________________________

	A data structure is
		– An implementation of an ADT in a given programming language
		- Each ADT we will examine in this course has certain:
		- Well defined operations and capabilities that are often useful
	Each data structure will
		– Implement a specific ADT
		– Time & space advantages
		– Time & space disadvantages
	We study those operations, advantages and disadvantages
	data structure examples: array, linked-list. 
	We can think of an ascii character as a primitive(fundamental) data type, and a string as an abstract data type.

__________________________________________________Lists_____________________________________________________

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
	This abstract class (contains pure virtual functions) allows many possible derived implementations
		– A pure virtual function has “=0” after it to specify that implementation is not defined in this class and virtual keyword before it.
		– Any derived implementation must implement these public member functions as specified
	Derived Classes:
		– Linked List
		– Unbounded Dynamic Array (arrayList)
	The const keyword is used to indicate do not change data, but it placement has different meaning as to what data not changed
		1) After a member function: This member function cannot modify data of the object of the class for which it is a member function
		2) Before a parameter: The data for the parameter cannot be modified by the function
		3) By a return value: The return value data cannot be modified.	

___________________________________________Stacks_____________________________________________

Stacks and Queues - Lists with restrictions about how insertion and removal are done
	– Stack – Only ever insert/remove from one end of the list
	– Queue – Only ever insert at one end and remove from the other

Stack ADT: A list of items where insertion and removal only occurs at one end of the list

	- Stacks are LIFO
	– Newest item at top
	– Oldest item at bottom

	Operations a stack supports
	– push(item) – Add an item to the top of the Stack
	– pop() - Remove the top item from the Stack
	– top() - Get a reference to the top item on the Stack (don't remove it though!)
	– size() - Get the number of items in the Stack

_____________________________________________Queue__________________________________________________

Queue ADT: Queue – A list of items where insertion only occurs at the back of the list and removal only occurs at the front of the list
	#ifndef QUEUE_H
	#define QUEUE_H
	class Queue {
		public:
		Queue();
		~Queue();
		int size() const;
		const int& front() const;
		void push_back(const int& v); //enqueue
		void pop_front(); // dequeue
		bool empty() const;
		private:
		// ???
	};
	#endif
	– Like waiting in line for a cashier at a store
	- Queues are FIFO (First In, First Out)
	– Items at the back of the queue are the newest
	– Items at the front of the queue are the oldest
	– Elements are processed in the order they arrive
	How should you implement a Queue?
		– Array List?
		– Linked List?
	COMPOSITION:
	#ifndef QUEUE_H
	#define QUEUE_H
	#include "llist.h"
	class Queue
	{
		public:
		Queue();
		~Queue();
		int size() const;
		void push_back(const int& v);
		void pop_front(); // dequeue
		const int& front();
		bool empty() const;
		private:
		LList mylist_;
	};
	Queue::Queue() :
		mylist_() // member constructor
	{ }
	void Queue::push_back(const int& v)
	{
	// call member function of mylist_
		mylist_.push_back(v);
	}
	#endif
	INHERITANCE:
	#ifndef QUEUELIST_H
	#define QUEUELIST_H
	#include "llist.h"
	class QueueList : private LList
	{	
		public:
		QueueList();
		~QueueList();
		int size() const;
		void push_back(const int& v);
		const int& front();
		void pop_front();
		bool empty() const;
		private:
		// no data member needed
	};
	QueueList::QueueList() :
		LList<T>() // base-class constructor
	{ }
	void QueueList::push_back(const int& v)
	{
		// call base class function
		LList::push_back(v);
	}
	#endif

DEQUE ADT - Double-ended queues: Equally good at pushing and popping on either end
	std::vector is essentially a Dynamic Array List
		– Slow at removing and inserting at the front or middle
		– Fast at adding/remove from the back
	std::deque gives fast insertion and removal from front and back along with fast random access (i.e. at(i))
		– Almost has "look and feel" of linked list with head and tail pointers providing fast addition/removal from either end
		– Implies it could be used well as a (stack / queue)
		– What data structure may be best to implement deque? circular doubly linked list? circular array/buffer?
	If vector is more powerful than a deque (permits insertion or removal any place, so can implement List), why not always uses vectors instead?

_____________________________________Maps/Dictionaries_______________________________________________

Stores key,value pairs
	– Example: Map student names to their GPA
	- Keys must be unique (can only occur once in the structure)
	- No constraints on the values
	- What operations do you do on a map/dictionary?
	- No inherent ordering between key/value pair
	Operation: Description; Input(s), Output(s)
		- Insert / add: Add a new key,value pair to the dictionary (assuming its not there already); input: Key, Value
		- Remove Remove the key,value pair with the given key; input: Key
		- Lookup / Get: Lookup the value associated with the given key or indicate the key,value pair doesn't exist
		input: Key, output: Value associated with the key

________________________________________ Hash Table ______________________________________________

	A hash table implements a map ADT 
		– Add(key,value) "Jill" - 6 (years old)
		– Remove(key)
		– Lookup/Find(key) : returns value
	• In a BST the keys are kept in order – A Binary Search Tree implements an ORDERED MAP
	• In a hash table keys are evenly distributed throughout the table (unordered)
		– A hash table implements an UNORDERED MAP

_____________________________________________Set____________________________________________________

	A set is a dictionary where we only store keys (no associated values)
	– Example: All the courses taught at USC (ARLT 100, ..., CSCI 104, MATH 226, ...)
	- Keys must be unique
	– No duplicate keys (only one occurrence)
	- Not accessed based on index but on key value
	What operations do we perform on a set?
	Operation Description Input(s) Output(s)
		- Insert / add: Add a new key to the set (assuming its not there already); input: Key
		- Remove: Remove; input: Key
		- In / Find: Check if the given key is present in the map; input: Key, output: bool

__________________________________________Graph ADT______________________________________________________

	A Graph ADT should provide at least the following operations:
		1. Add a node.
		2. Delete a node
		3. Add an edge
		4. Delete an edge
		5. Test if an edge from u to v exists
		6. Enumerate all outgoing edges from a node
		7. Enumerate all incoming edges from a node
	
	Graphs as list of lists (adjacency list)
		– List of vertices each having their own adjacent list
	Alternatively, sometimes graphs are also represented with an adjacency matrix
		– Entry at (i,j) = 1 if there is an edge between vertex i and j, 0 otherwise

___________________________________________ Tree ______________________________________________

		
*/