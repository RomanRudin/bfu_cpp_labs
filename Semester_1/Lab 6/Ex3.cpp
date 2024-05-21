#include <cctype>
#include <fstream>


int Length(char* word) {
    int leng = 0;
    while (word[leng] != '\0') leng++;
    return leng;
}


char ToLower(char letter) {
    if ((letter >= 'А') && (letter <= 'Я')) {
        letter += 32;
    }
    else if (letter == 'Ё') letter = 'ё';
    return letter;
}


void WordToUpper(char* word) {
    for (int i = 0; i < Length(word); i++) {
        if ((word[i] >= 'а') && (word[i] <= 'я')) word[i] -= 32;
        else if (word[i] == 'ё') word[i] = 'Ё';
    }
}

int main() {
    const int N = 100; 
    std::ifstream in("input3.txt");
    std::ofstream out("output3.txt");
    while (!in.eof()) {
        char word[N] = {};
        char found_letters[N] = {};
        int count = 0;
        in >> word;
        for (int i = 0; i < Length(word); i++) {
            bool new_letter = true;
            if (ispunct(word[i])) new_letter = false;
            else {
                for (int j = 0; j < i; j++) {
                    if ((ToLower(word[i]) == ToLower(word[j]))) {
                        new_letter = false;
                        break;
                    }
                }
            }
            if (new_letter) {
                found_letters[count] = ToLower(word[i]);
                count++;
            }
        }
        found_letters[count] = '\0';
        if (count > 7) {
            WordToUpper(word);
            out << word << '(' << found_letters << ')';
        }
        else {
            out << word;
        }
        out << ' ';
    }
    return 0;
}