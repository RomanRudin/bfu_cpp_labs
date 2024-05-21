#pragma once
#include <iostream>
#include <string>

namespace bint {
	class BigInt {
	private:
		int* data;
		int size;
		bool is_negative;

	public:
		BigInt() : data(nullptr), size(0), is_negative(false) {};
		BigInt(const std::string& number);
		BigInt(const BigInt& other);
		~BigInt();

		BigInt& operator=(const BigInt& other);


		bool operator<(BigInt& other);
		bool operator>(BigInt& other);
		bool operator==(BigInt& other);
		bool operator!=(BigInt& other);
		bool operator<=(BigInt& other);
		bool operator>=(BigInt& other);


		BigInt operator+(BigInt& other);
		BigInt& operator+=(BigInt& other);
		BigInt operator-(BigInt& other);
		BigInt& operator-=(BigInt& other);
		BigInt operator*(BigInt& other);
		BigInt& operator*=(BigInt& other);
		BigInt operator/(BigInt& other);//TODO
		BigInt& operator/=(BigInt& other);//TODO
		BigInt pow(int num);//TODO
		BigInt sqrt(); //TODO
		BigInt root(int num);//TODO


		friend std::istream& operator>>(std::istream& in, BigInt& other);
		friend std::ostream& operator<<(std::ostream& out, BigInt& other);
	};

	std::istream& operator>>(std::istream& in, bint::BigInt& other);
	std::ostream& operator<<(std::ostream& out, bint::BigInt& other);
}