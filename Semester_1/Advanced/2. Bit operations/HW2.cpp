#include <iostream>

void main()
{
	setlocale(LC_ALL, "Rus");
	
	unsigned short a;
	unsigned short b;

	std::cout << "������� �����:" << std::endl;
	std::cin >> a;
	std::cout << "������� ����� ����:" << std::endl;
	std::cin >> b;

	a &= ~(1 << b);
	std::cout << a;
}