#include <iostream>
#include <cstring>
#include <string>
#include "BigInt.hpp"

namespace bint {
    BigInt::BigInt(const std::string& number) {
        this->is_negative = (number[0] == '-');
        size = number.size() - this->is_negative;
        this->data = new int[size];
        for (int i = size - 1, j = (this->is_negative ? 1 : 0); i >= 0; --i, ++j) {
            this->data[i] = number[j] - '0';
        }
    }

    BigInt::BigInt(const BigInt& other) {
        size = other.size;
        this->data = new int[size];
        memcpy(this->data, other.data, size * sizeof(int));
        this->is_negative = other.is_negative;
    }

    BigInt::~BigInt() {
        delete[] this->data;
    }

    BigInt& BigInt::operator=(const BigInt& other) {
        if (this != &other) {
            delete[] this->data;
            size = other.size;
            this->data = new int[size];
            memcpy(this->data, other.data, size * sizeof(int));
            this->is_negative = other.is_negative;
        }
        return *this;
    }


    bool BigInt::operator<(BigInt& other) {
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
    bool BigInt::operator>(BigInt& other) {
        return other < *this;
    }
    bool BigInt::operator==(BigInt& other) {
        return !(*this < other) && !(other < *this);
    }
    bool BigInt::operator!=(BigInt& other) {
        return !(*this == other);
    }
    bool BigInt::operator>=(BigInt& other) {
        return (other < *this) || (other == *this);
    }
    bool BigInt::operator<=(BigInt& other) {
        return (*this > other) || (other == *this);
    }


    BigInt BigInt::operator+(BigInt& other) {
        BigInt result;
        if (this->is_negative == other.is_negative) {
            result.size = std::max(size, other.size) + 1;
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
            if (result.data[result.size - 1] == 0)
                --result.size;
        }
        else {
            if (this->is_negative) 
                other -= *this;
            else
                *this -= other;
        }
        // else {
        //     BigInt copy = *this;
        //     result.size = std::max(size, other.size);
        //     result.data = new int[result.size];
        //     bool flag = false;
        //     if (copy.size == other.size) {
        //         for (int i = copy.size - 1; i > 0; i--) {
        //             if (copy.data[i] > other.data[i]) {
        //                 flag = true;
        //             }
        //         }
        //     }
        //     if (copy.size > other.size)
        //         flag = true;
        //     if (flag)
        //     {
        //         for (int i = 0; i < result.size; i++)
        //         {
        //             if (copy.data[i] < 0)
        //             {
        //                 copy.data[i] += 10;
        //                 copy.data[i + 1] -= 1;
        //             }
        //             if (i >= other.size)
        //             {
        //                 result.data[i] = copy.data[i];
        //                 continue;
        //             }
        //             if (copy.data[i] - other.data[i] < 0)
        //             {
        //                 copy.data[i] += 10;
        //                 copy.data[i + 1] -= 1;
        //             }
        //             result.data[i] = copy.data[i] - other.data[i];
        //         }
        //         result.is_negative = (copy.is_negative > other.is_negative);
        //     }
        //     else {
        //         for (int i = 0; i < result.size; i++)
        //         {
        //             if (other.data[i] < 0)
        //             {
        //                 other.data[i] += 10;
        //                 other.data[i + 1] -= 1;
        //             }
        //             if (i >= copy.size)
        //             {
        //                 result.data[i] = other.data[i];
        //                 continue;
        //             }
        //             if (other.data[i] - copy.data[i] < 0)
        //             {
        //                 other.data[i] += 10;
        //                 other.data[i + 1] -= 1;
        //             }
        //             result.data[i] = other.data[i] - copy.data[i];
        //         }
        //         result.is_negative = (other.is_negative > copy.is_negative);
        //         if (result.data[result.size - 1] == 0)
        //             --result.size;
        //     }
        // }
        return result;
    }

    BigInt& BigInt::operator+=(BigInt& other) {
        *this = *this + other;
        return *this;
    }

    BigInt BigInt::operator-(BigInt& other) {
        BigInt result;
        if (other.is_negative != this->is_negative)
            (*this) += other;
        BigInt copy = *this;
        result.size = std::max(size, other.size);
        result.data = new int[result.size];
        bool flag = false;
        if (copy.size == other.size) {
            for (int i = copy.size - 1; i > 0; i--) {
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
            if (result.data[result.size - 1] == 0)
                --result.size;
        }
    return result;

    }

    BigInt& BigInt::operator-=(BigInt& other) {
        BigInt temp = other;
        temp.is_negative = !other.is_negative;
        return (*this) += temp;
    }

    BigInt BigInt::operator*(BigInt& other) {
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
        while (result.size > 1 && result.data[result.size - 1] == 0)
            --result.size;
        result.is_negative = (this->is_negative != other.is_negative);
        return result;
    }

    BigInt& BigInt::operator*=(BigInt& other) {
        *this = *this * other;
        return *this;
    }

    BigInt BigInt::operator/(BigInt& other) {
        //todo        
        return (*this);
    };
    BigInt& BigInt::operator/=(BigInt& other) {
        //todo        
        return (*this);
    };
    BigInt BigInt::pow(int num) {
        if (num >= 2)
            for (int i = 1; i < num; i++)
                (*this) *= (*this);
        return (*this);
    };
    BigInt BigInt::sqrt() {
        //todo        
        return (*this);
    };
    BigInt BigInt::root(int num) {
        //todo        
        return (*this);
    };


    std::ostream& operator<<(std::ostream& out, BigInt& bigint) {
        if (bigint.is_negative)
            out << '-';
        bool flag = false;
        for (int i = bigint.size - 1; i >= 0; --i) {
            if (bigint.data[i] != 0)
            {
                flag = true;
            }
            if (flag) {
                out << bigint.data[i];
            }
        }

        return out;
    }

    std::istream& operator>>(std::istream& in, BigInt& bigint) {
        std::string number;
        in >> number;
        bigint = BigInt(number);
        return in;
    }
};