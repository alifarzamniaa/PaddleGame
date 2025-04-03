#pragma once
#include <SFML/Graphics.hpp>
class Box
{
public:
	Box(const sf::Vector2f& Pos,const sf::Color& Color, float width, float height);
	void Draw(sf::RenderWindow& window) const;
	sf::Vector2f GetPos() const;
	sf::Vector2f GetSize() const; // x is width , y is height
	int GetBoxScore() const;
private:
	sf::RectangleShape boxShape;
	sf::Color color;
	int BoxScore = 1;
};

