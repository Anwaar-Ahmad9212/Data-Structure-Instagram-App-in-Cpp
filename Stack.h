#pragma once
#include <iostream>
#include "Node.h"
#include"Post.h"

class Stack
{
	Node<Post>* Top;
public:
	Stack() :Top(NULL) {}
	void Push(Post & post);
	Post Pop();
	void Traversal();
	bool isempty();

};


//#pragma once
//#include <iostream>
//#include "Node.h"  // Include Node.h to define Node<T> in Stack
//using namespace std;
//// Forward declare Node
//template <typename T>
//class Node;
//
//template <typename T>
//class Stack
//{
//private:
//    Node<T>* top;
//
//public:
//    Stack()
//    {
//        top = nullptr;
//    }
//
//    ~Stack() {
//        while (!isEmpty())
//        {
//            Pop();
//        }
//    }
//
//    void Push(T value)
//    {
//        Node<T>* newNode = new Node<T>(value);
//      //  newNode->Str = value;
//        newNode->Next = top;
//        top = newNode;
//       // cout << value << " pushed to stack." << endl;
//    }
//
//    void Pop() {
//        if (isEmpty())
//        {
//            cout << "Stack is empty. Cannot pop." << endl;
//            return;
//        }
//        Node<T>* temp = top;
//        top = top->Next;
//        //cout << temp->Str << " popped from stack." << endl;
//        delete temp;
//    }
//
//    T Peek() {
//        if (isEmpty()) {
//            cout << "Stack is empty." << endl;
//            return T();  // Return default value for the type T
//        }
//        return top->Str;
//    }
//
//    bool isEmpty() {
//        return top == nullptr;
//    }
//};
