#include <iostream>
#include "Matrix.hpp"

int main()
{
	float** a = new float*[3];
	for (int i = 0; i < 3; i++)
		a[i] = new float[3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = (i + 1) * (j + 1);
	 
	fs::Matrix C(a, 3, 3);
	fs::Matrix A(3, 3);
	fs::Matrix B(2, 2);

	A.Print();
	B.Print();
	C.Print();

	B = A = C;
	
	A.Print();
	B.Print();
	C.Print();
}