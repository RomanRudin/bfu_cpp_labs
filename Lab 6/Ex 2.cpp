#include <iostream>
#include <sstream>
#include <string>

int main()
{
	setlocale(LC_ALL, "Rus");

	const int vowelsLen = 19;
	const int len = 2000;
	std::string input = "оно не хочет умирать";
	const char vowels[vowelsLen]{ 'А', 'а', 'Е', 'е', 'Ё', 'ё', 'И', 'и', 'О', 'о', 'У', 'у', 'ы',  'Э', 'э', 'Ю', 'ю',  'Я', 'я' };
	bool flag = true;
	std::string answer[len];
	float sorter[len];

	std::istringstream strstream(input);
	unsigned int wordsLen = 0;

	while (strstream) {
		std::string word;
		strstream >> word;
		answer[wordsLen] = word;

		for (int i = 0; i < (int)(word.length() / 2); i++) {
			if ((word[i] != word[word.length() - i - 1]) || (word.length() <= 2)) flag = false;
		}

		wordsLen++;

		if (flag) break;
	}


	if (flag) {
		int i = 0;
		strstream.seekg(0);
		while (strstream) {
			std::string word;
			strstream >> word;
			answer[i] = word;
			sorter[i] = 0;

			for (char letter : word) {
				for (char vowel : vowels) {
					if (letter == vowel) {
						sorter[i]++;
						break;
					}
				}
			}
			sorter[i] /= word.length();
			i++;
		}

		wordsLen = i - 1;

		for (int i = 0; i < wordsLen - 1; i++) {
			for (int j = i + 1; j < wordsLen; j++) {
				if (sorter[i] > sorter[j]) {
					double swap = sorter[i];
					sorter[i] = sorter[j];
					sorter[j] = swap;

					std::string newSwap = answer[i];
					answer[i] = answer[j];
					answer[j] = newSwap;
				}
			}
		}

		for (int i = 0; i < wordsLen; i++) {
			std::cout << answer[i] << "\t" << sorter[i] << std::endl;
		}
	}

	else {
		wordsLen--;
		for (int i = 0; i < wordsLen; i++) {

			std::string word = answer[i];
			std::string newWord = "";

			for (char letter : word) {
				bool isVowel = false;
				for (char vowel : vowels) {
					if (letter == vowel) {
						isVowel = true;
						break;
					}
				}
				if (!isVowel) {
					newWord += letter;
					newWord += letter;
				}
			}

			answer[i] = newWord;
		}

		for (int i = 0; i < wordsLen - 1; i++) {
			for (int j = i + 1; j < wordsLen; j++) {
				if (answer[i][0] > answer[j][0]) {
					std::string swap = answer[i];
					answer[i] = answer[j];
					answer[j] = swap;
				}
			}
		}

		for (int i = 0; i < wordsLen; i++) {
			std::cout << answer[i] << std::endl;
		}
	}

	return 1;
}
