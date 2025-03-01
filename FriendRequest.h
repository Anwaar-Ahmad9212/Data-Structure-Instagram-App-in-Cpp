#pragma once
#include <iostream>
#include <string>
#include "Users.h"
#include "Queue.h"
#include "FriendRequest.h"
//#include "Graph.h"

using namespace std;

struct AdjListNode {
    Users dest;
    string weight;
    AdjListNode* next;

    AdjListNode(Users destination, string weight_temp)
        : dest(destination), weight(weight_temp), next(nullptr) {}
};

// Vertex for Graph
struct Vertex {
    Users data;
    AdjListNode* adjListHead;
    Vertex* next;

    Vertex(Users d) : data(d), adjListHead(nullptr), next(nullptr) {}
};

// Graph Class
class Graph {
public:
    Vertex* head;

    Vertex* getVertex(Users data) {
        Vertex* current = head;
        while (current != nullptr) {
            if (current->data.GetName() == data.GetName()) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

public:
    Graph() : head(nullptr) {}

    void addVertex(Users data) {
        if (getVertex(data) == nullptr) {
            Vertex* newVertex = new Vertex(data);
            newVertex->next = head;
            head = newVertex;
        }
    }

    void addEdge(Users src, Users dest, string weight) {
        Vertex* srcVertex = getVertex(src);
        Vertex* destVertex = getVertex(dest);

        if (srcVertex == nullptr || destVertex == nullptr) {
            cout << "Source or Destination vertex not found!" << endl;
            return;
        }

        // Add edge for source to destination
        AdjListNode* newNode = new AdjListNode(dest, weight);
        newNode->next = srcVertex->adjListHead;
        srcVertex->adjListHead = newNode;

        // Add edge for destination to source (undirected)
        newNode = new AdjListNode(src, weight);
        newNode->next = destVertex->adjListHead;
        destVertex->adjListHead = newNode;
    }

    bool hasEdge(const Users& src, Users& dest) {
        Vertex* srcVertex = getVertex(src);
        if (srcVertex == nullptr) return false;

        AdjListNode* current = srcVertex->adjListHead;
        while (current != nullptr) {
            if (current->dest.GetName() == dest.GetName()) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void displayFriendsOf(const Users& user) {
        Vertex* userVertex = getVertex(user);
        if (userVertex == nullptr) {
            cout << "User not found in the network." << endl;
            return;
        }

        AdjListNode* current = userVertex->adjListHead;
        bool hasFriends = false;

        while (current != nullptr) {
            if (current->weight == "friend") {
                cout << current->dest.GetName() << endl;
                hasFriends = true;
            }
            current = current->next;
        }

        if (!hasFriends) {
            cout << "No friends found." << endl;
        }
    }

    // Function to display all available users in the network
    void displayAllUsers() {
        if (head == nullptr) {
            cout << "No users in the network." << endl;
            return;
        }

        cout << "All available users in the network:" << endl;
        Vertex* current = head;
        while (current != nullptr) {
            cout << "- " << current->data.GetName() << endl;
            current = current->next;
        }
    }

    Users* findUser(const string& source)
    {
        Vertex* current = head;
        while (current != nullptr)
        {
            if (current->data.GetName() == source)
            {
                return &(current->data); // Return a pointer to the user if found
            }
            current = current->next;
        }
        return nullptr; // Return nullptr if user not found
    }

    // Function to search for a specific user in the graph
    bool searchUser(const string& username) {
        Vertex* current = head;
        while (current != nullptr) {
            if (current->data.GetName() == username) {
                cout << "User \"" << username << "\" found in the network." << endl;
                return true;
            }
            current = current->next;
        }
        cout << "User \"" << username << "\" not found in the network." << endl;
        return false;
    }
};

// Friend Request Class
class FriendRequest {
private:
    Users sender;
    Users receiver;
    string status; // "pending", "accepted", "blocked"

public:
    FriendRequest() : status("pending") {}

    FriendRequest(const Users& send, const Users& rec)
        : sender(send), receiver(rec), status("pending") {}

    void setSender(const Users& send) { sender = send; }
    void setReceiver(const Users& rec) { receiver = rec; }
    void setStatus(const string& stat) { status = stat; }

    Users getSender() const { return sender; }
    Users getReceiver() const { return receiver; }
    string getStatus() const { return status; }

    void displayRequest() {
        cout << "From: " << sender.GetName()
            << " | Status: " << status << endl;
    }
};

// Friend Request Manager
class FriendRequestManager {
private:
    Graph userNetwork;
    Queue<FriendRequest> pendingRequests;

public:
    bool hasPendingRequest(Users& sender, Users& receiver) {
        Queue<FriendRequest> tempQueue;
        bool requestExists = false;

        while (!pendingRequests.isempty()) { //checking from both ends
            FriendRequest currentRequest = pendingRequests.Dequeue();

            if ((currentRequest.getSender().GetName() == sender.GetName() &&
                currentRequest.getReceiver().GetName() == receiver.GetName() &&
                currentRequest.getStatus() == "pending") ||
                (currentRequest.getSender().GetName() == receiver.GetName() &&
                    currentRequest.getReceiver().GetName() == sender.GetName() &&
                    currentRequest.getStatus() == "pending")) {
                requestExists = true;
            }

            tempQueue.Enqueue(currentRequest);
        }

        pendingRequests = tempQueue;
        return requestExists;
    }

    void sendFriendRequest(Users& sender, Users& receiver) {
        // Check if a friend request already exists
        if (hasPendingRequest(sender, receiver)) {
            cout << "A friend request is already pending with " << receiver.GetName() << endl;
            return;
        }

        // Check if they are already friends
        if (areFriends(sender, receiver)) {
            cout << "You are already friends with " << receiver.GetName() << endl;
            return;
        }

        // Check if user has already sent a request
        if (sender.GetSent()) {
            cout << "You have already sent a friend request. Please wait for a response." << endl;
            return;
        }

        FriendRequest newRequest(sender, receiver);
        pendingRequests.Enqueue(newRequest);
        sender.SetSent(true);
        Notification notify("New Friend Request from " + sender.GetName());
        receiver.ReceiveNotification(notify);
        cout << "Friend request sent to " << receiver.GetName() << endl;
    }

    void acceptFriendRequest(Users& sender, Users& receiver) {
        Queue<FriendRequest> tempQueue;
        bool requestFound = false;

        while (!pendingRequests.isempty()) {
            FriendRequest currentRequest = pendingRequests.Dequeue();

            if (currentRequest.getSender().GetName() == sender.GetName() &&
                currentRequest.getReceiver().GetName() == receiver.GetName()) {
                currentRequest.setStatus("accepted");

                userNetwork.addVertex(sender);
                userNetwork.addVertex(receiver);
                userNetwork.addEdge(sender, receiver, "friend");

                // Reset the sent status
                sender.SetSent(false);

                requestFound = true;

                Notification notify("Friend Request Accepted by " + receiver.GetName());
                sender.ReceiveNotification(notify);
            }

            tempQueue.Enqueue(currentRequest);
        }

        pendingRequests = tempQueue;

        if (requestFound) {
            cout << "Friend request from " << sender.GetName()
                << " accepted by " << receiver.GetName() << endl;
        }
        else {
            cout << "No pending friend request found." << endl;
        }
    }

    void rejectFriendRequest(Users& sender, Users& receiver) {
        Queue<FriendRequest> tempQueue;
        bool requestFound = false;

        while (!pendingRequests.isempty()) {
            FriendRequest currentRequest = pendingRequests.Dequeue();

            if (currentRequest.getSender().GetName() == sender.GetName() &&
                currentRequest.getReceiver().GetName() == receiver.GetName()) {
                currentRequest.setStatus("rejected");

                // Reset the sent status
                sender.SetSent(false);

                requestFound = true;

                Notification notify("Friend Request Rejected by " + receiver.GetName());
                sender.ReceiveNotification(notify);
            }

            tempQueue.Enqueue(currentRequest);
        }

        pendingRequests = tempQueue;

        if (requestFound) {
            cout << "Friend request from " << sender.GetName()
                << " rejected by " << receiver.GetName() << endl;
        }
        else {
            cout << "No pending friend request found." << endl;
        }
    }

    void displayPendingRequests(Users& user) {
        Queue<FriendRequest> tempQueue;
        bool hasRequests = false;

        cout << "Pending Friend Requests for " << user.GetName() << ":" << endl;

        while (!pendingRequests.isempty()) {
            FriendRequest currentRequest = pendingRequests.Dequeue();

            if (currentRequest.getReceiver().GetName() == user.GetName() &&
                currentRequest.getStatus() == "pending") {
                currentRequest.displayRequest();
                hasRequests = true;
            }

            tempQueue.Enqueue(currentRequest);
        }

        pendingRequests = tempQueue;

        if (!hasRequests) {
            cout << "No pending friend requests." << endl;
        }
    }

    bool areFriends(const Users& user1, Users& user2) {
        return userNetwork.hasEdge(user1, user2);
    }

    void displayFriends(Users& user) {
        cout << "Friends of " << user.GetName() << ":" << endl;
        userNetwork.displayFriendsOf(user);
    }

    void displayAllUsers() {
        userNetwork.displayAllUsers();
    }

    void searchUserInNetwork(const string& username) {
        userNetwork.searchUser(username);
    }
};
