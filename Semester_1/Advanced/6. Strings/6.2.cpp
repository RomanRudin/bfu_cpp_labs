#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

bool hasLiDuplicateIleNiHas(const std::string& word) {
	std::string lowerWord = word;
	std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

	const std::string glas = "аеёиоуыэюя";

	for (char bukwa:glas) {
		size_t count = std::count_if(lowerWord.begin(), lowerWord.end(), [=](char c) {return c == bukwa; });
		if (count >= 2) {
			return true;
		}
		else{
			return false;
		}
	}

}

void main() {

	setlocale(LC_ALL, "Rus");

	std::string input = "Дана строк содержащая русский текст. Строки в с это ужас";//Исходная строка сюда ручками вводить

	std::istringstream iss(input);
	std::string word;
	std::vector<std::string> wordsKotoriHaveDuplicate;
	std::vector<std::string> invertedWords;

	while (iss >> word) {
		if (hasLiDuplicateIleNiHas(word)) {
			wordsKotoriHaveDuplicate.push_back(word);
		}
		else {
			std::reverse(word.begin(), word.end());
			invertedWords.push_back(word);
		}
	}

	std::sort(wordsKotoriHaveDuplicate.begin(), wordsKotoriHaveDuplicate.end());
	std::sort(invertedWords.begin(), invertedWords.end());

	for (const auto& word : wordsKotoriHaveDuplicate) {
		std::cout << word << " ";
	}

	std::cout << '|';
	
	for (const auto& word : invertedWords){
		std::cout<<word<<" ";
		}

}