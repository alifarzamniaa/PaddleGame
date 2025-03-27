#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
public:
	Ball(float rad,const sf::Vector2f& pos,float speed,const sf::Color& color);
	void Draw(sf::RenderWindow& window) const;
	void Movement(float delta,const sf::Window& window);

private:
	void Bouncing(float delta, const sf::Window& window);

private:
	sf::CircleShape ball;
	float radius;
	float speed;
	sf::Vector2f dir = {1.f,1.f};
	sf::Vector2f BallVel;
};

