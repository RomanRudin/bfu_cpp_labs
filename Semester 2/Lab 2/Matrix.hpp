#pragma once

namespace fs
{
	class Matrix {
	private:
		int n, m;
		float** data;

	public:
		Matrix() = default;
		Matrix(const float** data);
		Matrix(const Matrix& other) : Matrix(other.data);

		~Matrix();

		Matrix& operator=(Matrix matrix);
	};
}