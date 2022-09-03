#pragma once
#include <SFML/System.hpp>

class FpsCounter
{
public:
	FpsCounter();
	void printFPS();

private:
	int count = 0;
	sf::Clock clock;
};

