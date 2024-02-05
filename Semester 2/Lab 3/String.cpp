#pragma once
#include <iostream>
#include "String.hpp"
namespace str {
	String::String() {

	};
	String::String(char* data) {

	};
	String::~String() {

	};

	String::String(String& other) : String(other.data) {

	};
	String String::operator=(const String& other) {

	};

	String String::operator+(const String& other) {

	};
	String& String::operator+=(const String& other) {

	};
	String String::operator*(int a) {

	};
	String& String::operator*=(int a) {

	};

	char String::operator[](int index) {

	};

	bool String::operator==(const String& other) {

	};
	bool String::operator<(const String& str) {

	};
	bool String::operator>(const String& str) {

	};

	char String::at(int index) {

	};
	bool String::isEmpty() {

	};
	int String::find(char symbol) {

	};
	int String::find(String& str) {

	};
	int String::rfind(char symbol) {

	};
	int String::rfind(String& str) {

	};
	int String::count(char symbol) {

	};
	int String::count(String& str) {

	};
	int String::length() {

	};
	char* String::c_str() {

	};

	bool String::isUpper() {

	};
	bool String::isLower() {

	};
	void String::capitalise() {

	};
	void String::toUpper() {

	};
	bool String::isUpper() {

	};
	bool String::isDigit() {

	};
	bool String::isSymbol() {

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