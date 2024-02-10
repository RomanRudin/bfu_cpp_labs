#include <iostream>
#include "String.hpp"

namespace str {
	/*String::String() {
		this->len = 1;
	};*/
	String::String(char* data) {
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
		this->len += other.len;
		this->str = strcat(this->str, other.str);
		return *this;
	};
	String String::operator*(int a) {
		String tmp (*this);
		for (int i = 0; i < (a - 1); i++) {
			tmp += tmp;
		}
		return tmp;
	};
	String& String::operator*=(int a) {

	};

	char String::operator[](int index) {
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

	char String::at(int index) {
		if ((index >= 0) && (index < this->len)) {
			return this->str[index];
		}
	};
	bool String::isEmpty() {
		return this->len == 1;
	};
	int String::find(char symbol) {
		for (size_t i = 0; i < this->len; i++)
			if (this->str[i] == symbol) return i;
	};
	int String::find(String& str) {

	};
	int String::rfind(char symbol) {
		for (size_t i = this->len; i > 0; i--)
			if (this->str[i] == symbol) return i;
	};
	int String::rfind(String& str) {

	};
	int String::count(char symbol) {
		int counter = 0;
		for (size_t i = this->len; i > 0; i--)
			if (this->str[i] == symbol) counter++;
		return counter;
	};
	int String::count(String& str) {

	};
	size_t String::length() {
		return this->len;
	};
	char* String::c_str() {

	};

	bool String::isUpper() {
		for (size_t i = 0; i < this->len; i++)
			if ((this->str[i] >= 141) && (this->str[i] <= 172))
				return false;
		return true;
	};
	bool String::isLower() {
		for (size_t i = 0; i < this->len; i++)
			if ((this->str[i] >= 101) && (this->str[i] <= 132))
				return false;
		return true;
	};
	void String::capitalise() {

	};
	void String::toUpper() {

	};
	bool String::toLower() {

	};
	bool String::isDigit() {
		for (size_t i = 0; i < this->len; i++)
			if (!((this->str[i] >= 60) && (this->str[i] <= 71)))
				return false;
		return true;
	};
	bool String::isLetter() {
		for (size_t i = 0; i < this->len; i++)
			if (!((this->str[i] >= 141) && (this->str[i] <= 172) || (this->str[i] >= 101) && (this->str[i] <= 132)))
				return false;
		return true;
	};

	void String::replace(char from, char to) {

	};
	void String::replace(char from, char to, int repeat) {

	};
	void String::replace(String& from, String& to) {

	};
	void String::replace(String& from, String& to, int repeat) {

	};

	std::istream& operator>>(std::istream& in, String& other);
	std::ostream& operator<<(std::ostream& out, String& other);
}
