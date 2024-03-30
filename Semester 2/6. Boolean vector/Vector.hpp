#include <iostream>
#include "Vector.hpp"
namespace vct {
	template<typename T>
	class Vector
	{
	private:
	public:
	};

	template<>
	class Vector<bool>
	{
	private:
		char* arr;
		size_t byte_len;
		size_t bit_len;

	public:
		Vector<bool>() {

		};
		Vector<bool>(bool firstElem) {

		};
		Vector<bool>(char* string) {

		};
		~Vector<bool>() {

		};
		void push_back(bool elem) {
			if (this->bit_len != 8) {
				this->arr[byte_len] |= pow(2, 7 - (int)this->bit_len);
				this->bit_len++;
				return;
			}
			this->arr[byte_len] |= pow(2, 7 - (int)this->bit_len);
			this->bit_len++;
			return;
		};
		bool& at(int index) {

		};
		size_t size() {

		};
		void insert(int index, bool elem) {

		};
		void erase(int index) {

		};
	};
}