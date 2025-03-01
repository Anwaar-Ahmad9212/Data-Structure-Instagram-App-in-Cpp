#pragma once
#include "Post.h"
#include "Notification.h"

template <typename T>
class Node
{
public:

	T Str;
	//Notification Mess;
	Node<T>* Next;
	Node<T>* Left;
	Node<T>* Right;
	int Height;

	Node(T st ) :Str(st), Next(NULL) {}
	//Node(Notification st) :Mess(st),Next(NULL){}
};

