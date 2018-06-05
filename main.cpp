/* 
 * Linked Lists part 2
 * Alex Young
 * C++ Galbraith Period 6
 *
 * This is the Hash table that uses previous linked list code
 * 
 * Last updated: 1/25/2018
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include "Node.h"
#include "student.h"
#include "hashTable.h"

using namespace std;

// function prototypes for the functions that the user will be prompted for
void add(Node* &head, Student* st);
void print(Node* nextNode);
void average(Node* current);
void generator(Node* &head);

int nextID = 10000; // so i can increment the ids in generator
HashTable hashTable;

int main() {
	Node* head = NULL;
	bool cont = true; // program runs until this is false

	while (cont) {
		// user prompted to choose a command
		
		cout << "Student List, you can (ADD, GENERATE, PRINT, DELETE, or QUIT)" << endl;
		char entry[10];
		cin.get(entry, sizeof(entry));
		cin.get();
		
		// read in user entry, call respective function

		if (strcmp(entry, "ADD") == 0 || strcmp(entry, "add") == 0 || strcmp(entry, "a") == 0) {
			add(head, NULL);
			cout << endl;
		}
	
		else if (strcmp(entry, "GENERATE") == 0 || strcmp(entry, "generate") == 0 || strcmp(entry, "g") == 0) {
			generator(head);
			cout << endl;
		}	

		else if (strcmp(entry, "PRINT") == 0 || strcmp(entry, "print") == 0 || strcmp(entry, "p") == 0) {
			cout << endl;
			hashTable.print();
		}

		else if (strcmp(entry, "DELETE") == 0 || strcmp(entry, "delete") == 0 || strcmp(entry, "d") == 0) {
			// if the user wants to delete something
			// need to read in an id to delete from user
			int id;
			cout << endl << "What Student do you want to delete? (ID)" << endl;
			cin >> id;
			cin.get();
			cout << endl;
			// check the head of the list to see if should delete
			hashTable.erase(id);
		}
		
		else if (strcmp(entry, "QUIT") == 0 || strcmp(entry, "quit") == 0 || strcmp(entry, "q") == 0) {
			cont = false;
		}

	}
	
	// wooo
	return 0;
}

// add function creates a student, a node, checks the head and calls a recursive adding
void add(Node* &head, Student* st) {
	Student* student = NULL;
	
	// if there is no student already then the user can enter their own name and id and gpa manually
	if (st == NULL) {
		// create a new student by asking questions
		int id;
		float gpa;
		char* first = new char[20];
		char* last = new char[20];

		cout << endl << "First Name: ";
		cin.get(first, sizeof(first));
		cin.get();
		
		cout << "Last Name: ";
		cin.get(last, sizeof(last));
		cin.get();
		
		cout << "Student ID: ";
		cin >> id;
		cin.get();
		
		cout << "Student GPA: ";
		cin >> gpa;
		cin.get();
		
		student = new Student(first, last, id, gpa);
	} else { // otherwise it is generated
		student = st;
	}
	
	// and added to the hash table
	hashTable.add(student);

}

// this function creates a randomly generate student from 2 files
void generator(Node* &head) {

	// the files include 600 first names and 1000 last names
	char first[600][30];
	char last[1000][30];

	ifstream inFile;

	inFile.open("first.txt");

	// if there is a file then read in the values into the array
	if (inFile.is_open()) {
		int i = 1;
		for (i = 1; i < 601; i++) {
			if (!(inFile >> first[i])) {
				break;
			}
		}
	}

	inFile.close();

	inFile.open("last.txt");

	// read last names into array
	if (inFile.is_open()) {
		int i = 1;
		for (i = 1; i < 1001; i++) {
			if (!(inFile >> last[i])) {
				break;
			}
		}
	}

	inFile.close();

	// ask user for number of students to randomly create
	cout << "How many students do you wish to generate?" << endl;
	int entry;
	cin >> entry;
	cin.get();
	
	// create a new random student using rand()
	for (int i = 0; i < entry; i++) {
		int firstRand = 0;
		int lastRand = 0;
		int id = nextID;
		nextID++; // the ID is incremented from 1000
		int gpaRand = 0;
		float gpa;
		char* f = new char[30];
		char* l = new char[30];

		firstRand = rand() % 600;
		lastRand = rand() % 1000;
		// the new first and last name are taken using the randomly generated index
		strcpy(f, first[firstRand]);
		strcpy(l, last[lastRand]);
	
		gpaRand = rand() % 500;
		gpa = gpaRand / 100.0;
		
		// a new student is created and added to the hash table
		Student* student = new Student(f, l, id, gpa);
		add(head, student);
	}

	return;
}