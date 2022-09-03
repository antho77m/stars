#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

#include "Turret.hpp"


enum class Direction;
class BulletContainer;
class Bullet;

class Ship : public sf::Drawable
{
public:
	Ship();
	void move(Direction direction);
	bool isDie(const sf::Vector2u& screenSize);
	void prepareToFire();
	std::optional<Bullet> makeAction(sf::Vector2i mousePos);

	bool intersect(sf::FloatRect other);
	void intersected();
	

private:
	sf::CircleShape ship{ 25,3 };
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void move();
	void turn(sf::Vector2i mousePos);
	void refreshPosition(sf::Vector2i mousePos);
	std::optional<Bullet> shoot(const sf::Vector2i& mousePos);
	int life{1};


	sf::Vector2f positionAtLastMoveUser;
	sf::Vector2f positionToGo;
	sf::Time lastRefresh;
	sf::Time speedToGoPosition=sf::seconds(2);

	Turret turret{ship.getPoint(1)};
	bool prepareToShoot = false;

	friend std::ostream& operator<<(std::ostream& os, const Ship& ship);



};

