#pragma once

namespace fs
{
	class Matrix {
	private:
		int n, m;
		float** data;

	public:
		Matrix() = default;
		Matrix(float** &data, int n, int m);
		Matrix(int n, int m);
		Matrix(Matrix& other) : Matrix(other.data, other.n, other.m) {};

		~Matrix();

		Matrix& operator=(Matrix matrix);
		void Print();
	};
}