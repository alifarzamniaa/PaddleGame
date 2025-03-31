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
void Ball::Movement(float delta, const PlayGround& Area, const Paddle& paddle)
{
	Bouncing(delta, Area);
	CheckPaddleCollision(paddle);
	ball.move(BallVel * delta);
}
bool Ball::GetFloorHit()
{
	return IsHitFloor;
}
void Ball::Bouncing(float delta, const PlayGround& Area)
{
	if (ball.getPosition().x < Area.GetPosition().x - (Area.GetWidth() / 2)) // origin is on center so we need the half of the width to get left side
	{
		float DotProduct = (BallVel.x * 0) + (BallVel.y * 1);
		BallVel = (2.f * (DotProduct * sf::Vector2f(0, 1))) - BallVel;
	}
	if (ball.getPosition().x + 2 * radius > Area.GetWidth() + (Area.GetOffset().x / 2))
	{
		float DotProduct = (BallVel.x * 0) + (BallVel.y * -1);
		BallVel =(2.f * (DotProduct * sf::Vector2f(0, -1))) - BallVel;
	}
	if (ball.getPosition().y < Area.GetPosition().y - (Area.GetHeight() / 2))
	{
		float DotProduct = (BallVel.x * 1) + (BallVel.y * 0);
		BallVel = (2.f * (DotProduct * sf::Vector2f(1, 0))) - BallVel;
	}
	if (ball.getPosition().y + 2 * radius > Area.GetHeight() + (Area.GetOffset().y / 2 + Area.GetTopOffset()))
	{
		IsHitFloor = true;
	}
}

void Ball::CheckPaddleCollision(const Paddle& paddle)
{
	if (ball.getPosition().x < paddle.GetPos().x + paddle.GetWidth() &&
	   ball.getPosition().x + 2 * radius > paddle.GetPos().x &&
	   ball.getPosition().y < paddle.GetPos().y + paddle.GetHeight() &&
	   ball.getPosition().y + 2 * radius > paddle.GetPos().y && 
	   BallVel.y > 0.f
		)
		{
			sf::Vector2f paddleVec =  sf::Vector2f(paddle.GetWidth(),0).normalized();
			float DotProduct = BallVel.x * paddleVec.x + BallVel.y * paddleVec.y;
			BallVel =  (2.f * (DotProduct * paddleVec)) - BallVel;
			
		}
}
