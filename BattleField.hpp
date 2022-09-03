#pragma once
#include "AsteroidSpawner.hpp"
#include "BulletContainer.hpp"
#include "Ship.hpp"
#include "ShipControler.hpp"
#include "Asteroid.hpp"

class ShipControler;

class BattleField:public sf::Drawable
{
public:
	BattleField();
	void updateField(sf::Vector2i mousePos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool shipIsDie(sf::Vector2u screenSize);
private:

	void generateAsteroid();
	void BulletAndAsteroidColision();
	void AsteroidManager();
	void ShipColision();
	void updateColision();
	
	BulletContainer bulletContainer;
	Ship ship;
	ShipControler shipControler;
	std::vector<Asteroid> asteroids;
	AsteroidSpawner asteroidSpawner;
	
};

