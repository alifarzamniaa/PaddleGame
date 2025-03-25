#pragma once
#include <SFML/Graphics.hpp>
class Paddle
{
public:
	Paddle(float in_width,float in_height,const sf::Vector2f& in_pos,const sf::Color& color, float speed)
	:
	speed(speed)
	{
		paddle.setSize({in_width,in_height });
		paddle.setPosition(in_pos);
		paddle.setFillColor(color);
	}
	void draw(sf::RenderWindow& window) const
	{
		window.draw(paddle);
	}
	void SetPosition(const sf::Vector2f& in_pos)
	{
		paddle.setPosition(in_pos);
	}
	sf::Vector2f GetPos() const
	{
		return paddle.getPosition();
	}
	void Movement(float delta,const sf::Window& window)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			float PaddlePosX = paddle.getPosition().x;
			float PaddleWidth = paddle.getSize().x;
			if(PaddlePosX + PaddleWidth > window.getSize().x) // this is just give us the rightside of the paddle
			{
				float newPos = window.getSize().x - PaddleWidth;
				paddle.setPosition({ newPos,paddle.getPosition().y});
			}
			else
				paddle.move({speed * delta,0});
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			if (paddle.getPosition().x < 0)
			{
				paddle.setPosition({ 0.f,paddle.getPosition().y });
			}
			else
				paddle.move({ -speed * delta,0 });
		}
	}
private:
	sf::RectangleShape paddle;
	float speed; 
};

