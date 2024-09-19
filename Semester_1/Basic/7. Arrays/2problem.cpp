#include <iostream>


int first_d(int n) { //Procedure that returns the first digit of the number
	short digit;
	while (n != 0) {
		digit = n % 10;
		n /= 10;
	}
	return digit;
}


int dig_mult(int n) { //Procedure that returns the multiplication of digits of the number
	int mult = 1;
	while (n != 0) {
		mult *= n % 10;
		n /= 10;
	}
	return mult;
}


int main() {
	short j;
	std::cout << "Please input j:" << std::endl;
	std::cin >> j;
	int array[1000] = {};
	std::cout << "Please input elements of massive:" << std::endl;
	for (short i = 0; i < j; i++) {
		std::cin >> array[i];
	}
	for (short a = 0; a < j - 1; a++)
		for (short b = a + 1; b < j; b++) {
			if (first_d(array[b]) < first_d(array[a])) {
				std::swap(array[a], array[b]);
			}
			else if ((first_d(array[b]) == first_d(array[a])) && (dig_mult(array[b]) < (dig_mult(array[a])))) {
				std::swap(array[a], array[b]);
			}
			else if ((dig_mult(array[b]) == (dig_mult(array[a]))) && (array[b] < array[a])) {
				std::swap(array[a], array[b]);
			}
		}
	for (short i = 0; i < j; i++) {
		std::cout << array[i] << " ";
	}
	return 0;
}