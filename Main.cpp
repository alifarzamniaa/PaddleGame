#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "PaddleGame", sf::Style::Default);
    while (window.isOpen())
    {
       while(const std::optional event = window.pollEvent())
       {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
       }
    }
}