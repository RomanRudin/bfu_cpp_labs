#include <iostream>


int main() {
	setlocale(LC_ALL, "Russian");
	char x;
	std::cout << "Ââåäèòå X:" << std::endl;
	std::cin >> x;
	if (x == 1)
	{
		std::cout << "Positive number" << std::endl;
	}
	else if (x == -1)
	{
		std::cout << "Negative number" << std::endl;
	}
	else
	{
		std::cout << "Error, X is over the range" << std::endl;
	}
	return 0;
}
