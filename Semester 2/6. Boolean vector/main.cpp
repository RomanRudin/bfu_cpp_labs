#include <vector>
#include <stdexcept>
#include <iostream>


class BoolVector {
private:
    std::vector<unsigned char> data;
    size_t size;
public:
    BoolVector() {
        this->size = 0;
    }

    size_t length() {
        return this->size;
    }

    void push_back(bool value) {
        if (this->size % 8 == 0) {
            this->data.push_back(0);
        }
        if (value) {
            this->data.back() |= (1 << (this->size % 8));
        }
        this->size++;
    }

    void at(bool val, size_t index)
    {
        if ((index > this->size) || (index < 0))
        {
            throw std::out_of_range("Error: Index OOR");
        }
        if (val == true) this->data[index / 8] |= (1 << (index % 8)); // записать 1 в указанный бит
        else this->data[index / 8] &= ~(1 << (index % 8)); // записать 0 в указанный бит
    }

    bool& operator[](size_t index)
    {
        bool curr_val = ((1 << (index % 8)) & (this->data[index / 8])) != 0; // значение бита на позиции index

        return curr_val;
    }

    void insert(size_t index, bool value) {
        if (index > this->size) {
            throw std::out_of_range("Index out of range");
        }
        push_back(false); // Добавляем место для нового значения
        for (size_t i = this->size - 1; i > index; --i) {
            this->at((*this)[i - 1], i);
        }
        (*this)[index] = value;
    }

    void erase(size_t index) {
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

// Пример использования
int main() {
    BoolVector bv;
    bv.push_back(true);
    std::cout << bv[0] << std::endl;
    bv.push_back(false);
    std::cout << bv[1] << std::endl;
    bv.insert(1, true);
    bv.erase(2);
    std::cout << bv.length() << std::endl;

    for (size_t i = 0; i < bv.length(); ++i) {
        std::cout << bv[i] << ' ';
    }

    return 0;
}