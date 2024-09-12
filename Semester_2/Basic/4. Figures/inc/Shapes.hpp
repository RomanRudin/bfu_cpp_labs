#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Circle
	{
		float m_r;
		float m_x, m_y;
		int m_red;
		sf::CircleShape m_shape;
	public:
		Circle() = default;

		Circle(float x, float y, float r, int red)
		{
			Setup(x, y, r, red);
		}

		void Setup(float x, float y, float r, int red)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_red = red;
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Color(m_red, 0, 90, 225));
		}

		sf::CircleShape Get()
		{
			return m_shape;
		}
	};



	class Rectangle
	{
		float m_x;
		float m_y;
		int m_red;
		float m_recth;
		float m_rectw;
		float m_angle;

		sf::RectangleShape m_shape;
	public:
		Rectangle() = default;

		Rectangle(float x, float y,int red, float recth, float rectw, float angle)
		{
			Setup(x, y, red, recth, rectw, angle);
		}

		void Setup(float x, float y, int red, float recth, float rectw, float angle)
		{
			m_x = x;
			m_y = y;
			m_recth = recth;
			m_rectw = rectw;
			m_angle = angle;
			m_red = red;
			m_shape.setPosition(m_x, m_y);
			m_shape.setRotation(m_angle);
			m_shape.setSize(sf::Vector2f(m_recth, m_rectw));
			m_shape.setFillColor(sf::Color::Color(m_red, 0, 90, 225));
		}

		sf::RectangleShape Get()
		{
			return m_shape;
		}
	};


	class Triangle
	{
		float m_x;
		float m_y;
		float m_r;
		int m_red;
		float m_angle;
		sf::CircleShape m_shape;

	public:
		Triangle() = default;

		Triangle(float x, float y, float r, int red, float angle)
		{
			Setup(x, y, r, red, angle);
		}

		void Setup(float x, float y, float r, int red, float angle)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_red = red;
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			m_shape.setRotation(m_angle);
			m_shape.setFillColor(sf::Color::Color(m_red, 0, 90, 225));
			m_shape.setPointCount(3);

		}

		sf::CircleShape Get()
		{
			return m_shape;
		}
	};


	class Line
	{
		float m_x;
		float m_y;
		int m_red;
		float m_linelen;
		float m_angle;

		sf::RectangleShape m_shape;
	public:
		Line() = default;

		Line(float x, float y, int red, float linelen, float angle)
		{
			Setup(x, y, red, linelen, angle);
		}

		void Setup(float x, float y, int red, float linelen, float angle)
		{
			m_x = x;
			m_y = y;
			m_linelen = linelen;
			m_angle = angle;
			m_red = red;
			m_shape.setPosition(m_x, m_y);
			m_shape.setRotation(m_angle);
			m_shape.setSize(sf::Vector2f(m_linelen, 1));
			m_shape.setFillColor(sf::Color::Color(m_red, 0, 90, 225));
		}

		sf::RectangleShape Get()
		{
			return m_shape;
		}
	};
}