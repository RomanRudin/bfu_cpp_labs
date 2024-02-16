#pragma once
#include <iostream>
namespace str {
	class String {
	private:
		char* str;
		size_t len;

	public:
		String();
		String(size_t length);
		String(char* data);
		String(const char* data);
		~String();

		String(const String& other);
		String& operator=(const String& other);

		String operator+(const String& other);
		String& operator+=(const String& other);
		String operator*(int a);
		String& operator*=(int a); 

		char& operator[](int index);

		bool operator==(const String& other);
		bool operator!=(const String& other);
		bool operator<(const String& other);
		bool operator>(const String& other);
		bool operator<=(const String& other);
		bool operator>=(const String& other);

		friend std::istream& operator>>(std::istream& in, String& other);
		friend std::ostream& operator<<(std::ostream& out, String& other);

		char& at(int index);
		bool isEmpty();
		int find(char symbol);
		int find(String& str);
		int rfind(char symbol);
		int rfind(String& str);
		int count(char symbol);
		int count(String& str);
		size_t length();
		char* c_str();

		bool isUpper();
		bool isLower();
		void capitalise();
		void toUpper();
		bool toLower();
		bool isDigit();
		bool isLetter();

		void replace(char from, char to);
		void replace(char from, char to, int repeat);
		void replace(String& from, String& to); //TODO
		void replace(String& from, String& to, int repeat);//TODO
	};

	std::istream& operator>>(std::istream& in, String& other);
	std::ostream& operator<<(std::ostream& out, String& other);
}
