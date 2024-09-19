#include <iostream>


int main() {
	int N;
	int sum = 0;
	std::cout << "Input N:" << std::endl;
	std::cin >> N;
		while (N > 0) {
		sum += N % 10;
		N /= 10;
	}
		std::cout << "Digits sum = " << sum << std::endl;
	return 0;
}