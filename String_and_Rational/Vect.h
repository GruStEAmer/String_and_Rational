#pragma once
#include<iostream>
class Vect
{
	int sz = 0;
	double* v;
	void gen();

public:
//(de/con)srtructors
	Vect(int sz = 0);
	Vect(const Vect& next_v);
	~Vect();

//fun
	int size();
	void resize(int nsz);
	double modul();
	void push_back(double d);
	bool pop_back();
//operators
	double& operator[](const int i);
	Vect& operator=(const Vect& next_v);
	Vect operator+(const Vect& next_v) const;
	void operator+=(const Vect& next_v);
	Vect operator++();
	const Vect operator++(int);
	Vect operator*(const double  d) const;
	double operator*(const Vect& v) const;
	bool operator==(const Vect& vec) const;
	bool operator!=(const Vect& vec) const;
//friend operators
	friend std::ostream& operator<<(std::ostream& os, const Vect& vec);
	friend std::istream& operator>>(std::istream& is, Vect& vec);
};

