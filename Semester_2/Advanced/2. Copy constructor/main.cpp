#include <iostream>
#include "Matrix.hpp"

int main()
{
	float** a = new float* [3];
	for (int i = 0; i < 3; i++)
		a[i] = new float[3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = (i + 1) * (j + 1);

	mx::Matrix C(3, 3, a);
	mx::Matrix A(3, 3);
	mx::Matrix B(2, 2);

	A.Print();
	B.Print();
	C.Print();

	B = A = C;

	std::cout << "After operation: " << std::endl;

	A.Print();
	B.Print();
	C.Print();
}
