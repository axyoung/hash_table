#include "hashTable.h"
#include <iomanip> // setPrecision

// constructor of the hash table will create the table
HashTable::HashTable() {
	// hash table starts with 100 slots
	tableSize = 100;
	table = new Node*[tableSize];
	
	for (int i = 0; i < tableSize; i++) {
		table[i] = NULL;
	}
}

// destructor of the hash table
HashTable::~HashTable() {
	
	for (int i = 0; i < tableSize; i++) {
		delete table[i];
	}
	
	delete[] table;
}

// function to add a student
void HashTable::add(Student* student) {
	Node* node = new Node(student);
	add(node);
}

// function to add a node
void HashTable::add(Node* node) {
	Node* &head = table[hash(node->getStudent()->getStudentID())]; // head references the table to point at the id
	// add to head
	node->setNext(head);
	head = node;
	
	// now we loop through and count how many collisions to call resize
	int count = 0;
	Node* current = head;
	while (current != NULL) {		
		current = current->getNext();
		count++;
	}
	
	if (count > 3) {
		resize();
	}
}

// function to delete a student ID
void HashTable::erase(int studentID) { // looking at the ID because hashing the ID
	Node* &head  = table[hash(studentID)];
	Node* current = head;
	
	// if the head's id is the same as the student id, delete/replace the head
	if (head != NULL && head->getStudent()->getStudentID() == studentID) {
		Node* next = head->getNext();
		delete head;
		head = next;
	} else { // go through the next IDs in the table index and check it should be deleted
		while (current != NULL && current->getNext() != NULL) {
			
			if (current->getNext()->getStudent()->getStudentID() == studentID) { // delete next in mid
				Node* next = current->getNext()->getNext();
				delete current->getNext();
				current->setNext(next);
				return;
			}
			
			current = current->getNext();
		}
	}
}

// function to print the list
void HashTable::print() {
	
	// goes through each index
	for (int i = 0; i < tableSize; i++) {
		Node* current = table[i];
		
		// prints out the student in each index
		while (current != NULL) {
			cout << "Student: " << current->getStudent()->getStudentFirst() <<
				" " << current->getStudent()->getStudentLast() << endl;
			cout << "ID: " << current->getStudent()->getStudentID() << endl;
			cout << "GPA: " << fixed << setprecision(2) <<
				current->getStudent()->getStudentGPA() << endl << endl;
				
			current = current->getNext();
		}
	}
}

int HashTable::hash(int studentID) { // this will hash the ID by its remainder
	return studentID % tableSize;
}

// the resize function makes a new table and doubles its size
// the old table is saved in order to go through the list and rehash the students
void HashTable::resize() { // this will resize the table
	int oldSize = tableSize;
	tableSize *= 2; // double table size
	Node** oldTable = table;
	table = new Node*[tableSize];
	
	for (int i = 0; i < tableSize; i++) {
		table[i] = NULL;
	}
	
	// go through the list and add each student again
	for (int i = 0; i < oldSize; i++) {
		while (oldTable[i] != NULL) {
			Node* temp = oldTable[i];
			oldTable[i] = oldTable[i]->getNext();
			add(temp);
		}
	}
	
	delete[] oldTable;	
}