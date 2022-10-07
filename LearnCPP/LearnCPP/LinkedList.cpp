#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>

void LinkedList::pushFront( const int value)
{
	Node* newNode = new Node(value);
	newNode->next = this->head;
	this->head = newNode;
}

void LinkedList::pushAfter( Node *node, const int value )
{
	if (node == NULL) {
		std::cout << "error " << std::endl;
		return;
	}

	Node* newNode = new Node(value);
	newNode->next = node->next;
	node->next = newNode;
}

LinkedList::Node *LinkedList::find(const int value) {
	Node* current = this->head;
	if (current == NULL) {
		return NULL;
	}
	while (current != NULL) {
		if (current->value == value)
			return current;
		current = current->next;
	}
	return NULL;
}

void LinkedList::push(const int value) {
	Node* newNode = new Node(value);
	Node* current = this->head;
	if (this->head == NULL) {
		this->head = newNode;
		std::cout << "added value" << newNode->value << " to head" << std::endl;
	} else {
		Node* current = this->head;
		while (current->next!= NULL) {
			current = current->next;
		}
		current->next = newNode;
		std::cout << "added value" << newNode->value << " to node" << std::endl;
	}
}

void LinkedList::show() {
	Node* current = this->head;
	if (current == NULL) {
		std::cout << "???" << std::endl;
		return;
	}
	while (current != NULL) {
		std::cout << current->value << " " << std::endl;
		current = current->next;
	}
}
