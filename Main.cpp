#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode({900,800}), "PaddleGame", sf::Style::Default);
    Paddle paddle(200.f,20.f,sf::Vector2f(450.f,600.f), sf::Color::Green,800.f);
    Ball ball(15.f,{300,400},400.f,sf::Color::Red);
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
       window.clear(sf::Color::Black);

       paddle.draw(window);
       paddle.Movement(DeltaTime.asSeconds(),window);
       
       ball.Draw(window);
       ball.Movement(DeltaTime.asSeconds(),window,paddle);

       window.display();
    }
}