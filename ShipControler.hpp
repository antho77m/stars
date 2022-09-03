#pragma once
#include <SFML/System/Time.hpp>

class Ship;

class ShipControler
{
public:
	ShipControler(Ship& ship);
	void shootControl();
	void control() ;

private:
	void moveControl() const;
	void displayControl() const;


	sf::Time refreshControl= sf::milliseconds(100);
	sf::Time lastRefreshControl;
	Ship* ship;
};

