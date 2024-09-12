
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <clocale>

std::string is_bukv(std::string s) //убирает знаки препинание + в нижний регистр
{
	std::string result;
	for (int i = 0; i < s.length(); i++)
		if (((s[i] >= 'а') and (s[i] <= 'я')) or ((s[i] >= 'А') and (s[i] <= 'Я')))
			result += tolower(s[i]);
	return result;
}

int glas_count(std::string comp_wrd) //подсчёт гласных в слове
{
	comp_wrd = is_bukv(comp_wrd);
	int counter = 0;
	char glas[] = "уеыаоэяию";
	for (int i = 0; i < comp_wrd.length(); i++)
		for (int j = 0; j < strlen(glas); j++)
			if (comp_wrd[i] == glas[j])
				counter++;

	return counter;
}

std::string dubl_delete(std::string s, std::string soglas) // дублировать согласные , убрать гласные , ь и ъ не трогать(наверное)
{
	std::string result;
	char mg = 'ь';
	char tv = 'ъ';
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < soglas.length(); j++)
		{
			if ((s[i] != soglas[j]) and ((s[i] == mg) or (s[i] == tv)))
			{
				result += s[i];
				break;
			}
			else if (s[i] == soglas[j])
			{
				result += s[i];
				result += s[i];
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
	std::string out_mas_dbdl[2001];
	std::string soglas = "йцкнгшщзхфвпрлджчсмтб";
	int text_size = 0;
	int newword = 0;
	int newword_dbdl = 0;

	while (!in.eof())
	{
		std::string text;
		in >> text;
		mas[text_size] = text;
		text_size++;
	}


	for (int j = 0; j < text_size; j++) //применяем функцию dubl_delete и добавляем результат в новый массив 
	{
		std::string dodik;
		dodik = mas[j];
		if (glas_count(dodik) < 3)
		{
			out_mas_dbdl[newword_dbdl] = dubl_delete(dodik, soglas);
			newword_dbdl++;
		}
		else
		{
			out_mas[newword] = dodik;
			newword++;
		}

	}



	std::string temp;

	for (int i = 0; i < newword - 1; i++) //обратная сортировка пузырьком по алфавиту
	{
		for (int j = i + 1; j < newword; j++)
		{
			if (out_mas[j] >= out_mas[i])
			{
				temp = out_mas[j];
				out_mas[j] = out_mas[i];
				out_mas[i] = temp;
			}

		}

	}

	for (int j = 0; j < newword; j++) //вывод 1
	{
		std::cout << is_bukv(out_mas[j]) << std::endl;
		out << out_mas[j] << std::endl;
	}

	for (int j = 0; j < newword_dbdl; j++) //вывод 2
	{
		if (out_mas_dbdl[j].length() > 0)
		std::cout << out_mas_dbdl[j] << std::endl;
		out << out_mas_dbdl[j] << std::endl;
	}

}
