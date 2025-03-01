#pragma once
#include <iostream>
using namespace std;
class Post
{
	string post;
	string Author;
	string CurrentTime;
public:
	Post(string str);
	Post(){}
	void setCurrentTime(const string&Time);
	void SetName(const string& Name);
	string GetAuthor();
	string GetPost();
	string Getcurrenttime();
};
