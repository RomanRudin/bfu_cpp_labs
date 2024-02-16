#include "figures.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

namespace fs {

	float Pythagoras(float a, float b) {
		return sqrt(pow(a, 2) + pow(b, 2));
	}

	//	Square
	void Square::Setup(float side) {
		this->side = side;
	}
	Square::Square(float side) {
		if (side > 0) {
			Setup(side);
		}
	}
	Square::~Square() {}

	void Square::SetSide(float side) {
		if (side > 0) {
			this->side = side;
		}
	}

	float Square::Area() {
		return pow(this->side, 2);
	}
	float Square::Perimeter() {
		return this->side * 4;
	}
	float Square::Diagonal() {
		return this->side * sqrt(2);
	}

	void Square::Print() {
		std::cout << "Square:" << "\t" << this->side << std::endl;
	}



	//Rectangle
	void Rectangle::Setup(float width, float height) {
		this->width = width;
		this->height = height;
	}
	Rectangle::Rectangle(float width, float height) {
		if ((width > 0) && (height > 0)) {
			Setup(width, height);
		}
	}
	Rectangle::~Rectangle() {}

	void Rectangle::SetWidth(float width) {
		if (width > 0) {
			this->width = width;
		}
	}
	void Rectangle::SetHeight(float height) {
		if (height > 0) {
			this->height = height;
		}
	}

	float Rectangle::Area() {
		return this->width * this->height;
	}
	float Rectangle::Perimeter() {
		return (this->width + this->height) * 2;
	}
	float Rectangle::Diagonal() {
		return sqrt(this->width * this->height);
	}

	void Rectangle::Print() {
		std::cout << "Rectangle:" << "\t" << this->width << "\t" << this->height << std::endl;
	}



	//	Cube
	void Cube::Setup(float side) {
		this->side = side;
	}
	Cube::Cube(float side) {
		if (side > 0) {
			Setup(side);
		}
	}
	Cube::~Cube() {}

	void Cube::SetSide(float side) {
		if (side > 0) {
			this->side = side;
		}
	}

	float Cube::Area() {
		return pow(this->side, 2) * 6;
	}
	float Cube::Volume() {
		return pow(this->side, 3);
	}
	float Cube::Diagonal() {
		return this->side * sqrt(3);
	}

	void Cube::Print() {
		std::cout << "Cube:" << "\t" << this->side << std::endl;
	}



	//	Prism
	void Prism::Setup(Rectangle* base, float depth) {
		this->base = base;
		this->depth = depth;
	}
	Prism::Prism(float width, float height, float depth) {
		if ((width > 0) && (height > 0) && (depth > 0)) {
			Rectangle* base = new Rectangle(width, height);
			Setup(base, depth);
		}
	}
	Prism::~Prism() {
		delete this->base;
	}

	void Prism::SetWidth(float width) {
		if (width > 0) {
			this->base->SetWidth(width);
		}
	}
	void Prism::SetHeight(float height) {
		if (height > 0) {
			this->base->SetHeight(height);
		}
	}
	void Prism::SetDepth(float depth) {
		if (depth > 0) {
			this->depth = depth;
		}
	}

	float Prism::Area() {
		return (this->base->Area() * 2) + (this->base->GetHeight() * this->depth * 2) + (this->base->GetWidth() * this->depth * 2);
	}
	float Prism::Volume() {
		return this->base->Area() * this->depth;
	}
	float Prism::Diagonal() {
		return sqrt(this->base->GetHeight() + this->base->GetWidth() + this->depth);
	}

	void Prism::Print() {
		std::cout << "Prism with base:" << std::endl;
		std::cout << "\t";
		this->base->Print();
		std::cout << "\t" << this->depth << std::endl;
	}



	//	Sphere
	void Sphere::Setup(float radius) {
		this->radius = radius;
	}
	Sphere::Sphere(float radius) {
		if (radius > 0) {
			Setup(radius);
		}
	}
	Sphere::~Sphere() {}

	void Sphere::SetRadius(float radius) {
		if (radius > 0) {
			this->radius = radius;
		}
	}

	float Sphere::Area() {
		return 4 * PI * pow(this->radius, 2);
	}
	float Sphere::Volume() {
		return (4 / 3) * PI * pow(this->radius, 3);
	}

	void Sphere::Print() {
		std::cout << "Sphere:" << "\t" << this->radius << std::endl;
	}



	//	Triangle
	void Triangle::Setup(float sideA, float sideB, float angle) {
		this->sideA = sideA;
		this->sideB = sideB;
		this->angle = angle;
	}
	Triangle::Triangle(float sideA, float sideB, float angle) {
		if ((sideA > 0) && (sideB > 0) && (angle > 0) && (angle < 180)) {
			Setup(sideA, sideB, angle);
		}
	}
	Triangle::~Triangle() {}

