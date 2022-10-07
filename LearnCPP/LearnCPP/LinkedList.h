#pragma once
#include <atomic>
class LinkedList
{
public:
	class Node {
	public:
		Node(const int value) { this->value = value;  this->next = NULL; };
		int value;
		Node* next;
	};

	LinkedList() {};

	void push(const int value);
	void pushFront( const int value);
	void pushAfter(Node* node, const int value);
	Node *find(const int value);
	void show();
private:
	Node* head;

};

