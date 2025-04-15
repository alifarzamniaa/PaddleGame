#include "PlayGround.h"
#include <random>
PlayGround::PlayGround(const std::string& GameOverPath, const sf::Window& window, const sf::Color& OutLineColor)
	:
    window(window),
    paddle(200.f, 20.f, sf::Vector2f(450.f, 680.f)),
    ball(15.f, { 300,400 }, sf::Color(160, 21, 62)),
    ScoreText(font)
{
    assert(GameOverImage.loadFromFile(GameOverPath));
    assert(GameOver.loadFromImage(GameOverImage));
    GameOverState = false;
    GameOverRect.setTexture(&GameOver);
    GameOverRect.setSize((sf::Vector2f)window.getSize());

    
    PlayArea.setOutlineColor(OutLineColor);
    PlayArea.setFillColor(sf::Color(0, 34, 77));
    PlayArea.setOutlineThickness(9.f);
    PlayArea.setSize(sf::Vector2f(window.getSize().x - OffsetX, window.getSize().y - OffsetY));
    PlayArea.setOrigin(PlayArea.getSize() / 2.f);
    PlayArea.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().x / 2.f + TopOffset));

    SpawnBoxes();

    ScoreText.setCharacterSize(TextSize);
    ScoreText.setFillColor(TextColor);
    ScoreText.setPosition({20.f,20.f});
    ScoreText.setString("Score is : " + std::to_string(GetScore()));
}


void PlayGround::Draw(sf::RenderWindow& window)
{
    if(GameOverState)
    {
        window.draw(GameOverRect);
        window.draw(ScoreText);
        ScoreText.setPosition({ window.getSize().x / 2.f - OffsetX ,window.getSize().y / 2.f + 200.f + OffsetY });
    }
    else
    {
         window.draw(PlayArea);
         window.draw(ScoreText);
         paddle.Draw(window);
         ball.Draw(window);
         for(const auto& b : boxes)
         {
            b.Draw(window);
         }
         
    }
}
void PlayGround::UpdateGameState(float delta)
{
    ball.Movement(delta,paddle);
    paddle.Movement(delta,GetLeftnRight().x, GetLeftnRight().y,GetTopnBottom().x, GetTopnBottom().y);
    
    if(ball.WallCollision(GetLeftnRight().x, GetLeftnRight().y, GetTopnBottom().x, GetTopnBottom().y)) // if it hits the floor
    {
        GameOverState = true;
    }
    for(int i = 0; i < boxes.size();i++)
    {
        if(ball.BoxCollision(boxes[i]))
        {
            UpdateScore(boxes[i].GetBoxScore());
            boxes.erase(boxes.begin() + i);
        }
    }
    if (boxes.size() == 0 && ball.GetBallPos().y > GetHeight() / 2) // if the ball passed the boxes then respawn the box
    {
        SpawnBoxes();
        // rest the ball speed to default after breaking all the boxes
        ball.SetSpeed(ball.GetInitSpeed());
    }
}
void PlayGround::SpawnBoxes()
{
        std::random_device rd;
        std::mt19937 re(rd());
        std::uniform_int_distribution<int> ColorPick(0, 4);
        for (int i = 0; i < NumberOfBoxesInColumn; i++)
        {
            int ColorNum = ColorPick(re);
            for (int j = 0; j < NumberOfBoxesInRow; j++)
            {
                float Xpos = GetLeftnRight().x;
                float Ypos = GetTopnBottom().x;
                Xpos += j * (BoxWidth + Padding.x);
                Ypos += i * (BoxHeight + Padding.y);
                boxes.emplace_back(Box(sf::Vector2f(Xpos, Ypos), BoxColors[ColorNum], BoxWidth, BoxHeight));
            }
        }
}

float PlayGround::GetWidth() const
{
    return PlayArea.getSize().x;
}

float PlayGround::GetHeight() const
{
    return PlayArea.getSize().y;
}

int PlayGround::GetScore() const
{
    return score;
}
void PlayGround::UpdateScore(int val)
{
    score += val;
    ScoreText.setString("Score is : " + std::to_string(GetScore())); // updating the text
}

sf::Vector2f PlayGround::GetPosition() const
{
    return PlayArea.getPosition();
}

sf::Vector2f PlayGround::GetLeftnRight() const
{
    return {PlayArea.getPosition().x - (GetWidth() / 2) , PlayArea.getPosition().x + (GetWidth() / 2)};
}

sf::Vector2f PlayGround::GetTopnBottom() const
{
    return { PlayArea.getPosition().y - (GetHeight() / 2) , PlayArea.getPosition().y + (GetHeight() / 2) };
}

