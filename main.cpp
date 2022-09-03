#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
    sf::RenderWindow window;
    std::cout << "comment lancer le jeu : " << std::endl;
    std::cout << "1: grand ecran " << std::endl;
    std::cout << "2: fenetre " << std::endl;
    int choix;
    std::cin >> choix;
    if (choix==1)
    {
	    sf::RenderWindow window(sf::VideoMode(900, 900), "Stars" ,sf::Style::Fullscreen);

        window.setFramerateLimit(120);

        Game::initialize(window);
        Game::run();

    }else
    {
        sf::RenderWindow window(sf::VideoMode(900, 900), "Stars");

        window.setFramerateLimit(120);

        Game::initialize(window);

        Game::run();

    }

    return 0;
}
