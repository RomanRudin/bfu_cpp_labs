#include <iostream>

void main() {
	
	int j, index;
	float a, sum = 1, min = 10000000;

	std::cout << "Enter number of eliments:" << std::endl;
	std::cin >> j;

	std::cout << "Enter numbers:" << std::endl;
	for (int i = 0; i < j; i++) {
		std::cin >> a;
		if ((a - int(a) != 0) && (a < 0)) {
			sum *= a;
			if (a < min) {
				min = a;
				index = i;
			}
			else {
				continue;
			}
		}
		else {
			continue;
		}
	}

	if (sum == 1) {
		std::cout << 0 << ' ' << min << ' ' << index;
	}
	else {
		std::cout << sum << ' ' << min << ' ' << index;
	}

}