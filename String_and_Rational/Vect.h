#pragma once
#include<iostream>
class Vect
{
	int sz = 0;
	double* v;
	void gen();

public:
//(de/con)srtructors
	Vect(int sz = 1);
	Vect(const Vect& next_v);
	~Vect();

//fun
	int size();

//operators
	double& operator[](const int i);
	Vect& operator=(const Vect& next_v);
	Vect operator+(const Vect& next_v) const;
	void operator+=(const Vect& next_v);
//friend operators
	friend std::ostream& operator<<(std::ostream& os, const Vect& vec);
	friend std::istream& operator>>(std::istream& is, Vect& vec);
};

