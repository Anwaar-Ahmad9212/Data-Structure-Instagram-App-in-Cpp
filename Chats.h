#pragma once
#include <iostream>
#include <string>
//#include"Users.h"
#include "Queue.h"
class Node_msg {
public:
    std::string data;
    Node_msg* next;

    Node_msg(const std::string& value) : data(value), next(nullptr) {}
    Node_msg() : next(nullptr) {}
};

class stack_msg {
private:
    Node_msg* top;

public:
    stack_msg() : top(nullptr) {}

    ~stack_msg() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const std::string& value) {
        Node_msg* newNode = new Node_msg(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) return;
        Node_msg* temp = top;
        top = top->next;
        delete temp;
    }

    std::string peek() const 
    {
      /*if (isEmpty())
        {
            return {};
        }
        */


        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

//class Users;

class Chats
{
    stack_msg* message_of_user;
    Queue<string> Names_user;
    int index = 0;

public:

    Chats() {
        message_of_user= new stack_msg[10];
    }
    void send_message(string sender, string msg)
    {
        char buffer[26];
        time_t now = time(nullptr);
        string currentTime;

        if (ctime_s(buffer, sizeof(buffer), &now) == 0)
        {
            currentTime = string(buffer);

         }
        else {
            cout << "Failed to get current time\n";
        }

        string timeandmsg = msg + " " + currentTime;
      
        int temp = Names_user.find(sender);
        if (temp == -1)
        {
            Names_user.Enqueue(sender);
            message_of_user[index].push(timeandmsg);
            index++;
        }
        else
        {
            message_of_user[temp].push(timeandmsg);
        }
    }


    void show_chats()
    {
        Names_user.Traversal();               // Display all nodes in the queue
    }


    void open_chat_of_user(string user)
    {
        int temp = Names_user.find(user);

        if (temp != -1)
        {
            while (!message_of_user[temp].isEmpty())
            {
              cout << message_of_user[temp].peek() << std::endl; // Display the top message
              message_of_user[temp].pop(); // Remove the top message
            }
        }
    }

};

