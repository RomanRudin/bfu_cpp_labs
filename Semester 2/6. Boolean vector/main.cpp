#include <iostream>>
#include "BoolVector.hpp"

int main() {
    bv::BoolVector boolv;
    boolv.push_back(true);
    std::cout << boolv[0] << std::endl;
    boolv.push_back(false);
    std::cout << boolv[1] << std::endl;
    boolv.insert(1, true);
    boolv.erase(2);
    std::cout << boolv.length() << std::endl;

    for (size_t i = 0; i < boolv.length(); ++i) {
        std::cout << boolv[i] << ' ';
    }

    return 0;
}