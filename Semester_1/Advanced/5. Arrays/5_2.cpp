#include <iostream>

int SumOfDigits(int num) {
	int sum = 0;

	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

bool compare(int num1, int num2) {

	int sum1 = SumOfDigits(num1);
	int sum2 = SumOfDigits(num2);

	if (sum1 < sum2) {
		return true;
	}
	else if (sum1 > sum2) {
		return false;
	}
	else {
		int numm1 = num1;
		int numm2 = num2;
		int digit1 = num1;
		int digit2 = num2;

		while (numm1 > 0) {
			digit1 = numm1;
			numm1 /= 10;
		}
		while (numm2 > 0) {
			digit2 = numm2;
			numm1 /= 10;
		}

		if (digit1 < digit2) {
			return true;
		}
		else if (digit1 > digit2) {
			return false;
		}
		else {
			return num1 <= num2;
		}
	}

}

void main() {
	
	int N;
	std::cout << "Enter amount of numbers: " << std::endl;
	std::cin >> N;
	
	int* arr = new int[N];
	std::cout << "Enter numbers: " << std::endl;
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (compare(arr[i], arr[j]) == false) {
				std::swap(arr[i],arr[j]);
			}
		}
	}
	
	for (int i = 0; i < N;i++) {
		std::cout << arr[i] << " ";
	}
	
	delete[] arr;

}