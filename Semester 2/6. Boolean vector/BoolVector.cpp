#include <vector>
#include <stdexcept>
#include "BoolVector.hpp"


namespace bv {
    BoolVector::BoolVector() {
        this->size = 0;
    }

    size_t BoolVector::length() {
        return this->size;
    }

    void BoolVector::push_back(bool value) {
        if (this->size % 8 == 0) {
            this->data.push_back(0);
        }
        if (value) {
            this->data.back() |= (1 << (this->size % 8));
        }
        this->size++;
    }

    void BoolVector::at(bool val, size_t index)
    {
        if ((index > this->size) || (index < 0))
            throw std::out_of_range("Index out of range");
        if (val) this->data[index / 8] |= (1 << (index % 8));
        else this->data[index / 8] &= ~(1 << (index % 8)); 
    }

    bool& BoolVector::operator[](size_t index)
    {
        bool curr_val = ((1 << (index % 8)) & (this->data[index / 8])) != 0; 
        return curr_val;
    }

    void BoolVector::insert(size_t index, bool value) {
        if (index > this->size) {
            throw std::out_of_range("Index out of range");
        }
        push_back(false);
        for (size_t i = this->size - 1; i > index; --i) {
            this->at((*this)[i - 1], i);
        }
        (*this)[index] = value;
    }

    void BoolVector::erase(size_t index) {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < this->size - 1; ++i) {
            (*this)[i] = (*this)[i + 1];
        }
        if ((size - 1) % 8 == 0) {
            this->data.pop_back();
        }
        else {
            this->data.back() &= ~(1 << ((this->size - 1) % 8));
        }
        this->size--;
    }
};
