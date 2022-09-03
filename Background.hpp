#pragma once
#include <SFML/Graphics.hpp>

class Background:public sf::Drawable
{
public:
	static void initTexture();
	Background(sf::Vector2u size);

private:
	std::shared_ptr<sf::Texture> texture;
	sf::RectangleShape background;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

