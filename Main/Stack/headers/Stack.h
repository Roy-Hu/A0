
#ifndef STACK_H
#define STACK_H
#include <iostream>

// this is the node class used to build up the LIFO stack
template <class Data>
class Node {

private:

	Data holdMe;
	Node *next;
	
public:

	/*****************************************/
	/** WHATEVER CODE YOU NEED TO ADD HERE!! */
	/*****************************************/
	Node(Data data) {
		this->holdMe = data;
		this->next = NULL;
	}

	Data getDate() { 
		return holdMe;
	}

	Node* getNext() {
		return next;
	}

	void setDate(Data newData) { 
		holdMe = newData;
	}

	void setNext(Node *newNext) {
		next = newNext;
	}
};

// a simple LIFO stack
template <class Data> 
class Stack {

	Node <Data> *head;

public:

	// destroys the stack
	~Stack () {
		Node <Data>* top;
		Node <Data>* cur;

		top = head;
		while (top != NULL) {
			cur = top;
			top = top->getNext();
			delete(cur);
		}		
	}

	// creates an empty stack
	Stack () { 
		head = NULL;
	 }

	// adds pushMe to the top of the stack
	void push (Data pushMe) { 
		Node <Data>* newNode;
		newNode = new Node <Data> (pushMe);

		// Fail to allocate memory for stack
		if (newNode == NULL) {
			exit(1);
		}

		newNode->setNext(head);
		head = newNode;
	}

	// return true if there are not any items in the stack
	bool isEmpty () { 
		return head == NULL;
	}

	// pops the item on the top of the stack off, returning it...
	// if the stack is empty, the behavior is undefined
	Data pop () { 
		Node <Data>* cur;
		Data data;
		
		// Trying to pop a empty stack
		if (head == NULL) {
			exit(1);
		}

		data = head->getDate();

		cur = head;

		head = head->getNext(); 

		delete(cur);

		return data; 
	}
};

#endif
