#include <iostream>
#include "Matrix.hpp"
int main()
{
    mtx::Matrix <int, 2, 2> a;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a(i, j) = i + j;
    std::cout << "Matrix a:" << "\n" << a << std::endl;

    int a_det = a.det();
    std::cout << "Determinant of matrix a:" << "\n" << a_det << std::endl;

    mtx::Matrix <int, 2, 2> b = a;
    std::cout << "Matrix b:" << "\n" << b << std::endl;

    a++;
    std::cout << "Matrix a++:" << "\n" << a << std::endl;

    b *= 2;
    std::cout << "Matrix b *= 2:" << "\n" << b << std::endl;

    mtx::Matrix <int, 2, 2> c = a + b;
    std::cout << "Matrix c = a + b:" << "\n" << c << std::endl;

    mtx::Matrix <int, 2, 2> d;
    std::cout << "Please, input matrix d: " << std::endl;
    std::cin >> d;

    c *= d;
    std::cout << "Matrix c *= d: " << "\n" << c << std::endl;
}