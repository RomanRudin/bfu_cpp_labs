#pragma once
#include <iostream>
#include "BigInt.hpp"
#include "String.hpp"
namespace bint {
	BigInt::BigInt() {
		this->str = str::String("");
	};
	BigInt::BigInt(int data) {
		this->str = str::String("");
		while (data > 0) {
			this->str = str::String((char)(data % 10 + 48) + this->str.c_str());
			data /= 10;
		}
	};
	BigInt::BigInt(long long data) {
		this->str = str::String("");
		while (data > 0) {
			this->str = str::String((char)(data % 10 + 48) + this->str.c_str());
			data /= 10;
		}
	};
	BigInt::BigInt(str::String data) {
		if (!data.isDigit()) {
			throw "";
		}
		this->str = data;
	};
	BigInt::~BigInt() {
		this->str.~String();
	};

	BigInt BigInt::operator+(const BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator+=(BigInt& other) {

		//TODO

	};
	BigInt BigInt::operator-(const BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator-=(const BigInt& other) {
		str::String tmp("");

		//TODO

	};
	BigInt BigInt::operator*(const BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator*=(const BigInt& other) {
		str::String tmp("");

		//TODO

	};
	BigInt BigInt::operator/(const BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator/=(const BigInt& other) {
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
		if (other.negative) out << "-";
		out << other.str;
		return out;
	};
}