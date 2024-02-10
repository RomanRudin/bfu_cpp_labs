#pragma once

namespace mx
{
	class Matrix {
	private:
		int n, m;
		float** data;

	public:
		Matrix() = default;
		Matrix(int n, int m, float**& data);
		Matrix(int n, int m);
		Matrix(Matrix& other);

		~Matrix();

		Matrix& operator=(Matrix matrix);
		void Print();
	};
}
