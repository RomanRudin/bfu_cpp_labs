#pragma once
#include <iostream>
#include "BigInt.hpp"
#include "String.hpp"
namespace bint {
	BigInt::BigInt() {
		this->str = str::String("");
		this->negative = false;
	};
	BigInt::BigInt(str::String data) {
		if (!data.isDigit()) {
			std::cout << "The string contains characters other than digits!" << std::endl;
			throw std::exception("The string contains characters other than digits!");
		}
		this->str = data;
		this->negative = false;
	};
	BigInt::~BigInt() {
		this->str.~String();
	};


	BigInt BigInt::operator+(int num)
	{
		//TODO
	}
	BigInt BigInt::operator+=(int num)
	{
		//TODO
	}
	BigInt BigInt::operator-(int num)
	{
		//TODO
	}
	BigInt BigInt::operator-=(int num)
	{
		//TODO
	}
	BigInt BigInt::operator*(int num)
	{
		//TODO
	}
	BigInt BigInt::operator*=(int num)
	{
		//TODO
	}
	BigInt BigInt::operator/(int num)
	{
		//TODO
	}
	BigInt BigInt::operator/=(int num)
	{
		//TODO
	}

	BigInt BigInt::operator+(BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator+=(BigInt& other) {
		if (this->negative != other.negative) {
			if (this->negative) return (other -= *this);
			if (other.negative) return (*this -= other);
		}
		str::String tmpS = other.str;
		tmpS = tmpS.reverse();
		str::String tmpL = this->str.reverse();
		if (tmpS.length() > tmpL.length()) {
			str::String tmpL = tmpS;
			tmpS = this->str.reverse();
		}
		bool extra_digit = false;
		for (int i = 0; i < tmpS.length(); i++) {
			tmpL[i] += tmpS[i] - 48;
			if (extra_digit) {
				tmpL[i]++;
				extra_digit = false;
			}
			extra_digit = tmpL[i] > 57;
			if (extra_digit) tmpL[i] -= 10;
		}
		if (extra_digit) {
			if (tmpL.length() == tmpS.length()) {
				tmpL += "1";
			}
			else {
				for (int i = tmpS.length(); i < tmpL.length(); i++) {
					if (extra_digit) {
						tmpL[i]++;
						extra_digit = false;
					}
					extra_digit = tmpL[i] > 57;
					if (extra_digit) tmpL[i] -= 10;
				}
			}
		}
		this->str = tmpL.reverse();
		return *this;
	};
	BigInt BigInt::operator-(BigInt& other) {
		BigInt tmp(*this);
		tmp += other;
		return tmp;
	};
	BigInt& BigInt::operator-=(BigInt& other) {
		str::String tmpS = other.str;
		tmpS = tmpS.reverse();
		str::String tmpL = this->str.reverse();
		if (tmpS > tmpL) {
			this->negative = true;
			str::String tmpL = tmpS;
			tmpS = this->str.reverse();
		}
		bool extra_digit = false;
		for (int i = 0; i < tmpS.length(); i++) {
			tmpL[i] -= tmpS[i] + 48;
			if (extra_digit) {
				tmpL[i]--;
				extra_digit = false;
			}
			extra_digit = tmpL[i] < 48;
			if (extra_digit) tmpL[i] += 10;
		}

		//  TODO 
		// In need of system od calculating edge variant of something like 10000 - 1
		if (extra_digit) {
			if (tmpL.length() == tmpS.length()) {
				tmpL += "1";
			}
			else {
				for (int i = tmpS.length(); i < tmpL.length(); i++) {
					if (extra_digit) {
						tmpL[i]++;
						extra_digit = false;
					}
					extra_digit = tmpL[i] > 57;
					if (extra_digit) tmpL[i] -= 10;
				}
			}
		}
		this->str = tmpL.reverse();
		return *this;
	};
	BigInt BigInt::operator*(BigInt& other) {
		BigInt tmp(*this);
		tmp *= other;
		return tmp;
	};
	BigInt& BigInt::operator*=(BigInt& other) {
		BigInt tmp();
		if (!(this->negative ^ other.negative))
			this->negative = false;
		else 
			this->negative = true;
		BigInt currentIter();
		for (int i = 0; i < other.str.length(); i++) {
			
		}
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
		if (other.negative) out << "-";
		out << other.str;
		return out;
	};
}