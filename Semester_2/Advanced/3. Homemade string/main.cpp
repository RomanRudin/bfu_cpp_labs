#include <iostream>
#include "String.hpp"
int main()
{
	str::String s("Hello world!");
	str::String a = s;
	s[11] = '?';
	a += s;
	str::String b = a + s;
	std::cout << a[11] << std::endl;
	str::String c(" It's me!");
	int seeking = c.find('I');
	if (c != s) {
		std::cout << seeking << "\t" << c.length() << std::endl << c << std::endl;
	}
	if (a < s) {
		std::cin >> a.at(0);
		std::cout << a << std::endl;
		std::cin >> a;
		std::cout << a << std::endl;
	}
	std::cout << a.c_str();
}