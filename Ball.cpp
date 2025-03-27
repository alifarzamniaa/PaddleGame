#include "Ball.h"


Ball::Ball(float rad, const sf::Vector2f& pos, float speed, const sf::Color& color)
	:
	radius(rad),
	speed(speed)
{
	ball.setPosition(pos);
	ball.setRadius(radius);
	ball.setFillColor(color);
	BallVel = speed * dir;
}
void Ball::Draw(sf::RenderWindow& window) const
{
	window.draw(ball);
}
void Ball::Movement(float delta, const sf::Window& window)
{
	Bouncing(delta, window);
}
void Ball::Bouncing(float delta, const sf::Window& window)
{
	if (ball.getPosition().x < 0)
	{
		float DotProduct = (BallVel.x * 1) + (BallVel.y * 0);
		BallVel = BallVel - (2.f * (DotProduct * sf::Vector2f(1, 0)));
	}
	if (ball.getPosition().x + 2 * radius > window.getSize().x)
	{
		float DotProduct = (BallVel.x * -1) + (BallVel.y * 0);
		BallVel = BallVel - (2.f * (DotProduct * sf::Vector2f(-1, 0)));
	}
	if (ball.getPosition().y < 0)
	{
		float DotProduct = (BallVel.x * 0) + (BallVel.y * 1);
		BallVel = BallVel - (2.f * (DotProduct * sf::Vector2f(0, 1)));
	}
	if (ball.getPosition().y + 2 * radius > window.getSize().y)
	{
		float DotProduct = (BallVel.x * 0) + (BallVel.y * -1);
		BallVel = BallVel - (2.f * (DotProduct * sf::Vector2f(0, -1)));
	}
	ball.move(BallVel * delta);
}