#include "Stack.h"
#include "Node.h"
#include <iostream>
#include <string>
#include "Post.h"
using namespace std;


void Stack::Push(Post & post)
{
	Node<Post>* P = new Node<Post>(post);
	if (P == NULL)
	{
		cout << "Stack overflow occurs\n";
	}
	else if (Top == NULL)
	{

		Top = P;
		Top->Next = NULL;
	}
	else
	{
		P->Next = Top;
		Top = P;
	}

}

Post Stack::Pop()
{
	if (isempty())
	{
		cout << "Stsck is empty\n";
		return Post(" ");
	}
	Node<Post>* P = Top;
	Post st = P->Str;
	Top = P->Next;
	delete P;
	return st;

}
void Stack::Traversal()
{
	Node<Post>* ptr = Top;
	while (ptr != NULL)
	{
		cout << ptr->Str.GetPost() << endl;
		ptr = ptr->Next;
	}
}
bool Stack::isempty()
{
	Node<Post>* P = Top;
	if (Top == NULL)
	{
		return true;
	}
	else
		return false;
}

