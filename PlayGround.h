#pragma once
#include <SFML/Graphics.hpp>
#include "Box.h"
#include <vector>
#include "Score.h"
class PlayGround
{
public:
	PlayGround(const std::string& GameOverPath, const sf::Window& window, int in_OffsetX, int in_OffsetY, const sf::Color& OutLineColor);
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
	void SpawnBoxes();
	std::vector<Box>& GetBoxes();
private:
	//PlayArea And GameOver
	sf::RectangleShape PlayArea;
	const sf::Window& window;
	sf::RectangleShape GameOverRect;
	sf::Image GameOverImage;
	sf::Texture GameOver;
	bool GameOverState = false;

	//Box Properties
	sf::Vector2f Padding = {5.f,5.f};
	std::vector<Box> boxes;
	sf::Color BoxColors[5] = {sf::Color::Magenta,sf::Color::Green,sf::Color::Yellow,sf::Color::White,sf::Color::Cyan};
	float OffsetX;
	float OffsetY;
	float TopOffset = 20.f;
	float BoxWidth = 88.f;
	float BoxHeight = 35.f;
	int NumberOfBoxesInRow = 9;
	int NumberOfBoxesInColumn = 6;


	std::unique_ptr<Score> score;
};

