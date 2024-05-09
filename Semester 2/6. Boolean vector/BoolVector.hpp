#pragma once
#include <vector>

namespace bv {
    class BoolVector {
    private:
        std::vector<unsigned char> data;
        size_t size;
    public:
        BoolVector();
        size_t length();
        void push_back(bool value);
        void at(bool val, size_t index);
        bool& operator[](size_t index);
        void insert(size_t index, bool value);
        void erase(size_t index);
    };
}