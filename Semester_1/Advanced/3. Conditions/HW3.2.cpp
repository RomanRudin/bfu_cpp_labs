#include <iostream>

void main() {

	setlocale(LC_ALL, "Rus");

	// 1 - яблоко
	// 2 - груша
	// 3 - банан
	// 4 - мандарин
	// 5 - арбуз

	unsigned int a;

	std::cout << "Введите номер товара:" << std::endl;
	std::cin >> a;

	switch (a) {
	case 1:
		std::cout << "Яблоко";
		break;
	case 2:
		std::cout << "Груша";
		break;
	case 3:
		std::cout << "Банан";
		break;
	case 4:
		std::cout << "Мандарин";
		break;
	case 5:
		std::cout << "Арбуз";
		break;
	default:
		std::cout << "Такого номера не существует";
		break;
	}

}