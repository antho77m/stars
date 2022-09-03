#include "Bullet.hpp"

#include <iostream>

#include "Game.hpp"


Bullet::Bullet(sf::Vector2f origins,float rotation, sf::Vector2f position, float speed, float angle):speed(speed),angle(angle),lastAdvance(Game::getTimeGame())
{
	bullet.setOrigin(origins);
	bullet.setRotation(rotation);
	bullet.setPosition(position);
	bullet.setFillColor(sf::Color::White);
	bullet.setRadius(5);
	advance();


}

void Bullet::advance()
{
	float delta = Game::getTimeGame().asSeconds() - lastAdvance.asSeconds();
	sf::Vector2f translation{ speed * cos(angle), speed * sin(angle) };
	bullet.move(translation*delta);
	lastAdvance = Game::getTimeGame();
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(bullet);
}

sf::Vector2f Bullet::getPosition() const
{
	return bullet.getPosition();
}

sf::FloatRect Bullet::getGlobalBounds() const
{
	return bullet.getGlobalBounds();
}

void Bullet::intersected()
{
	isHit = true;
}

bool Bullet::isHitted() const
{
	return isHit;
}

bool operator==(const Bullet& lhs, const Bullet& rhs)
{
	return lhs.speed == rhs.speed && lhs.angle == rhs.angle && lhs.bullet.getPosition() == rhs.bullet.getPosition() &&
		lhs.isHit == rhs.isHit;
}


