#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "PlayGround.h"
#include "Box.h"
#include <assert.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode({900,900}), "PaddleGame", sf::Style::Default);
    Paddle paddle(200.f,20.f,sf::Vector2f(450.f,680.f), sf::Color(21,245,186), 800.f);
    Ball ball(15.f,{300,400},400.f, sf::Color(160, 21, 62));
    PlayGround playGround("Images/GameOver.png",window,70.f,120.f,sf::Color(131,111,255),{80.f,30.f},{130.f,20.f},{40.f,20.f});
    playGround.SetTextAttr("Font/Boldonse-Regular.ttf", 24, sf::Color::White, { 20.f,20.f });
    sf::Clock Time;
    while (window.isOpen())
    {
        
       while(const std::optional event = window.pollEvent())
       {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
                
            } 
       }
       auto DeltaTime = Time.restart();
       window.clear(sf::Color(0, 34, 77));
       if(!playGround.GetGameOverState())
       {
           playGround.Draw(window);
           paddle.draw(window);
           paddle.Movement(DeltaTime.asSeconds(), playGround);
           ball.Draw(window);
           ball.Movement(DeltaTime.asSeconds(), playGround, paddle);
           ball.CheckBoxCollision(playGround); 
           playGround.SetGameOverState(ball.GetFloorHit());
       }
       else
       {
           playGround.Draw(window);
       }

       window.display();
    }
}