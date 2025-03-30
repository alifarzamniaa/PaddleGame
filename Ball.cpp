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
void Ball::Movement(float delta, const sf::Window& window, const Paddle& paddle)
{
	Bouncing(delta, window);
	CheckPaddleCollision(paddle);
	ball.move(BallVel * delta);
}
void Ball::Bouncing(float delta, const sf::Window& window)
{
	if (ball.getPosition().x < 0)
	{
		float DotProduct = (BallVel.x * 0) + (BallVel.y * 1);
		BallVel = (2.f * (DotProduct * sf::Vector2f(0, 1))) - BallVel;
	}
	if (ball.getPosition().x + 2 * radius > window.getSize().x)
	{
		float DotProduct = (BallVel.x * 0) + (BallVel.y * -1);
		BallVel =(2.f * (DotProduct * sf::Vector2f(0, -1))) - BallVel;
	}
	if (ball.getPosition().y < 0)
	{
		float DotProduct = (BallVel.x * 1) + (BallVel.y * 0);
		BallVel = (2.f * (DotProduct * sf::Vector2f(1, 0))) - BallVel;
	}
	if (ball.getPosition().y + 2 * radius > window.getSize().y)
	{
		float DotProduct = (BallVel.x * -1) + (BallVel.y * 0);
		BallVel = (2.f * (DotProduct * sf::Vector2f(-1, 0))) - BallVel;
	}
}

void Ball::CheckPaddleCollision(const Paddle& paddle)
{
	if (ball.getPosition().x < paddle.GetPos().x + paddle.GetWidth() &&
	   ball.getPosition().x + 2 * radius > paddle.GetPos().x &&
	   ball.getPosition().y < paddle.GetPos().y + paddle.GetHeight() &&
	   ball.getPosition().y + 2 * radius > paddle.GetPos().y
		)
		{
			sf::Vector2f paddleVec =  sf::Vector2f(paddle.GetWidth(),0).normalized();
			float DotProduct = BallVel.x * paddleVec.x + BallVel.y * paddleVec.y;
			BallVel =  (2.f * (DotProduct * paddleVec)) - BallVel;
		}
}
