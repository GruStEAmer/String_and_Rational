#pragma once
#include<iostream>
class Rational
{	
	int
		m = 0,
		n = 0;
	void reducer();
public:
	Rational();
	Rational(int m,int n = 1);
	Rational(const Rational& r);

	void operator=(Rational r);
	Rational operator+(const Rational r) const;
	Rational operator-(const Rational r) const;
	Rational operator*(const Rational r) const;
	Rational operator/(const Rational r) const;
	void operator+=(const Rational r);
	friend std::ostream& operator<<(std::ostream& os, Rational r);
	friend std::istream& operator>>(std::istream& is, Rational& r);
};

