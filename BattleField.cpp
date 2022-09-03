#include "BattleField.hpp"

#include <optional>
#include <random>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "ShipControler.hpp"


BattleField::BattleField() :shipControler(ship)
{
}

void BattleField::updateField(sf::Vector2i mousePos)
{
	shipControler.control();
	if(std::optional<Bullet> bullet = ship.makeAction(mousePos))
	{
		bulletContainer.addBullet(*bullet);
		
	}
	generateAsteroid();
	updateColision();

	bulletContainer.advanceBullets();
	for (auto& asteroid : asteroids)
	{
		asteroid.advance();
	}
}

void BattleField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(ship);
	target.draw(bulletContainer);
	for (auto& asteroid : asteroids)
	{
		target.draw(asteroid);
	}
}

bool BattleField::shipIsDie(sf::Vector2u screenSize)
{
	return ship.isDie(screenSize);
}



void BattleField::generateAsteroid()
{
	std::vector<Asteroid> newAsteroids = asteroidSpawner.spawnWave();
	asteroids.insert(asteroids.end(), newAsteroids.begin(), newAsteroids.end());
}

void BattleField::BulletAndAsteroidColision()
{
	for (auto& asteroid : asteroids)
	{
		if (!asteroid.isDestroy())
		{
			for (size_t j = 0; j < bulletContainer.getSize(); j++)
			{
				Bullet* bullet{ bulletContainer.getBullet(j) };
				if (!bullet->isHitted())
				{
					if (asteroid.intersects(bullet->getGlobalBounds()))
					{
						bulletContainer.removeBullet(*bullet);
						asteroid.intersected();
					}

				}

			}
		}


	}
}

void BattleField::AsteroidManager()
{

	std::vector<Asteroid> newAsteroids;
	asteroids.erase(
		std::ranges::remove_if(asteroids, [&newAsteroids](const Asteroid& asteroid)
			{
				if (asteroid.isDestroy())
				{
					auto asteroidSpawn = asteroid.destroy();
					newAsteroids.insert(newAsteroids.end(), asteroidSpawn.begin(), asteroidSpawn.end());
					return true;
				}
				return false;

			}).begin(),
				asteroids.end());


	asteroids.insert(asteroids.end(), newAsteroids.begin(), newAsteroids.end());

}

void BattleField::ShipColision()
{

	for (auto& asteroid : asteroids)
	{
		if (ship.intersect(asteroid.getGlobalBound()))
		{
			ship.intersected();
		}
	}

}

void BattleField::updateColision()
{

	BulletAndAsteroidColision();
	AsteroidManager();
	ShipColision();
	

}
