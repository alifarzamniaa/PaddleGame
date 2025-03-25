#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode({900,800}), "PaddleGame", sf::Style::Default);
    Paddle paddle(200.f,30.f,sf::Vector2f(450.f,600.f), sf::Color::Green,800.f);
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
       window.clear(sf::Color::Black);

       paddle.draw(window);
       paddle.Movement(Time.restart().asSeconds(),window);


       window.display();
    }
}