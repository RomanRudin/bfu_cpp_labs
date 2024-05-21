#include <iostream>
#include <fstream>
#include <string>

int main() {
	const int aLength = 20000; // 2 * 10000 because there can be a situation when all 10000 elemnts will be duplicated
	const int N = 10;

	int a[aLength]{ 1, 594, 11, 10, 20, 954, 101, 459, 40, 1231243 };
	int i = 0;
	int extraSteps = 0;

	while (i < N) {
		int product = 1;
		int first = 0;
		int number = a[i];

		while (number > 9) {
			product *= number % 10;
			number /= 10;
		}

		product *= number;
		first = number;

		if (product == 180) {
			for (int j = i; j < N + extraSteps; j++) {
				a[j] = a[j + 1];
			}
			i--;
			extraSteps--;
		}

		if (a[i] % 10 == first) {
			for (int j = N + extraSteps; j > i; j--) {
				a[j] = a[j - 1];
			}
			i++;
			extraSteps++;
		}

		i++;
	}

	std::cout << "Answer:" << std::endl;
	for (int i = 0; i < N + extraSteps; i++) {
		std::cout << a[i] << std::endl;
	}

	return 1;
}