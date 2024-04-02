#include"StringMy.h"
#include"Rational.h"

int main() {
	StringMy s(4);
	s = "qwerty";
	std::cout << s;

	StringMy r(s);
	std::cout << r;

	r = "dasdasd";
	StringMy a = "asfddf";
	std::cout << a;
	std::cout << a.size();

}