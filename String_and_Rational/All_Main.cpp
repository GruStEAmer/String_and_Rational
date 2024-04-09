#include"StringMy.h"
#include"Rational.h"

int main() {
	/*
	StringMy s(4);
	s = "qwerty";
	std::cout << s;

	StringMy r(s);
	std::cout << r;

	
	StringMy a = "asfddf";
	std::cout << a  << "\n";

	r = "dasdasd";
	StringMy ans = s + r;
	std::cout << ans;
	std::cout << ans.size() << "\n";
	
	ans += s;
	std::cout << ans;
	std::cout << ans.size();
	*/
	Rational a(112);
	Rational b;
	std::cin >> a;
	std::cin >> b;
	std::cout << a ;
	std::cout << b ;
	std::cout << a + b;
	std::cout << a - b;
	std::cout << a * b;
	std::cout << a / b;
}