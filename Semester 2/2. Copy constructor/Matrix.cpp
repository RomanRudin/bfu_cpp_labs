#include "Matrix.hpp"
#include <iostream>

namespace fs
{
	//Matrix::Matrix() {
	//	this->n = 1;
	//	this->m = 1;
	//	this->data = new float* [1];
	//	this->data[0] = new float[1];
	//	this->data[0][0] = 0;
	//};

	Matrix::Matrix(int n, int m) {
		this->n = n;
		this->m = m;
		this->data = new float* [this->n];
		
		for (int i = 0; i < this->n; i++)
			this->data[i] = new float[this->m];

		std::cout << "Please, enter the numbers: " << std::endl;
		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->m; j++)
				std::cin >> this->data[i][j];
	};

	Matrix::Matrix(float** &data, int n, int m) {
		this->n = n;
		this->m = m;
		this->data = new float* [this->n];
		for (int i = 0; i < this->n; i++)
			this->data[i] = new float[this->m];

		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->m; j++)
				this->data[i][j] = data[i][j];
	};

	Matrix::~Matrix() {
		for (int i = 0; i < this->n; i++)
			delete[] this->data[i];
		delete[] this->data;
	};

	Matrix& Matrix::operator=(Matrix other) {

		for (int i = 0; i < this->n; i++)
			delete[] this->data[i];
		delete[] this->data;

		this->n = other.n;
		this->m = other.m;

		this->data = new float* [this->n];
		for (int i = 0; i < this->n; i++)
			this->data[i] = new float[this->m];

		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->m; j++)
				this->data[i][j] = other.data[i][j];

		return *this;
	};

	void Matrix::Print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
				std::cout << data[i][j] << "\t";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	};
}