#include <iostream>

void main() {

	setlocale(LC_ALL, "Rus");

	// 1 - ������
	// 2 - �����
	// 3 - �����
	// 4 - ��������
	// 5 - �����

	unsigned int a;

	std::cout << "������� ����� ������:" << std::endl;
	std::cin >> a;

	switch (a) {
	case 1:
		std::cout << "������";
		break;
	case 2:
		std::cout << "�����";
		break;
	case 3:
		std::cout << "�����";
		break;
	case 4:
		std::cout << "��������";
		break;
	case 5:
		std::cout << "�����";
		break;
	default:
		std::cout << "������ ������ �� ����������";
		break;
	}

}