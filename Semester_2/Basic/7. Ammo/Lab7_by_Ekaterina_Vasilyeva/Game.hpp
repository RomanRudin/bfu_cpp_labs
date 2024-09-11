#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <thread>
#include <iostream>
#include "Ship.hpp"
#include "Bullet.hpp"
#include "Circle.hpp"

namespace mt
{

	const float pi = acos(-1);

	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		std::vector<mt::Circle> m_c;
		sf::RenderWindow m_window;
		sf::Texture m_textureBackground;
		sf::Sprite m_spriteBackground;
		sf::Font m_font;
		sf::Text m_fpsText;
		Ship m_ship;
		bool isVisible = true;
		bool isTouchBorder = true;

	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		bool Setup(int n)
		{
			// Создание окна
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			//Загрузка текстуры фона

			if (!m_textureBackground.loadFromFile("imagine.jpg"))
			{
				std::cout << "Error while loading imagine.jpg" << std::endl;
				return false;
			}
			m_spriteBackground.setTexture(m_textureBackground);

			// Создание корабля игрока
			if (!m_ship.Setup(100, 100))
				return false;

			srand(time(0));
			for (int i = 0; i < n; i++)
			{
				int r = rand() % 100 + 40;
				int x = rand() % (1000 - 2 * r) + r;
				int y = rand() % (600 - 2 * r) + r;
				int v = rand() % 50 + 100;
				float alfa = rand() % 2;
				Circle* c = new Circle(x, y, r, v, alfa);
				m_c.push_back(*c);
			}
		}
		/*
		void Shot()
		{
			float alphaRad = acos(-1) * m_ship.A() / 180;
			float m_v_bullet = 200;
			int x_s = m_ship.X();
			int y_s = m_ship.X();
			int r_b = m_bullet.R();
			int v_s = m_ship.V();
			if (m_bullet.Available())
				m_bullet.Setup(x_s, y_s, r_b, (v_s + m_v_bullet) * cos(alphaRad), (v_s + m_v_bullet) * sin(alphaRad));
		}*/

		void TouchBorder(Circle& obj)
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if (isTouchBorder)
			{
				isTouchBorder = false;

				if (x + r >= m_width || x - r <= 0)
				{
					obj.Alfa(pi - obj.Alfa());
				}

				if (y + r >= m_height || y - r <= 0)
				{
					obj.Alfa(2 * pi - obj.Alfa());
				}
			}
			else
			{
				if (x + r + 20 <= m_width || x - r - 20 >= 0)
				{
					isTouchBorder = true;
				}

				if (y + r + 20 <= m_height || y - r - 20 >= 0)
				{
					isTouchBorder = true;
				}
			}

		}

		void Collision(int i)
		{
			Circle& c = m_c.at(i);
			float dist = sqrt(pow(m_ship.X() - c.X(), 2) + pow(m_ship.Y() - c.Y(), 2));
			std::cout << "Collision " << m_ship.V() << std::endl;
			if (m_ship.R() + c.R() >= dist)
			{
				std::cout << "Collision " << m_ship.V() << std::endl;
				isVisible = false;
			}
		}
		
		void Bullet_collision(int i, int j)
		{
			Bullet bullet = m_ship.getBullets().at(j);
			Circle& c = m_c.at(i);
			float dist2 = sqrt(pow(bullet.X() - c.X(), 2) + pow(bullet.Y() - c.Y(), 2));
			if (c.R() + bullet.R() >= dist2)
			{
				std::cout << "Bullet collided with circle number " << i << " out of totel " << m_c.size() << std::endl;
				m_c.erase(m_c.begin() + i);
				m_ship.destroyBullet(j);
			}
		}

		void LifeCycle()
		{
			sf::Clock clock;


			while (m_window.isOpen())
			{
				// Обработка событий
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				// Обработка клавиатуры
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					m_ship.setVelocity(0.1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					m_ship.setVelocity(-0.1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					m_ship.Rotate(-0.2);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					m_ship.Rotate(0.2);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					m_ship.Attack();
				}
			/*	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					m_ship.BulletReset();
				}*/

				float dt = clock.restart().asSeconds();

				for (int i = 0; i < m_c.size(); i++)
					TouchBorder(m_c[i]);

				for (int i = 0; i < m_c.size(); i++)
				{
					float x = m_c[i].X();
					float y = m_c[i].Y();
					float r = m_c[i].R();
					float v = m_c[i].V();
					float alfa = m_c[i].Alfa();

					float x_s = x + v * cos(alfa) * dt;
					float y_s = y + v * sin(alfa) * dt;

					bool collision = false;
					if (x_s + r >= m_width)
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(m_width - r);
						collision = true;
					}

					if (x_s - r <= 0)
					{
						m_c[i].Alfa(pi - m_c[i].Alfa());
						m_c[i].X(r);
						collision = true;
					}

					if (y_s + r >= m_height)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(m_height - r);
						collision = true;
					}

					if (y_s - r <= 0)
					{
						m_c[i].Alfa(2 * pi - m_c[i].Alfa());
						m_c[i].Y(r);
						collision = true;
					}

					if (!collision)
					{
						m_c[i].X(x_s);
						m_c[i].Y(y_s);
					}
				}

				/*for (int i = 0; i < m_n; i++)
					Collision(i);*/

                m_ship.Move(dt);  
				for (Bullet &bullet : m_ship.getBullets())
					bullet.Move(dt);
				m_ship.AttackCounter(dt);
				
				for (int i = 0; i < m_c.size(); i++)
					for (int j = 0; j < m_ship.getBullets().size(); j++)
						Bullet_collision(i, j);

				// Перемещение корабля
				m_fpsText.setString(std::to_string(1 / dt));

				// Отображение
				m_window.clear();
				m_window.draw(m_spriteBackground);
				m_window.draw(m_fpsText);
				
				
				for (Bullet &bullet : m_ship.getBullets())
					m_window.draw(bullet.Get());

				if (isVisible)
					m_window.draw(m_ship.Get());
				for (Circle& circle : m_c)
				{
					m_window.draw(circle.Get());
				}
				m_window.display();
			}
		}
	};
}