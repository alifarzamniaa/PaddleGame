#include "PlayGround.h"
#include <random>
PlayGround::PlayGround(const std::string& GameOverPath, const sf::Window& window,int in_OffsetX,int in_OffsetY, const sf::Color& OutLineColor,
    const sf::Vector2f& BoxesSize,const sf::Vector2f& BoxesInitPos, const sf::Vector2f& Padding)
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

    std::random_device rd;
    std::mt19937 re(rd());
    std::uniform_int_distribution<int> ColorPick(0,4);
    sf::Vector2f TopLeft = PlayArea.getPosition() - (PlayArea.getSize() / 2.f);
    for(int i = 0; i < 5; i++)
    {
        int ColorNum = ColorPick(re);
        for(int j = 0; j < 5;j++)
        {
            float Xpos = TopLeft.x + BoxesInitPos.x;
            float Ypos = TopLeft.y + BoxesInitPos.y;
            Xpos += j * (BoxesSize.x + Padding.x);
            Ypos += i * (BoxesSize.y + Padding.y);
            boxes.emplace_back(Box(sf::Vector2f(Xpos, Ypos) ,BoxColors[ColorNum], BoxesSize.x, BoxesSize.y));
        }
    }
}


void PlayGround::Draw(sf::RenderWindow& window)
{
    if(GameOverState)
    {
        window.draw(GameOverRect);
    }
    else
    {
         window.draw(PlayArea);    
         for(const auto& b : boxes)
         {
            b.Draw(window);
         }
    }
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

std::vector<Box>& PlayGround::GetBoxes()
{
    return boxes;
}

//void PlayGround::BoxCollision(Ball& ball)
//{
//    for(auto b : boxes)
//    {
//        std::remove_if(boxes.begin(),boxes.end(),[&](const Box& box)
//        {
//            return ball.CheckBoxCollision(box);
//        });
//    }
//}
