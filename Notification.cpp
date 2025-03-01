#include "Notification.h"

Notification::Notification(string str) :Message(str)
{
	char buffer[26];
	time_t now = time(nullptr);

	if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
		string currentTime(buffer);

		setCurrentTime(currentTime);
		// cout << "Current time: " << currentTime <<  endl;
	}
	else {
		cout << "Failed to get current time\n";
	}
}

void Notification::setCurrentTime(const string& Time)
{
	Currentime = Time;
}


string Notification::Getmessage()
{
	return Message;
}

string Notification::Getcurrenttime()
{
	return Currentime;
}

ostream& operator<<(ostream& os, const Notification& obj) {
	os << obj.Message;
	return os;
}