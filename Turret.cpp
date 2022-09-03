#include "Turret.hpp"


#include "Bullet.hpp"
#include "Game.hpp"


Turret::Turret()
{
}

Turret::Turret(sf::Vector2f location)
{
	sf::Sprite sprite;
	turret.setFillColor(sf::Color::Yellow);
	turret.setPosition(location);
	turret.setOrigin(turret.getRadius(), turret.getRadius());
}

void Turret::setTimeToReload(sf::Time time)
{
	timeToReload = time;
}

void Turret::setPosition(sf::Vector2f position) 
{
	turret.setPosition(position);
}

void Turret::setOrigin(sf::Vector2f origin)
{
	turret.setOrigin(origin);
}

void Turret::setRotation(float angle)
{
	turret.setRotation(angle);
}

float Turret::getRadius()
{
	return turret.getRadius();
}

std::optional<Bullet> Turret::shoot(const sf::Vector2i& mousePos)
{
	if (Game::getTimeGame()-lastShoot>=timeToReload)
	{
		lastShoot = Game::getTimeGame();

		float dx = mousePos.x - turret.getPosition().x;
		float dy = turret.getPosition().y - mousePos.y;

		float angle = -(atan2(dy, dx));
		return Bullet{ turret.getOrigin(),turret.getRotation(),turret.getPosition(),1000, angle };

	}
	return std::nullopt;

}


void Turret::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(turret);
}

