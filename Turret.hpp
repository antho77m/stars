#pragma once
#include <optional>
#include <SFML/Graphics.hpp>


class Bullet;

class Turret:public sf::Drawable
{
public:
	Turret();
	Turret(sf::Vector2f location);
	void setTimeToReload(sf::Time time);
	void setPosition(sf::Vector2f position);
	void setOrigin(sf::Vector2f origin);
	void setRotation(float angle);
	float getRadius();

	std::optional<Bullet> shoot(const sf::Vector2i& mousePos);
private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::CircleShape turret{10};
	sf::Time timeToReload{sf::seconds(0.25)};
	sf::Time lastShoot;

};

