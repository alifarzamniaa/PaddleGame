#include <SFML/Graphics.hpp>
#include "PlayGround.h"
#include <assert.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode({900,900}), "PaddleGame", sf::Style::Default);
    
    PlayGround playGround("Images/GameOver.png",window,sf::Color(131,111,255));
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

       playGround.UpdateGameState(DeltaTime.asSeconds());
       playGround.Draw(window);

       window.display();
    }
}