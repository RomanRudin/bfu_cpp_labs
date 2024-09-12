#include <iostream>

void main() {

	unsigned int a, b, c;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	if (a < b && b < c) {
		std::cout << (c - b - a) << std::endl;
	}
	else if (a % c == 0) {
		std::cout << ((a / c) + b) << std::endl;
	}
	else {
		std::cout << (a + b + c);
	}

}