#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	int c;
	std::cout << "Ââåäèòå A, B, C:" << std::endl;
	std::cin >> a >> b >> c;
	if ((a % c == 0) && (b % c == 0))
	{
		std::cout << (a + b) / c << std::endl;
	}
	else if ((a % c == 0) && (b % c != 0))
	{
		std::cout << a / c + b << std::endl;
	}
	else
	{
		std::cout << a - b - c << std::endl;
	}
	return 0;
}
