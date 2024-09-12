
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <clocale>

std::string bukv_count(std::string word, char letter)//подсчет в слове word кол-ва letter
{
	std::string counter;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == letter) {
			counter += letter;
		}
	}

	return counter;
}

int letter_count(std::string word, std::string letter)//подсчет в слове word кол-ва letter
{
	int counter = 0;

	for (int i = 0; i < word.length(); i++)
	{

		if (word[i] == letter[0])
			{
				counter++;
			}
		
	}
	return counter;
}

std::string uniq(std::string word)//оставляет только уникальные буквы в слове
{
	std::string result = "";
	result += word[0];
	for (int i = 1; i < word.length(); i++)
	{
		for (int j = 0; j < result.length(); j++)
		{
			if (word[i] == result[j])
			{
				break;
			}
			else if (j == result.length()-1)
			{
				result += word[i];
			}
		}
		
	}
	return result;
}

std::string is_bukv(std::string s) //не буква - удалить  
{
	std::string result;
	for (int i = 0; i < s.length(); i++)
		if (((s[i] >= 'а') and (s[i] <= 'я')) or ((s[i] >= 'А') and (s[i] <= 'Я')))
			result += tolower(s[i]);
	return result;
}

std::string BIG(std::string s) //делает заглавными
{	
	std::string result;
	for (int i = 0; i < s.length(); i++)
		if (((s[i] >= 'а') and (s[i] <= 'я')))
		{
			result += toupper(s[i]);
		}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int text_size = 0;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt", std::ios::app);
	std::string text[2001];
	std::string digits[32];
	std::string digits_one[32];
	std::string alphabet = "абвгдеёжзийклмнопрстуфхцчщъыьэюя";
	std::string text2[2001];
	const int alphlen = alphabet.length();

	while (!in.eof())
	{
		std::string textt;
		in >> textt;
		text[text_size] = textt;
		text_size++;
	}

	for (int i = 0; i < alphlen; i++)
	{
		for (int j = 0; j < text_size; j++)
		{
			digits[i] += bukv_count(text[j], alphabet[i]);
		}
	}

	std::string temp;

	for (int i = 0; i < alphlen-1; i++) //сортировка
	{
		for (int j = i + 1; j < alphlen; j++)
		{
			if (digits[j].length() > digits[i].length())
			{
				temp = digits[j];
				digits[j] = digits[i];
				digits[i] = temp;
			}
		}
	}

	for (int i = 0; i < alphlen; i++)
	{
		digits_one[i] = digits[i][0];
	}



	for (int i = 0; i < text_size; i++)
	{
		for (int j = 0; j < alphlen; j++)
		{
			if ((letter_count(uniq(is_bukv(text[i])), digits_one[j]) == 1))
			{
				text2[i] = BIG(text[i]) + "(" + digits_one[j] + ")";
				break;
			}

			else
			{
				text2[i] = text[i];
				break;
			}
		}
	}


	for (int j = 0; j < text_size; j++) //вывод
	{
		std::cout << text2[j] << " ";
		//out << text2[j] << std::endl;
	}

	
}

