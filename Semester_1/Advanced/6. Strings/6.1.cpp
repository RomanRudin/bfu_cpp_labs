#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

// Ф-ия возвращяющая словарь с ключом - слово, и значением - кол-во согласных
std::map<std::string, int> countSogl(std::string& word) {
    std::map<std::string, int> result;
    std::string sogl = "бвгджзйклмнпрстфхцчшщ";
    int count = 0;

    for (char c : word) {
        if (sogl.find(c) != std::string::npos) {
            count++;
        }
    }

    result[word] = count;
    return result;

}

// Ф-ия сравнивающая кол-во согласных
bool compareSlov(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
    return a.second > b.second;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::map<std::string, int> words;
    int N;

    std::cout << "Enter N:" << std::endl;
    std::cin >> N;

    if (!input.is_open()) {
        std::cout << "Error";
        return 1;
    }

    std::string word;
    int i = 0;

    while (input >> word && i <= N) {
        words.merge(countSogl(word));
        i++;
    }

    input.close();

    std::vector<std::pair<std::string, int>> sortedWords(words.begin(), words.end());
    std::sort(sortedWords.begin(), sortedWords.end(), compareSlov);

    for (const auto& word:sortedWords) {
        output << word.first << " : " << word.second << std::endl;
    }
    
}