	void Triangle::SetSideA(float sideA) {
		if (sideA > 0) {
			this->sideA = sideA;
		}
	}
	void Triangle::SetSideB(float sideB) {
		if (sideB > 0) {
			this->sideB = sideB;
		}
	}
	void Triangle::SetAngle(float angle) {
		if (angle > 0) {
			this->angle = angle;
		}
	}

	float Triangle::Area() {
		return this->sideA * this->sideB * sin(this->angle / (2 * Pi)) / 2;
	}
	float Triangle::Perimeter() {
		return this->sideA + this->sideB + sqrt(pow(this->sideA, 2) + pow(this->sideB, 2) - 2 * this->sideA * this->sideB * cos(this->angle));
	}

	void Triangle::Print() {
		std::cout << "Triangle" << "\t" << this->sideA << "\t" << this->sideB << "\t" << this->angle << std::endl;
	}



	//	Parallelogram
	void Parallelogram::Setup(float sideA, float sideB, float angle) {
		this->sideA = sideA;
		this->sideB = sideB;
		this->angle = angle;
	}
	Parallelogram::Parallelogram(float sideA, float sideB, float angle) {
		if ((sideA > 0) && (sideB > 0) && (angle > 0) && (angle < 180)) {
			Setup(sideA, sideB, angle);
		}
	}
	Parallelogram::~Parallelogram() {}

	void Parallelogram::SetSideA(float sideA) {
		if (sideA > 0) {
			this->sideA = sideA;
		}
	}
	void Parallelogram::SetSideB(float sideB) {
		if (sideB > 0) {
			this->sideB = sideB;
		}
	}
	void Parallelogram::SetAngle(float angle) {
		if (angle > 0) {
			this->angle = angle;
		}
	}

	float Parallelogram::Area() {
		return this->sideA * this->sideB * sin(this->angle / (2 * PI));
	}
	float Parallelogram::Perimeter() {
		return (this->sideA + this->sideB) * 2;
	}

	void Parallelogram::Print() {
		std::cout << "Parallelogram" << "\t" << this->sideA << "\t" << this->sideB << "\t" << this->angle << std::endl;
	}



	//	Ellipse
	void Ellipse::Setup(float a, float b) {
		this->a = a;
		this->b = b;
	}
	Ellipse::Ellipse(float a, float b) {
		if ((a > 0) && (b > 0)) {
			Setup(a, b);
		}
	}
	Ellipse::~Ellipse() {}

	void Ellipse::SetA(float a) {
		if (a > 0) {
			this->a = a;
		}
	}
	void Ellipse::SetB(float b) {
		if (b > 0) {
			this->b = b;
		}
	}

	float Ellipse::Area() {
		return PI * this->a * this->b;
	}
	float Ellipse::Perimeter() {
		return 2 * PI * sqrt((pow(this->a, 2) + pow(this->b, 2)) / 2);
	}

	void Ellipse::Print() {
		std::cout << "Ellipse" << "\t" << this->a << "\t" << this->b << std::endl;
	}



	//	Tetrahedron
	void Tetrahedron::Setup(float side) {
		this->side = side;
	}
	Tetrahedron::Tetrahedron(float side) {
		if (side > 0) {
			Setup(side);
		}
	}
	Tetrahedron::~Tetrahedron() {}

	void Tetrahedron::SetSide(float side) {
		if (side > 0) {
			this->side = side;
		}
	}

	float Tetrahedron::Area() {
		return pow(this->side, 2) * sqrt(3);
	}
	float Tetrahedron::Volume() {
		return pow(this->side, 3) / (6 * sqrt(2));
	}

	void Tetrahedron::Print() {
		std::cout << "Tetrahedron" << "\t" << this->side << std::endl;
	}



	//	Cone
	void Cone::Setup(float radius, float height) {
		this->radius = radius;
		this->height = height;
	}
	Cone::Cone(float radius, float height) {
		if ((radius > 0) && (height > 0)) {
			Setup(radius, height);
		}
	}
	Cone::~Cone() {}

	void Cone::SetRadius(float radius) {
		if (radius > 0) {
			this->radius = radius;
		}
	}
	void Cone::SetHeight(float height) {
		if (height > 0) {
			this->height = height;
		}
	}

	float Cone::Area() {
		return (PI * pow(this->radius, 2)) + (PI * this->radius * Pythagoras(this->radius, this->height));
	}
	float Cone::Volume() {
		return (1 / 3) * PI * pow(this->radius, 2) * this->height;
	}

	void Cone::Print() {
		std::cout << "Cone" << "\t" << this->radius << "\t" << this->height << std::endl;
	}
};