#pragma once
#include <SFML/Graphics.hpp>
class Paddle
{
public:
	Paddle(float in_width,float in_height,const sf::Vector2f& in_pos);
	void Draw(sf::RenderWindow& window) const;
	void SetPosition(const sf::Vector2f& in_pos);
	void Movement(float delta, float Left, float Right, float Top, float Bottom);
	sf::Vector2f GetPos() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	sf::RectangleShape paddle;
	sf::Color PaddleColor = sf::Color(21, 245, 186);
	float speed = 850.f; 
};

