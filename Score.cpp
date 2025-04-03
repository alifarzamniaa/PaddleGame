#include "Score.h"
#include <assert.h>

Score::Score(const std::string& fontPath, int textSize, const sf::Color& color,const sf::Vector2f& pos)
	:
	text(font)
{
	assert(font.openFromFile(fontPath));
	text.setCharacterSize(textSize);
	text.setFillColor(color);
	text.setPosition(pos);
	text.setString("Score is : " + std::to_string(GetScore()));
}

void Score::Draw(sf::RenderWindow& window) const
{
	window.draw(text);
}

void Score::AddScore(int in_v)
{
	score += in_v;
	text.setString("Score is : " + std::to_string(GetScore()));
}

void Score::SetPos(const sf::Vector2f& pos)
{
	text.setPosition(pos);
}

sf::Vector2f Score::GetPos() const
{
	return text.getPosition();
}

int Score::GetScore() const
{
	return score;
}
