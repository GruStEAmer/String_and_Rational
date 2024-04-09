#pragma once
#include<iostream>
class Rational
{	
	int
		m = 0,
		n = 1;
	void reducer();
public:
	Rational();
	Rational(int m,int n = 1);

	void operator=(Rational r);
	Rational operator+(const Rational r) const;
	Rational operator-(const Rational r) const;
	Rational operator*(const Rational r) const;
	Rational operator/(const Rational r) const;

	friend std::ostream& operator<<(std::ostream& os, Rational r);
	friend std::istream& operator>>(std::istream& is, Rational& r);
};

