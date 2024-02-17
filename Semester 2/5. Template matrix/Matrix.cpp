#include <iostream>

namespace mtx {
	template <typename T, int N, int M>
	class Matrix {
		T m_mat[N][M];

	public:
		Matrix() {

		};
		Matrix(const Matrix& other) = delete;
		Matrix& operator=(const Matrix& other) = delete;
		~Matrix() {

		};

		friend std::istream& operator>>(std::istream& in, Matrix& other);
		friend std::ostream& operator<<(std::ostream& out, Matrix& other);

		T operator+(const Matrix& other) {

		};
		T& operator+=(const Matrix& other) {

		};
		T operator*(int number) {

		};
		T operator*(const Matrix& other) {

		};
		T& operator*=(int number) {

		};
		T& operator*=(const Matrix& other) {

		};


		T& operator++() {

		};

		T Det() {

		};

		T& operator()(int i, int j) {

		};

		void Print() {

		};
	};

	std::istream& operator>>(std::istream& in, Matrix& matrix)
	{
		std::cin >> matrix.len >> matrix.str;
		return in;
	}

	std::ostream& operator<<(std::ostream& out, Matrix& matrix)
	{
		out << matrix.str;
		return out;
	}
}