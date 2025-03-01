#include "Post.h"
#include <iostream>
#include <string>
using namespace std;

Post::Post(string str) :post(str)
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

void Post::SetName(const string& Name)
{
	Author = Name;
}
void Post::setCurrentTime(const string& Time)
{
	CurrentTime = Time;
}

string Post::GetAuthor()
{
	return Author;
}

string Post::GetPost()
{
	return post;
}

string Post::Getcurrenttime()
{
	return CurrentTime;
}
