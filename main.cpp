/* 
 * Linked Lists part 2
 * Alex Young
 * C++ Galbraith Period 6
 *
 * This is the second part of a student list program that uses linked lists.
 * Using code from Russell-Chai
 * 
 * Last updated: 12/13/2017
 */

#include <iostream>
#include <cstring>
#include <iomanip> // setPrecision
#include "Node.h"
#include "student.h"

using namespace std;

void add(Node* node);
//void addRecursive();
void print(Node* nextNode);
//void erase();
//void average();

int main() {
	
	// create pointers to a new student with ID numbers given below
	Student* one = new Student((char*)"alex", (char*)"young", 420, 4.0);
	Student* two = new Student((char*)"bob", (char*)"hi", 42, 2.0);
	Student* three = new Student((char*)"j", (char*)"s", 4, 9.0);
	
	// add a node for each student that was created
	Node* n1 = new Node(one);
	Node* n2 = new Node(two);
	Node* n3 = new Node(three);
	
	// here I link the nodes together by setting consecutive nodes for the singly linked list
	n1 -> setNext(n2);
	n2 -> setNext(n3);
	
	// print out the id of each student using getStudent and getStudentId on each node
	cout << n1 -> getStudent() -> getStudentFirst();
	cout << n1 -> getStudent() -> getStudentID() << endl;
	cout << n1 -> getNext() -> getStudent() -> getStudentID() << endl;
	cout << n1 -> getNext() -> getNext() -> getStudent() -> getStudentID() << endl;

	Node* head = NULL;
	bool cont = true; // program runs until this is false

	while (cont) {
		cout << "Student List, you can (ADD, PRINT, DELETE, AVERAGE, or QUIT)" << endl;
		char entry[10];
		//cin.get();
		//cin >> entry;
		cin.get(entry, sizeof(entry));
		//cin.get();
		cout << entry << endl;

		if (strcmp(entry, "ADD") == 0 || strcmp(entry, "add") == 0) {
			add(head);
		}

		if (strcmp(entry, "PRINT") == 0 || strcmp(entry, "print") == 0) {
			print(head);
		}

		if (strcmp(entry, "DELETE") == 0 || strcmp(entry, "delete") == 0) {
			//erase();
		}

		if (strcmp(entry, "AVERAGE") == 0 || strcmp(entry, "average") == 0) {
			//average();
		}

		if (strcmp(entry, "QUIT") == 0 || strcmp(entry, "quit") == 0) {
			cont = false;
		}

		cin.get();

	}

	return 0;
}

void add(Node* head) {
	
	int id;
	float gpa;
	char* first = new char[20];
	char* last = new char[20];

	cout << "First name: ";
	cin >> first;
	
	cout << "Last name: ";
	cin >> last;
	
	cout << "Student ID: ";
	cin >> id;
	
	cout << "Student GPA: ";
	cin >> gpa;
	
	Student* student = new Student(first, last, id, gpa);
	Node* Node = new Node(student);

	//add(node -> getNext(), student);

	// now that I have a student and a node I need to use a recursive function to add it to my list
}
/*
void addRecursive(Node* current) {
	if (current == head) {
		return;
	}

	if (current != NULL) {
		current -> setNext(
	superlintball
}
*/
void print(Node* nextNode) {
	if (nextNode == NULL) {
		return;
		//cout << "List of students:" << endl;
	}

	cout << "Student: " << nextNode -> getStudent() -> getStudentFirst() << " " <<
			       nextNode -> getStudent() -> getStudentLast() << endl;
	cout << "ID: " << nextNode -> getStudent() -> getStudentID() << endl;
	cout << "GPA: " << nextNode -> getStudent() -> getStudentGPA() << endl << endl;;
	
	if (nextNode -> getNext() != NULL) {
		print(nextNode -> getNext());
	}
}

void delete(Node*);
