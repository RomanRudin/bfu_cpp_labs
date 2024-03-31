#include "String.hpp"
#include "BigInt.hpp"

int main() {
    long long data = 1234;
    bint::BigInt a(data);
    std::cout << "a \t" << a << std::endl;
    /*str::String string1("1324");
    bint::BigInt a(string1);
    std::cout << "a \t" << a << std::endl;
    bint::BigInt b(12345678909876543);
    std::cout << "b \t" << b << std::endl;
    *///bint::BigInt c = a + b;
    //std::cout << c << std::endl;
}