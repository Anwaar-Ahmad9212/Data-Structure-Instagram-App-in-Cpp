#include <iostream>
#include <string>
#include <limits>
#include "Stack.h"
#include "Queue.h"
#include "Post.h"
#include "Tree.h"
#include "FriendRequest.h"
//#include "Graph.h"
#include <Windows.h>
#include <limits>

using namespace std;

// Function to clear input buffer
void clearInputBuffer() {
	cin.clear();
	cin.ignore(256, '\n');
}

class Instagram
{
private:
	Graph userNetwork;
	FriendRequestManager Friend;
	Users Loggedin;
	Tree Detector;
	Queue<Notification> NotificationQueue;
	int Utilize;
	int Size;



public:
	Instagram(int size) : Size(size), Utilize(0) {}

	void send_message(string name, string msg)
	{
		Users* temp = userNetwork.findUser(name);

		temp->send_message(Loggedin, msg);
		Loggedin.send_message(*temp, msg);


	}

	void display_msgs(string username)
	{
		Loggedin.display_user_chats(username);
	}


	void display_list()
	{
		Loggedin.display_chats();
	}
	void Menu()
	{
		char Opt = 'N';
		cout << "ALREADY HAVE AN ACCOUNT? ";
		cout << "\nEnter Y -> Yes & N -> No: ";
		cin >> Opt;
		cin.ignore();

		switch (Opt) {
		case 'Y':
		case 'y':
			system("cls");
			Login();
			break;
		case 'N':
		case 'n':
			system("cls");
			AddUser();
			break;
		default:
			break;
		}
	}

	void AddUser()
	{
		cout << "--------------------------REGISTRATION PORTAL---------------------------\n";
		Users AddUser;
		bool Flag = false;

		while (!Flag) {
			cout << "Enter UserName: ";
			string Name;
			getline(cin, Name);

			for (int i = 0; i < Name.length(); i++)
			{
				Name[i] = tolower(Name[i]);
			}
			Flag = true;
			// Use graph search instead of array traversal
			Vertex* current = userNetwork.head;
			while (current != nullptr) {
				if (current->data.GetName() == Name) {
					Flag = false;
					cout << "\nName Already Exists\n";
					break;
				}
				current = current->next;
			}

			if (Flag) {
				AddUser.setName(Name);
			}
		}

		cin >> AddUser;

		// Add user to graph
		userNetwork.addVertex(AddUser);
		Loggedin = AddUser;
		Detector.Insert(AddUser.GetName());
		Utilize++;

		cout << "\nAccount Created Successfully";
		Sleep(1000);
		system("cls");

		cout << "\nDo You Want to Login??\n";
		char Opt;
		cout << "\nEnter Y -> Yes & N -> No: ";
		cin >> Opt;
		cin.ignore();

		switch (Opt) {
		case 'Y':
		case 'y':
			system("cls");
			Login();
			break;
		case 'N':
		case 'n':
			system("cls");
			DisplayMenu();
			break;
		default:
			break;
		}


		Login();
	}

	void ForgotPassword() {
		cout << "\nEnter New Password: ";
		string Password;
		getline(cin, Password);

		bool validPassword = false;
		while (!validPassword) {
			if (Loggedin.ValidatePassword(Password)) {
				Loggedin.SetPassword(Password);
				validPassword = true;

				// Update the password in the Graph
				Vertex* current = userNetwork.head;
				while (current != nullptr) {
					if (current->data.GetName() == Loggedin.GetName()) {
						current->data.SetPassword(Password);
						break;
					}
					current = current->next;
				}
			}
			else {
				cout << "\nInvalid password. Please try again: ";
				getline(cin, Password);
			}
		}

		cout << "\nPassword updated successfully. Login again with the new password.\n";


		Login();
	}

