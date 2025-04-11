#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "PlayGround.h"
class Ball
{
public:
	Ball(float rad,const sf::Vector2f& pos,const sf::Color& color);
	void Draw(sf::RenderWindow& window) const;
	void Movement(float delta, const PlayGround& Area, const Paddle& paddle);
	void CheckBoxCollision(PlayGround& Area);
	bool GetFloorHit();
private:
	void Bouncing(float delta, const PlayGround& Area);
	void CheckPaddleCollision(const Paddle& paddle);
private:
	sf::CircleShape ball;
	float speed = 600.f;
	float radius;
	sf::Vector2f dir = {1.f,1.f};
	sf::Vector2f BallVel;


	float SpeedUpOnHit = 0.f;
	bool IsHitFloor = false;
};

