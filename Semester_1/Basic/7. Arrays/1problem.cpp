#include <iostream>


int main() {
	short j; //Value of variables that we input
	bool same_values = false; //Flag that says that we have 2 same values in massive
	std::cout << "Please input j" << std::endl;
	std::cin >> j;
	int array[10000] = {};
	std::cout << "Input elements of the massive" << std::endl;
	for (short i = 0; i < j; i++) {
		std::cin >> array[i];
	}
	std::cout << std::endl;
	for (short a = 0; a < j - 1; a++)
		for (short b = a + 1; b < j; b++) { //Searches same values
			if (array[a] == array[b]) {
				same_values = true;
				break;
			}
		}
	if (same_values) { //Sort cycle for massive
		for (short a = 0; a < j - 1; a++)
			for (short b = a + 1; b < j; b++){
				if ((array[b] % 10) > (array[a] % 10)) {
					std::swap(array[a], array[b]);
				}
		}
		for (short i = 0; i < j; i++) { //Prints massive after sort
			std::cout << array[i] << " ";
		}
	}
	else
		std::cout << "Same values weren'n found" << std::endl;
	return 0;
}