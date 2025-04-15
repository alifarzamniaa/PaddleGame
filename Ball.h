#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Box.h"
class Ball
{
public:
	Ball(float rad,const sf::Vector2f& pos,const sf::Color& color);
	void Draw(sf::RenderWindow& window) const;
	void Movement(float delta, const Paddle& paddle);
	bool BoxCollision(const Box& box);
	bool WallCollision(float Left, float Right, float Top, float Bottom);
	
	void SetSpeed(float val);
private:
	void PaddleCollision(const Paddle& paddle); // TODO it this necessary?
private:
	sf::CircleShape ball;
	
	float speed = 600.f;
	float radius;
	float SpeedUpOnHit = 10.f;

	sf::Vector2f BallVel;
};

