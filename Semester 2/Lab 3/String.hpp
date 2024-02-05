#pragma once
#include <iostream>
namespace str{
	class String {
	private:
		char* data;

	private:
		void setup();
		void swap(const String& other);

	public:
		String() = default;
		String(char* data);
		~String();

		String(String& other) : String(other.data) {};
		String operator=(const String& other);

		String operator+(const String& other);
		String& operator+=(const String& other);
		String operator*(int a);
		String& operator*=(int a);

		char operator[](int index);

		bool operator==(const String& other);
		bool operator<(const String& str);
		bool operator>(const String& str);

		friend std::istream& operator>>(std::istream& in, String& other);
		friend std::ostream& operator<<(std::ostream& out, String& other);
	
		char at(int index);
		bool isEmpty();
		int find(char symbol);
		int find(String& str);
		int rfind(char symbol);
		int rfind(String& str);
		int count(char symbol);
		int count(String& str);
		int length();
		char* c_str();
		
		bool isUpper();
		bool isLower();
		void capitalise(); 
		void toUpper();
		bool isUpper();
		bool isDigit();
		bool isSymbol();

		void replace(char from, char to);
		void replace(char from, char to, int repeat);
		void replace(String& from, String& to);
		void replace(String& from, String& to, int repeat);
	};

	std::istream& operator>>(std::istream& in, String& other);
	std::ostream& operator<<(std::ostream& out, String& other);
}