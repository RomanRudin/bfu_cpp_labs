#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");
	char n;
	std::cout << "Ââåäèòå N:" << std::endl;
	std::cin >> n;
	switch (n)
	{
	case 1:
		std::cout << "Ïîíåäåëüíèê" << std::endl;
		break;
	case 2:
		std::cout << "Âòîðíèê" << std::endl;
		break;
	case 3:
		std::cout << "Ñðåäà" << std::endl;
		break;
	case 4:
		std::cout << "×åòâåðã" << std::endl;
		break;
	case 5:
		std::cout << "Ïÿòíèöà" << std::endl;
		break;
	case 6:
		std::cout << "Ñóááîòà" << std::endl;
		break;
	case 7:
		std::cout << "Âîñêðåñåíüå" << std::endl;
		break;
	default:
		std::cout << "Îøèáêà! Íåâåðíîå ÷èñëî." << std::endl;
		break;
	}
	return 0;
}
