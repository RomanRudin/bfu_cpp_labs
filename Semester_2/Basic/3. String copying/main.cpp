#include <iostream>

class zxString
{
	char* _str;

public:
	zxString(const char *str) // constr
	{
		std::cout << "CONSTR" << std::endl;
		int len = strlen(str);
		_str = new char[len+1];

		for (int i = 0; i < len; i++)
		{
			_str[i] = str[i];
		}

		_str[len] = '\0';
	}

	zxString(const zxString& other) : zxString(other._str)//copy constr
	{
		
	}

	zxString& operator=(const zxString& other)
	{
		delete[] _str;

		int len = strlen(other._str);
		_str = new char[len + 1];

		for (int i = 0; i < len; i++)
		{
			_str[i] = other._str[i];
		}

		_str[len] = '\0';

		return *this;
	}


	~zxString() //destr
	{
		std::cout << "DESTR_BEG" << std::endl;
		delete[] _str;
		std::cout << "CONSTR_END" << std::endl;
	}

	void Print()
	{
		std::cout << _str << std::endl;
	}

};


int main()
{
	zxString str("chin chopa chin chopa");
	zxString str_o("skuf");

	str.Print();
	str_o.Print();

	str_o = str;

	str_o.Print();
	
	return 123;
}


