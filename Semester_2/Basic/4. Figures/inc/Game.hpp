#pragma once
#include <string>

namespace mt
{

	class Game1
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle *m_kpyr;
		int m_n;
		sf::RenderWindow m_window;

	public:
		Game1(int width, int height, const std::string& capture)
		{

			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setTitle(m_capture);

			srand(time(0));

			m_kpyr = new mt::Circle[m_n];
			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 720;
				int r = rand() % 300 + 1;
				int red = rand() % 225;
				m_kpyr[i].Setup(x, y, r, red);
			}
		}

		void LifeCycle()
		{
			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_kpyr[i].Get());
				m_window.display();
			}
		}

	};


	class Game2
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Rectangle* m_rect;
		int m_n;
		sf::RenderWindow m_window;
	public:
		Game2(int width, int height, const std::string& capture)
		{

			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setTitle(m_capture);

			srand(time(0));

			m_rect = new mt::Rectangle[m_n];
			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 720;
				int recth = rand() % 300 + 1;
				int rectw = rand() % 300 + 1;
				int angle = rand() % 360;
				int red = rand() % 225;
				m_rect[i].Setup(x, y, red, recth, rectw, angle);
			}
		}

		void LifeCycle()
		{
			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_rect[i].Get());
				m_window.display();
			}
		}
	};

	
	class Game3
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Triangle* m_trig;
		int m_n;
		sf::RenderWindow m_window;

	public:
		Game3(int width, int height, const std::string& capture)
		{

			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setTitle(m_capture);

			srand(time(0));

			m_trig = new mt::Triangle[m_n];
			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 720;
				int r = rand() % 300 + 1;
				int red = rand() % 225;
				int angle = rand() % 360;
				m_trig[i].Setup(x, y, r, red, angle);
			}
		}

		void LifeCycle()
		{
			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_trig[i].Get());
				m_window.display();
			}
		}
	};

	class Game4
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Line* m_line;
		int m_n;
		sf::RenderWindow m_window;
	public:
		Game4(int width, int height, const std::string& capture)
		{

			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setTitle(m_capture);

			srand(time(0));

			m_line = new mt::Line[m_n];
			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 720;
				int linelen = rand() % 300 + 1;
				int angle = rand() % 360;
				int red = rand() % 225;
				m_line[i].Setup(x,y,red,linelen,angle);
			}
		}

		void LifeCycle()
		{
			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_line[i].Get());
				m_window.display();
			}
		}
	};
}