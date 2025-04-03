#pragma once
#include <SFML/Graphics.hpp>
class Score
{

public:
	Score(const std::string& fontPath,int textSize,const sf::Color& color, const sf::Vector2f& pos);
	void Draw(sf::RenderWindow& window) const;
	void AddScore(int in_v);
	void SetPos(const sf::Vector2f& pos);
	sf::Vector2f GetPos() const;
	int GetScore() const;
private:
	int score = 0;
	sf::Font font;
	sf::Text text;
};

