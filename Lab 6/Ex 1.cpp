#include <iostream>
#include <fstream>
#include <string>

int main()
{
	setlocale(LC_ALL, "Rus");
	const int N = 2000;

	std::string words[N];
	int wordsCounter = 1;
	char letter = 'À';
	std::ifstream in("input1.txt");
	std::ofstream out("output1.txt");

	if ((!in.is_open()) || (!out.is_open())) {
		std::cerr << "Open file error" << std::endl;
		return -1;
	}

	while (!in.eof()) {
		std::string currentWord;
		in >> currentWord;
		if (currentWord[0] == letter) {
			for (int i = 0; i < wordsCounter; i++) {
				if (currentWord == words[i]) {
					break;
				}
				if ((currentWord.length() > words[i].length()) || (words[i] == "")) {
					wordsCounter++;
					for (int j = wordsCounter; j > i; j--) {
						words[j] = words[j - 1];
					}
					words[i] = currentWord;
					break;
				}
			}
		}
	}


	if (!out.eof()) {
		for (int i = 0; i < wordsCounter - 1; i++) {
			out << words[i] << std::endl;
		}
	}

	return 1;
}
