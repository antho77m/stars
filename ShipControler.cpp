#include "ShipControler.hpp"

#include <iostream>

#include "Game.hpp"
#include "Ship.hpp"
#include "Direction.hpp"

ShipControler::ShipControler(Ship& ship)
{
	this->ship = &ship;
}

void ShipControler::shootControl()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        ship->prepareToFire();
    }
}

void ShipControler::control() 
{
	if (Game::getTimeGame()-lastRefreshControl>refreshControl)
	{
        lastRefreshControl = Game::getTimeGame();
        moveControl();
        displayControl();
        shootControl();
	}
}

void ShipControler::moveControl() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        ship->move(Direction::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        ship->move(Direction::Top);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        ship->move(Direction::Down);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ship->move(Direction::Right);
    }
}

void ShipControler::displayControl() const
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        std::cout << *ship << std::endl;
    }
}


