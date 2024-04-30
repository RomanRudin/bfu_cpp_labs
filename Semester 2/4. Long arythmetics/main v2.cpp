#include <iostream>
#include <cstring>
#include <string>

class BigInt {
private:
    int* digits; 
    int size; 
    bool negative; 
public:
    // Базовый конструктор
    BigInt() : digits(nullptr), size(0), negative(false) {}

    // Конструктор из строки
    BigInt(const std::string& number) {
        negative = (number[0] == '-'); // Установка флага отрицательности
        size = number.size() - negative;
        digits = new int[size];
        for (int i = size - 1, j = (negative ? 1 : 0); i >= 0; --i, ++j) {
            digits[i] = number[j] - '0';
        }
    }



    // Конструктор копирования
    BigInt(const BigInt& other) {
        size = other.size;
        digits = new int[size];
        memcpy(digits, other.digits, size * sizeof(int));
        negative = other.negative;
    }

    // Деструктор
    ~BigInt() {
        delete[] digits;
    }

    // Оператор присваивания
    BigInt& operator=(const BigInt& other) {
        if (this != &other) {
            delete[] digits;
            size = other.size;
            digits = new int[size];
            memcpy(digits, other.digits, size * sizeof(int));
            negative = other.negative;
        }
        return *this;
    }

    // Оператор меньше
    bool operator<(const BigInt& other) const {
        if (negative != other.negative)
            return negative;
        if (size != other.size)
            return (size < other.size) ^ negative;
        for (int i = size - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i])
                return (digits[i] < other.digits[i]) ^ negative;
        }
        return false;
    }

    // Оператор больше
    bool operator>(const BigInt& other) const {
        return other < *this;
    }

    // Оператор равенства
    bool operator==(const BigInt& other) const {
        return !(*this < other) && !(other < *this);
    }

    // Оператор неравенства
    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }
    // Оператор сложения
    BigInt operator+(const BigInt& other) const {
        BigInt result;
        if (negative == other.negative) { // Если знаки чисел одинаковые
            result.size = std::max(size, other.size) + 1; // Размер результата не превысит наибольший из размеров слагаемых + 1 (на случай переноса)
            result.digits = new int[result.size];
            int carry = 0;
            for (int i = 0; i < result.size; ++i) {
                int sum = carry;
                if (i < size)
                    sum += digits[i];
                if (i < other.size)
                    sum += other.digits[i];
                result.digits[i] = sum % 10;
                carry = sum / 10;
            }
            result.negative = negative;
            if (result.digits[result.size - 1] == 0) // Удаляем лишний нуль, если он есть
                --result.size;
        }
        else {
            BigInt copy = *this;
            result.size = std::max(size, other.size);
            result.digits = new int[result.size];
            bool flag = false;
            if (copy.size == other.size) {
                for (int i = 0; i < copy.size; i++) {
                    if (copy.digits[i] > other.digits[i]) {
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
                    if (copy.digits[i] < 0)
                    {
                        copy.digits[i] += 10;
                        copy.digits[i + 1] -= 1;
                    }
                    if (i >= other.size)
                    {
                        result.digits[i] = copy.digits[i];
                        continue;
                    }
                    if (copy.digits[i] - other.digits[i] < 0)
                    {
                        copy.digits[i] += 10;
                        copy.digits[i + 1] -= 1;
                    }
                    result.digits[i] = copy.digits[i] - other.digits[i];
                }
                result.negative = (copy.negative > other.negative);
            }
            else {
                for (int i = 0; i < result.size; i++)
                {
                    if (other.digits[i] < 0)
                    {
                        other.digits[i] += 10;
                        other.digits[i + 1] -= 1;
                    }
                    if (i >= copy.size)
                    {
                        result.digits[i] = other.digits[i];
                        continue;
                    }
                    if (other.digits[i] - copy.digits[i] < 0)
                    {
                        other.digits[i] += 10;
                        other.digits[i + 1] -= 1;
                    }
                    result.digits[i] = other.digits[i] - copy.digits[i];
                }
                result.negative = (other.negative > copy.negative);
                if (result.digits[result.size - 1] == 0) // Удаляем лишний нуль, если он есть
                    --result.size;
            }
        }
        return result;
    }

    // Оператор сложения с присваиванием
    BigInt& operator+=(const BigInt& other) {
        *this = *this + other;
        return *this;
    }

    


    // Оператор умножения
    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.size = size + other.size;
        result.digits = new int[result.size];
        memset(result.digits, 0, result.size * sizeof(int));

        for (int i = 0; i < size; ++i) {
            int carry = 0;
            for (int j = 0; j < other.size || carry; ++j) {
                long long current = result.digits[i + j] + digits[i] * 1ll * (j < other.size ? other.digits[j] : 0) + carry;
                result.digits[i + j] = current % 10;
                carry = current / 10;
            }
        }

        // Убираем лишние нули в начале числа
        while (result.size > 1 && result.digits[result.size - 1] == 0)
            --result.size;

        // Определение знака результата
        result.negative = (negative != other.negative);
        return result;
    }

    // Оператор умножения с присваиванием
    BigInt& operator*=(const BigInt& other) {
        *this = *this * other;
        return *this;
    }



    // Оператор вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint) {
        if (bigint.negative)
            os << '-';
        bool flag = false;
        for (int i = bigint.size - 1; i >= 0; --i) {
            if (bigint.digits[i] != 0)
            {
                flag = true;
            }
            if (flag) {
                os << bigint.digits[i];
            }
        }

        return os;
    }

    // Оператор ввода из потока
    friend std::istream& operator>>(std::istream& is, BigInt& bigint) {
        std::string number;
        is >> number;
        bigint = BigInt(number);
        return is;
    }
};

int main() {
    BigInt a("-10");
    BigInt b("1");
    BigInt c = a + b;
    BigInt d = a * b;


    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    std::cout << "a * b: " << d << std::endl;
    return 0;
}
