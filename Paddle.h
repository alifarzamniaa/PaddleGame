#pragma once
#include <SFML/Graphics.hpp>
#include "PlayGround.h"
class Paddle
{
public:
	Paddle(float in_width,float in_height,const sf::Vector2f& in_pos,const sf::Color& color, float speed);
	void draw(sf::RenderWindow& window) const;
	void SetPosition(const sf::Vector2f& in_pos);
	void Movement(float delta, const PlayGround& Area);
	sf::Vector2f GetPos() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	sf::RectangleShape paddle;
	float speed; 
};

