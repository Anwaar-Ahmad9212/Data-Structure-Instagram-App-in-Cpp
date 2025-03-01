//#pragma once
//#include <iostream>
//#include "Node.h"
//using namespace std;
//
//
//class Queue
//{
//public:
//	Node<Notification>* Front;
//	Node<Notification>* Rear;
//
//	Queue() : Front(NULL), Rear(NULL) {}
//	bool isempty();
//	void Enqueue(Notification & Str);
//	Notification Dequeue();
//	void Traversal();
//
//};
//


#pragma once
#include <iostream>
#include"Node.h";
using namespace std;

template <typename T>
class Queue {
private:
	Node<T>* Front;
	Node<T>* Rear;

public:
	Queue() : Front(nullptr), Rear(nullptr) {}

	// Check if queue is empty
	bool isempty() const
	{
		return Front == nullptr;
	}

	// Enqueue an item
	void Enqueue(const T& item) {
		Node<T>* newNode = new Node<T>(item);

		if (isempty()) {
			Front = Rear = newNode;
		}
		else {
			Rear->Next = newNode;
			Rear = newNode;
		}
	}

	int find(string source)
	{
		Node<string>* temp = Front;
		int index = 0;
		while (temp != nullptr)
		{
			if (temp->Str == source) return index;
			temp = temp->Next;
		}
		return -1;
	}

	// Dequeue an item
	T Dequeue() {
		if (isempty()) {
			throw runtime_error("Queue is empty");

		}
		else
		{


			Node<T>* temp = Front;
			T item = Front->Str;

			Front = Front->Next;

			// If queue becomes empty after dequeuing
			if (Front == nullptr) {
				Rear = nullptr;
			}

			delete temp;
			return item;
		}
	}

	// Traverse and print queue contents
	void Traversal() {
		Node<T>* current = Front;
		while (current != nullptr) {
			cout << current->Str << endl;
			current = current->Next;
		}
	}

	//
	//  Destructor to prevent memory leaks
	~Queue() {
		while (!isempty()) {
			Dequeue();
		}
	}

	// Copy constructor and assignment operator to handle deep copying
	Queue(const Queue& other) : Front(nullptr), Rear(nullptr) {
		Node<T>* current = other.Front;
		while (current != nullptr) {
			Enqueue(current->Str);
			current = current->Next;
		}
	}

	Queue& operator=(const Queue& other) {
		if (this != &other) {
			// Clear existing queue
			while (!isempty()) {
				Dequeue();
			}

			// Copy elements from other queue
			Node<T>* current = other.Front;
			while (current != nullptr) {
				Enqueue(current->Str);
				current = current->Next;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& outfile,  T & obj) {
		outfile << obj.Str; // Define how to print the object
		return outfile;
	}
};