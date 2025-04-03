#pragma once
#include <SFML/Graphics.hpp>
#include "Box.h"
#include <vector>
#include "Score.h"
class PlayGround
{
public:
	PlayGround(const std::string& GameOverPath, const sf::Window& window, int in_OffsetX, int in_OffsetY, const sf::Color& OutLineColor,
			   const sf::Vector2f& BoxesSize , const sf::Vector2f& BoxesInitPos, const sf::Vector2f& Padding);
	void Draw(sf::RenderWindow& window);
	bool GetGameOverState() const;
	float GetWidth() const;
	float GetHeight() const;
	float GetTopOffset() const;
	sf::Vector2f GetOffset() const;
	sf::Vector2f GetPosition() const;
	void SetTextAttr(const std::string& fontPath, int textSize, const sf::Color& color, const sf::Vector2f& pos);
	void UpdateScore(int val);
	void SetGameOverState(bool in_state);
	
	std::vector<Box>& GetBoxes();
private:
	sf::RectangleShape PlayArea;
	const sf::Window& window;
	sf::Image GameOverImage;
	sf::Texture GameOver;
	bool GameOverState = false;
	sf::RectangleShape GameOverRect;
	float OffsetX;
	float OffsetY;
	float TopOffset = 20.f;
	std::vector<Box> boxes;
	sf::Color BoxColors[5] = {sf::Color::Magenta,sf::Color::Green,sf::Color::Yellow,sf::Color::White,sf::Color::Cyan};
	std::unique_ptr<Score> score;
};

