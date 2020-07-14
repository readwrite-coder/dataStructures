#ifndef HASHMAP_H
#define HASHMAP_H

class hashMap{

//n is an integer representing the number of keys we expect to enter. 
//m is an integer to denote the table size of our hash table. 


int m; //the size of the table is a prime number. 
std::string * array; 

public:
hashMap();
void add(std::string key, std::string value);
void remove(std::string key);
std::string find(std::string key); 
int hash(std::string value);
void display();

/*
A hash table implements a map ADT 
– Add(key,value) "Jill" - 6
– Remove(key)
– Lookup/Find(key) : returns value
• In a BST the keys are kept in order – A Binary Search Tree implements an ORDERED MAP
• In a hash table keys are evenly distributed throughout the table (unordered)
– A hash table implements an UNORDERED MAP
*/
/*
C++11 added new container classes: 
– unordered_map
– unordered_set
• Each uses a hash table for average complexity to insert , erase, and find in O(1)
• Must compile with the -std=c++11 option in g++
*/
/*
A hash table is an array that stores key,value pairs
– Usually smaller than the size of possible set of keys, |S|
• USC ID's = 1010 options
– But larger than the expected number of keys to be entered (defined as n)
• The table is coupled with a function, h(k), that maps keys to an integer in the range [0..tableSize-1] (i.e. [0 to m-1])
• What are the considerations...
– How big should the table be?
– How to select a hash function?
– What if two keys map to the same array location? (i.e. h(k1) == h(k2) )
• Known as a collision
*/
/*
The table size should be bigger than the amount of expected entries (m > n)
• But anything smaller than the size of all possible keys admits the chance that two keys map to the same location in the table (a.k.a. COLLISION)
• You will see that tableSize should usually be a prime number
*/
/*
Challenge: Distribute keys to locations in hash table such that
• Easy to compute and retrieve values given key
• Keys evenly spread throughout the table
• Distribution is consistent/repeatable for retrieval
• If necessary key data type is converted to integer before hash is applied
– Akin to the operator<() needed to use a data type as a key for the C++ map
• Example: Strings
– Use ASCII codes for each character and add them or group them
– "hello" => 'h' = 104, 'e'=101, 'l' = 108, 'l' = 108, 'o' = 111 = 532
– Hash function is then applied to the integer value 532 such that it maps to a value between 0 to M-1 where M is the table size
• Rules of thumb
– The hash function should examine the entire search key,not just a few digits or a portion of the key.
– When modulo hashing is used,the base should be prime.
*/
/*
• Recall for hash tables we let...
– n = # of entries (i.e. keys), m = size of the hash
table
• If n > m, is every entry in the table used?
– No. Some may be blank?
• Is it possible we haven't had a collision?
– No. Some entries have hashed to the same location
– Pigeon Hole Principle says given n items to be slotted into m holes and n > m there is at least one hole with more than 1 item
– So if n > m, we know we've had a collision
• We can only avoid a collision when n < m
*/

};

#endif