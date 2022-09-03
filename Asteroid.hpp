#pragma once

#include <SFML/Graphics.hpp>

#include "Size.hpp"

class Asteroid:public sf::Drawable
{
public:

	static void initTexture();

	Asteroid(sf::Vector2f position,float speed,float angleDirection,float rotation,Size size);
	void advance();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


	bool intersects(sf::FloatRect other)const;
	void intersected();
	bool isDestroy()const;
	std::vector<Asteroid>destroy()const;
	sf::FloatRect getGlobalBound()const;


private:
	sf::Sprite asteroid;
	float speed;
	float rotation;
	float angleDirection;
	int life;
	sf::Time lastUpdate;
	Size size;
	

	
};

