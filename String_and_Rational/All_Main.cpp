#include"Vect.h"
#include<iostream>

int main() {
	Vect v(4);
	std::cin >> v;
	Vect v2(4);
	std::cin >> v2;
	double ans;
	ans = v * v2;
	v.resize(13);
	std::cout << v;
}