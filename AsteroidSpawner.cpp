#include "AsteroidSpawner.hpp"

#include <cassert>
#include <iostream>
#include <random>
#include <SFML/System/Vector2.hpp>

#include "AngleRadiant.hpp"
#include "Asteroid.hpp"
#include "Game.hpp"
#include "GameComponent.hpp"

template <typename T1>
T1 generateRandomNumber(const T1 min, const T1 max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	const std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

Size generateRandomSize()
{
	int randomNumber = generateRandomNumber(0, 100);
	if (randomNumber<=50)
	{
		return Size::little;
	}
	if (randomNumber<=80)
	{
		return Size::medium;
	}
	if (randomNumber<=95)
	{
		return Size::large;
	}
	return Size::huge;

}


sf::Vector2f giveAsteroidePosition(int side)
{

	//1 - top, 2 - right, 3 - bottom, 4 - left of window

	sf::Vector2f windowSize = sf::Vector2f(Game::getGameInformation().windowSize);
	switch (side)
	{
	case 1:
		return sf::Vector2f(generateRandomNumber(0.f, windowSize.x), 0);
		break;
	case 2:
		return sf::Vector2f(windowSize.x, generateRandomNumber(0.f, windowSize.y));
		break;
	case 3:
		return sf::Vector2f(generateRandomNumber(0.f, windowSize.x), windowSize.y);
		break;
	case 4:
		return sf::Vector2f(0, generateRandomNumber(0.f, windowSize.y));
		break;
	}
	assert(false && "side matches to no value");
	return sf::Vector2f(0, 0);
}

float giveRandomAngle(int side)
{

	//1 - top, 2 - right, 3 - bottom, 4 - left of window
	//give angle in degrees

	switch (side)
	{
	case 1:
		return generateRandomNumber(45.f, 135.f);
		break;
	case 2:
		return generateRandomNumber(135.f, 180.f);
		break;
	case 3:
		return generateRandomNumber(225.f, 315.f);
		break;
	case 4:
		return generateRandomNumber(-45.f, 45.f);
	}
	return 0;

}


std::vector<Asteroid> AsteroidSpawner::spawnWave()
{
	updateLevel();
	numberOfWaveCall++;

	std::vector<Asteroid> asteroidsCreate;	
	if (Game::getTimeGame()-lastSpawn>timeBetweenSpawn)
	{
		lastSpawn = Game::getTimeGame();

		int numberOfAsteroid = generateRandomNumber(1, waveLevel + 1);

		for (int i = 0; i < numberOfAsteroid; i++)
		{
			const int side = generateRandomNumber(1, 4);
			sf::Vector2f position = giveAsteroidePosition(side);
			float radiantAngle = convertToRadiant(giveRandomAngle(side));
			Asteroid asteroid{ position,100,radiantAngle,static_cast<float>(generateRandomNumber(0,50)),generateRandomSize() };
			asteroidsCreate.push_back(asteroid);
		}

	}
	return asteroidsCreate;
}

void AsteroidSpawner::nextLevel()
{
	waveLevel++;
}

int AsteroidSpawner::getWaveLevel()const
{
	return waveLevel;
}

int AsteroidSpawner::getNumberOfWaveCall() const
{
	return numberOfWaveCall;
}

void AsteroidSpawner::updateLevel()
{
	if (Game::getTimeGame()-lastLevelUpdate>timeBetweenLevel)
	{
		lastLevelUpdate = Game::getTimeGame();
		waveLevel++;
		std::cout<<"level :"<<waveLevel<<std::endl;
	}
}

