#pragma once
#include <iostream>
#include "BigInt.hpp"
#include "String.hpp"
namespace bint {
	BigInt::BigInt() {
		this->str = str::String("");
		this->isNegative = false;
		this->length = 0;
	};
	BigInt::BigInt(int data) {
		this->str = str::String("");
		this->isNegative = data > 0;
		data = std::abs(data);
		unsigned int counter = 0;
		while (data > 0) {
			this->str = str::String((char)(data % 10 + 48) + this->str.c_str());
			data /= 10;
			counter++;
		}
		this->length = counter;
	};
	BigInt::BigInt(long long data) {
		this->str = str::String("");
		this->isNegative = data > 0;
		data = std::abs(data);
		unsigned int counter = 0;
		while (data > 0) {
			this->str = str::String((char)(data % 10 + 48) + this->str.c_str());
			data /= 10;
			counter++;
		}
		this->length = counter;
	};
	BigInt::BigInt(str::String data) {
		if (!data.isDigit()) {
			throw "";
		}
		this->str = data;
		this->isNegative = false;
		this->length = data.length();
	};
	BigInt::~BigInt() {
		this->str.~String();
	};

	BigInt BigInt::operator+(BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator+=(BigInt& other) {
		if ((this->isNegative && !other.isNegative) || (!this->isNegative && other.isNegative)) {
			BigInt tmp(*this);
			tmp -= other;
			return *this;
		}
		str::String tmp("");
		if (this->length >= other.length) {
			bool addDigit = false;
			unsigned short currentDigit;
			for (int i = this->length; i > 0; i--) {
				currentDigit = (short)this->str.at(i) + (short)other.str.at(i) - 92;
				if (addDigit) {
					currentDigit++;
					addDigit = false;
				}
				if (currentDigit > 10) addDigit = true;
				tmp = (char)((currentDigit % 10) + 48)
			}
		}
		else {

		}
		this->str = tmp;
		return *this;
	};
	BigInt BigInt::operator-(BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator-=(BigInt& other) {
		str::String tmp("");

		//TODO

	};
	BigInt BigInt::operator*(BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator*=(BigInt& other) {
		str::String tmp("");

		//TODO

	};
	BigInt BigInt::operator/(BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator/=(BigInt& other) {
		str::String tmp("");

		//TODO

	};
	BigInt BigInt::pow(int num) {
		BigInt tmp(*this);
		for (int i = 1; i < num; i++) {
			tmp *= tmp;
		}
		return tmp;
	};
	BigInt BigInt::sqrt() {

	};
	BigInt BigInt::root(int num) {

	};

	bool BigInt::operator==(const BigInt& other) {
		return (this->str == other.str);
	};
	bool BigInt::operator!=(const BigInt& other) {
		return (!(this->str == other.str));
	};
	bool BigInt::operator<(const BigInt& other) {
		return (this->str < other.str);
	};
	bool BigInt::operator>(const BigInt& other) {
		return (this->str > other.str);
	};
	bool BigInt::operator<=(const BigInt& other) {
		return (this->str <= other.str);
	};
	bool BigInt::operator>=(const BigInt& other) {
		return (this->str >= other.str);
	};


	std::istream& operator>>(std::istream& in, BigInt& other) {
		std::cin >> other.str;
		return in;
	};
	std::ostream& operator<<(std::ostream& out, BigInt& other) {
		if (other.isNegative) out << "-";
		out << other.str;
		return out;
	};
}