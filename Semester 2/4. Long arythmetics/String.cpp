#include <iostream>
#include "String.hpp"

namespace str {
	String::String() {
		this->len = 1;
		this->str = new char[0];
	};
	String::String(size_t length) {
		this->len = length + 1;
		this->str = new char[this->len];
	};
	String::String(char* data) {
		this->len = strlen(data) + 1;
		this->str = new char[this->len];
		std::copy(data, data + this->len, this->str);
	};
	String::String(const char* data) {
		this->len = strlen(data) + 1;
		this->str = new char[this->len];
		std::copy(data, data + this->len, this->str);
	};
	String::~String() {
		delete[] this->str;
	};

	String::String(const String& other) : String(other.str) {};
	String& String::operator=(const String& other) {
		delete[] this->str;
		this->str = new char[this->len];
		std::copy(other.str, other.str + this->len, this->str);
		return *this;
	};

	String String::operator+(const String& other) {
		String tmp(*this);
		tmp += other;
		return tmp;
	};
	String& String::operator+=(const String& other) {
		String tmp(*this);
		delete[] this->str;
		this->len += other.len;
		this->str = new char[this->len];
		std::copy(tmp.str, tmp.str + tmp.len, this->str);
		strcat_s(this->str, this->len, other.str);
		return *this;
	};
	String String::operator*(int a) { //TODO
		String tmp(*this);
		for (int i = 0; i < (a - 1); i++) {
			tmp += tmp;
		}
		return tmp;
	};
	String& String::operator*=(int a) { //TODO
		String tmp(*this);
		return tmp;
	};

	String String::reverse() {
		String tmp(this->length());
		for (int i = 0; i < this->length(); i++)
			tmp.str[i] = this->str[this->length() - i];
		return tmp;
	}

	char& String::operator[](int index) {
		return this->str[index];
	};

	bool String::operator==(const String& other) {
		return strcmp(this->str, other.str) == 0;
	};
	bool String::operator!=(const String& other) {
		return !(*this == other);
	};
	bool String::operator<(const String& other) {
		return strcmp(this->str, other.str) < 0;
	};
	bool String::operator>(const String& other) {
		return strcmp(this->str, other.str) > 0;
	};
	bool String::operator<=(const String& other) {
		return strcmp(this->str, other.str) <= 0;
	};
	bool String::operator>=(const String& other) {
		return strcmp(this->str, other.str) >= 0;
	};

	char& String::at(int index) {
		if ((index < 0) || (index >= this->len))
		{
			throw;
		}
		return this->str[index];
	};
	bool String::isEmpty() {
		return this->len == 1;
	};
	int String::find(char symbol) {
		for (size_t i = 0; i < this->len; i++)
			if (this->str[i] == symbol) return i;
		return -1;
	};
	int String::find(String& str) {
		if (str.len > this->len)
			return -1;
		for (size_t i = 0; i < this->len - str.len; i++) {
			bool flag = true;
			for (size_t j = 0; j < str.len; j++)
				if (this->str[i + j] != str.str[j]) {
					flag = false;
					break;
				}
			if (flag) return i;
		}
		return -1;
	};
	int String::rfind(char symbol) {
		for (size_t i = this->len; i > 0; i--)
			if (this->str[i] == symbol) return i;
		return -1;
	};
	int String::rfind(String& str) {
		if (str.len > this->len)
			return -1;
		for (size_t i = this->len; i > str.len; i--) {
			bool flag = true;
			for (size_t j = str.len; j > 0; j--)
				if (this->str[i + j] != str.str[j]) {
					flag = false;
					break;
				}
			if (flag) return i;
		}
		return -1;
	};
	int String::count(char symbol) {
		int counter = 0;
		for (size_t i = this->len; i > 0; i--)
			if (this->str[i] == symbol) counter++;
		return counter;
	};
	int String::count(String& str) {
		if (str.len > this->len)
			return 0;
		int counter = 0;
		for (size_t i = 0; i < this->len - str.len; i++) {
			counter++;
			for (size_t j = 0; j < str.len; j++)
				if (this->str[i + j] != str.str[j]) {
					counter--;
					break;
				}
		}
		return counter;
	};
	size_t String::length() {
		return this->len - 1;
	};
	char* String::c_str() {
		return str;
	};

	bool String::isUpper() {
		for (size_t i = 0; i < this->len; i++)
			if ((this->str[i] >= 97) && (this->str[i] <= 122))
				return false;
		return true;
	};
	bool String::isLower() {
		for (size_t i = 0; i < this->len; i++)
			if ((this->str[i] >= 65) && (this->str[i] <= 90))
				return false;
		return true;
	};
	void String::capitalise() {
		if ((this->str[0] >= 97) && (this->str[0] <= 122))
			this->str[0] -= 32;
	};
	void String::toUpper() {
		for (size_t i = 0; i < this->len; i++)
			if ((this->str[0] >= 97) && (this->str[0] <= 122))
				this->str[0] -= 32;
	};
	void String::toLower() {
		for (size_t i = 0; i < this->len; i++)
			if ((this->str[0] >= 65) && (this->str[0] <= 90))
				this->str[0] += 32;
	};
	bool String::isDigit() {
		for (size_t i = 0; i < this->len - 1; i++)
			if (!((this->str[i] >= 48) && (this->str[i] <= 57)))
				return false;
		return true;
	};
	bool String::isLetter() {
		for (size_t i = 0; i < this->len; i++)
			if (!((this->str[i] >= 97) && (this->str[i] <= 122) || (this->str[i] >= 65) && (this->str[i] <= 90)))
				return false;
		return true;
	};

	void String::replace(char from, char to) {
		for (size_t i = 0; i < this->len; i++)
			if (this->str[i] == from)
				this->str[i] = to;
	};
	void String::replace(char from, char to, int repeat) {
		if (repeat <= 0)
			return;
		for (size_t i = 0; i < this->len; i++) {
			if (this->str[i] == from) {
				this->str[i] = to;
				repeat--;
			}
			if (repeat <= 0)
				return;
		}
	}
	void String::replace(String& from, String& to) {
		/*	if (from.len > this->len)
				return;
			for (size_t i = 0; i < this->len - from.len; i++) {

			}
		*/
	}
	void String::replace(String& from, String& to, int repeat) {
		/*	if (from.len > this->len)
			return;
		for (size_t i = 0; i < this->len - from.len; i++) {

		}
	*/
	}

	std::istream& operator>>(std::istream& in, String& string)
	{
		std::cin >> string.len >> string.str;
		return in;
	}

	std::ostream& operator<<(std::ostream& out, String& string)
	{
		out << string.str;
		return out;
	}
}