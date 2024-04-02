#pragma once
#include<iostream>

class StringMy
{
	int _size_ = 1;
	char* string;

public:
	StringMy();
	StringMy(int size_);
	StringMy(const StringMy& s);
	StringMy(const char* c);
	~StringMy();

	int size();
	void create();

	const char operator[](int char_num);
	void operator=(const StringMy& s);
	void operator=(const char* c);
	friend std::ostream& operator<<(std::ostream& os,const StringMy& s);
	
};

