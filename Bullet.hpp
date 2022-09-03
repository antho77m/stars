#pragma once
#include <SFML/Graphics.hpp>


class Bullet:public sf::Drawable
{
public:
	Bullet(sf::Vector2f origins, float rotation,sf::Vector2f position,float speed, float angle);
	void advance();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Vector2f getPosition() const;
	sf::FloatRect getGlobalBounds() const;
	void intersected();
	bool isHitted()const;
private:

	friend bool operator==(const Bullet& lhs, const Bullet& rhs);
	sf::CircleShape bullet;
	float speed;

	float angle;
	bool isHit=false;
	sf::Time lastAdvance;

};

