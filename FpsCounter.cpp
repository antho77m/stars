#include "FpsCounter.hpp"

#include <iostream>

FpsCounter::FpsCounter()
{
}

void FpsCounter::printFPS()
{
	if (clock.getElapsedTime().asSeconds()>1)
	{

		std::cout << "FPS :" << count << std::endl;
		count = 0;
		clock.restart();
	}

	count++;
}
