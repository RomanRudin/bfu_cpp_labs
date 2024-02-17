#include <iostream>

namespace mtx {
	template <typename T, int N, int M>
	class Matrix {
		T matrix[N][M];
	public:
		Matrix() {

		};
		Matrix(const Matrix& other) = delete;
		Matrix& operator=(const Matrix& other) = delete;
		~Matrix() {

		};

		friend std::istream& operator>>(std::istream& in, Matrix& other);
		friend std::ostream& operator<<(std::ostream& out, Matrix& other);

		Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) {
			*this += other;
			return *this;
		};
		Matrix<T, N, M>& operator+=(const Matrix<T, N, M>& other) {
			if ((other.N != this->N) || (other.M != this->M)) {
				std::cerr << "Wrong matrix size!"; 
				throw std::exception("Wrong matrix size!");
			}
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					this->matrix[i][j] += other.matrix[i][j];
			return *this;
		};
		Matrix<T, N, M> operator*(T val) {
			*this *= val;
			return *this;
		};
		template<int L>
		Matrix<T, N, L> operator*(const Matrix<T, M, L>& other) {
			Matrix<T, N, L> tmp{};
			for (int i = 0; i < N; i++)
				for (int j = 0; j < L; j++)
					for (int k = 0; k < M; k++)
						tmp(i, j) += this->matrix[i][k] * other(k, j);
			return tmp;
		};
		Matrix<T, N, M>& operator*=(T val) {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					this->matrix[i][j] *= val;
			return *this;
		};
		template<int L>
		Matrix<T, N, L>& operator*=(const Matrix<T, M, L>& other) {
			*this = *this * other;
			return *this;
		};


		Matrix<T, N, M>& operator++() {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					this->matrix[i][j]++;
			return *this;
		};

		T Det() {
			if (N != M)
			{
				std::cerr << "The matrix isn't square!";
				throw std::exception("The matrix isn't square!");
			}
			Matrix<T, N, M> tmp(*this);
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {

				}
			}
		};

		T& operator()(int i, int j) {
			return this->matrix[i][j];
		};

		void Print() {

		};
	};

	template<typename T, int N, int M>
	std::istream& operator>>(std::istream& in, Matrix<T, N, M>& matrix)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				in >> matrix.matrix[i][j];
			}
		}
		return in;
	}

	template<typename T, int N, int M>
	std::ostream& operator<<(std::ostream& out, Matrix<T, N, M>& matrix)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				out << matrix.matrix[i][j] << '\t';
			}
			out << '\n'
		}
		return out;
	}
}