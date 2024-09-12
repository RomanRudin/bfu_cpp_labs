#include <iostream>

int SumOfDigital(int a) {

	int sum = 0;

	while (a > 0) {
		sum += a % 10;
		a /= 10;
	}

	return sum;

}

void main() {

	const unsigned int n = 1000;
	unsigned int c = 0;
	int arr[n];

	for (int i = 0; i != n; i++) {
		arr[i] = i;
		if (SumOfDigital(i) == 19) {
			c += 1;
		}
	}

	if (c == 0) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] < arr[j]) {
					std::swap(arr[i], arr[j]);
				}
			}
		}
	}

}