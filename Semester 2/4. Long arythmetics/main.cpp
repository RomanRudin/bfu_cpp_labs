#include "BigInt2.hpp"

int main() {
    bint::BigInt a("-10");
    bint::BigInt b("1");
    bint::BigInt c = a + b;
    bint::BigInt d = a * b;


    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    std::cout << "a * b: " << d << std::endl;
    return 0;
}
