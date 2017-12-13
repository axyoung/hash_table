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
#include "Node.h"
#include "student.h"

using namespace std;

int main() {
	// the code in here is used to test if my linked lists works
	
	// create pointers to a new student with ID numbers given below
	Student* one = new Student("alex", "young", 420, 4.0);
	Student* two = new Student("bob", "hi", 42, 2.0);
	Student* three = new Student("j", "s", 4, 9.0);
	
	// add a node for each student that was created
	Node* n1 = new Node(one);
	Node* n2 = new Node(two);
	Node* n3 = new Node(three);
	
	// here I link the nodes together by setting consecutive nodes for the singly linked list
	n1 -> setNext(n2);
	n2 -> setNext(n3);
	
	// print out the id of each student using getStudent and getStudentId on each node
	cout << n1 -> getStudent() -> getStudentID() << endl;
	cout << n1 -> getNext() -> getStudent() -> getStudentID() << endl;
	cout << n1 -> getNext() -> getNext() -> getStudent() -> getStudentID() << endl;

	return 0;
}
