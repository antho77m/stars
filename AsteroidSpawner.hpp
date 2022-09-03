#pragma once
#include <vector>
#include <SFML/System/Time.hpp>

#include "Size.hpp"
class Asteroid;


class AsteroidSpawner
{
public:
	std::vector<Asteroid> spawnWave();
	void nextLevel();
	int getWaveLevel() const;
	int getNumberOfWaveCall() const;

private:
	void updateLevel();

	int waveLevel {0};
	int numberOfWaveCall{ 0 };
	sf::Time lastSpawn;
	sf::Time lastLevelUpdate;
	sf::Time timeBetweenSpawn{ sf::seconds(2.f) };
	sf::Time timeBetweenLevel{ sf::seconds(7.f) };
};

