#include <iostream>
#include "figures.hpp"

int main()
{
	std::cout << "Enter the side of the square:" << std::endl;
	float side;
	std::cin >> side;
	fs::Square square(side);
	std::cout << "Area is: " << "\t" << square.Area() << std::endl;
	std::cout << "Perimeter is: " << "\t" << square.Perimeter() << std::endl;
	std::cout << "Diagonal is: " << "\t" << square.Diagonal() << std::endl;


	std::cout << "Enter the sides of the rectangle:" << std::endl;
	float width, heigth;
	std::cin >> width >> heigth;
	fs::Rectangle rectangle(width, heigth);
	std::cout << "Area is: " << "\t" << rectangle.Area() << std::endl;
	std::cout << "Perimeter is: " << "\t" << rectangle.Perimeter() << std::endl;
	std::cout << "Diagonal is: " << "\t" << rectangle.Diagonal() << std::endl;


	std::cout << "Enter the side of the cube:" << std::endl;
	std::cin >> side;
	fs::Cube cube(side);
	std::cout << "Area is: " << "\t" << cube.Area() << std::endl;
	std::cout << "Volume is: " << "\t" << cube.Volume() << std::endl;
	std::cout << "Diagonal is: " << "\t" << cube.Diagonal() << std::endl;


	std::cout << "Enter the sides of the prism:" << std::endl;
	float depth;
	std::cin >> width >> heigth >> depth;
	fs::Prism prism(width, heigth, depth);
	std::cout << "Area is: " << "\t" << prism.Area() << std::endl;
	std::cout << "Volume is: " << "\t" << prism.Volume() << std::endl;
	std::cout << "Diagonal is: " << "\t" << prism.Diagonal() << std::endl;


	std::cout << "Enter the radius of the sphere:" << std::endl;
	float radius;
	std::cin >> radius;
	fs::Sphere sphere(radius);
	std::cout << "Area is: " << "\t" << sphere.Area() << std::endl;
	std::cout << "Volume is: " << "\t" << sphere.Volume() << std::endl;


	std::cout << "Enter the sides and angle of the triangle:" << std::endl;
	float sideA, sideB, angle;
	std::cin >> sideA >> sideB >> angle;
	fs::Triangle triangle(sideA, sideB, angle);
	std::cout << "Area is: " << "\t" << triangle.Area() << std::endl;
	std::cout << "Perimeter is: " << "\t" << triangle.Perimeter() << std::endl;


	std::cout << "Enter the sides and angle of the parallelogram:" << std::endl;
	std::cin >> sideA >> sideB >> angle;
	fs::Parallelogram parallelogram(sideA, sideB, angle);
	std::cout << "Area is: " << "\t" << parallelogram.Area() << std::endl;
	std::cout << "Perimeter is: " << "\t" << parallelogram.Perimeter() << std::endl;


	std::cout << "Enter the sides and angle of the ellipse:" << std::endl;
	float a, b;
	std::cin >> a >> b;
	fs::Ellipse ellipse(a, b);
	std::cout << "Area is: " << "\t" << ellipse.Area() << std::endl;
	std::cout << "Perimeter is: " << "\t" << ellipse.Perimeter() << std::endl;


	std::cout << "Enter the side and angle of the tetrahedron:" << std::endl;
	std::cin >> side;
	fs::Tetrahedron tetrahedron(side);
	std::cout << "Area is: " << "\t" << tetrahedron.Area() << std::endl;
	std::cout << "Volume is: " << "\t" << tetrahedron.Volume() << std::endl;


	std::cout << "Enter the radius and height and angle of the cone:" << std::endl;
	float height;
	std::cin >> radius >> heigth;
	fs::Cone cone(radius, heigth);
	std::cout << "Area is: " << "\t" << cone.Area() << std::endl;
	std::cout << "Volume is: " << "\t" << cone.Volume() << std::endl;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
