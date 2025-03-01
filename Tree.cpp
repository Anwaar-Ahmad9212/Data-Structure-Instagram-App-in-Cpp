#include "Tree.h"
#include <iostream>
#include <algorithm>
#include "Node.h"
using namespace std;

// Constructor: Initializes the root of the tree to NULL
Tree::Tree() : Root(NULL) {}

// Destructor: Deletes the entire tree
Tree::~Tree() {
	DeleteTree(Root);
}

// Helper function: Returns the height of a node
int Tree::Height(Node< string>* P) {
	if (P == NULL) {
		return 0;
	}
	return P->Height;
}

// Helper function: Calculates the balance factor of a node
int Tree::BalanceFactor(Node< string>* P) {
	if (P == NULL) {
		return 0;
	}
	return Height(P->Left) - Height(P->Right);
}

// Right rotation: Performs a right rotation around the given node
Node< string>* Tree::RightRotate(Node< string>* y) {
	Node< string>* x = y->Left;
	Node< string>* T = x->Right;

	x->Right = y;
	y->Left = T;

	y->Height = max(Height(y->Left), Height(y->Right)) + 1;
	x->Height = max(Height(x->Left), Height(x->Right)) + 1;

	return x;
}

// Left rotation: Performs a left rotation around the given node
Node< string>* Tree::LeftRotate(Node< string>* x) {
	Node< string>* y = x->Right;
	Node< string>* T = y->Left;

	y->Left = x;
	x->Right = T;

	y->Height = max(Height(y->Left), Height(y->Right)) + 1;
	x->Height = max(Height(x->Left), Height(x->Right)) + 1;

	return y;
}

// Recursive function to insert a node into the tree
Node< string>* Tree::InsertRecursive(Node<string>* current, const string& str) {
	if (current == NULL) {
		return new Node< string>(str);
	}

	if (str == current->Str) {
		return current;
	}

	if (str < current->Str) {
		current->Left = InsertRecursive(current->Left, str);
	}
	else {
		current->Right = InsertRecursive(current->Right, str);
	}

	current->Height = max(Height(current->Left), Height(current->Right)) + 1;
	int BF = BalanceFactor(current);

	// Left Left Case
	if (BF > 1 && str < current->Left->Str) {
		return RightRotate(current);
	}

	// Right Right Case
	if (BF < -1 && str > current->Right->Str) {
		return LeftRotate(current);
	}

	// Left Right Case
	if (BF > 1 && str > current->Left->Str) {
		current->Left = LeftRotate(current->Left);
		return RightRotate(current);
	}

	// Right Left Case
	if (BF < -1 && str < current->Right->Str) {
		current->Right = RightRotate(current->Right);
		return LeftRotate(current);
	}

	return current;
}

// Helper function to delete the entire tree
void Tree::DeleteTree(Node< string>* node) {
	if (node != NULL) {
		DeleteTree(node->Left);
		DeleteTree(node->Right);
		delete node;
	}
}

// Pre-order traversal: Prints the nodes of the tree in pre-order
void Tree::PreOrder(Node< string>* P) const {
	if (P == NULL) {
		return;
	}

	cout << P->Str << " ";
	PreOrder(P->Left);
	PreOrder(P->Right);
}

// Get the root of the tree
Node< string>* Tree::GetRoot() const {
	return Root;
}

// Public method to insert a node into the tree
void Tree::Insert(const  string& str) {
	Root = InsertRecursive(Root, str);
}
bool Tree:: Search(Node<string>* P, string key)
{
	if (P != NULL)
	{
		if (P->Str == key)
		{
			return true;
		}
		else
		{
			if (P->Str > key)
			{
				return Search(P->Left, key);
			}
			else
			{
				return Search(P->Right, key);
			}
		}
	}
	else
	{
		return false;
	}
}