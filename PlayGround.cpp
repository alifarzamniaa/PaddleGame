#include "PlayGround.h"
#include <random>
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

    SpawnBoxes();
}


void PlayGround::Draw(sf::RenderWindow& window)
{
    if(GameOverState)
    {
        window.draw(GameOverRect);
        score->Draw(window);
        window.getSize().x / 2;
        score->SetPos({ window.getSize().x / 2.f - OffsetX ,window.getSize().y / 2.f + 200.f + OffsetY });
    }
    else
    {
         window.draw(PlayArea);    
         assert(score); // you have to call the SetTextAttr func before drawing it
         score->Draw(window);
         for(const auto& b : boxes)
         {
            b.Draw(window);
         }
         if(boxes.size() == 0)
         {
            SpawnBoxes();
         }
    }
}
void PlayGround::SpawnBoxes()
{
        std::random_device rd;
        std::mt19937 re(rd());
        std::uniform_int_distribution<int> ColorPick(0, 4);
        sf::Vector2f TopLeft = PlayArea.getPosition() - (PlayArea.getSize() / 2.f);
        for (int i = 0; i < NumberOfBoxesInColumn; i++)
        {
            int ColorNum = ColorPick(re);
            for (int j = 0; j < NumberOfBoxesInRow; j++)
            {
                float Xpos = TopLeft.x;
                float Ypos = TopLeft.y;
                Xpos += j * (BoxWidth + Padding.x);
                Ypos += i * (BoxHeight + Padding.y);
                boxes.emplace_back(Box(sf::Vector2f(Xpos, Ypos), BoxColors[ColorNum], BoxWidth, BoxHeight));
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

void PlayGround::SetTextAttr(const std::string& fontPath, int textSize, const sf::Color& color, const sf::Vector2f& pos)
{
   score = std::make_unique<Score>(fontPath,textSize,color,pos);
}

void PlayGround::UpdateScore(int val)
{
    if(score)
    {
        score->AddScore(val);
    }
}

void PlayGround::SetGameOverState(bool in_state)
{
    GameOverState = in_state;
}

std::vector<Box>& PlayGround::GetBoxes()
{
    return boxes;
}

