#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>

class Vec2
{
public:
	float x = 0;
	float y = 0;

	Vec2() {}
	Vec2(float xin, float yin)
		: x(xin)
		, y(yin)
	{

	}

	Vec2 operator - (const Vec2& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	float length() const
	{
		return sqrtf(x * x + y * y);
	}

};


class player
{
public:
	Vec2 position = { 0,0 };
	int Velocity = 0;
	sf::CircleShape s;
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	player(const Vec2& p, int v, int radius)
		: position(p)
		, Velocity(v)
		, s(radius, 50)
	{
		s.setFillColor(sf::Color::Yellow);
		s.setOutlineColor(sf::Color::Yellow);
		s.setOutlineThickness(1.0);
		s.setOrigin(radius, radius);
		s.setPosition(sf::Vector2f(position.x, position.y));
	}
};





int main(int argc, char* argv[])
{
	// draw a window
	const int wWidth = 800;
	const int wHight = 700;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHight), "SFML works!");
	window.setFramerateLimit(60);

	// draw a background image
	const std::string& BackgroundName = "Data/Background.png";
	sf::Texture BackgroundImage;
	BackgroundImage.loadFromFile(BackgroundName);
	sf::Sprite cosmos(BackgroundImage);

	// draw the player
	player spaceShip(Vec2(100, 100), 5, 10);




	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					spaceShip.up = true;
					break;
				case sf::Keyboard::S:
					spaceShip.down = true;
					break;
				case sf::Keyboard::A:
					spaceShip.left = true;
					break;
				case sf::Keyboard::D:
					spaceShip.right = true;
					break;
				default: break;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					spaceShip.up = false;
					break;
				case sf::Keyboard::S:
					spaceShip.down = false;
					break;
				case sf::Keyboard::A:
					spaceShip.left = false;
					break;
				case sf::Keyboard::D:
					spaceShip.right = false;
					break;
				default: break;
				}
			}

		}

		if (spaceShip.up)
		{
			spaceShip.position.y -= spaceShip.Velocity;
			std::cout << spaceShip.position.y << std::endl;
		}

		if (spaceShip.down)
		{
			spaceShip.position.y += spaceShip.Velocity;
		}

		if (spaceShip.right)
		{
			spaceShip.position.x += spaceShip.Velocity;
		}

		if (spaceShip.left)
		{
			spaceShip.position.x -= spaceShip.Velocity;
		}

		spaceShip.s.setPosition(spaceShip.position.x, spaceShip.position.y);

		//std::cout << blocks.size() << std::endl;

		window.clear();

		window.draw(cosmos);



		window.draw(spaceShip.s);
		window.display();
	}
}