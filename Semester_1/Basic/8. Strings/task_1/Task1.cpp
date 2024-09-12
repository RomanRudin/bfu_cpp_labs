
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <clocale>

bool used_let(std::string usr_wrd, std::string comp_wrd) //функция сравнивающая вводимое слово и слово из текста.
{
	int extra = 0; //переменная лишних букв так 
	int counter = 0;

	for (int i = 0; i < comp_wrd.length(); i++) 
	{
		for (int x = 0; x < usr_wrd.length(); x++) 
		{
			if (comp_wrd[i] == usr_wrd[x])
			{
				counter = 0;
				break;
			}
			else
			{
				counter++;
			}
			if(counter == usr_wrd.length())
			{
				extra++;
				counter = 0;
			}
		}
	}
	if (extra > 1)
		return 0;
	else
		return 1;
}

std::string is_bukv(std::string s) //не буква - удалить  
{
	std::string result;
	for (int i = 0; i < s.length(); i++)
		if (((s[i] >= 'а') and (s[i] <= 'я')) or ((s[i] >= 'А') and (s[i] <= 'Я')))
			result += tolower(s[i]);
	return result;
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
			else if (j == result.length() - 1)
			{
				result += word[i];
			}
		}

	}
	return result;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream in("input.txt");
	std::ofstream out("output.txt", std::ios::app);
	std::string mas[2001];
	std::string out_mas[2001];
	std::string out_mas2[2001];
	std::string str; //вводимое слово
	int text_size = 0;

	std::cin >> str;
	str = is_bukv(str);
	//std::cout << str;

	while (!in.eof()) 
	{
		std::string text;
		in >> text;
		mas[text_size] = text;
		text_size++;
	}
	

	std::string temp;

	int newword = 0;
	int newword2 = 0;
	for (int j = 0; j < text_size; j++) //добавляет в новый массив подходящие слова, который потом отсортируется 
	{
		std::string dodik;
		dodik = is_bukv(mas[j]);
		if (used_let(str, uniq(dodik)) == 1)
			out_mas[newword] = mas[j];
			newword++;
	}

	for (int i = 0; i < newword-1; i++) //сортировка
	{
		for (int j = i + 1; j < newword; j++)
		{
			if (out_mas[j].length() >= out_mas[i].length()) 
				temp = out_mas[j];
				out_mas[i] = out_mas[j];
				out_mas[i] = temp;
		}
	}

	int h = 0;
	for (int j = 0; j < newword; j++) //добавляет уникальные слова в новый массив 
	{
		int reps = 0;
		for (int p=j; p < newword; p++)
		{
			std::string dodik;
			if (out_mas[j] == out_mas[p])
				reps++;		
		}
		if ((reps == 1) and (out_mas[j] != "—"))
		{
			out_mas2[h] = out_mas[j];
			h++;
		}
	}

	for (int j = 0; j < h; j++) //вывод
	{
		std::cout << out_mas2[j] << std::endl;
		//out << out_mas2[j] << std::endl;
	}
}
