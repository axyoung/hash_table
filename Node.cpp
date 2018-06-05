#include <iostream>
#include "Node.h"

using namespace std;

// this code was taken from Russell-Chai's linked list as in the previous project I used his Node.o instead
// constructor of student
Node::Node(Student* newStudent) {
  nextNode = NULL;
  student = newStudent;
}

// returns the next node
Node* Node::getNext() {
  return nextNode;
}

// returns the student of a node
Student* Node::getStudent() {
  return student;
}

// sets the next node
void Node::setNext(Node* setNode) {
  nextNode = setNode;
}

// destructor
Node::~Node() {
  delete student;
}