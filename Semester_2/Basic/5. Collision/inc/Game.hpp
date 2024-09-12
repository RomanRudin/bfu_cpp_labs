#pragma once
#include <string>
#include <iostream>
#include <hero.hpp>

namespace mt
{
	const float pi = acos(-1);

	class Game1
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle *m_kpyr;
		int m_n;
		sf::RenderWindow m_window;
		sf::Clock clock;

		sf::Texture m_bg_txr;
		sf::Sprite m_bg_spr;

		mt::Hero m_hero;

	public:
		Game1(int width, int height, const std::string& capture)
		{

			m_width = width;
			m_height = height;
			m_capture = capture;

		}

		bool Setup(int n)
		{
			m_n = n;


			//window setup
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setTitle(m_capture);

			//bg setup
			if (!m_bg_txr.loadFromFile("img\\bg.jpg"))
			{
				std::cout << "bg texture loading error" << std::endl;
				return 0;
			}
			m_bg_spr.setTexture(m_bg_txr);

			//hero setup
			if (!m_hero.Setup(0,0))
			{
				std::cout << "hero setup error" << std::endl;
				return 0;
			}

			srand(time(0));

			

			//circle setup
			m_kpyr = new mt::Circle[m_n];
			for (int i = 0; i < m_n; i++)
			{
				int r = rand() % 30 + 10;
				int x = rand() % 1000 + r;
				if (x - r < 0)
					x = r;
				if (x + r > m_width)
					x = m_width - r;
				int y = rand() % 720 + r;
				if (y - r < 0)
					y = r;
				if (y + r > m_height)
					y = m_height - r;

				int red = rand() % 225;
				int v = rand() % 100 - 200;
				int vAng = rand() % 7;
				m_kpyr[i].Setup(x, y, r, red, v, vAng);
			}
		}


		void brdrColl(Circle& obj)
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if ((x + r) >= m_width || (x - r) <= 0)
			{
				obj.vang(pi - obj.Alfa());
			}
			if ((y + r) >= m_height || (y - r) <= 0)
			{
				obj.vang(2*pi - obj.Alfa());
				
			}
			
		}

		//просчитываение столкновения с другим шаром

		void ownColl(Circle& obj1, Circle& obj2)
		{
			float x1 = obj1.X();
			float y1 = obj1.Y();
			float r1 = obj1.R();
			float va1 = obj1.Alfa();

			float x2 = obj2.X();
			float y2 = obj2.Y();
			float r2 = obj2.R();
			float va2 = obj2.Alfa();


			float Dx = x1 - x2;
			float Dy = y1 - y2;
			float d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;
			if (d < r1 + r2)
			{
				float tmp = va1;
				obj1.vang(va2);
				obj2.vang(tmp);
			}
			/*if (obj1.objBounds().contains(x2 + r2, y2 + r2))
			{
				
			}*/						
		}

		void heroColl(Hero& hero, Circle& obj)
		{
			if (hero.SpriteGet().getGlobalBounds().intersects(obj.objBounds()))
			{
				std::cout << "collide" << std::endl;

			}

		}

		void LifeCycle()
		{
			while (m_window.isOpen())
			{

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();

					//movement animation
					if (event.type == sf::Event::KeyReleased)
					{
						m_hero.MoveAnim(0);
					}
					if (event.type == sf::Event::KeyPressed)
					{
						std::cout << dt << std::endl;
						if ((int(dt*100000)) % 3 == 0)
							m_hero.MoveAnim(1);
						else
							m_hero.MoveAnim(2);
					}
				}

				

				//movement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					m_hero.Move(0,-0.1);

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					m_hero.Move(0,0.1);

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					m_hero.Move(0.1, 0);

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					m_hero.Move(-0.1, 0);

				}


				for (int i = 0; i < m_n; i++)
				{
					m_kpyr[i].Move(dt);
				}

				//collision

				for (int i = 0; i < m_n; i++)
				{
					brdrColl(m_kpyr[i]);
					heroColl(m_hero, m_kpyr[i]);
				}

				for (int i = 0; i < m_n; i++)
					for (int j = i+1; j < m_n; j++)
						ownColl(m_kpyr[i],m_kpyr[j]);

				
				//display

				m_window.clear();
				m_window.draw(m_bg_spr);
				m_window.draw(m_hero.Get());
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_kpyr[i].Get());

				m_window.display();
			}

			
		}

	};
}