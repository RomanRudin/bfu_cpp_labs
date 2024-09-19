#include <iostream>


int main() {
	short i;
	short j;
	std::cout << "Please input height and width of matrix" << std::endl;
	std::cin >> i >> j;
	int column_summ;
	int min_summ = 2000000000;
	short min_column_number;
	int matrix[100][100] = {};
	std::cout << "Please input elements of matrix line-by-line:" << std::endl;
	for (short a = 0; a < i; a++)
		for (short b = 0; b < j; b++) {
			std::cin >> matrix[a][b];
		}
	std::cout << std::endl;
	for (short b = 0; b < j; b++) { //a - strings, b - columns
		column_summ = 0;
		for (short a = 0; a < i; a++) {
			column_summ += matrix[a][b];
		}
		if (column_summ < min_summ) {
			min_summ = column_summ;
			min_column_number = b;
		}
	}
	for (short a = 0; a < i; a++) {
		matrix[a][min_column_number] += 3;
	}
	for (short a = 0; a < i; a++) {
		for (short b = 0; b < j; b++) {
			std::cout << matrix[a][b] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}