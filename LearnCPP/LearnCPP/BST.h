#pragma once
//template< class T>

class BST
{
	struct Node {
		int value;
		Node* right;
		Node* left;
	};
public:
	BST() {}

	void create(const int value);
	void insert(const int value);
	void remove(const int value);
	Node *search(const int value);
	void show();

private:
	Node* head = NULL;

};

