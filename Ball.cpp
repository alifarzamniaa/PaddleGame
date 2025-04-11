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
	if (ball.getPosition().x < Area.GetPosition().x - (Area.GetWidth() / 2) ||  // origin is on center so we need the half of the width to get left side
		ball.getPosition().x + 2 * radius > Area.GetWidth() + (Area.GetOffset().x / 2)
		) 
	{
		BallVel.x *= -1;
	}
	if (ball.getPosition().y < Area.GetPosition().y - (Area.GetHeight() / 2))
	{
		BallVel.y *= -1;
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
void Ball::CheckBoxCollision(PlayGround& Area)
{
	auto& boxes = Area.GetBoxes();
	for(int i = 0; i < boxes.size();i++)
	{
		if (ball.getPosition().x < boxes[i].GetPos().x + boxes[i].GetSize().x &&
			ball.getPosition().x + 2 * radius > boxes[i].GetPos().x &&
			ball.getPosition().y < boxes[i].GetPos().y + boxes[i].GetSize().y &&
			ball.getPosition().y + 2 * radius > boxes[i].GetPos().y
			)
		{
			
			float PaddleCenter = (boxes[i].GetPos().x + boxes[i].GetSize().x / 2.f);
			float HitPos = (ball.getPosition().x - PaddleCenter) / (boxes[i].GetSize().x / 2);
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
			BallVel.x += SpeedUpOnHit;
			BallVel.y += SpeedUpOnHit;
			Area.UpdateScore(boxes[i].GetBoxScore());
			boxes.erase(boxes.begin() + i);
		}
	}
}
