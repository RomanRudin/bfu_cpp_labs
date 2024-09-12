#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <locale>

std::string alph = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";

void main() {

	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	std::string word;
	std::map <char, int, std::greater<int>> bukwaKolvo;
	std::vector<char> mostAga;

	if (!input) {
		std::cout << "Îøèáêà îòêğûòèÿ ôàéëà input.txt" << std::endl;
		return ;
	}

	if (!output) {
		std::cout << "Îøèáêà îòêğûòèÿ ôàéëà output.txt" << std::endl;
		return ;
	}

	while (input >> word) {
		for (char c : word) {
			if (alph.find(c)!=std::string::npos) {
				c = std::tolower(c);
				bukwaKolvo[c]++;
			}
		}
	}

	int N = 0;
	
	for (const auto& pair : bukwaKolvo) {
		mostAga.push_back(pair.first);
		N++;
		if (N == 8) {
			break;
		}
	}
	
	input.clear();
	input.seekg(0);
	
	while (input >> word) {
		bool flag = true;
		int i = 0;
		std::string upperWord = word;
		for (char& c : upperWord) {
			if (alph.find(c) != std::string::npos) {
				c = std::toupper(c);
			}
		}
		
		for (char c : word) {
			if (std::find(mostAga.begin(),mostAga.end(), std::tolower(c)) == mostAga.end()) {
				flag = false;
				break;
			}
			else {
				i++;
			}
		}

		if (flag && i >= 5) {
			output << upperWord << '(';
			for (char c : mostAga){
				if (word.find(c) != std::string::npos) {
					output << std::toupper(c);
				}
			}
			output << ')';
		}

	}

	input.close();
	output.close();

}