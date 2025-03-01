#pragma once
#include <iostream>
using namespace std;

class Notification
{
	string Message;
	string Currentime;
public:

	Notification(string str);
	Notification(){}
	void setCurrentTime(const string& Time);
	string Getmessage();
	string Getcurrenttime();
	friend ostream& operator<<(ostream& os, const Notification& obj);
};

