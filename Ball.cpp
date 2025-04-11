#include "Ball.h"

Ball::Ball(float rad, const sf::Vector2f& pos, const sf::Color& color)
	:
	radius(rad)
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
void Ball::Movement(float delta, const Paddle& paddle)
{
	PaddleCollision(paddle);
	ball.move(BallVel * delta);
}
bool Ball::WallCollision(float Left,float Right,float Top, float Bottom)
{
	
	if (ball.getPosition().x < Left ||
		ball.getPosition().x + 2 * radius > Right
		) 
	{
		BallVel.x *= -1;
	}
	if (ball.getPosition().y < Top)
	{
		BallVel.y *= -1;
	}
	if (ball.getPosition().y + 2 * radius > Bottom)
	{
		return true;
	}
	return false;
}

void Ball::SetSpeed(float val)
{
	speed = val;
}

void Ball::PaddleCollision(const Paddle& paddle)
{
	if (ball.getPosition().x < paddle.GetPos().x + paddle.GetWidth() &&
	   ball.getPosition().x + 2 * radius > paddle.GetPos().x &&
	   ball.getPosition().y < paddle.GetPos().y + paddle.GetHeight() &&
	   ball.getPosition().y + 2 * radius > paddle.GetPos().y && 
	   BallVel.y > 0.f
		)
		{
			float PaddleCenter = (paddle.GetPos().x + paddle.GetWidth() / 2.f);
			float HitPos = (ball.getPosition().x - PaddleCenter) / (paddle.GetWidth() /2);
			HitPos = std::clamp(HitPos,-1.f,1.f);
			if (HitPos < 0.0f) //if it hits the left side
			{
				if(BallVel.x > 0)
					BallVel.x *= -1;
				if(BallVel.x < 0)
					BallVel.x *= 1;
			}	
			else
			{
				if (BallVel.x > 0)
					BallVel.x *= 1;
				if (BallVel.x < 0)
					BallVel.x *= -1;
			}
			
			BallVel.y *= -1;
			
		}
}
bool Ball::BoxCollision(const Box& box)
{
		if (ball.getPosition().x < box.GetPos().x + box.GetSize().x &&
			ball.getPosition().x + 2 * radius > box.GetPos().x &&
			ball.getPosition().y < box.GetPos().y + box.GetSize().y &&
			ball.getPosition().y + 2 * radius > box.GetPos().y
			)
		{
			
			float BoxCenter = (box.GetPos().x + box.GetSize().x / 2.f);
			float HitPos = (ball.getPosition().x - BoxCenter) / (box.GetSize().x / 2);
			HitPos = std::clamp(HitPos, -1.f, 1.f);
			if (HitPos < 0.0f) //if it hits the left side
			{
				if (BallVel.x > 0)
					BallVel.x *= -1;
				if (BallVel.x < 0)
					BallVel.x *= 1;
			}
			else
			{
				if (BallVel.x > 0)
					BallVel.x *= 1;
				if (BallVel.x < 0)
					BallVel.x *= -1;
			}
			BallVel.y *= -1;
			return true;
	}
	return false;
}
