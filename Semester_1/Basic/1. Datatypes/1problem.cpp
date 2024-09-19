#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	std::cout << "	bool					" << sizeof(bool) << " " << "0 " << "1 " << "\n";
	std::cout << "	char           " << sizeof(char) << " " << SCHAR_MIN << " " << SCHAR_MAX << "\n";
	std::cout << "	unsigned char			" << sizeof(char) << " " << "0 " << UCHAR_MAX << "\n";
	std::cout << "	short					" << sizeof(short) << "	" << SHRT_MIN << " " << SHRT_MAX << "\n";
	std::cout << "	unsigned short		" << sizeof(short) << " " << "0 " << USHRT_MAX << "\n";
	std::cout << "	int					" << sizeof(int) << " " << INT_MIN << " " << INT_MAX << "\n";
	std::cout << "	unsigned int			" << sizeof(int) << " " << "0 " << UINT_MAX << "\n";
	std::cout << "	long					" << sizeof(long) << " " << LONG_MIN << " " << LONG_MAX << "\n";
	std::cout << "	unsigned long			" << sizeof(long) << " " << "0 " << ULONG_MAX << "\n";
	std::cout << "	long long				" << sizeof(long long) << " " << LLONG_MIN << " " << LLONG_MAX << "\n";
	std::cout << "	unsigned long long	" << sizeof(long long) << " " << "0 " << ULLONG_MAX << "\n";
	std::cout << "	float					" << sizeof(float) << " " << FLT_MIN << " " << FLT_MAX << "\n";
	std::cout << "	double				" << sizeof(double) << " " << DBL_MIN << " " << DBL_MAX << "\n";
	return 0;
}
