#ifndef NODE
#define NODE
#include "student.h"

// class node has functions to getNext, getStudent, and setNext
class Node {
 public:
  Node(Student newStudent);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
  Node(Student*);
  
 private:
  Student* student;
  Node* nextNode;
};
#endif