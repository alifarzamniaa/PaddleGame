#include "PlayGround.h"

PlayGround::PlayGround(const std::string& GameOverPath, const sf::Window& window,int in_OffsetX,int in_OffsetY, const sf::Color& OutLineColor)
	:
    window(window),
    OffsetX(in_OffsetX),
    OffsetY(in_OffsetY)
{
    assert(GameOverImage.loadFromFile(GameOverPath));
    assert(GameOver.loadFromImage(GameOverImage));
    GameOverState = false;
    GameOverRect.setTexture(&GameOver);
    GameOverRect.setSize((sf::Vector2f)window.getSize());

    
    PlayArea.setOutlineColor(OutLineColor);
    PlayArea.setFillColor(sf::Color(0, 34, 77));
    PlayArea.setOutlineThickness(9.f);
    PlayArea.setSize(sf::Vector2f(window.getSize().x - in_OffsetX, window.getSize().y - in_OffsetY));
    PlayArea.setOrigin(PlayArea.getSize() / 2.f);
    PlayArea.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().x / 2.f + TopOffset));
}

sf::RectangleShape PlayGround::GetPlayArea() const
{
    return PlayArea;
}

sf::RectangleShape PlayGround::GetGameOverRect() const
{
    return GameOverRect;
}

bool PlayGround::GetGameOverState() const
{
    return GameOverState;
}

float PlayGround::GetWidth() const
{
    return PlayArea.getSize().x;
}

float PlayGround::GetHeight() const
{
    return PlayArea.getSize().y;
}

sf::Vector2f PlayGround::GetOffset() const
{
    return sf::Vector2f(OffsetX,OffsetY);
}

float PlayGround::GetTopOffset() const
{
    return TopOffset;
}

sf::Vector2f PlayGround::GetPosition() const
{
    return PlayArea.getPosition();
}

void PlayGround::SetGameOverState(bool in_state)
{
    GameOverState = in_state;
}
