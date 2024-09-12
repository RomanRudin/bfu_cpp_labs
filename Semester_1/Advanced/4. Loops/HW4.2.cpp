#include <iostream>

void main() {

	unsigned int N, min = 9;

	std::cout << "Enter number:" << std::endl;
	std::cin >> N;

	while (N > 0) {
		if (N % 10 < min) {
			min = N % 10;
		}
		N /= 10;
	}

	std::cout << min;

}