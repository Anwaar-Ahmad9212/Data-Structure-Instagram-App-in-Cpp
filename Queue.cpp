//#include "Queue.h"
//#include "Node.h"
//#include <iostream>
//#include <string>
//#include "Notification.h"
//#include "Post.h"
//
//using namespace std;
//
//
//bool Queue::isempty()
//{
//	if (Front == NULL)
//	{
//		return true;
//	}
//	return false;
//}
//
//
//void Queue::Enqueue(Notification & str)
//{
//	Node<Notification>* P = new Node<Notification>(str);
//	P->Next = NULL;
//	if (Front == NULL)
//	{
//		Front = Rear = P;
//	}
//	else
//	{
//		Rear->Next = P;
//		Rear = P;
//	}
//}
//
//Notification Queue::Dequeue()
//{
//	if (isempty())
//	{
//		cout << "Queue is empty\n";
//	}
//	else
//	{
//		Node<Notification>* P = Front;
//		Front = Front->Next;
//		return P->Str;
//		delete[]P;
//	}
//}
//
//void Queue::Traversal()
//{
//	Node<Notification>* P = Front;
//	while (P != NULL)
//	{
//		cout << P->Str.Getmessage() << endl;
//		P = P->Next;
//	}
//	cout << endl;
//}
//
