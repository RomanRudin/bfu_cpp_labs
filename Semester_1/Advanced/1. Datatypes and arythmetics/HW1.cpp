#include <iostream>

void main()
{
	setlocale(LC_ALL, "Rus");
	
	bool a;
	std::cout << "������� �����:" << std::endl;
	std::cin >> a;
	std::cout << "����� �����:" << a*a*a;
}