	void Login() {
		char Opt;
		cout << "------------------------ENTER LOGIN DETAILS:----------------------";
		string Username, Password;
		bool flag = false;
		Users* LoggedInUser = nullptr;

		while (!flag) {
			cout << "\nEnter Your Username : ";
			getline(cin, Username);

			for (int i = 0; i < Username.length(); i++)
			{
				Username[i] = tolower(Username[i]);
			}
			// Search through graph vertices 
			Vertex* current = userNetwork.head;
			while (current != nullptr) {
				if (current->data.GetName() == Username) {
					flag = true;
					LoggedInUser = &(current->data);
					Loggedin = *LoggedInUser;
					break;
				}
				current = current->next;
			}

			if (!flag) {
				cout << "Username not found. Please try again.\n";

				cout << "Do you Want to Create Account: ";
				cout << "\nEnter Y -> Yes & N -> No: ";
				cin >> Opt;
				cin.ignore();

				switch (Opt) {
				case 'Y':
				case 'y':
					system("cls");
					AddUser();
					return;
				case 'N':
				case 'n':
					cout << "Exiting: ";
					return;
				default:
					break;
				}
			}

		}

		bool passwordCorrect = false;
		int count = 0;
		while (!passwordCorrect) {
			cout << "Enter Password: ";
			getline(cin, Password);

			// Remove leading/trailing spaces from input
			Password.erase(0, Password.find_first_not_of(' '));
			Password.erase(Password.find_last_not_of(' ') + 1);

			if (LoggedInUser->GetPassword() == Password) {
				passwordCorrect = true;
				cout << "Authentication successful.\n";
			}
			else {
				cout << "Incorrect password. Please try again.\n";
				count++;
			}
			if (count == 3)
			{
				cout << "\nForgot Password";
				ForgotPassword();

			}
		}
		cout << "\nLoggedIn At: " << LoggedInUser->Getcurrenttime();
		system("cls");
		Loggedin.CheckFollowersPosts();

		// Show menu after login
		system("cls");
		DisplayLoggedInMenu();
	}


	void ManageMessages() {
		while (true) {
			cout << "\n--- Message Management ---\n";
			cout << "1. Send a Message\n";
			cout << "2. View Messages from a User\n";
			cout << "3. View All Chats\n";
			cout << "4. Return to Main Menu\n";
			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			clearInputBuffer();

			switch (choice) {
			case 1: {
				string recipientName, message;
				cout << "\nEnter the recipient's username: ";
				getline(cin, recipientName);

				cout << "\nEnter your message: ";
				getline(cin, message);

				send_message(recipientName, message);
				cout << "Message sent successfully to " << recipientName << "." << endl;
				break;
			}
			case 2: {
				string username;
				cout << "\nEnter the username to view messages: ";
				getline(cin, username);

				display_msgs(username);
				break;
			}
			case 3:
				display_list();
				break;
			case 4:
				return;
			default:
				cout << "\nInvalid choice. Please try again.\n";
			}
		}
	}

	void DisplayLoggedInMenu() {
		while (true) {
			cout << "\n--- Social Network Menu ---\n";
			cout << "1. Manage Friends\n";
			cout << "2. Manage Posts\n";
			cout << "3. Manage Notifications\n";
			cout << "4. Search User\n";
			cout << "5. Logout\n";
			cout << "6 Message Menu" << endl;
			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			clearInputBuffer();

			switch (choice) {
			case 1:
			{
				system("cls");
				ManageFriends();
				break;
			}

			case 2:
			{
				system("cls");
				ManagePosts();
				break;
			}
			case 3:
			{  system("cls");
			ManageNotifications();
			break;
			}

			case 4:
			{
				system("cls");
				SearchUser();
				break;
			}
			case 5:
				LogOut();
				return;

			case 6:
				ManageMessages();
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
			}
		}
	}


