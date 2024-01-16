#pragma once

namespace fs
{
	float Pythagoras(float a, float b);

	class Square {
		float side;

	public:
		Square(float side);
		void Setup(float side);
		~Square();

		void SetSide(float side);

		float GetSide() {
			return this->side;
		}

		float Area();
		float Perimeter();
		float Diagonal();

		void Print();
	};


	class Rectangle {
		float width;
		float height;

	public:
		Rectangle(float width, float height);
		~Rectangle();
		void Setup(float width, float height);

		void SetWidth(float width);
		void SetHeight(float height);

		float GetWidth() {
			return this->width;
		}
		float GetHeight() {
			return this->height;
		}

		float Area();
		float Perimeter();
		float Diagonal();

		void Print();
	};


	class Cube {
		float side;

	public:
		Cube(float side);
		~Cube();
		void Setup(float side);

		void SetSide(float side);

		float GetSide() {
			return this->side;
		}

		float Area();
		float Volume();
		float Diagonal();

		void Print();
	};


	class Prism {
		Rectangle* base;
		float depth;

	public:
		Prism(float width, float height, float depth);
		~Prism();
		void Setup(Rectangle* base, float depth);

		void SetWidth(float width);
		void SetHeight(float height);
		void SetDepth(float depth);


		Rectangle* GetBase() {
			return this->base;
		}
		float GetDepth() {
			return this->depth;
		}

		float Area();
		float Volume();
		float Diagonal();

		void Print();
	};


	class Sphere {
		float radius;

	public:
		Sphere(float radius);
		~Sphere();
		void Setup(float radius);

		void SetRadius(float radius);

		float GetRadius() {
			return this->radius;
		}

		float Area();
		float Volume();

		void Print();
	};


	class Triangle {
		float sideA;
		float sideB;
		float angle;

	public:
		Triangle(float sideA, float sideB, float angle);
		~Triangle();
		void Setup(float sideA, float sideB, float angle);

		void SetSideA(float sideA);
		void SetSideB(float sideB);
		void SetAngle(float angle);

		float GetSideA() {
			return this->sideA;
		}
		float GetSideB() {
			return this->sideB;
		}
		float GetAngle() {
			return this->angle;
		}

		float Area();
		float Perimeter();

		void Print();
	};


	class Parallelogram {
		float sideA;
		float sideB;
		float angle;

	public:
		Parallelogram(float sideA, float sideB, float angle);
		~Parallelogram();
		void Setup(float sideA, float sideB, float angle);

		void SetSideA(float sideA);
		void SetSideB(float sideB);
		void SetAngle(float angle);

		float GetSideA() {
			return this->sideA;
		}
		float GetSideB() {
			return this->sideB;
		}
		float GetAngle() {
			return this->angle;
		}

		float Area();
		float Perimeter();

		void Print();
	};


	class Ellipse {
		float a;
		float b;

	public:
		Ellipse(float a, float b);
		~Ellipse();
		void Setup(float a, float b);

		void SetA(float a);
		void SetB(float b);

		float GetA() {
			return this->a;
		}
		float GetB() {
			return this->b;
		}

		float Area();
		float Perimeter();

		void Print();
	};


	class Tetrahedron {
		float side;

	public:
		Tetrahedron(float side);
		~Tetrahedron();
		void Setup(float side);

		void SetSide(float side);

		float GetSide() {
			return this->side;
		}

		float Area();
		float Volume();

		void Print();
	};


	class Cone {
		float radius;
		float height;

	public:
		Cone(float radius, float height);
		~Cone();
		void Setup(float radius, float height);

		void SetRadius(float radius);
		void SetHeight(float height);

		float GetRadius() {
			return this->radius;
		}
		float GetHeight() {
			return this->height;
		}

		float Area();
		float Volume();

		void Print();
	};
}