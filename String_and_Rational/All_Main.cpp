#include"Vect.h"
#include<iostream>
#include"Rational.h"

int main() {
	Vect<Rational> v(2);
	std::cin >> v;

	std::cout << v;
}