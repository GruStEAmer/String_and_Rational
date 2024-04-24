#include"Vect.h"
#include<iostream>

int main() {
	Vect v(4);
	std::cin >> v;
	Vect v2(2);
	std::cin >> v2;
	Vect ans;
	ans = v + v2;
	std::cout << ans;
}