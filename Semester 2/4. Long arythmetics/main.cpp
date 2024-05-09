#include "BigInt.hpp"

int main() {
    bint::BigInt a("-105890765789000065789");
    bint::BigInt b("1234564356743");
    bint::BigInt c = a + b;
    bint::BigInt d = a * b;


    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    std::cout << "a * b: " << d << std::endl;
    return 0;
}