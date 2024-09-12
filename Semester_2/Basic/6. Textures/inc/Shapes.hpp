#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Circle
	{
		float m_r;
		float m_x, m_y;
		float m_v;
		float m_vAng;
		int m_red;
		sf::CircleShape m_shape;
		sf::Texture m_shape_txr;

	public:
		Circle() = default;

		Circle(float x, float y, float r, int red, float v, float vAng)
		{
			Setup(x, y, r, red, v, vAng);
		}

		void Setup(float x, float y, float r, int red, float v,float vAng)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_v = v;
			m_vAng = vAng;
			m_red = red;
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			m_shape.setOrigin(m_r, m_r);
			m_shape.setFillColor(sf::Color::Color(m_red, 0, 90, 225));
			m_shape_txr.loadFromFile("img\\monster.png");
			m_shape.setTexture(&m_shape_txr);
		}

		float X() { return m_x; }
		float Y() { return m_y; }
		float R() { return m_r; }
		float Alfa() { return m_vAng; }
		float V() { return m_v; }
		float Vang() { return m_vAng; }

		void vang(float alfa)
		{
			m_vAng = alfa;
		}


		void movex(float x)
		{
			m_x += x;
		}


		void Move(float dt)
		{
			float vx = m_v * cos(m_vAng);
			float vy = m_v * sin(m_vAng);
			m_x += vx*dt;
			m_y += vy*dt;
			m_shape.setPosition(m_x, m_y);
		}

		sf::FloatRect objBounds()
		{
			return m_shape.getGlobalBounds();
		}

		sf::CircleShape Get()
		{
			return m_shape;
		}
	};
}