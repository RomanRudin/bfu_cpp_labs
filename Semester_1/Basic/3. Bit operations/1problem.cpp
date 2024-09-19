#include <iostream>


int main() {
	unsigned int x;
	short i;
	std::cin >> x >> i;
	std::cout << ~(~x | (1 << i));
	// 0110 1001
	// 1011= ~0100
}
