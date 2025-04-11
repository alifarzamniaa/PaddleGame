#pragma once
#include <SFML/Graphics.hpp>
#include "Box.h"
#include "Paddle.h"
#include "Ball.h"
#include <vector>
class PlayGround
{
public:
	PlayGround(const std::string& GameOverPath, const sf::Window& window, const sf::Color& OutLineColor);
	void Draw(sf::RenderWindow& window);
	void UpdateGameState(float delta);

	float GetWidth() const;
	float GetHeight() const;
	int GetScore() const;
	sf::Vector2f GetPosition() const;
	sf::Vector2f GetLeftnRight() const;
	sf::Vector2f GetTopnBottom() const;

	void UpdateScore(int val);
	void SpawnBoxes();
private:
	//PlayArea
	sf::RectangleShape PlayArea;
	const sf::Window& window;
	float OffsetX = 70.f;
	float OffsetY = 120.f;
	float TopOffset = 20.f;
	
	//GameOver
	sf::RectangleShape GameOverRect;
	sf::Image GameOverImage;
	sf::Texture GameOver;
	bool GameOverState = false;

	//Box Properties
	sf::Vector2f Padding = {5.f,5.f};
	std::vector<Box> boxes;
	sf::Color BoxColors[5] = {sf::Color::Magenta,sf::Color::Green,sf::Color::Yellow,sf::Color::White,sf::Color::Cyan};
	float BoxWidth = 88.f;
	float BoxHeight = 35.f;
	int NumberOfBoxesInRow = 9;
	int NumberOfBoxesInColumn = 6;

	// Ball
	Ball ball;

	// Paddle
	Paddle paddle;

	//Score props
	int score = 0;
	sf::Font font = sf::Font("Font/Boldonse-Regular.ttf");
	sf::Text ScoreText;
	sf::Color TextColor = sf::Color::White;
	int TextSize = 24;

};

