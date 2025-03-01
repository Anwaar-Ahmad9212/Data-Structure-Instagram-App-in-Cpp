#pragma once
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Node.h"
#include "Post.h"
#include "Tree.h"
#include "Notification.h"
#include"Chats.h"
#include <Windows.h>

using namespace std;
//class Chats;
class Users
{
	string UserName;
	string Password;
	string City;
	string CurrentTime;
	Stack PersonalPost;
	Stack NewsFeedPost;
	Queue<Notification> NotificationQueue;
	bool Sent;
	//Queue<string> name_sender;
	//Stack *messages_of_user;
//	int index = 0;
	Chats chats_of_user;
//	Tree Detector;
public:

	void send_message(Users& source, string msg)
	{
		//this->chats_of_user = new Chats[1];

		chats_of_user.send_message(source.GetName(), msg);
		cout << "Message sent succefully" << endl;
		cout << endl;
	}
	void SetSent(bool Set)
	{
		Sent = Set;
	}

	bool GetSent()
	{
		return Sent;
	}

	void display_chats()
	{
		chats_of_user.show_chats();
	}

	void display_user_chats(string source)
	{
		chats_of_user.open_chat_of_user(source);
	}

	friend istream& operator>>(istream& input, Users& user) 
	{
		cout << "Enter Password: ";
		string password;
		getline(input, password);

		// Validate the password
		while (!user.ValidatePassword(password)) {
			cout << "\nEnter Password Again: ";
			getline(input, password);
		}

		// Set the validated password
		user.SetPassword(password); // This line ensures the password is saved to the class attribute

		cout << "Enter City: ";
		string City;
		getline(input, City);

		// Validate and set the city
		while (!user.setCity(City)) {
			cout << "\nEnter City Again: ";
			getline(input, City);
		}

		// Set the current time
		char buffer[26];
		time_t now = time(nullptr);

		if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
			string currentTime(buffer);
			user.setCurrentTime(currentTime);
		}
		else {
			cout << "\nFailed to get current time\n";
		}
		return input;
	}

	bool ValidatePassword(const string& pass) {
		if (pass.length() < 8) {
			cout << "\nPassword must be at least 8 characters long.";
			return false;
		}

		bool allSpaces = true;
		for (int i = 0; i < pass.length(); i++) {
			if (!isspace(pass[i]))
			{
				allSpaces = false;
				break;
			}
		}

		if (allSpaces) {
			cout << "\nError! Password cannot consist only of spaces.";
			return false;
		}

		//cout << "\nPassword validation successful.\n";
		return true;
	}

	void SetUserPassword() {
		string pas;
		bool validPassword = false;

		while (!validPassword) {
			cout << "\nEnter Password: ";
			getline(cin, pas);

			if (ValidatePassword(pas)) {
				SetPassword(pas);
				validPassword = true;
			}
		}

	}
	void setCurrentTime(const string& Time)
	{
		CurrentTime = Time;
	}
	void setName(const string& Name)
	{
		UserName = Name;
	}
	bool setCity(const string& city)
	{
		bool flag = true;
		for (int i = 0; i < City.length(); i++) {
			if (!isalpha(City[i])) // Check if character is not a digit
				flag = false;

		}
		if (flag == false)
		{
			cout << "Error! Please enter a Name\n";

			return false;
		}
		else {
			City = city;
			return true;
		}

	}
	void SetPassword(const string& password)
	{
		Password = password;
	}
	string GetName()
	{
		return UserName;
	}
	string GetPassword()
	{
		return Password;
	}

	string GetCity()
	{
		return City;
	}

	string Getcurrenttime()
	{
		return CurrentTime;
	}


	void CreatePersonalPost(Post& Post)
	{
		cout << "\nPosting........\n";
		Sleep(1000);
		system("cls");
		PersonalPost.Push(Post);
		NewsFeedPost.Push(Post);
		cout << "\nPost Created Successfully\n";
		cout << endl << endl;

		cout << "Post: " << Post.GetPost() << endl;
		cout << "Posted By: " << UserName << endl;
		cout << "Posted On: " << Post.Getcurrenttime() << endl;



	}
	void NewsFeed()
	{
		cout << "Checking Feed\n";
		NewsFeedPost.Traversal();
	}
	void PersonalNewsFeed(const Users& User)
	{
		cout << "Checking Feed\n";
		if (!PersonalPost.isempty())
		{
			PersonalPost.Traversal();
		}
		else
		{
			cout << "\nNo Post has been Made.";
			cout << endl << endl;

			cout << "Do You Want to Create your First Post\n";
			char opt = 'N';
			cout << "\nEnter Y -> Yes & N -> No: "; cin >> opt;

			switch (opt)
			{
			case 'Y':
			case 'y':
			{
				cin.ignore();
				string POST;
				cout << "\nKindly Share Your Thoughts: "; getline(cin, POST);
				Post Posttobe(POST);
				CreatePersonalPost(Posttobe);
				break;
			}
			case 'N':
			case 'n':
			{
				cout << "\n No Post Has been Made";
			}

			default:
				break;
			}
		}

	}

	void CheckFollowersPosts()
	{
		if (!NewsFeedPost.isempty())
		{
			NewsFeedPost.Traversal();
		}
		else
		{
			cout << "\nNo Post Yet\n";
		}

	}
	void ReceiveNotification(Notification& Notify)
	{
		cout << "\nSending Notification..............\n";
		Sleep(1000);
		NotificationQueue.Enqueue(Notify);

		cout << endl << endl;
		cout << "Notification: " << Notify.Getmessage() << endl;
		cout << "Sent At: " << Notify.Getcurrenttime() << endl;
		cout << "Notification Sent Successfully\n";
	}

	void DisplayUnReadNotification()
	{
		cout << "\nNotification to Be Read:\n\n";
		NotificationQueue.Traversal();
	}

	void CheckNotifications()
	{
		if (!NotificationQueue.isempty())
		{
			Notification Check = NotificationQueue.Dequeue();
			cout << "SEEN NOTIFICATION: " << Check.Getmessage() << endl;
		}
		else
		{
			cout << "\nNo Notification Yet";
		}
	}

	void ClearNotification()
	{
		Notification Check = NotificationQueue.Dequeue();
		cout << "NOTIFICATION CLEARED: " << Check.Getmessage() << endl;
	}

	void MarkRead(int Choice)
	{
		switch (Choice)
		{
		case 1:
		{
			Notification Check = NotificationQueue.Dequeue();
			cout << "Marked As Read" << endl;
			break;
		}
		case 2:
		{
			Notification Check = NotificationQueue.Dequeue();
			NotificationQueue.Enqueue(Check);
			cout << "Marked as UnRead" << endl;
			break;
		}
		default:
			break;
		}
	}
	/*void AddInstagram()
	{
		string S = "A";
		Detector.Insert(S);
		Detector.Insert(S);
		Detector.PreOrder(Detector.GetRoot());
	}*/

	Stack GetPersonalPost()
	{
		return PersonalPost;
	}

};

