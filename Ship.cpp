#include "Ship.hpp"

#include <iostream>

#include "Bullet.hpp"
#include "Game.hpp"
#include "Direction.hpp"


Ship::Ship()
{
	ship.setPosition(200, 200);
	turret.setPosition(sf::Vector2f(200, 200));
	positionAtLastMoveUser = ship.getPosition();
	positionToGo = ship.getPosition();
	ship.setOrigin(sf::Vector2f(ship.getRadius(), ship.getRadius()));
	ship.setFillColor(sf::Color::Red);
	
	//formule compliqu� pour que la turret soit bien avec le ship
	turret.setOrigin(sf::Vector2f(ship.getRadius() / 4, ship.getRadius() / 4)-sf::Vector2f(ship.getPoint(1).x/2, ship.getPoint(1).y/2)+sf::Vector2f(0,turret.getRadius()/2));
}


void Ship::move(Direction direction)
{
	sf::Vector2f translation{};
	switch (direction)
	{
	case Direction::Down:
		translation.y = 25.f;
		break;
	case Direction::Top:
		translation.y = -25.f;
		break;
	case Direction::Left:
		translation.x = -25.f;
		break;
	case Direction::Right:
		translation.x = 25.f;
		break;
	default:
		std::cout << "Error in Ship::move()" << std::endl;
		break;
	}
	
	positionToGo += translation;
	lastRefresh = Game::getTimeGame();
	positionAtLastMoveUser = ship.getPosition();
}


void Ship::refreshPosition(sf::Vector2i mousePos)
{
		move();
		turn(mousePos);
		turret.setRotation(ship.getRotation());
		turret.setPosition(ship.getPosition());
}

//return true if the ship is die
bool Ship::isDie(const sf::Vector2u& screenSize)
{
	return life==0 || ship.getPosition().x+ship.getRadius() < 0|| ship.getPosition().y+ship.getRadius()<0
		|| ship.getPosition().x-ship.getRadius() > screenSize.x || ship.getPosition().y-ship.getRadius() > screenSize.y;
}

void Ship::prepareToFire()
{
	prepareToShoot = true;
}

std::optional<Bullet> Ship::shoot(const sf::Vector2i& mousePos)
{

	prepareToShoot = false;
	return turret.shoot(mousePos);
}

std::optional<Bullet> Ship::makeAction(sf::Vector2i mousePos)
{
	refreshPosition(mousePos);
	if (prepareToShoot)
	{
		return std::optional<Bullet>{shoot(mousePos)};
	}
	return std::nullopt;
}


bool Ship::intersect(sf::FloatRect other)
{
	return ship.getGlobalBounds().intersects(other);
	
}

void Ship::intersected()
{
	if (life>0)
	{
		life -= 1;
	}
}


void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(ship);
	//target.draw(turret);
}


void Ship::move()
{
	const sf::Vector2f totalDistance{ positionToGo - positionAtLastMoveUser };
	const sf::Time timeBeginningPositionToGo{ Game::getTimeGame() - lastRefresh }; //temp depuis la derniere action de mouvement du joueur
	const float pourcentOfWayBySec = timeBeginningPositionToGo.asSeconds() / speedToGoPosition.asSeconds(); //pourcentage de la distance parcourue par le temps
	sf::Vector2f translation = totalDistance * pourcentOfWayBySec;
	ship.setPosition(positionAtLastMoveUser + translation);
}


float getAngleOfTwoPoint(sf::Vector2f firstPoint, sf::Vector2f secondPoint)
{

	const float PI = 3.14159265f;
	
	float dx = secondPoint.x - firstPoint.x;
	float dy = secondPoint.y - firstPoint.y;

	float rotation = (atan2(dy, dx)) * 180 / PI;

	return rotation;
}


void Ship::turn(sf::Vector2i mousePos)
{
	ship.setRotation(getAngleOfTwoPoint(sf::Vector2f(mousePos), ship.getPosition() )+150);

}




std::ostream& operator<<(std::ostream& os, const Ship& ship)
{
	os<< "Ship : position" << ship.ship.getPosition().x << " " << ship.ship.getPosition().y << std::endl;
	return os;
}
