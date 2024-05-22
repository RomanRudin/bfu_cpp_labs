#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Bullet.hpp"

namespace mt
{
	class Ship
	{
		const int m_bulletR = 10;
		float m_v_bullet = 200;
		mt::Circle* m_c;

		float m_x, m_y;
		float m_alpha;
		float m_v;
		float m_r;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;
		float m_scaleFactor = 0.2f;
		bool Enemy_isVisible = true;
		float attack_time = 0.0;

		std::vector<Bullet> m_bullets;

	public:
		Ship() = default;
		// !!!
		Ship(float x, float y)
		{
			m_x = x;
			m_y = y;
		}

		bool Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
			m_alpha = 0;
			m_v = 0;

			// Загрузка текстуры кота
			if (!m_textureShip.loadFromFile("kot.png"))
			{
				std::cout << "Error while loading kot.png" << std::endl;
				return false;
			}
			m_spriteShip.setTexture(m_textureShip);

			m_spriteShip.setScale(m_scaleFactor, m_scaleFactor);
			m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2);
			m_spriteShip.setPosition(m_x, m_y);
			m_spriteShip.setRotation(m_alpha);

			if (m_textureShip.getSize().x > m_textureShip.getSize().y)
				m_r = m_scaleFactor * m_textureShip.getSize().x / 2;
			else
				m_r = m_scaleFactor * m_textureShip.getSize().y / 2;

			//bullet.Setup(100, 100, 20, 10, 10);
		}

		Bullet Attack()
		{
			if (this->attack_time <= 0) {
				float alphaRad = acos(-1) * m_alpha / 180;
				Bullet new_bullet = Bullet(m_x, m_y, m_bulletR, (m_v + m_v_bullet) * cos(alphaRad), (m_v + m_v_bullet) * sin(alphaRad));
				m_bullets.push_back(new_bullet); 
				this->attack_time = .5; // Изменить это число, чтобы стрелять быстрее или медленнее (время перезарядки в секундах)
				return new_bullet;
			}
		}

		void AttackCounter(float dt) {
			if (this->attack_time <= 0) return;
			this->attack_time -= dt;
		}

		void setVelocity(float dv)
		{
			m_v += dv;
		}

		void Move(float dt)
		{
			float alphaRad = acos(-1) * m_alpha / 180;
			m_x += m_v * cos(alphaRad) * dt;
			m_y += m_v * sin(alphaRad) * dt;
			m_spriteShip.setPosition(m_x, m_y);
		}

		float R() { return m_r; }
		float X() { return m_x; }
		float Y() { return m_y; }
		float A() { return m_alpha; }
		float V() { return m_v; }

		void Rotate(float dalpha)
		{
			m_alpha += dalpha;
			m_spriteShip.setRotation(m_alpha);
		}

		sf::Sprite Get()
		{
			return m_spriteShip;
		}

		std::vector<Bullet>& getBullets() {
			return m_bullets;
		}

		void destroyBullet(int index) {
			m_bullets.erase(m_bullets.begin() + index);
		}
	}; 
}