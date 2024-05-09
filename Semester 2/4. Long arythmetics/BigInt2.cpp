#include <iostream>
#include <cstring>
#include <string>

class BigInt {
private:
    int* data;
    int size;
    bool is_negative;
public:
    BigInt() : data(nullptr), size(0), is_negative(false) {}

    BigInt(const std::string& number) {
        this->is_negative = (number[0] == '-'); // Установка флага отрицательности
        size = number.size() - this->is_negative;
        this->data = new int[size];
        for (int i = size - 1, j = (this->is_negative ? 1 : 0); i >= 0; --i, ++j) {
            this->data[i] = number[j] - '0';
        }
    }

    BigInt(const BigInt& other) {
        size = other.size;
        this->data = new int[size];
        memcpy(this->data, other.data, size * sizeof(int));
        this->is_negative = other.is_negative;
    }

    ~BigInt() {
        delete[] this->data;
    }


    BigInt& operator=(const BigInt& other) {
        if (this != &other) {
            delete[] this->data;
            size = other.size;
            this->data = new int[size];
            memcpy(this->data, other.data, size * sizeof(int));
            this->is_negative = other.is_negative;
        }
        return *this;
    }


    bool operator<(const BigInt& other) const {
        if (this->is_negative != other.is_negative)
            return this->is_negative;
        if (size != other.size)
            return (this->size < other.size) ^ this->is_negative;
        for (int i = this->size - 1; i >= 0; --i) {
            if (this->data[i] != other.data[i])
                return (this->data[i] < other.data[i]) ^ this->is_negative;
        }
        return false;
    }
    bool operator>(const BigInt& other) const {
        return other < *this;
    }
    bool operator==(const BigInt& other) const {
        return !(*this < other) && !(other < *this);
    }
    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }
    bool operator>=(const BigInt& other) const {
        return (other < *this) || (other == *this);
    }
    bool operator==(const BigInt& other) const {
        return (other > *this) || (other == *this);
    }

    
    BigInt operator+(const BigInt& other) const {
        BigInt result;
        if (this->is_negative == other.is_negative) { // Если знаки чисел одинаковые
            result.size = std::max(size, other.size) + 1; // Размер результата не превысит наибольший из размеров слагаемых + 1 (на случай переноса)
            result.data = new int[result.size];
            int carry = 0;
            for (int i = 0; i < result.size; ++i) {
                int sum = carry;
                if (i < size)
                    sum += this->data[i];
                if (i < other.size)
                    sum += other.data[i];
                result.data[i] = sum % 10;
                carry = sum / 10;
            }
            result.is_negative = this->is_negative;
            if (result.data[result.size - 1] == 0) // Удаляем лишний нуль, если он есть
                --result.size;
        }
        else {
            BigInt copy = *this;
            result.size = std::max(size, other.size);
            result.data = new int[result.size];
            bool flag = false;
            if (copy.size == other.size) {
                for (int i = 0; i < copy.size; i++) {
                    if (copy.data[i] > other.data[i]) {
                        flag = true;
                    }
                }
            }
            if (copy.size > other.size)
                flag = true;
            if (flag)
            {
                for (int i = 0; i < result.size; i++)
                {
                    if (copy.data[i] < 0)
                    {
                        copy.data[i] += 10;
                        copy.data[i + 1] -= 1;
                    }
                    if (i >= other.size)
                    {
                        result.data[i] = copy.data[i];
                        continue;
                    }
                    if (copy.data[i] - other.data[i] < 0)
                    {
                        copy.data[i] += 10;
                        copy.data[i + 1] -= 1;
                    }
                    result.data[i] = copy.data[i] - other.data[i];
                }
                result.is_negative = (copy.is_negative > other.is_negative);
            }
            else {
                for (int i = 0; i < result.size; i++)
                {
                    if (other.data[i] < 0)
                    {
                        other.data[i] += 10;
                        other.data[i + 1] -= 1;
                    }
                    if (i >= copy.size)
                    {
                        result.data[i] = other.data[i];
                        continue;
                    }
                    if (other.data[i] - copy.data[i] < 0)
                    {
                        other.data[i] += 10;
                        other.data[i + 1] -= 1;
                    }
                    result.data[i] = other.data[i] - copy.data[i];
                }
                result.is_negative = (other.is_negative > copy.is_negative);
                if (result.data[result.size - 1] == 0) // Удаляем лишний нуль, если он есть
                    --result.size;
            }
        }
        return result;
    }

    BigInt& operator+=(const BigInt& other) {
        *this = *this + other;
        return *this;
    }


    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.size = size + other.size;
        result.data = new int[result.size];
        memset(result.data, 0, result.size * sizeof(int));

        for (int i = 0; i < size; ++i) {
            int carry = 0;
            for (int j = 0; j < other.size || carry; ++j) {
                long long current = result.data[i + j] + this->data[i] * 1ll * (j < other.size ? other.data[j] : 0) + carry;
                result.data[i + j] = current % 10;
                carry = current / 10;
            }
        }

        // Убираем лишние нули в начале числа
        while (result.size > 1 && result.data[result.size - 1] == 0)
            --result.size;

        // Определение знака результата
        result.is_negative = (this->is_negative != other.is_negative);
        return result;
    }

    BigInt& operator*=(const BigInt& other) {
        *this = *this * other;
        return *this;
    }

    
    friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint) {
        if (bigint.is_negative)
            os << '-';
        bool flag = false;
        for (int i = bigint.size - 1; i >= 0; --i) {
            if (bigint.data[i] != 0)
            {
                flag = true;
            }
            if (flag) {
                os << bigint.data[i];
            }
        }

        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInt& bigint) {
        std::string number;
        is >> number;
        bigint = BigInt(number);
        return is;
    }
};