	void ManageFriends() {
		system("cls");
		while (true) {
			cout << "\n--- Friend Management ---\n";
			cout << "1. Send Friend Request\n";
			cout << "2. View Pending Friend Requests\n";
			cout << "3. Accept Friend Request\n";
			cout << "4. View Friends List\n";
			cout << "5. Reject Friend Request\n";
			cout << "6. Return to Main Menu\n";
			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			clearInputBuffer();

			switch (choice) {
			case 1: {
				string receiverName;
				userNetwork.displayAllUsers();
				cout << "\nEnter the name of the user you want to send a friend request to: ";
				getline(cin, receiverName);

				for (int i = 0; i < receiverName.length(); i++) {
					receiverName[i] = tolower(receiverName[i]);
				}

				string loggedinName = Loggedin.GetName();
				for (int i = 0; i < loggedinName.length(); i++) {
					loggedinName[i] = tolower(loggedinName[i]);
				}

				if (receiverName == loggedinName) {
					cout << "You cannot send a friend request to yourself." << endl;
					break;
				}

				Vertex* current = userNetwork.head;
				bool userFound = false;

				while (current != nullptr) {
					string currentName = current->data.GetName();
					for (int i = 0; i < currentName.length(); i++) {
						currentName[i] = tolower(currentName[i]);
					}

					if (currentName == receiverName) {
						userFound = true;
						Friend.sendFriendRequest(Loggedin, current->data);
						Sleep(1000);
						system("cls");
						break;
					}
					current = current->next;
				}

				// If no user was found in the network
				if (!userFound) {
					cout << "No user found with the name \"" << receiverName << "\"." << endl;
				}
				break;
			}
			case 2:
				system("cls");
				Friend.displayPendingRequests(Loggedin);
				break;
			case 3: {
				system("cls");
				string senderName;
				Friend.displayPendingRequests(Loggedin);
				cout << "\nEnter the name of the user whose friend request you want to accept: ";
				getline(cin, senderName);

				for (int i = 0; i < senderName.length(); i++)
				{
					senderName[i] = tolower(senderName[i]);
				}
				// Find sender in graph
				Vertex* current = userNetwork.head;
				while (current != nullptr) {
					if (current->data.GetName() == senderName) {
						Friend.acceptFriendRequest(current->data, Loggedin);
						break;
					}
					current = current->next;
				}
				break;
			}
			case 4:
				system("cls");
				Friend.displayFriends(Loggedin);
				break;
			case 5: {
				system("cls");
				string senderName;
				Friend.displayPendingRequests(Loggedin);
				cout << "\nEnter the name of the user whose friend request you want to reject: ";
				getline(cin, senderName);

				for (int i = 0; i < senderName.length(); i++)
				{
					senderName[i] = tolower(senderName[i]);
				}
				// Find sender in graph
				Vertex* current = userNetwork.head;
				while (current != nullptr) {
					if (current->data.GetName() == senderName) {
						Friend.rejectFriendRequest(current->data, Loggedin);
						break;
					}
					current = current->next;
				}
				break;
			}
			case 6:
				return;
			default:
				cout << "\nInvalid choice. Please try again.\n";
			}
		}
	}
	void ManagePosts() {
		while (true) {
			cout << "\n--- Post Management ---\n";
			cout << "1. Create a New Post\n";
			cout << "2. View Personal Posts\n";
			cout << "3. View News Feed\n";
			cout << "4. Return to Main Menu\n";
			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			clearInputBuffer();

			switch (choice) {
			case 1: {
				string postContent;
				cout << "\nEnter your post content: ";
				getline(cin, postContent);

				Post newPost(postContent);
				newPost.SetName(Loggedin.GetName());
				Loggedin.CreatePersonalPost(newPost);
				break;
			}
			case 2:
				Loggedin.PersonalNewsFeed(Loggedin);
				break;
			case 3:
				Loggedin.CheckFollowersPosts();
				break;
			case 4:
				return;
			default:
				cout << "\nInvalid choice. Please try again.\n";
			}
		}
	}

	void ManageNotifications() {
		while (true) {
			cout << "\n--- Notification Management ---\n";
			cout << "1. View Unread Notifications\n";
			cout << "2. Check Notification\n";
			cout << "3. Mark Notification\n";
			cout << "4. Return to Main Menu\n";
			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			clearInputBuffer();

			switch (choice) {
			case 1:
				Loggedin.DisplayUnReadNotification();
				break;
			case 2:
				Loggedin.CheckNotifications();
				//break;
			case 3: {
				int markChoice;
				cout << endl;
				cout << "1. Mark as Read\n";
				cout << "2. Mark as Unread\n";
				cout << "Enter your choice: ";
				cin >> markChoice;
				clearInputBuffer();

				Loggedin.MarkRead(markChoice);
				break;
			}
			case 4:
				return;
			default:
				cout << "\nInvalid choice. Please try again.\n";
			}
		}
	}

	void SearchUser() {
		string UserName;
		cout << "\nEnter the UserName to be Searched: ";
		getline(cin, UserName);

		// Use graph search 
		Vertex* current = userNetwork.head;
		bool userFound = false;

		while (current != nullptr) {
			if (current->data.GetName() == UserName) {
				userFound = true;
				cout << "Opening Users Account......\n";
				system("cls");
				Sleep(100);
				current->data.CheckFollowersPosts();
				break;
			}
			current = current->next;
		}

		if (!userFound) {
			cout << "\nNo User Found";
		}
	}

	void LogOut() {
		cout << "\nLogged Out Successfully";
		system("cls");
		Menu();
	}

	void DisplayMenu() {
		int choice;
		do {
			cout << "\n---------------------- Instagram Clone Menu--------------------" << endl;
			cout << "1. Login" << endl;
			cout << "2. SignUp" << endl;
			cout << "3. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cin.ignore(); // Clear input buffer

			switch (choice) {
			case 1:
				Login();
				break;
			case 2:
				system("cls");
				AddUser();
				break;
			case 3:
				cout << "\nExiting Instagram Clone. Goodbye!" << endl;
				return;
			default:
				cout << "\nInvalid choice. Please try again." << endl;
			}
		} while (true);
	}
};

int main() {
	Instagram socialNetwork(5);
	socialNetwork.DisplayMenu();
	return 0;
}