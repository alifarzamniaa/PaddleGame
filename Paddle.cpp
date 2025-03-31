#include "Paddle.h"

Paddle::Paddle(float in_width, float in_height, const sf::Vector2f& in_pos, const sf::Color& color, float speed)
	:
	speed(speed)
{
	paddle.setSize({ in_width,in_height });
	paddle.setPosition(in_pos);
	paddle.setFillColor(color);
}
void Paddle::draw(sf::RenderWindow & window) const
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
void Paddle::Movement(float delta, const PlayGround& Area)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		float PaddlePosX = paddle.getPosition().x;
		if (PaddlePosX + GetWidth() > Area.GetWidth() + (Area.GetOffset().x / 2)) // this is just give us the rightside of the paddle
		{
			float newPos = Area.GetWidth() + (Area.GetOffset().x / 2) - GetWidth();
			paddle.setPosition({ newPos,paddle.getPosition().y });
		}
		else
			paddle.move({ speed * delta,0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (paddle.getPosition().x < Area.GetPosition().x - (Area.GetWidth() / 2))
		{
			paddle.setPosition({ Area.GetPosition().x - (Area.GetWidth() / 2),paddle.getPosition().y });
		}
		else
			paddle.move({ -speed * delta,0 });
			
	}
}