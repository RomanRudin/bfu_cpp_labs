#include <vector>
#include <stdexcept>
#include <iostream>

namespace bv {
    template<typename T>
    class vector
    {
    private:
    public:
    };

    template<>
    class vector<bool>
    {
    private:
        std::vector<unsigned char> data;
        size_t length;
    public:
        vector<bool>() {
            this->length = 0;
        }

        size_t size() {
            return this->length;
        }

        void push_back(bool value) {
            if (this->length % 8 == 0) {
                this->data.push_back(0);
            }
            if (value) {
                this->data.back() |= (1 << (this->length % 8));
            }
            this->length++;
        }

        void at(bool val, size_t index)
        {
            if ((index > this->length) || (index < 0))
                throw std::out_of_range("Index out of range");
            if (val) this->data[index / 8] |= (1 << (index % 8));
            else this->data[index / 8] &= ~(1 << (index % 8));
        }

        bool& operator[](size_t index)
        {
            bool curr_val = ((1 << (index % 8)) & (this->data[index / 8])) != 0;
            return curr_val;
        }

        void insert(size_t index, bool value) {
            if (index > this->length) {
                throw std::out_of_range("Index out of range");
            }
            push_back(false);
            for (size_t i = this->length - 1; i > index; --i) {
                this->at((*this)[i - 1], i);
            }
            (*this)[index] = value;
        }

        void erase(size_t index) {
            if (index >= this->length) {
                throw std::out_of_range("Index out of range");
            }
            for (size_t i = index; i < this->length - 1; ++i) {
                (*this)[i] = (*this)[i + 1];
            }
            if ((this->length - 1) % 8 == 0) {
                this->data.pop_back();
            }
            else {
                this->data.back() &= ~(1 << ((this->length - 1) % 8));
            }
            this->length--;
        }
    };
};