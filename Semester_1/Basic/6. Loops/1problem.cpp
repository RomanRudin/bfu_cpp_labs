#include <iostream>


int main() {
	const short length = 10;
	float array[length] {991.2, 10.1, 1000.0, 1.0, 17.2, 10.5};
	float max_array = -10000.0;
	short elem = 0;
	float sum = 0.0;
	for (int i=0; i < length; i++) {
		if (array[i] > -7.0 && array[i] < 19.0) {
			sum += array[i];
			if (array[i] > max_array) {
				max_array = array[i];
				elem = i;
			}
		}
	}
	std::cout << "Sum:" << sum << std::endl;
	std::cout << "Max in [-7, 19]: array[" << elem << "] = " << max_array << std::endl;
	return 0;
}