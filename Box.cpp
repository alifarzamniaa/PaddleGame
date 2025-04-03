#include "Box.h"

Box::Box(const sf::Vector2f& Pos, const sf::Color& Color, float width, float height)
	:
	color(Color)
{
	boxShape.setPosition(Pos);
	boxShape.setSize({width,height});
	boxShape.setFillColor(color);
	boxShape.setOutlineThickness(1.f);
	boxShape.setOutlineColor(sf::Color(240,243,255));
}

void Box::Draw(sf::RenderWindow& window) const
{
	window.draw(boxShape);
}

sf::Vector2f Box::GetPos() const
{
	return boxShape.getPosition();
}

sf::Vector2f Box::GetSize() const
{
	return boxShape.getSize();
}

int Box::GetBoxScore() const
{
	return BoxScore;
}


