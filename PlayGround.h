#pragma once
#include <SFML/Graphics.hpp>
class PlayGround
{
public:
	PlayGround(const std::string& GameOverPath, const sf::Window& window, int in_OffsetX, int in_OffsetY, const sf::Color& OutLineColor);
	sf::RectangleShape GetPlayArea() const;
	sf::RectangleShape GetGameOverRect() const;
	bool GetGameOverState() const;
	float GetWidth() const;
	float GetHeight() const;
	float GetTopOffset() const;
	sf::Vector2f GetOffset() const;
	sf::Vector2f GetPosition() const;

	void SetGameOverState(bool in_state);

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
};

