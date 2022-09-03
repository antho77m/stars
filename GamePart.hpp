#pragma once
#include <SFML/Graphics/Drawable.hpp>

class GamePart:public sf::Drawable
{
public:
	virtual void update() = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

