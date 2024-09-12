#include <iostream>

void main() {
	const int n = 100, m = 100;
	int matrix[n][m], num = 0, max = INT_MIN, N;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = num;
			num += 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += abs(matrix[i][j]);
		}
		if (sum > max) {
			max = sum;
			N = i;
		}
	}

	for (int j = 0; j < m; j++) {
		matrix[N][j] = 9999;
	}

}