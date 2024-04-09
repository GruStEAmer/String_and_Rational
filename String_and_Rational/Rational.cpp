#include "Rational.h"
Rational::Rational() {
	m = 0;
	n = 1;
}
Rational::Rational(int m, int n) :m(m), n(n) {}

void Rational::reducer() {
	int x = m, y = n;
	if (m == 0 && n == 0) return;

	while (x > 0 && y > 0) {
		if (x > y) x %= y;
		else y %= x;
	}
	m /= x + y;
	n /= x + y;
}

void Rational::operator=(Rational r) {
	m = r.m;
	n = r.m;
}
Rational Rational::operator+(const Rational r)const {
	Rational res;
	res.m = m * r.n + r.m * n;
	res.n = n * r.n;
	res.reducer();
	return res;
}
Rational Rational::operator-(const Rational r)const {
	Rational res;
	res.m = (m * r.n) - (r.m * n);
	res.n = n * r.n;
	return res;
}
Rational Rational::operator*(const Rational r)const {
	Rational res;
	res.m = m * r.m;
	res.n = n * r.n;
	res.reducer();
	return res;
}
Rational Rational::operator/(const Rational r)const {
	Rational res;
	res.m = m * r.n;
	res.n = n * r.m;
	res.reducer();
	return res;
}

std::ostream& operator<<(std::ostream& os, Rational r) {
	if (r.n != 1) {
		os << r.m << "/" << r.n << "\n";
	}
	else os << r.m << "\n";
	return os;
}
std::istream& operator>>(std::istream& is, Rational& r) {
	is >> r.m >> r.n;

	return is;
}