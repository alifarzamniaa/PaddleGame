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
	void SetSpeed(float val);
	
	bool BoxCollision(const Box& box);
	bool WallCollision(float Left, float Right, float Top, float Bottom);
	
	float GetInitSpeed() const;
	sf::Vector2f GetBallPos() const; 
private:
	void PaddleCollision(const Paddle& paddle); // TODO it this necessary?
private:
	sf::CircleShape ball;
	
	float speed = 600.f; 
	float SpeedUpOnHit = 5.f; // change this for ball speed up change after hit


	float radius;
	float InitSpeed;

	sf::Vector2f BallVel;
};

