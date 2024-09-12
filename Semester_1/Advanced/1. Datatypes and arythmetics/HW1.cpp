#include <iostream>

void main()
{
	setlocale(LC_ALL, "Rus");
	
	bool a;
	std::cout << "Введите число:" << std::endl;
	std::cin >> a;
	std::cout << "Объем равен:" << a*a*a;
}