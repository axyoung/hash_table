#ifndef HASHTABLE
#define HASHTABLE
#include "Node.h"

// hash table class holds the table -> overlayed on top of the linked lists
class HashTable {
	public:
		HashTable();
		~HashTable();
		// functions to add and delete and print from the hash table
		void add(Student* student);
		void add(Node* node);
		void erase(int studentID); // looking at the ID because hashing the ID
		void print();

	private:
		Node** table; // this will have an array of node pointers (chaining)
		int tableSize;
		int hash(int studentID); // this will hash the ID
		void resize(); // this will resize the table, it will need to preserve hash values

};

#endif