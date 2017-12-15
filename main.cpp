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

void add(Node* node, Student* student);
void print(Node* node);
void erase(Node* node, Student* student);
void average(Node* node);

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

	
	bool cont = true; // program runs until this is false

	while (cont) {
		cout << "Student List, you can (ADD, PRINT, DELETE, AVERAGE, or QUIT)" << endl;
		char entry[10] = "";
		cin.get(entry, sizeof(entry));
		cin.get();

		if (strcmp(entry, "ADD") == 0 || strcmp(entry, "add") == 0) {
			add(Node* node, Student* student);
		}

		if (strcmp(entry, "PRINT") == 0 || strcmp(entry, "print") == 0) {
			print(Node* node);
		}

		if (strcmp(entry, "DELETE") == 0 || strcmp(entry, "delete") == 0) {
			erase(Node* node, Student* student);
		}

		if (strcmp(entry, "AVERAGE") == 0 || strcmp(entry, "average") == 0) {
			average(Node* node);
		}

		if (strcmp(entry, "QUIT") == 0 || strcmp(entry, "quit") == 0) {
			cont = false;
		}

	return 0;
}

void add(Node* node, Student* student) {
	Node* current = new Node(student);
	if (node == NULL) {
		node -> setNext(current);
		return;
	}

	if (node != NULL) {
		cout << "Student ID: ";
		current -> getNext() -> setID;
		add(node->getNext(), student)

}

void print(Node* node) {


}

void erase(Node* node, Student* student) {


}

void average(Node* node) {


}


