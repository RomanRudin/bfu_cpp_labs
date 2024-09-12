#include <iostream>

void main() {

	unsigned int x;

	std::cout << "Enter number(-1 or 1):" << std::endl;
	std::cin >> x;

	if (x == -1) {
		std::cout << "Negative number";
	}
	else if (x == 1) {
		std::cout << "Possitive number";
	}
	else {
		std::cout << "Wrong value";
	}
}