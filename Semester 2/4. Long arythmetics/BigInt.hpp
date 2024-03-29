#pragma once
#include <iostream>
#include "String.hpp"
namespace bint {
	char toChar(int num);
	int toInt(char sym);

	class BigInt {
	private:
		str::String str;
		bool negative;

	public:
		BigInt();
		BigInt(int data);
		BigInt(long long data);
		BigInt(str::String data);
		~BigInt();


		BigInt operator+(int num);
		BigInt operator+=(int num);
		BigInt operator-(int num);
		BigInt operator-=(int num);
		BigInt operator*(int num);
		BigInt operator*=(int num);
		BigInt operator/(int num);
		BigInt operator/=(int num);

		BigInt operator+(BigInt& other);
		BigInt& operator+=(BigInt& other);
		BigInt operator-(BigInt& other);
		BigInt& operator-=(BigInt& other);
		BigInt operator*(BigInt& other);
		BigInt& operator*=(BigInt& other);
		BigInt operator/(BigInt& other);
		BigInt& operator/=(BigInt& other);
		BigInt pow(int num);
		BigInt sqrt();
		BigInt root(int num);


		bool operator==(const BigInt& other);
		bool operator!=(const BigInt& other);
		bool operator<(const BigInt& other);
		bool operator>(const BigInt& other);
		bool operator<=(const BigInt& other);
		bool operator>=(const BigInt& other);

		
		friend std::istream& operator>>(std::istream& in, BigInt& other);
		friend std::ostream& operator<<(std::ostream& out, BigInt& other);
	};
		
	std::istream& operator>>(std::istream& in, BigInt& other);
	std::ostream& operator<<(std::ostream& out, BigInt& other);
}