#include "Paddle.h"

Paddle::Paddle(float in_width, float in_height, const sf::Vector2f& in_pos)
{
	paddle.setSize({ in_width,in_height });
	paddle.setPosition(in_pos);
	paddle.setFillColor(PaddleColor);
}
void Paddle::Draw(sf::RenderWindow & window) const
{
	window.draw(paddle);
}
void Paddle::SetPosition(const sf::Vector2f& in_pos)
{
	paddle.setPosition(in_pos);
}
sf::Vector2f Paddle::GetPos() const
{
	return paddle.getPosition();
}
float Paddle::GetWidth() const
{
	return paddle.getSize().x;
}
float Paddle::GetHeight() const
{
	return paddle.getSize().y;
}
void Paddle::Movement(float delta, float Left, float Right, float Top, float Bottom)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		float PaddlePosX = paddle.getPosition().x;
		if (PaddlePosX + GetWidth() > Right) // this is just give us the rightside of the paddle
		{
			float newPos = Right - GetWidth();
			paddle.setPosition({ newPos,paddle.getPosition().y });
		}
		else
			paddle.move({ speed * delta,0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (paddle.getPosition().x < Left)
		{
			paddle.setPosition({ Left,paddle.getPosition().y });
		}
		else
			paddle.move({ -speed * delta,0 });
			
	}
}