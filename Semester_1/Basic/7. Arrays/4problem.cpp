#include <iostream>


bool dif_digits(int n)
{
	bool flag = true;
	if ((n / 10) == 0) {
		flag = false;
	}
	else {
		while (n != 0) {
			short digit = n % 10;
			n /= 10;
			int n_check = n;
			while (n_check != 0) {
				if (digit == n_check % 10) {
					flag = false;
					break;
				}
				n_check /= 10;
			}
			if (flag == false)
				break;
		}
	}
	return flag;
}


bool mltpl_14(int n) {
	bool is_2 = false;
	bool is_7 = false;
	if ((n / 10) == 0)
		return false;
	else {
		while (n != 0) {
			if ((n % 10) == 2) {
				is_2 = true;
			}
			if ((n % 10) == 7) {
				is_7 = true;
			}
			if (is_2 && is_7)
				break;
			n /= 10;
		}
	}
	return (is_2 && is_7);
}


int main() {
	short array_length;
	unsigned int array[10000] = {};
	std::cout << "Please input massive length:" << std::endl;
	std::cin >> array_length;
	std::cout << "Please input massive elements:" << std::endl;
	//a - first variable-counter
	//b - second variable-counter
	for (short i = 0; i < array_length; i++) {
		std::cin >> array[i];
	}
	for (short a = 0; a < array_length; a++) {
		if (dif_digits(array[a])) {
			for (short b = a; b < array_length; b++) {
				array[b] = array[b + 1];
			}
			array_length--;
			a--;
		}
	}
	for (short a = 0; a < array_length; a++) {
		if (mltpl_14(array[a])) {
			for (short b = array_length; b > a + 1; b--) {
				array[b] = array[b - 1];
			}
			array[a + 1] = array[a];
			array_length++;
			a++;
		}
	}
	for (short i = 0; i < array_length; i++) {
		std::cout << array[i] << " ";
	}
	return 0;
}