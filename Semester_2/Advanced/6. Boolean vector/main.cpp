#include <iostream>>
#include "BoolVector.cpp"

int main() {
    bv::vector<bool> boolv;
    std::cout << "H" << std::endl;
    boolv.push_back(true);

    std::cout << boolv[0] << "\t boolv[0]" << std::endl;
    boolv.push_back(false);
    std::cout << boolv[1] << "\t boolv[1]" << std::endl << std::endl;
    boolv.insert(0, true);
    for (size_t i = 0; i < boolv.size(); ++i)
        std::cout << boolv[i] << "\t boolv[" << i << "]" << std::endl;
    boolv.erase(2);
    std::cout << boolv.size() << "\t boolv.size()" << std::endl;

    for (int i = 0; i < 8; i++) {
        boolv.push_back(true);
    }
    std::cout << std::endl;

    for (size_t i = 0; i < boolv.size(); ++i) 
        std::cout << boolv[i] << "\t boolv[" << i << "]" << std::endl;

    return 0;
}