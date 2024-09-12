#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

namespace mt
{
	class Hero 
	{

		float m_x, m_y;
		float m_v;
		float m_vAng;

		
		sf::Texture m_hero_txr;
		sf::Sprite m_hero_spr;

	public:
		Hero() = default;

		Hero(float x, float y)
		{
			Setup(x, y);
		}

		bool Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
	
			m_hero_spr.setPosition(m_x, m_y);

			if (!m_hero_txr.loadFromFile("img\\still.png"))
			{
				std::cout << "hero texture loading error" << std::endl;
				return 0;
			}
			m_hero_spr.setTexture(m_hero_txr);

			m_hero_spr.setScale(2.0f, 2.0f);
			m_hero_spr.setOrigin(m_hero_txr.getSize().x / 2, m_hero_txr.getSize().y / 2);
			

		}

		sf::Sprite SpriteGet() { return m_hero_spr; }

		void Move(float dx, float dy)
		{
			
			m_x += dx;
			m_y += dy;
			m_hero_spr.setPosition(m_x, m_y);
		}

		void MoveAnim(int a)
		{
			if (a == 1)
			{
				m_hero_txr.loadFromFile("img\\go_1.png");
				m_hero_spr.setTexture(m_hero_txr);
			}
			if (a == 0)
			{
				m_hero_txr.loadFromFile("img\\still.png");
				m_hero_spr.setTexture(m_hero_txr);
			}
			if (a == 2)
			{
				m_hero_txr.loadFromFile("img\\go_2.png");
				m_hero_spr.setTexture(m_hero_txr);
			}

		}





		sf::Sprite Get()
		{
			return m_hero_spr;
		}
	};
}